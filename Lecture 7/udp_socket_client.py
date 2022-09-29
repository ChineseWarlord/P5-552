import socket

HOST = '127.0.0.1'
PORT = 5000

client_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
client_socket.settimeout(1.0)
message = b'test'
addr = (HOST, PORT)

client_socket.sendto(message, addr)
try:
    data, server = client_socket.recvfrom(1024)
    print("Received {} from {}".format(data,server))
except socket.timeout:
    print('Request timeout')