import csv
import pickle
import threading
from threading import Thread
from socket import *
from multiprocessing import Process
import os
import time

HOST = '127.0.0.1'           # Symbolic name meaning all available interfaces
LOAD_USER_PORT = 1000
BASE_PORT = 1234    # Arbitrary non-privileged port
PP = 2001  # Port to listen on (non-privileged ports are > 1023)
LOGS_PORT = 2005

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
global UserLog
global UserSockets
count = 0
port = 2000
listofports = []
allUsers = []
LoginName = ""
UserLog = ""
UserSockets = []

FUCKMITLIV = []


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
            
            
            print("Connected to verify thread!")
            print("socket: {}".format(self.conn))
            print(f"IP address: {addr}")
            data = self.conn.recv(BUFFER_SIZE)
            self.data2 = pickle.loads(data)
            print("Data: {}".format(self.data2))
            # Data structure: [GroupName,UserToAdd,LoginName,CHECKDATA]
            self.Data_User = self.data2[0]
            self.Data_Pass = self.data2[1]
            self.Data_Check = self.data2[2]
            self.Data_UserAddToGroup = self.data2[3]
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
                #self.conn.close()
            if self.Data_Check == "userlogin":
                self.Check_User_Login()
                #self.conn.close()
            if self.Data_Check == "UserAdd":
                global LoginName
                LoginName = self.Data_Pass
                self.Add_User()
                #self.conn.close()
            if self.Data_Check == "UserAddGroup":
                self.CreateGroup()
                #self.conn.close()
            if self.Data_Check == "UserAddToGroup":
                self.AddUserToGroup()
                
    def AddUserToGroup(self):
        Username = self.Data_User
        GroupName = self.Data_Pass
        UserToAdd = self.Data_UserAddToGroup 
        UsersInGroup = []
        global LoginName
        global FUCKMITLIV
        
        print("==============================================")
        print("==============================================")
        print("What is Username?:",Username)
        print("What is GroupName?:",GroupName)
        print("What is UserToAdd?:",UserToAdd)
        print(f"What is UsersInGroup?: {UsersInGroup}")
        print("==============================================")
        print("==============================================")
        
        with open(f"UserGroups/{Username}/{GroupName}.csv", 'r', newline='') as read_group:
            csv_readerX = csv.reader(read_group)
            for lineGroup in csv_readerX:
                print(f"lineGroup: {lineGroup}")
                #cunt = ''.join(lineGroup)
                #print(f"cunt: {cunt}")
                #testGroups.append(cunt)
                UsersInGroup.append(''.join(lineGroup))
        
        if UserToAdd in UsersInGroup:
            print("Han er allerede her!")
            self.conn.send(pickle.dumps("USER ALREADY IN GROUPCHAT#{}".format(Username)))
        if UserToAdd not in UsersInGroup:
            write_group = open(f"UserGroups/{Username}/{GroupName}.csv", 'a', newline='')
            csv_writerX = csv.writer(write_group)
            print("Det ser bar fint ud!")
            csv_writerX.writerow([UserToAdd])
            self.conn.send(pickle.dumps("USER ADDED IN GROUPCHAT#{}".format(Username)))
            write_group.close()
            
                
    def CreateGroup(self):
        GroupName = self.Data_Pass
        global LoginName
        
        os.makedirs("UserGroups",exist_ok=True) 
        os.makedirs("UserGroups/{}".format(LoginName),exist_ok=True)
        
        GroupExist = os.path.exists("UserGroups/{}/{}.csv".format(LoginName,GroupName))
        if GroupExist == False:
            #open("UserGroups/{}/{}.csv".format(LoginName,GroupName),"a", newline='')
            with open("UserGroups/{}/{}.csv".format(LoginName,GroupName),"a", newline='') as f:
                csv_writer = csv.writer(f)
                csv_writer.writerow(["USERS:"])       
            print("GROUP CREATED!")
            open('UserLogs/{}/{}.txt'.format(LoginName,GroupName), 'a', newline='')
            self.conn.send(pickle.dumps("GROUP CREATED#{}".format(LoginName)))
        else:
            self.conn.send(pickle.dumps("GROUP ALREADY EXISTS#{}".format(LoginName)))
         
    def Add_User(self):
        # Checks Users CSV for logged users
        # If trying to add user exits add user to current users friendlist
        # send OK to client
        user_name = self.Data_User
        global LoginName
        
        test1 = []
        test2 = []
        print("User added: ", user_name)
        with open('UserData/Users.csv', 'r') as f:
            csv_reader = csv.reader(f, delimiter=',')
            #next(csv_reader)
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
                with open('UserFriends/{}.csv'.format(LoginName), 'r') as f:
                    csv_reader = csv.reader(f, delimiter=',')
                    for line2 in csv_reader:
                        cunt2 = line2[0]
                        test2.append(cunt2)
                        #print("test2: {}".format(test2))
                if user_name not in test2: 
                    with open('UserFriends/{}.csv'.format(LoginName), 'a', newline='') as f:
                        print("Adding to friendlist!")
                        self.data_string = pickle.dumps("YES ADDED!#{}".format(user_name))
                        self.conn.send(self.data_string)
                        print("username {} : port {}".format(user_name, port))
                        csv_writer = csv.writer(f)
                        csv_writer.writerow([user_name])
                        createUserLog = open('UserLogs/{}/{}.txt'.format(LoginName,user_name), 'a')
                        createUserLog.close()
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
        
        os.makedirs("UserData",exist_ok=True)   
        createusers = open('UserData/Users.csv', 'a')
        createusers.close()
        with open('UserData/Users.csv', 'r') as f:
            csv_reader = csv.reader(f, delimiter=',')
            #next(csv_reader)
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
    
    
    def Check_User_Register(self):
        rows = [self.data2]
        #print("rows: {}".format(rows))
        test1 = []
        #print("test1: {}".format(test1))
        user_data = self.Data_UserPass
        #print("user_data: {}".format(user_data))
        os.makedirs("UserData",exist_ok=True) 
        os.makedirs("UserLogs/{}".format(self.Data_User),exist_ok=True)
        open("UserData/Users.csv", "a")
        with open('UserData/Users.csv', 'r') as f:
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
                
                with open('UserData/Users.csv', 'a', newline='') as f:
                    csv_writer = csv.writer(f)
                    csv_writer.writerows(rows)
                os.makedirs("UserFriends",exist_ok=True)
                with open('UserFriends/{}.csv'.format(self.Data_User), 'w', newline='') as f:
                    print("User: {} created!".format(self.Data_User))
                    global allUsers
                    allUsers.append(self.Data_User)
                    print("allUser: {}".format(allUsers))
               
    
class LoadDataThread(threading.Thread):
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
            # Data structure: [GroupName,UserToAdd,LoginName,CHECKDATA]
            data = self.conn.recv(BUFFER_SIZE)
            self.data2 = pickle.loads(data)
            print("Data: {}".format(self.data2))
            self.Data_GroupName = self.data2[0]
            self.Data_UserToAdd = self.data2[1]
            self.Data_LoginName = self.data2[2]
            self.Data_Check = self.data2[3]
            print("Data_GroupName: {}".format(self.Data_GroupName)) 
            print("Data_UserToAdd: {}".format(self.Data_UserToAdd)) 
            print("Data_LoginName: {}".format(self.Data_LoginName)) 
            print("Data_Check: {}".format(self.Data_Check))
            
            if self.Data_Check == "Load_Users":
                self.LoadingUsers()
            if self.Data_Check == "Load_Groups":
                self.LoadingGroups()
            if self.Data_Check == "Load_Group_Users":
                self.LoadingGroupUsers()
                
    def LoadingUsers(self):
        UserFriendList = []
        with open('UserFriends/{}.csv'.format(self.Data_LoginName), 'r') as f:
            csv_reader = csv.reader(f, delimiter=',')
            for line3 in csv_reader:
                cunt3 = line3[0]
                UserFriendList.append(cunt3)
                print("UserFriendList: {}".format(UserFriendList))
            LoadUsersData = pickle.dumps(UserFriendList)
            self.conn.send(LoadUsersData)
            
    def LoadingGroups(self):
        Username = self.Data_LoginName
        GroupName = self.Data_GroupName
        UserGroupList = []
        
        print("Username:",Username)
        print("GroupName:",GroupName)
        
        dir_path = "UserGroups/{}".format(Username)
        
        GroupExist = os.path.exists("UserGroups/{}".format(Username))
        if GroupExist == True:
            # Iterate directory
            for path in os.listdir(dir_path):
                # check if current path is a file
                if os.path.isfile(os.path.join(dir_path, path)):
                    UserGroupList.append(path)
                    UserGroupList = [x.split('.')[0] for x in UserGroupList]
            print(UserGroupList)

            test = [x.split('.')[0] for x in UserGroupList]
            print("what is test?:", test)
            LoadUserGroupData = pickle.dumps(UserGroupList)
            self.conn.send(LoadUserGroupData)
        else:
            print("Create group first")
            self.conn.send(pickle.dumps("No group found"))
        
    def LoadingGroupUsers(self):
        Username = self.Data_LoginName
        GroupName = self.Data_GroupName
        UsersInGroup = []
        with open("UserGroups/{}/{}.csv".format(Username,GroupName), 'r', newline='') as f:
            csv_reader = csv.reader(f, delimiter=',')
            for lineGroup in csv_reader:
                cunt = ''.join(lineGroup)  
                UsersInGroup.append(cunt)
        UsersInGroup.remove("USERS:")
        print("UsersInGroup:",UsersInGroup)
        self.conn.send(pickle.dumps(UsersInGroup)) 
        

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
            UserSockets.append([ds,uusername])
            print("UserSockets: {}".format(UserSockets))
            logs = PersistentLogs()
            
            # Lav ny variabel hvor du gemmer sockets og bruger den er fra
            # Lav ny variabel hvor du gemmer hvor beskeden skal sendes til
            # Hvis socket + bruger ikke er i den nye variabel
            # Lad vær med at skriv til persistent logs
            
            # Hvis socket + bruger er i den nye variabel
            # Skriv til persistent logs
            
            
            while True:
                print("-----------------------------------")
                print("Users in socket list: \n{}".format(UserSockets))
                print("-----------------------------------")
                
                recv_string =ds.recv(BUFFER_SIZE)
                recv_data = pickle.loads(recv_string)
                if len(recv_string) == 0: 
                        print("Closed shit")
                        break  

                # Data structure: [userlogin, msg, toUser, groupname, keyword]
                print("\n=============================================")
                print("What is recv_data: {}".format(recv_data))
                print("What is recv_data[0]: {}".format(recv_data[0]))
                print("What is recv_data[1]: {}".format(recv_data[1]))
                print("What is recv_data[2]: {}".format(recv_data[2]))
                print("What is recv_data[3]: {}".format(recv_data[3]))
                print("What is recv_data[4]: {}".format(recv_data[4]))
                print("=============================================\n")
                
                ##############################################################
                ######## How do we check list of users in group?      ########
                ######## Data structure is:                           ########
                ######## [user, msg, ['friend1','friend2','friend3']] ########
                ##############################################################                                                      
                
                if recv_data[1] == "EEXIT":
                    print("==================================\n==================================")
                    print("This is current username:", uusername)
                    self.usernames.remove(uusername)
                    print(self.usernames)
                    self.portids.remove(NEW_PORT)
                    print(self.portids)
                    self.porthandles.remove(ds)
                    print(self.porthandles)
                    self.userids.remove(indid)
                    print(self.userids)
                    self.counter=self.counter-1
                    print("==================================\n==================================")
                    ds.send(pickle.dumps("CLOSE CONN"))
                    ds.close()
                    print('*** Connection closed. Status: active/maximum users: {}/{}'.format(len(self.usernames),MAX_USERS))
                    print('    username: {}'.format(data_list[1]))
                    for sublist in UserSockets:
                        if sublist[1] == uusername:
                            print("sublist:",sublist)
                            print("UserSockets:",UserSockets)
                            UserSockets.remove(sublist)
                            print("removing sublist from UserSockets:",UserSockets)
                    break
                else:
                    for x in UserSockets:
                        # Data structure: [userlogin, msg, toUser, groupname, keyword]
                        if recv_data[4] == "SINGLE":
                            if x[1] == recv_data[2]:
                                x[0].send(recv_string)
                            if x[1] != recv_data[2]:
                                x[0].send(recv_string)
                                logs.WriteToLog(recv_data[0],recv_data[1],recv_data[2])
                                
                        if recv_data[4] == "GROUP":
                            print(f"recv_data from: [{recv_data[0]}] : {recv_data}")
                            
                            
                            tempList = recv_data[2]
                            print(f"tempList: [{tempList}]")
                            print(f"UserSockets: [{UserSockets}]")
                            
                            for x1 in UserSockets:
                                print(f"x1: {x1}")
                                
                            for x2 in tempList:
                                print(f"x2: {x2}")
                            """
                            for y in recv_data[2]:
                                print("What is y:",y)
                                print("what is x[1]:",x[1])
                                if x[1] == y:
                                    print("========================")
                                    print("1 My socket:",x[0])
                                    print("1 what is x[1]:",x[1])
                                    print("========================")
                                    x[0].send(recv_string)
                                if x[1] != y:
                                    print("========================")
                                    print("2 My socket:",x[0])
                                    print("2 what is x[1]:",x[1])
                                    print("========================")
                                    x[0].send(recv_string)
                            #[loginName,msg,['user1','user2'], PersistentLogName] 
                            """
                            logs.WriteToLogGroup(recv_data[0],recv_data[1],recv_data[2],recv_data[3])
                            
                            
        else:
            connect_not_ok_list=["NOT OK"]
            data_string = pickle.dumps(connect_not_ok_list)
            self.csocket.send(data_string)
            self.csocket.close()
            print('*** Connection {} refused. Maximum numbers of users reached.'.format(self.counter))
            print('    from {}'.format(clientAddress))
            print('    handled in {}'.format(threading.get_ident()))
            print('    username: {}'.format(data_list[1]))
  
            
class UserLogThread(threading.Thread):
    def __init__(self):
        threading.Thread.__init__(self) 
        while True:
            self.logssocket = socket(AF_INET, SOCK_STREAM)
            self.logssocket.setsockopt(SOL_SOCKET, SO_REUSEADDR, 1)
            self.logssocket.bind((HOST, LOGS_PORT))
            self.logssocket.listen()
            self.clientsock, clientaddr = self.logssocket.accept()
            
            print("Connected to logs thread!")
            print("socket: {}".format(self.clientsock))
            print(f"IP address: {clientaddr}")
            
            # Data structure: [usernameLogin, usernameFriend]
            self.data = self.clientsock.recv(BUFFER_SIZE)
            self.data = pickle.loads(self.data)
            print("Data: {}".format(self.data))
            print("Data[0]: {}".format(self.data[0]))
            print("Data[1]: {}".format(self.data[1]))
            
            # Data structure: ReadLog(usernameLogin, usernameFriend)
            logs = PersistentLogs()
            
            
            Wall_of_Text = logs.ReadLog(self.data[0],self.data[1])
        
            
            for i in Wall_of_Text:
                #print("Wall_of_Text: {}".format(i))
                Wall_of_Text = pickle.dumps(i)
                #time.sleep(0.1)
                self.clientsock.send(Wall_of_Text)
                
            STOP = "STOP!"
            STOP = pickle.dumps(STOP)
            self.clientsock.send(STOP)
              
class PersistentLogs():
    def __init__(self):
        print("Opening logs...")
    
    # Data structure WriteToLog: "Userlogs/{}/{}.txt" [loginName,msg, PersistentLogName]    
    def WriteToLog(self,user,msg,name):
        file1 = open('UserLogs/{}/{}.txt'.format(user,name), 'a', newline='')
        #file1.write("YOU: "+msg+"\n") ORIGINAL
        file1.write("\nYOU: "+msg+"\n")
        file1.close()
        file2 = open('UserLogs/{}/{}.txt'.format(name,user), 'a', newline='')
        #file2.write("{}: ".format(userfriend)+msg+"\n") ORIGINAL
        file2.write("\n{}: ".format(user)+msg+"\n")
        file2.close()
    
    # Data structure WriteToLogGroup: "Userlogs/{}/{}.txt" [loginName,msg,['user1','user2'], PersistentLogName]    
    def WriteToLogGroup(self,user,msg,broadcast,name):
        file1 = open('UserLogs/{}/{}.txt'.format(user,name), 'a', newline='')
        #file1.write("YOU: "+msg+"\n") ORIGINAL
        file1.write("\nYOU: "+msg+"\n")
        file1.close()
        for users in broadcast: 
            file2 = open('UserLogs/{}/{}.txt'.format(users,name), 'a', newline='')
            #file2.write("{}: ".format(userfriend)+msg+"\n") ORIGINAL
            file2.write("\n{}: ".format(user)+msg+"\n")
            file2.close()
        
    def ReadLog(self,user,name):
        text = []
        with open('UserLogs/{}/{}.txt'.format(user,name), 'r', newline='') as f:
            text = f.readlines()
            return text
        
    #def ReadLogGroup(self,user,groupName):
    #    text = ""
    #    text2 = []
    #    with open('UserLogs/{}/{}.txt'.format(user,groupName), 'r', newline='') as f:
    #        text2 = f.readlines()
    #        return text2

        
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
    process2 = Process(target=LoadDataThread)
    process2.start()
    process3 = Process(target=UserLogThread)
    process3.start()
    
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