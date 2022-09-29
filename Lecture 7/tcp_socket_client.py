import socket

HOST = '127.0.0.1'
PORT = 5000

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.connect((HOST,PORT))
    while True:
        s.sendall(input("Enter text: \n").encode())
        data = s.recv(1024)
        print('Received:', repr(data.decode()))
        
        if data.decode() == "Closing connection ...":
            break
        