import socket
import struct
from PIL import Image
import numpy as np

msgFromClient = "Hello UDP Server"
bytesToSend = str.encode(msgFromClient)
serverAddressPort = ("10.213.122.141", 14445)
bufferSize = 4800


# Create a UDP socket at client side

UDPClientSocket = socket.socket(family=socket.AF_INET, type=socket.SOCK_DGRAM)

# Send to server using created UDP socket
UDPClientSocket.sendto(bytesToSend, serverAddressPort)
msgFromServer = UDPClientSocket.recvfrom(bufferSize)
msg = "Message from Server {}".format(msgFromServer[0])
#msg_int=int.from_bytes(msg,"big")
#msg_int = struct.unpack('>H', msg(5))
#print("sonuc: %s" % (msgFromServer[0][0:10]))
print(msgFromServer)
print(len(msgFromServer[0]))


#w, h = 60, 80
w, h = 60, 60
data = np.zeros((h, w, 3), dtype=np.uint8)
#data = np.zeros((h, w), dtype=np.byte)

i, j= 0, 0
while j<h:
    while i<w:
        data[i][j]= [msgFromServer[0][j*w+i]*5, 0, 0]
        #data[i][j]= msgFromServer[0][j*w+i]
        i=i+1
    j=j+1
    i=0
print (data)
#data[0, 0:80] = [msgFromServer[0][0], 0, 0]
#data[1, 61:121] = [ord(msgFromServer[0][61:121]), 0, 0]
#data[0:60, 2] = [msgFromServer[0][121:180], 0, 0]

img = Image.fromarray(data, 'RGB')
#img.save('my.png')
img.show()
