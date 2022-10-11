import socket
import time
import select
from threading import Thread

HOST = '192.168.31.66'
PORT = 5000                 # An integer from 1 to 65535

def recvmsg(conn):
     data = conn.recv(1024)    # 1024 is the maximum amount of bytes to be received at once
     print('Received: ', data.decode())
     return data.decode()

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:    # AF_INET is the Internet address family for IPv4
    s.bind((HOST, PORT))
    s.listen()
    print("Server is waiting for a client ...")
    conn, addr = s.accept()
    s.setblocking(False)
    
    with conn:
        print('Connected by', addr)
        
        #t1 = Thread(target=recvmsg(conn))
        #t1.start()
        while True:
            readmsg = select.select([conn], [], [], 10)
            if (readmsg):
                recvmsg(conn)
                print("Received msg \n")
            else:
                data2 = "Closing connection ..."
            
                if recvmsg == "Close connection":
                    conn.sendall(data2.encode())
                    s.close()
                    break
                else:
                    conn.sendall(input("Enter text: \n").encode())