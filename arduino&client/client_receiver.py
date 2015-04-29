import serial
import socket
import sys
import time

host = 'pbridge.adm.cs.cmu.edu'
#host = '' #fills in address of host machine
port = 15440

#bailiang's computer
#ser = serial.Serial('/dev/cu.usbserial-A403I0LM', 9600)

#marisa's computer
#ser = serial.Serial('/dev/ttyUSB0', 9600)

while 1:
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_address = (host, port)
    sock.connect(server_address)
    print >>sys.stderr, 'connecting to %s port %s' % server_address
   
    #message = ser.readline()  
    message = raw_input("enter something:")

    m_arr = message.split(' ')
    sensor = m_arr[0]
    velocity = str(float(m_arr[1]) / 10) #divide by 10 to obtain m/s

    print >>sys.stderr, 'sending: %s' % message
    sock.send(sensor)
    sock.send(velocity)
    time.sleep(1)

    print >>sys.stderr, 'closing socket'
    sock.close()

