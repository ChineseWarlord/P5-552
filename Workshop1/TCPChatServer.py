import csv
import pickle
import threading
from socket import *
from multiprocessing import Process

HOST = ''           # Symbolic name meaning all available interfaces
LOAD_USER_PORT = 1000
BASE_PORT = 1234    # Arbitrary non-privileged port
CONN_COUNTER1 = 0    # Counter for connections
CONN_COUNTER2 = 0    # Counter for connections
CONN_COUNTER3 = 0    # Counter for connections
CONN_COUNTER4 = 0    # Counter for connections
CONN_COUNTER5 = 0    # Counter for connections

BUFFER_SIZE = 1024  # Receive Buffer size (power of 2)
MAX_USERS = 2

USERNAMES_LIST1 = []
USERNAMES_LIST2 = []
USERNAMES_LIST3 = []
USERNAMES_LIST4 = []
USERNAMES_LIST5 = []

ID_LIST1 = []
ID_LIST2 = []
ID_LIST3 = []
ID_LIST4 = []
ID_LIST5 = []

PORT_IDS1= []
PORT_IDS2 = []
PORT_IDS3 = []
PORT_IDS4 = []
PORT_IDS5 = []

PORT_HANDLES1 = []
PORT_HANDLES2 = []
PORT_HANDLES3 = []
PORT_HANDLES4 = []
PORT_HANDLES5 = []


PP = 65432  # Port to listen on (non-privileged ports are > 1023)

LoginName = ""

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
                        csv_writer = csv.writer(f)
                        csv_writer.writerow([user_name])
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
            #self.conn.close()    
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
            next(csv_reader)
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
               
    
class LoadUsersThread(threading.Thread):
    def __init__(self):
        threading.Thread.__init__(self)
        print("Loading users...\n")
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
        self.address = clientAddress
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
            print('    from {}'.format(self.address))
            print('    handled in {}'.format(threading.get_ident()))
            print('    username: {}'.format(data_list[1]))
            onlineusers=len(self.userids)
            NEW_PORT=BASE_PORT+self.counter
            print(NEW_PORT)
            self.portids.append(NEW_PORT)
            dedicatedserver = socket(AF_INET, SOCK_STREAM)
            dedicatedserver.setsockopt(SOL_SOCKET, SO_REUSEADDR, 1)
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
                #print("recv_data: {}".format(recv_data))
                
                if recv_data[1] == "EEXIT":
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
            print('    from {}'.format(self.address))
            print('    handled in {}'.format(threading.get_ident()))
            print('    username: {}'.format(data_list[1]))



if __name__=="__main__":
    print("Chat Server started.")
    print("Waiting for chat client connections...")
     
    testcount = 0
    newport = BASE_PORT+testcount
    server1 = socket(AF_INET, SOCK_STREAM)
    server1.setsockopt(SOL_SOCKET, SO_REUSEADDR, 1)
    server1.bind((HOST, newport))
    print("newport: {}".format(newport))

    testcount += 1
    newport = BASE_PORT+testcount
    server2 = socket(AF_INET, SOCK_STREAM)
    server2.setsockopt(SOL_SOCKET, SO_REUSEADDR, 1)
    server2.bind((HOST, newport))
    print("newport: {}".format(newport))

    testcount += 1
    newport = BASE_PORT+testcount
    server3 = socket(AF_INET, SOCK_STREAM)
    server3.setsockopt(SOL_SOCKET, SO_REUSEADDR, 1)
    server3.bind((HOST, newport))
    print("newport: {}".format(newport))

    testcount += 1
    newport = BASE_PORT+testcount
    server4 = socket(AF_INET, SOCK_STREAM)
    server4.setsockopt(SOL_SOCKET, SO_REUSEADDR, 1)
    server4.bind((HOST, newport))
    print("newport: {}".format(newport))

    testcount += 1
    newport = BASE_PORT+testcount
    server5 = socket(AF_INET, SOCK_STREAM)
    server5.setsockopt(SOL_SOCKET, SO_REUSEADDR, 1)
    server5.bind((HOST, newport))
    print("newport: {}".format(newport))

    while True:
        process1 = Process(target=VerifyThread)
        process1.start()
        
        process2 = Process(target=LoadUsersThread)
        process2.start()
        #ThreadVerify = VerifyThread()
        #ThreadVerify.start()
        
        server1.listen(1)
        server2.listen(1)
        server3.listen(1)
        server4.listen(1)
        server5.listen(1)
        
        clientsock1, clientAddress1 = server1.accept()
        clientsock2, clientAddress2 = server2.accept()
        clientsock3, clientAddress3 = server3.accept()
        clientsock4, clientAddress4 = server4.accept()
        clientsock5, clientAddress5 = server5.accept()
        
        CONN_COUNTER1=CONN_COUNTER1+1
        CONN_COUNTER2=CONN_COUNTER2+1
        CONN_COUNTER3=CONN_COUNTER3+1
        CONN_COUNTER4=CONN_COUNTER4+1
        CONN_COUNTER5=CONN_COUNTER5+1
        
        ClientThread1 = ClientThread(clientAddress1, clientsock1, CONN_COUNTER1, USERNAMES_LIST1, ID_LIST1, 
                                     PORT_IDS1, PORT_HANDLES1)
        ClientThread2 = ClientThread(clientAddress2, clientsock2, CONN_COUNTER2, USERNAMES_LIST2, ID_LIST2, 
                                     PORT_IDS2, PORT_HANDLES2)
        ClientThread3 = ClientThread(clientAddress3, clientsock3, CONN_COUNTER3, USERNAMES_LIST3, ID_LIST3, 
                                     PORT_IDS3, PORT_HANDLES3)
        ClientThread4 = ClientThread(clientAddress4, clientsock4, CONN_COUNTER4, USERNAMES_LIST4, ID_LIST4, 
                                     PORT_IDS4, PORT_HANDLES4)
        ClientThread5 = ClientThread(clientAddress5, clientsock5, CONN_COUNTER5, USERNAMES_LIST5, ID_LIST5, 
                                     PORT_IDS5, PORT_HANDLES5)
    
        ClientThread1.start()
        ClientThread2.start()
        ClientThread3.start()
        ClientThread4.start()
        ClientThread5.start()
       

    
    
