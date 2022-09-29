import socket

HOST = '127.0.0.1'
PORT = 5000

server_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
server_socket.bind((HOST,PORT))


message, address = server_socket.recvfrom(1024)
server_socket.sendto(message, address)
