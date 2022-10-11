import socket

HOST = '127.0.0.1'
PORT = 50000
with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.connect((HOST,PORT))
    while True:
        message = input("Enter message to send\n")
        s.sendall(message.encode())
        data = s.recv(1024)
        print('Received', repr(data))
        if (data.decode() == 'Bye'):
            print("Closing connection")
            break
# No s.close is needed