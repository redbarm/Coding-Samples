# Python code to read image
import cv2
import socket
import time
import numpy as np


msgFromClient       = "Hello UDP Server"
bytesToSend         = str.encode(msgFromClient)
serverAddressPort   = ("10.213.122.137", 8080)
bufferSize          = 25600

array1=np.zeros(6400,dtype=np.uint8)
img = np.zeros((80,80),dtype=np.uint8)
cv2.imshow("Thermal", img)

rpt=1000

for ply in range (1,rpt):
    # Create a UDP socket at client side
    UDPClientSocket = socket.socket(family=socket.AF_INET, type=socket.SOCK_DGRAM)
    # Send to server using created UDP socket
    UDPClientSocket.sendto(bytesToSend, serverAddressPort)
    msgFromServer = UDPClientSocket.recvfrom(bufferSize)
    msg = "Message from Server {}".format(msgFromServer[0])
    
    array1=np.zeros(6400,dtype=np.uint8)
    img = np.zeros((80,80),dtype=np.uint8)
    
    if ((msgFromServer[0][0]>=0)|(msgFromServer[0][0]<=255)):
        i=0
        for j in range(0,25600,4):
            array1[i]=msgFromServer[0][j]
            i=i+1
    #print (array1)

    for row in range(0,80):
        for clm in range(0,80):
            img[row,clm]=array1[row*80+clm]
    print(ply)
    time.sleep(0.5)

    cv2.imshow("Thermal", img)
    cv2.waitKey(100)
#cv2.destroyAllWindows()

cv2.waitKey(0)

#cv2.destroyAllWindows()
