/*
Copyright (c) 2014, Pure Engineering LLC
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

* Redistributions of source code must retain the above copyright notice, this
  list of conditions and the following disclaimer.

* Redistributions in binary form must reproduce the above copyright notice,
  this list of conditions and the following disclaimer in the documentation
  and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include <stdint.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/types.h>
#include <linux/spi/spidev.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define ARRAY_SIZE(a) (sizeof(a) / sizeof((a)[0]))
#define PORT     8080
#define MAXLINE 10

static void pabort(const char *s)
{
	perror(s);
	abort();
}

static const char *device = "/dev/spidev0.0";
static uint8_t mode;
static uint8_t bits = 8;
static uint32_t speed = 16000000;
static uint16_t delay;

#define VOSPI_FRAME_SIZE (164)
uint8_t lepton_frame_packet[VOSPI_FRAME_SIZE];
static unsigned int lepton_image[80][80];
static unsigned int udp_image[6400];

static void capture(void)
{
	int i;
	int j;
	unsigned int maxval = 0;
	unsigned int minval = UINT_MAX;
	char image_name[32];
	int image_index = 0;

	printf("Calculating min/max values for proper scaling...\n");
	
	for(i=0;i<60;i++)
	{
		for(j=0;j<80;j++)
		{
			if (lepton_image[i][j] > maxval) {
				maxval = lepton_image[i][j];
			}
			if (lepton_image[i][j] < minval) {
				minval = lepton_image[i][j];
			}
		}
	}
	printf("maxval = %u\n",maxval);
	printf("minval = %u\n",minval);
	
	int indx=0;
	for(i=0;i<60;i++)
	{
		for(j=0;j<80;j++)
		{
			udp_image[indx]= lepton_image[i][j] - minval;
			indx=indx+1;
		}
	}
}

int transfer(int fd)
{
	int ret;
	int i;
	int frame_number;
	uint8_t tx[VOSPI_FRAME_SIZE] = {0, };
	struct spi_ioc_transfer tr = {
		.tx_buf = (unsigned long)tx,
		.rx_buf = (unsigned long)lepton_frame_packet,
		.len = VOSPI_FRAME_SIZE,
		.delay_usecs = delay,
		.speed_hz = speed,
		.bits_per_word = bits,
	};

	ret = ioctl(fd, SPI_IOC_MESSAGE(1), &tr);
	if (ret < 1)
		pabort("can't send spi message");

	if(((lepton_frame_packet[0]&0xf) != 0x0f))
	{
		frame_number = lepton_frame_packet[1];

		if(frame_number < 60 )
		{
			for(i=0;i<80;i++)
			{
				lepton_image[frame_number][i] = (lepton_frame_packet[2*i+4] << 8 | lepton_frame_packet[2*i+5]);
			}
		}
	}
	return frame_number;
}

int main(int argc, char *argv[])
{
	int ret = 0;
	int fd;
	int sockfd;
    char buffer[MAXLINE];
    char *hello = "Hello from server";
    struct sockaddr_in servaddr, cliaddr;
	//int test_array[]={1,2,3,4,5,6}; //It does not work!!
	for (int ply=1;1000;ply++){
	fd = open(device, O_RDWR);
	if (fd < 0)
	{
		pabort("can't open device");
	}

	ret = ioctl(fd, SPI_IOC_WR_MODE, &mode);
	if (ret == -1)
	{
		pabort("can't set spi mode");
	}

	ret = ioctl(fd, SPI_IOC_RD_MODE, &mode);
	if (ret == -1)
	{
		pabort("can't get spi mode");
	}

	ret = ioctl(fd, SPI_IOC_WR_BITS_PER_WORD, &bits);
	if (ret == -1)
	{
		pabort("can't set bits per word");
	}

	ret = ioctl(fd, SPI_IOC_RD_BITS_PER_WORD, &bits);
	if (ret == -1)
	{
		pabort("can't get bits per word");
	}

	ret = ioctl(fd, SPI_IOC_WR_MAX_SPEED_HZ, &speed);
	if (ret == -1)
	{
		pabort("can't set max speed hz");
	}

	ret = ioctl(fd, SPI_IOC_RD_MAX_SPEED_HZ, &speed);
	if (ret == -1)
	{
		pabort("can't get max speed hz");
	}

	printf("spi mode: %d\n", mode);
	printf("bits per word: %d\n", bits);
	printf("max speed: %d Hz (%d KHz)\n", speed, speed/1000);

	while(transfer(fd)!=59){}

	close(fd);

	capture();

	// Creating socket file descriptor
    if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }
   
    memset(&servaddr, 0, sizeof(servaddr));
    memset(&cliaddr, 0, sizeof(cliaddr));
       
    // Filling server information
    servaddr.sin_family    = AF_INET; // IPv4
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(PORT);

	// Bind the socket with the server address
    if ( bind(sockfd, (const struct sockaddr *)&servaddr, 
            sizeof(servaddr)) < 0 )
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
       
    int len, n;
   
    len = sizeof(cliaddr);  //len is value/resuslt
   
    n = recvfrom(sockfd, (char *)buffer, MAXLINE, 
                MSG_WAITALL, ( struct sockaddr *) &cliaddr,
                &len);
    buffer[n] = '\0';
    printf("Client : %s\n", buffer);
	
	printf("size of udp_image %d \n",sizeof(udp_image));
	sendto(sockfd, udp_image , sizeof(udp_image), 
        MSG_CONFIRM, (const struct sockaddr *) &cliaddr,
            len);

    printf("%s",udp_image);
	printf("Hello message sent.\n"); 
	close(sockfd);
	}

	return ret;
}
