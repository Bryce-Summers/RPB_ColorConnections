import serial
#import pytz
import socket
import sys
import time

#host = 'pbridge.adm.cs.cmu.edu'
host = '' #fills in address of host machine
port = 15440

#bailiang's computer
#ser = serial.Serial('/dev/cu.usbserial-A403I0LM', 9600)

#marisa's computer
ser = serial.Serial('/dev/ttyUSB0', 9600)

while 1:
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_address = (host, port)
    sock.connect(server_address)
    print >>sys.stderr, 'connecting to %s port %s' % server_address
   
    message = ser.readline()
  
    #message = raw_input("enter something:")
    message = line
    print >>sys.stderr, 'sending "%s"' % message
    sock.sendall(message)
    time.sleep(1)

    print >>sys.stderr, 'closing socket'
    sock.close()

