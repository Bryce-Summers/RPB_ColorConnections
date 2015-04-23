import serial
import pytz
import socket
import sys
import time

host = 'pbridge.adm.cs.cmu.edu'
port = 15440
# ser = serial.Serial('/dev/cu.usbserial-A403I0LM', 9600)
count = 0
while  (count < 1):
	# count = count + 1
	# line = ser.readline()
	# line_split = line.split(' ')
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_address = (host, port)
    sock.connect(server_address)
    print >>sys.stderr, 'connecting to %s port %s' % server_address
    # count = count + 1
    
    message = "1 0"
    print >>sys.stderr, 'sending "%s"' % message
    sock.sendall(message)
    time.sleep(1)
    print >>sys.stderr, 'closing socket'
    sock.close()

# ser = serial.Serial('/dev/cu.usbserial-A403I0LM', 9600)

# while True:

#   line = ser.readline()
#   line_split = line.split(' ')
#   print line_split[0], line_split[1] 