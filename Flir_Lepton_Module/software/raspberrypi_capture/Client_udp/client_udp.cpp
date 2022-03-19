#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <opencv2/opencv.hpp>

int main(void){
    int socket_desc;
    struct sockaddr_in server_addr;
    //char server_message[2000], client_message[2000];
    int server_message[100];
    int server_struct_length = sizeof(server_addr);
    int client_image[80][80];
    
    // Clean buffers:
    memset(server_message, '\0', sizeof(server_message));
    //memset(client_message, '\0', sizeof(client_message));
    
    // Create socket:
    socket_desc = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    
    if(socket_desc < 0){
        printf("Error while creating socket\n");
        return -1;
    }
    printf("Socket created successfully\n");
    
    // Set port and IP:
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = inet_addr("10.213.122.138");
    
    // Get input from the user:
    //printf("Enter message: ");
    //gets(client_message);
    char client_message[]="orospu";
    
    // Send the message to server:
    if(sendto(socket_desc, client_message, strlen(client_message), 0,
         (struct sockaddr*)&server_addr, server_struct_length) < 0){
        printf("Unable to send message\n");
        return -1;
    }
    
    // Receive the server's response:
    if(recvfrom(socket_desc, server_message, sizeof(server_message), 0,
         (struct sockaddr*)&server_addr, &server_struct_length) < 0){
        printf("Error while receiving server's msg\n");
        return -1;
    }
    
    printf("Server's response in char: %s\n", server_message);
    //printf("Server's response in integer: %d\n", atoi(server_message[1]));
    //printf("Server's response in integer: %d \n",(int)(server_message[3]-48));
    printf("Server's response in integer: %d \n",(server_message[0]));
    printf("Server's response in integer: %d \n",(server_message[1]));
    printf("Server's response in integer: %d \n",(server_message[2]));
    printf("Server's response in integer: %d \n",(server_message[3]));
    printf("Server's response in integer: %d \n",(server_message[4]));
    printf("Server's response in integer: %d \n",(server_message[5]));

    //Creating 2D Array
    for (int i=0;i<60;i++){
        for (int j=0;j<80;j++){
            client_image[i][j]=server_message[i*60+j];
            printf("%d \t",client_image[i][j]);
        }
    }
    
    
    //printf("Client_image array: %d \n",client_image);

    // Close the socket:
    close(socket_desc);
    
    return 0;
}
