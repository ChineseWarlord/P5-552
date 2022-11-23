import csv
import pickle
import threading
from threading import Thread
from socket import *
from multiprocessing import Process

HOST = ''           # Symbolic name meaning all available interfaces
LOAD_USER_PORT = 1000
BASE_PORT = 1234    # Arbitrary non-privileged port
PP = 65432  # Port to listen on (non-privileged ports are > 1023)

BUFFER_SIZE = 1024  # Receive Buffer size (power of 2)
MAX_USERS = 3
CONN_COUNTER = 0    # Counter for connections
MAX_USERS = 200
USERNAMES_LIST = []
ID_LIST = []
PORT_IDS = []
PORT_HANDLES = []

global count
global port
global listofports
global allUsers
global LoginName
global UserSockets
count = 0
port = 2000
listofports = []
allUsers = []
LoginName = ""
UserSockets = []


class VerifyThread(threading.Thread):
    def __init__(self):
        threading.Thread.__init__(self)
        self.Data_User = []
        self.Data_Pass = []
        self.Usernames = []
        self.Passwords = []
        
        while True:
            self.s = socket(AF_INET, SOCK_STREAM)
            self.s.setsockopt(SOL_SOCKET, SO_REUSEADDR, 1)
            self.s.bind((HOST, PP))
            self.s.listen()
            self.conn, addr = self.s.accept()
            #with self.conn:
            print(f"Connected by {addr}")
            data = self.conn.recv(BUFFER_SIZE)
            self.data2 = pickle.loads(data)
            print("Data: {}".format(self.data2))
            self.Data_User = self.data2[0]
            self.Data_Pass = self.data2[1]
            self.Data_Check = self.data2[2]
            self.Data_UserPass = self.data2[0]+self.data2[1]
            print("Data_User: {}".format(self.Data_User))  
            print("Data_Pass: {}".format(self.Data_Pass))
            print("Data_Check: {}".format(self.Data_Check)) 
            print("Data_UserPass: {}".format(self.Data_UserPass)) 
            #text = "OK - Cancer"
            #self.data_string = pickle.dumps(text)
            #self.conn.send(self.data_string)
            self.data2.pop(2)
            print("DELETED test: ", self.data2)
            if self.Data_Check == "userregister":
                    self.Check_User_Register()
                    self.conn.close()
            if self.Data_Check == "userlogin":
                    self.Check_User_Login()
                    self.conn.close()
            if self.Data_Check == "UserAdd":
                    self.Add_User()
                    self.conn.close()

    def Add_User(self):
        # Checks Users CSV for logged users
        # If trying to add user exits add user to current users friendlist
        # send OK to client
        user_name = self.Data_User
        global LoginName
        
        test1 = []
        test2 = []
        print("User added: ", user_name)
        with open('Users.csv', 'r') as f:
            csv_reader = csv.reader(f, delimiter=',')
            next(csv_reader)
            for line in csv_reader:
                cunt = line[0]
                #print("line[0] = {} \nline[1] = {}".format(line[0],line[1]))
                #print("user_name: {}\nline[0]: {}".format(user_name,line[0]))
                test1.append(cunt)
                #print("test1: {}".format(test1))
                
                #print("LoginName USERADD: {}".format(LoginName))
                if LoginName in test1:
                    test1.remove(LoginName)
                    #print("REMOVED SAME USER!")
                    
            #print("test1: {}".format(test1))
            print("\nLoginName: {}".format(LoginName))
            print("user_name: {}\n".format(user_name))
            if LoginName == user_name:
                print("TRIED TO ADD YOURSELF!")
                self.data_string = pickle.dumps("TRIED TO ADD YOURSELF!#")
                self.conn.send(self.data_string)
            if user_name not in test1:
                print("User does not exist!")
                self.data_string = pickle.dumps("USER DOES NOT EXIST!#")
                self.conn.send(self.data_string)
                
            if user_name in test1:
                #print("test1: {}".format(test1))
                #print("user_name!: {}".format(user_name))
                with open('UserData/{}.csv'.format(LoginName), 'r') as f:
                    csv_reader = csv.reader(f, delimiter=',')
                    for line2 in csv_reader:
                        cunt2 = line2[0]
                        test2.append(cunt2)
                        #print("test2: {}".format(test2))
                if user_name not in test2: 
                    with open('UserData/{}.csv'.format(LoginName), 'a', newline='') as f:
                        print("Adding to friendlist!")
                        self.data_string = pickle.dumps("YES ADDED!#{}".format(user_name))
                        self.conn.send(self.data_string)
                        
                        global port
                        print("username {} : port {}".format(user_name, port))
                        csv_writer = csv.writer(f)
                        csv_writer.writerow([user_name,port])
                        port += 1000
                if user_name in test2:
                    print("ALREADY IN FRIENDLIST!")
                    self.data_string = pickle.dumps("ALREADY IN FRIENDLIST!#")
                    self.conn.send(self.data_string)

    def Check_User_Login(self):
        test1 = []
        user_data = self.Data_UserPass
        global LoginName
        LoginName = self.Data_User
        print("LoginName: {}".format(LoginName))
            
        with open('Users.csv', 'r') as f:
            csv_reader = csv.reader(f, delimiter=',')
            next(csv_reader)
            for line in csv_reader:
                cunt = line[0]+line[1]
                test1.append(cunt)
                #print("test1: {}".format(test1))
        if user_data in test1:
            print("OK LOGIN!")
            self.data_string = pickle.dumps("YES LOGIN!#{}#{}".format(self.Data_User,self.Data_Pass))
            self.conn.send(self.data_string)
            self.conn.close()    
        if user_data not in test1:
            print("NO LOGIN!")
            test1.clear()
            self.data_string = pickle.dumps("NO LOGIN!")
            self.conn.send(self.data_string)
            #self.conn.close()
    
    def Check_User_Register(self):
        rows = [self.data2]
        #print("rows: {}".format(rows))
        test1 = []
        #print("test1: {}".format(test1))
        user_data = self.Data_UserPass
        #print("user_data: {}".format(user_data))
            
        with open('Users.csv', 'r') as f:
            csv_reader = csv.reader(f, delimiter=',')
            for line in csv_reader:
                #print("line: {}".format(line))
                cunt = line[0]+line[1]
                #print("cunt: {}".format(cunt))
                test1.append(cunt)
                #print("test1: {}".format(test1))
                
            #print("user_data before if in test1: {}".format(user_data))
            #print("test1 if in: {}".format(test1))
            if user_data in test1:
                print("NOT OK!")
                #print("test1 not in data: {}".format(test1))
                self.data_string = pickle.dumps("NOT OK!")
                self.conn.send(self.data_string)
                #self.conn.close()
            #print("user_data before not in test1: {}".format(user_data))
            #print("test1 if not in: {}".format(test1))
            if user_data not in test1:
                #print("test1 in data: {}".format(test1))
                print("OK!")
                test1.clear()
                self.data_string = pickle.dumps("YES OK!")
                self.conn.send(self.data_string) 
                #self.conn.close()
                with open('Users.csv', 'a', newline='') as f:
                    csv_writer = csv.writer(f)
                    csv_writer.writerows(rows)
                with open('UserData/{}.csv'.format(self.Data_User), 'w', newline='') as f:
                    print("User: {} created!".format(self.Data_User))
                    global allUsers
                    allUsers.append(self.Data_User)
                    print("allUser: {}".format(allUsers))
               
    
class LoadUsersThread(threading.Thread):
    def __init__(self):
        threading.Thread.__init__(self)
        #print("Loading users...\n")
        while True:
            self.socketLoad = socket(AF_INET, SOCK_STREAM)
            self.socketLoad.setsockopt(SOL_SOCKET, SO_REUSEADDR, 1)
            self.socketLoad.bind((HOST, LOAD_USER_PORT))
            self.socketLoad.listen()
            self.conn, addr = self.socketLoad.accept()
            #with self.conn:
            print(f"LOAD USERS : Connected by {addr}")
            # ([stupidusername,"Load_User"])
            data = self.conn.recv(BUFFER_SIZE)
            self.data2 = pickle.loads(data)
            print("Data: {}".format(self.data2))
            self.Data_User = self.data2[0]
            self.Data_Check = self.data2[1]
            print("Data_User: {}".format(self.Data_User)) 
            print("Data_Check: {}".format(self.Data_Check))
            
            self.LoadingUsers()
            
    def LoadingUsers(self):
        UserFriendList = []
        with open('UserData/{}.csv'.format(self.Data_User), 'r') as f:
            csv_reader = csv.reader(f, delimiter=',')
            for line3 in csv_reader:
                cunt3 = line3[0]
                UserFriendList.append(cunt3)
                print("UserFriendList: {}".format(UserFriendList))
            LoadUsersData = pickle.dumps(UserFriendList)
            self.conn.send(LoadUsersData)


class ClientThread(threading.Thread):
    def __init__(self,clientAddress,clientsocket,cc,uu,ii,pi,hi):
        threading.Thread.__init__(self)
        self.csocket = clientsocket
        self.counter = cc
        self.usernames = uu
        self.userids = ii
        self.portids = pi
        self.porthandles = hi
        print("\n\n=======================")
        print("self.csocket: {}".format(self.csocket))
        print("self.counter: {}".format(self.counter))
        print("self.usernames: {}".format(self.usernames))
        print("self.userids: {}".format(self.userids))
        print("self.portids: {}".format(self.portids))
        print("self.porthandles: {}".format(self.porthandles))
        print("=======================")
    def run(self):
        r = self.csocket.recv(BUFFER_SIZE)
        print("WHat is r: {}".format(r))
        data_list = pickle.loads(r)
        if len(self.usernames)<MAX_USERS:
            indid=self.counter
            self.userids.append(indid)
            print("self.userids.append(indid): {}".format(self.userids))
            uusername=data_list[1]
            self.usernames.append(uusername)
            print("self.username list: {}".format(self.usernames))
            print("========================================================================")
            print('*** Connection {} accepted. Status: active/maximum users: {}/{}'.format(self.counter,len(self.usernames),MAX_USERS))
            print('    from {}'.format(clientAddress))
            print('    handled in {}'.format(threading.get_ident()))
            print('    username: {}'.format(data_list[1]))
            print("========================================================================")
            onlineusers=len(self.userids)
            NEW_PORT=BASE_PORT+self.counter
            print("this is NEW_PORT: {}".format(NEW_PORT))
            self.portids.append(NEW_PORT)
            dedicatedserver = socket(AF_INET, SOCK_STREAM)
            dedicatedserver.setsockopt(SOL_SOCKET, SO_REUSEADDR, 1)
            dedicatedserver.bind((HOST, NEW_PORT))
            connect_ok_list=["OK",indid,onlineusers,NEW_PORT]
            print("what is connect_ok_list: {}" .format(connect_ok_list))
            data_string = pickle.dumps(connect_ok_list)
            self.csocket.send(data_string)
            print("WHat am i sending? {}".format(data_string))
            self.csocket.close()
            print('    transferred to: {}'.format(NEW_PORT))
            dedicatedserver.listen(1)
            ds, userAddress = dedicatedserver.accept()
            self.porthandles.append(ds)
            test_string = ""
            while True:
                recv_string =ds.recv(BUFFER_SIZE)
                recv_data = pickle.loads(recv_string)
                # msg structure: [userlogin, msg, toUser]
                print("What is recv_data: {}".format(recv_data))
                #test_string = recv_data[1]
                #print("What is test_string: {}".format(test_string))
                X = ''.join(recv_data[1])
                print("What is X: {}".format(X))
                # Data structure: [username, msg, SendToUser]
                if X == 'cunt':
                    print("DIN STORE CUNT!") 
                    
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
                            print("what is x? {}".format(x))
                            
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

server = socket(AF_INET, SOCK_STREAM)
server.setsockopt(SOL_SOCKET, SO_REUSEADDR, 1)
server.bind((HOST, BASE_PORT))

if __name__=="__main__":
    print("Chat Server started.")
    print("Waiting for chat client connections...")
    #print("Chat Server started.")
    #print("Waiting for chat client connections...")
    
    process1 = Process(target=VerifyThread)
    process1.start()
    process2 = Process(target=LoadUsersThread)
    process2.start()
    
    while True:
        server.listen(1)
        clientsock, clientAddress = server.accept()
        CONN_COUNTER=CONN_COUNTER+1
        newthread = ClientThread(clientAddress, clientsock, CONN_COUNTER, USERNAMES_LIST, ID_LIST, PORT_IDS, PORT_HANDLES)
        print("\n\n=======================================")
        print("This is client socket: {}\nThis is client address: {}".format(clientsock,clientAddress))
        print("This is USERNAME_LIST: {}".format(USERNAMES_LIST))
        print("This is ID_LIST: {}".format(ID_LIST))
        print("This is PORT_IDS: {}".format(PORT_IDS))
        print("This is PORT_HANDLES: {}".format(PORT_HANDLES))
        print("=======================================\n\n")
        newthread.start()

    """
    count = 0
    
    testQ = []
    #while True:
    with open('Users.csv', 'r') as f:
            csv_reader = csv.reader(f, delimiter=',')
            next(csv_reader)
            for line in csv_reader:
                    cunt = line[0]+line[1]
                    testQ.append(cunt)
                    print("testQ: {}".format(len(testQ)))
            testQ.clear()
    while True:
        ThreadServer1 = Thread(target=server1)
        ThreadServer1.start()
        ThreadServer2 = Thread(target=server2)
        ThreadServer2.start()        
    
    """
    #for i in range(len(testQ)):
            #ThreadServers1 = Thread(target=createServers)
            #ThreadServers1.start()
        #ThreadServer1 = Thread(target=server1)
        #ThreadServer1.start()
        #ThreadServer2 = Thread(target=server2)
        #ThreadServer2.start()
        #print()
        
         
    #while True:
        #process1 = Process(target=VerifyThread)
        #process1.start()
        
        #process2 = Process(target=LoadUsersThread)
        #process2.start()
        #ThreadVerify = VerifyThread()
        #ThreadVerify.start()
        
        #ThreadServer1 = Thread(target=server1)
        #ThreadServer1.start()
        #ThreadServer2 = Thread(target=server2)
        #ThreadServer2.start()
        
        #server1()
        #server2()
        #server3(server3sock)
        #server4(server4sock)
        #server5(server5sock)
        
        
        
        #ThreadServer1 = Thread(target=server1,args=[server1sock])
        #ThreadServer1.start()
        
        #ThreadServer2 = Thread(target=server2,args=[server2sock])
        #ThreadServer2.start()
        
        #ThreadServer3 = Thread(target=server3,args=[server3sock])
        #ThreadServer3.start()
        
        #ThreadServer4 = Thread(target=server4,args=[server4sock])
        #ThreadServer4.start()
        
        #ThreadServer5 = Thread(target=server5,args=[server5sock])
        #ThreadServer5.start()
        
        
        
"""
testcount = 0
newport = BASE_PORT+testcount
server1sock = socket(AF_INET, SOCK_STREAM)
server1sock.setsockopt(SOL_SOCKET, SO_REUSEADDR, 1)
server1sock.bind((HOST, newport))
print("newport 1: {}".format(newport))

testcount += 1
newport = BASE_PORT+testcount
server2sock = socket(AF_INET, SOCK_STREAM)
server2sock.setsockopt(SOL_SOCKET, SO_REUSEADDR, 1)
server2sock.bind((HOST, newport))
print("newport 2: {}".format(newport))

testcount += 1
newport = BASE_PORT+testcount
server3sock = socket(AF_INET, SOCK_STREAM)
server3sock.setsockopt(SOL_SOCKET, SO_REUSEADDR, 1)
server3sock.bind((HOST, newport))
print("newport 3: {}".format(newport))

testcount += 1
newport = BASE_PORT+testcount
server4sock = socket(AF_INET, SOCK_STREAM)
server4sock.setsockopt(SOL_SOCKET, SO_REUSEADDR, 1)
server4sock.bind((HOST, newport))
print("newport 4: {}".format(newport))

testcount += 1
newport = BASE_PORT+testcount
server5sock = socket(AF_INET, SOCK_STREAM)
server5sock.setsockopt(SOL_SOCKET, SO_REUSEADDR, 1)
server5sock.bind((HOST, newport))
print("newport 5: {}".format(newport))
"""