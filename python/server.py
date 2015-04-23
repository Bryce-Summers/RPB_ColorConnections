import socket

host = '' #fills in address of host machine
port = 15440 #TODO: fix this
backlog = 5
size = 1024
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind((host, port))
s.listen(backlog)
while 1:
    client, address = s.accept()
    data = client.recv(size)
    if data:
        #TODO: process data
        print(data)

client.close() 
