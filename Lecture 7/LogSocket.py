import socket

class LogSocket:
    def __init__(self, socket):
        self.socket = socket
    def send(self, data):
        print("Sending {} to {}".format(
        data, self.socket.getpeername()[0]))
        self.socket.send(data)
    def close(self):
        self.socket.close()

if __name__=="__main__":

    HOST = '127.0.0.1'
    PORT = 5000                 # An integer from 1 to 65535
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:    # AF_INET is the Internet address family for IPv4
        s.bind((HOST, PORT))
        s.listen()                                         
        conn, addr = s.accept()
        client = LogSocket(conn)
        with conn:
            while True:
                data = client.socket.recv(1024)                  # 1024 is the maximum amount of bytes to be received at once
                if not data:
                    break
                client.send(data)
    # No s.close is needed