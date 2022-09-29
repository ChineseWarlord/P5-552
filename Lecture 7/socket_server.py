import socket
HOST = '127.0.0.1'
PORT = 5000                 # An integer from 1 to 65535
with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:    # AF_INET is the Internet address family for IPv4
    s.bind((HOST, PORT))
    s.listen()
    print("Server is waiting for a client ...")                                                  
    conn, addr = s.accept()
    with conn:
        print('Connected by', addr)
        while True:
            data = conn.recv(1024)                  # 1024 is the maximum amount of bytes to be received at once
            print("Server is receving data ...")
            if not data:
                break
            conn.sendall(data)
# No s.close is needed