from socket import *
import threading
import time
import pickle

SERVER_IP = "127.0.0.1"
SERVER_PORT = 1234
BUFFER_SIZE = 1024

class SendData(threading.Thread):
    def __init__(self,tcp_socket, user):
        threading.Thread.__init__(self)
        self.ds=tcp_socket
        self.uu=user
        
    def run(self):
        print("Write text and press enter to send [EEXIT to leave chat]: ")
        while True:
            send_data = input()
            if send_data == "EEXIT":
                chat_data=[send_data]
                chat_string = pickle.dumps(chat_data)
                self.ds.send(chat_string)
                print("Connection closed.")
                break
            else:
                chat_data=[self.uu,send_data]
                chat_string = pickle.dumps(chat_data)
                self.ds.send(chat_string)
   
class ReceiveData(threading.Thread):
    def __init__(self,tcp_socket):
        threading.Thread.__init__(self)
        self.ds=tcp_socket
    def run(self):
        while True:
            recv_string =self.ds.recv(BUFFER_SIZE)
            recv_data = pickle.loads(recv_string)
            print("{}: {}".format(recv_data[0],recv_data[1]))

USERNAME = input("Welcome to the chat. Enter your username: ")
print("Welcome {}. Initializing connection to the server.".format(USERNAME))
s = socket(AF_INET,SOCK_STREAM)
s.connect((SERVER_IP, SERVER_PORT))
connect_list=["CONNECT",USERNAME]
data_string = pickle.dumps(connect_list)

s.send(data_string)
data = s.recv(BUFFER_SIZE)
data_list = pickle.loads(data)
print("{}".format(data_list[0]))

if data_list[0]=="OK":
    print('Reply from server: you are now connected.')
    print('You user ID is {}'.format(data_list[1]))
    print('There {} online users right now.'.format(data_list[2]))
    NEW_PORT=data_list[3]
    print(NEW_PORT)
    ds = socket(AF_INET,SOCK_STREAM)
    ds.connect((SERVER_IP, NEW_PORT))
    thread1 = SendData(ds,USERNAME)
    thread2 = ReceiveData(ds)
    thread1.start()
    thread2.start()
  
else:
    print("Reply from server: server is full. Retry later.")
    

