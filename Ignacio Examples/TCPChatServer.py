import socket, threading, pickle

HOST = ''           # Symbolic name meaning all available interfaces
BASE_PORT = 1234    # Arbitrary non-privileged port
CONN_COUNTER = 0    # Counter for connections
BUFFER_SIZE = 1024  # Receive Buffer size (power of 2)
MAX_USERS = 2
USERNAMES_LIST = []
ID_LIST = []
PORT_IDS = []
PORT_HANDLES = []

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
    server.listen(1)
    clientsock, clientAddress = server.accept()
    CONN_COUNTER=CONN_COUNTER+1
    newthread = ClientThread(clientAddress, clientsock, CONN_COUNTER, USERNAMES_LIST, ID_LIST, PORT_IDS, PORT_HANDLES)
    newthread.start()
    
