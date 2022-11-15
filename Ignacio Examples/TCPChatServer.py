import socket, threading, pickle
import csv

HOST = '192.168.56.1'           # Symbolic name meaning all available interfaces
BASE_PORT = 1234    # Arbitrary non-privileged port
VERIFY_PORT = 1111  
CONN_COUNTER = 0    # Counter for connections
BUFFER_SIZE = 1024  # Receive Buffer size (power of 2)
MAX_USERS = 99
USERNAMES_LIST = []
ID_LIST = []
PORT_IDS = []
PORT_HANDLES = []

SERVER = socket.gethostbyname(socket.gethostname())
print(SERVER)

class VerifyThread(threading.Thread):
    def __init__(self):
        threading.Thread.__init__(self)
        PORT1 = 65432  # Port to listen on (non-privileged ports are > 1023)
        self.Data_User = []
        self.Data_Pass = []
        self.Usernames = []
        self.Passwords = []
        
        if input() == "exit":
            exit()
            
        while True:
            s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
            s.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
            print("Working?")
            s.bind((HOST, PORT1))
            s.listen()
            self.conn, addr = s.accept()
            
            with self.conn:
                print(f"Connected by {addr}")
                data = self.conn.recv(BUFFER_SIZE)
                self.data2 = pickle.loads(data)
                print("Data: {}".format(self.data2))
                self.Data_User = self.data2[0]
                self.Data_Pass = self.data2[1]
                self.Data_UserPass = self.data2[0]+self.data2[1]
                print("Data_User: {}".format(self.Data_User))  
                print("Data_Pass: {}".format(self.Data_Pass)) 
                print("Data_UserPass: {}".format(self.Data_UserPass)) 
                #text = "OK - Cancer"
                #self.data_string = pickle.dumps(text)
                #self.conn.send(self.data_string)
                self.Check_User()
                self.conn.close()
                #print("Socket status: {}".format(s))
            
    def Check_User(self):
            rows = [self.data2]
            test1 = []
            Data = self.Data_UserPass
            
            #testt = "hejfisk"
            #test2.append(testt)
            #print("test2 {}".format(test2))
            #if Data in test2:
            #    print("User: {}".format(Data))
            #    test2.clear()
            #    print("After test2 {}".format(test2))
                
            
            with open('Users.csv', 'r') as f:
                csv_reader = csv.reader(f, delimiter=',')
                #next(csv_reader)
                for line in csv_reader:
                    cunt = line[0]+line[1]
                    test1.append(cunt)
                    print("cunt: {}".format(cunt))
                    print("test1: {}".format(test1))
                    
                if Data in test1:
                        print("NOT OK!")
                        print("test1 not in data: {}".format(test1))
                    
                        text = "NOT OK!"
                        self.data_string = pickle.dumps(text)
                        self.conn.send(self.data_string)
                if Data not in test1:
                    test1.clear()
                    print("test1 in data: {}".format(test1))
                    with open('Users.csv', 'a', newline='') as f:
                        csv_writer = csv.writer(f)
                        csv_writer.writerows(rows)
                        print("OK!")
                
                        text = "YES OK!"
                        self.data_string = pickle.dumps(text)
                        self.conn.send(self.data_string) 


class ClientThread(threading.Thread):
    def __init__(self,clientAddress,clientsocket,cc,uu,ii,pi,hi):
        threading.Thread.__init__(self)
        self.csocket = clientsocket
        self.counter = cc
        self.usernames = uu
        self.userids = ii
        self.portids = pi
        self.porthandles = hi
    def run(self):
        r = self.csocket.recv(BUFFER_SIZE)
        data_list = pickle.loads(r)
        if len(self.usernames)<MAX_USERS:
            indid=self.counter
            self.userids.append(indid)
            uusername=data_list[1]
            self.usernames.append(uusername)
            print('*** Connection {} accepted. Status: active/maximum users: {}/{}'.format(self.counter,len(self.usernames),MAX_USERS))
            print('    from {}'.format(clientAddress))
            print('    handled in {}'.format(threading.get_ident()))
            print('    username: {}'.format(data_list[1]))
            onlineusers=len(self.userids)
            NEW_PORT=BASE_PORT+self.counter
            print(NEW_PORT)
            self.portids.append(NEW_PORT)
            dedicatedserver = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
            dedicatedserver.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
            dedicatedserver.bind((HOST, NEW_PORT))
            connect_ok_list=["OK",indid,onlineusers,NEW_PORT]
            data_string = pickle.dumps(connect_ok_list)
            self.csocket.send(data_string)
            self.csocket.close()
            print('    transferred to: {}'.format(NEW_PORT))
            dedicatedserver.listen(1)
            ds, userAddress = dedicatedserver.accept()
            self.porthandles.append(ds)
            while True:
                recv_string =ds.recv(BUFFER_SIZE)
                recv_data = pickle.loads(recv_string)
                if recv_data[0] == "EEXIT":
                    self.usernames.remove(uusername)
                    print(self.usernames)
                    self.portids.remove(NEW_PORT)
                    print(self.portids)
                    self.porthandles.remove(ds)
                    print(self.porthandles)
                    self.userids.remove(indid)
                    print(self.userids)
                    self.counter=self.counter-1
                    ds.close()
                    print('*** Connection closed. Status: active/maximum users: {}/{}'.format(len(self.usernames),MAX_USERS))
                    print('    username: {}'.format(data_list[1]))
                    break
                else:
                    for x in self.porthandles:
                        if x != ds:
                            x.send(recv_string)
                        else:
                            print("Message received from {}: {}".format(recv_data[0],recv_data[1]))
        else:
            connect_not_ok_list=["NOT OK"]
            data_string = pickle.dumps(connect_not_ok_list)
            self.csocket.send(data_string)
            self.csocket.close()
            print('*** Connection {} refused. Maximum numbers of users reached.'.format(self.counter))
            print('    from {}'.format(clientAddress))
            print('    handled in {}'.format(threading.get_ident()))
            print('    username: {}'.format(data_list[1]))

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
server.bind((HOST, BASE_PORT))
print("Chat Server started.")
print("Waiting for chat client connections...")
while True:
    threadd = VerifyThread()
    threadd.start()
    server.listen(1)
    clientsock, clientAddress = server.accept()
    CONN_COUNTER=CONN_COUNTER+1
    newthread = ClientThread(clientAddress, clientsock, CONN_COUNTER, USERNAMES_LIST, ID_LIST, PORT_IDS, PORT_HANDLES)
    newthread.start()
    
    send_data = input()
    if send_data == "EEXIT" or send_data == "eexit":
        break
    
