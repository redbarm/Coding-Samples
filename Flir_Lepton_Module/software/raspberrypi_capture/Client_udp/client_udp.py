# Python code to read image
import cv2
import socket
import numpy as np

 

msgFromClient       = "Hello UDP Server"
bytesToSend         = str.encode(msgFromClient)
serverAddressPort   = ("10.213.122.138", 8080)
bufferSize          = 25600

# Create a UDP socket at client side
UDPClientSocket = socket.socket(family=socket.AF_INET, type=socket.SOCK_DGRAM)

# Send to server using created UDP socket
UDPClientSocket.sendto(bytesToSend, serverAddressPort)
msgFromServer = UDPClientSocket.recvfrom(bufferSize)
msg = "Message from Server {}".format(msgFromServer[0])
img = np.zeros((80,80),dtype=np.uint8)
array1=np.zeros(6400,dtype=np.uint8)
#array2=np.zeros(6400,dtype=np.uint8)

i=0
for j in range(0,25600,4):
    array1[i]=msgFromServer[0][j]
    i=i+1
print (array1)


#array1=msgFromServer[0]
#i=0
#for j in range(0,6400,4):
#    array2[i]=array1[j]
#    i=i+1
#print (array2)

for row in range(0,80):
    for clm in range(0,80):
        img[row,clm]=array1[row*80+clm]
#print (img)


#print(msgFromServer[0][10])
#print("%d",msgFromServer)
#for row in range(0,48):
#    i=0
#    for clm in range(0,192,4):
#        img[row,i]=array1[row*192+clm]
#        #img[row,i]=125
#        #print (i)
#        i=i+1
#print(img)   


#print(array1[i], " ")


#print(array1)

#for i in range(1,50):
#    for j in range(1,50):
#        img[j,i]=msgFromServer[0][i*50+j]

#print("%d",msgFromServer)

# To read image from disk, we use
# cv2.imread function, in below method,

#img = cv2.imread("IMG_0006.pgm", cv2.IMREAD_COLOR)

# Creating GUI window to display an image on screen
# first Parameter is windows title (should be in string format)
# Second Parameter is image array

cv2.imshow("Thermal", img)

# To hold the window on screen, we use cv2.waitKey method
# Once it detected the close input, it will release the control
# To the next line
# First Parameter is for holding screen for specified milliseconds
# It should be positive integer. If 0 pass an parameter, then it will
# hold the screen until user close it.

cv2.waitKey(0)

# It is for removing/deleting created GUI window from screen
# and memory

cv2.destroyAllWindows()
