import socket
import threading

class ClientThread(threading.Thread):
    def __init__(self, client_socket):
        threading.Thread.__init__(self)
        self.csocket = client_socket
    def run(self):
        with self.csocket:
            while True:
                data = self.csocket.recv(1024)          # data received from client
                self.csocket.sendall(data)          # send back echo string to client
                if (data.decode() == 'Bye'):
                    print("Closing connection")
                    break


if __name__=="__main__":
    host = 'localhost'
    port = 50000
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        s.bind((host, port))  
        s.listen()  
        while True:
            client_socket, client_address = s.accept()   # connect to a new client
            client_thread = ClientThread(client_socket)  # start a new thread
            client_thread.start()
