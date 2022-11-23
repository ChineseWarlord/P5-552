"""
Project 1: encrypted chat

Design a secure chat system, with the following features:

● A separate server that only handles key and message exchange
● Encrypted group chats
● Persistent chat logs that are loaded if you close and reopen the program

You can assume the server can be trusted for the key exchange, but it should not
be able to decode messages
"""

import csv
import select
import tkinter as tk
from tkinter import ttk
from socket import *
import threading
import time
import pickle

SERVER_IP = "127.0.0.1"
SERVER_PORT = 1234
VERIFY_PORT = 65432
LOAD_USER_PORT = 1000
BUFFER_SIZE = 1024

root = tk.Tk()
#root.withdraw()
#root = tk.Toplevel()
root.geometry("700x550")
root.title("Awesome Chat Program!")

stupidusername = ""
UserDataLoaded = []

class Main_View(tk.Tk):
    def __init__(self):
        #super().__init__()
        tk.Frame.__init__(self)
        
        #self.title("Awesome Chat Program!")
        self.container = tk.Frame(root)
        self.container.pack(side=tk.TOP,fill="both",expand=True)
        self.container.grid_rowconfigure(0, weight = 1)
        self.container.grid_columnconfigure(0, weight = 1)
          
        #self.frames = {}
        #for FRAMES in (Page_Login, Page_UserRegistration, Page_Chat):
        #    frame = FRAMES(container,self)
        #    self.frames[FRAMES] = frame
        #    frame.grid()
        #    frame.grid(row = 0, column = 0, sticky ="nsew")

        
        #self.show_frame(Page_Login)
        #self.show_frame(Page_Chat)
        self.frames = {}
        
    def add_page(self,Name, Page, thread1=0):
        if Name == "Page_Chat":
            self.frames[Name] = Page(parent=self.container,controller=self, thread=thread1)    
            self.frames[Name].grid(row=0, column=0, sticky="nsew")
        else:    
            self.frames[Name] = Page(parent=self.container,controller=self)    
            self.frames[Name].grid(row=0, column=0, sticky="nsew")
        
    def show_frame(self, Page): 
        frame = self.frames[Page]
        frame.tkraise()
     
class Page_Login(tk.Frame):
    def __init__(self, parent, controller):
        tk.Frame.__init__(self, parent)
        
        self.controller = controller
        self.UsernameLogin = tk.StringVar()
        self.PasswordLogin = tk.StringVar()
        
        print("PAGE_LOGIN Am I printing this? 1")
        
        self.frame_master = tk.Frame(master=self, 
                               borderwidth=1, 
                               background="blue",
                               highlightthickness=5,)
        self.frame_master.pack(side=tk.TOP, fill='both',expand=True)
        
        self.frame1 = tk.Frame(self.frame_master, 
                               borderwidth=1,
                               highlightthickness=5,)
        self.frame1.pack(side=tk.TOP,expand=True)
        self.title_label = tk.Label(self.frame1, text="Awesome Chat Program!", font=('Arial',18,'bold'))
        self.title_label.pack(side=tk.TOP,expand=False)
        

        self.frame2 = tk.Frame(self.frame1, borderwidth=10, background="red")
        #self.frame2 = tk.Frame(root, borderwidth=10, background="red")
        self.frame2.pack(side=tk.TOP,expand=False)
        self.username_label = tk.Label(self.frame2,text="Username:")
        self.username_label.pack(side=tk.LEFT,fill='both',expand=True)
        self.username_entry_login = tk.Entry(self.frame2, width=50,textvariable=self.UsernameLogin)
        self.username_entry_login.pack(side=tk.TOP,fill='both',expand=True)
        self.username_entry_login.bind("<Return>",self.key_pressed)
        self.username_entry_login.focus()

        self.frame3 = tk.Frame(self.frame1, borderwidth=10, background="black")
        #self.frame3 = tk.Frame(root, borderwidth=10, background="black")
        self.frame3.pack(side=tk.TOP,expand=False)
        self.pwd_label = tk.Label(self.frame3,text="Password: ")
        self.pwd_label.pack(side=tk.LEFT)
        self.pwd_entry_login = tk.Entry(self.frame3, width=50,textvariable=self.PasswordLogin,show="*")
        self.pwd_entry_login.pack(side=tk.TOP,fill='both',expand=True)
        self.pwd_entry_login.bind("<Return>",self.key_pressed)
        
        self.frame4 = tk.Frame(self.frame1, borderwidth=10, background="green")
        #self.frame4 = tk.Frame(root, borderwidth=10, background="green")
        self.frame4.pack(side=tk.TOP,expand=False)
        
        self.login_button = tk.Button(self.frame4, text="Log In",command=lambda : [self.log_in(),self.clear_entry(), ], bg="#211A52", fg = "white")
        self.register_page_button = tk.Button(self.frame4, text="Register now",command=lambda : [self.register_user(),self.clear_entry()], bg="#211A52", fg = "white")
        self.login_button.pack(side=tk.LEFT)
        self.register_page_button.pack(side=tk.RIGHT)
        
        
    def key_pressed(self, event):
        self.log_in()
        self.clear_entry()
        
    def clear_entry(self):
        self.username_entry_login.delete(0, 'end')
        self.pwd_entry_login.delete(0, 'end')
     
    def register_user(self):
        root.add_page("Page_UserRegister",Page_UserRegister)

    def LoadUsers(self):
        while True:
            print("Data: {} {}".format(self.data[1],self.data[2]))
            self.data_string = pickle.dumps([self.data[1],self.data[2]])
            self.se.send(self.data_string)
            data_Load = self.se.recv(BUFFER_SIZE)
            data_Load = pickle.loads(data_Load)
            # Data structure: [UsernamePassword, FriendName, IP address]
            print("From Server: {}".format(data_Load))
            global UserDataLoaded
            UserDataLoaded = data_Load
            
            with open('UsersDataLoaded.csv', 'a', newline='') as f:
                    csv_writer = csv.writer(f)
                    csv_writer.writerows(data_Load)    
               
    def log_in(self):
        print("USER: "+self.UsernameLogin.get())
        print("PASS: "+self.PasswordLogin.get())
        self.se = socket(AF_INET,SOCK_STREAM)
        self.se.connect((SERVER_IP, VERIFY_PORT))
        data_User = self.UsernameLogin.get()
        data_Pass = self.PasswordLogin.get()
    
        print("data_User: {}\ndata_Pass: {}".format(data_User, data_Pass))
        
        data_Check = "userlogin"
        self.data_string = pickle.dumps([data_User, data_Pass, data_Check])
        self.se.send(self.data_string)
        self.data = self.se.recv(BUFFER_SIZE)
        self.data = pickle.loads(self.data)
        print("From Server1: {}".format(self.data))
        self.data = self.data.split('#')
        print("From Server2: {}".format(self.data))
            
        if self.data[0] == "YES LOGIN!":
            print("OK LOGIN :)")
            print(f"Username: {self.UsernameLogin.get()} \n" + f"Password: {self.PasswordLogin.get()}")
            self.title_label.config(text="Awesome Chat Program!", fg="black", font=('Arial',18,'bold'))
            global stupidusername
            stupidusername = self.data[1]
            print("From Server stupidusername: {}".format(stupidusername))
            self.clear_entry()
            
            self.UserChatSocket1 = socket(AF_INET,SOCK_STREAM)
            self.UserChatSocket1.connect((SERVER_IP, SERVER_PORT))
            connect_list=["CONNECT",stupidusername]
            print("connect_list: ",connect_list)
            data_string = pickle.dumps(connect_list)
            self.UserChatSocket1.send(data_string)
            data = self.UserChatSocket1.recv(BUFFER_SIZE)
            data_list = pickle.loads(data)
            print("From server data: {}".format(data_list))
            print("From server   OK: {}".format(data_list[0]))
            if data_list[0]=="OK":
                #self.chat_box.configure(state="normal")
                #self.chat_box.configure(state="disabled")
                NEW_PORT=data_list[3]
                print(NEW_PORT)
                UserChatSocket2 = socket(AF_INET,SOCK_STREAM)
                UserChatSocket2.connect((SERVER_IP, NEW_PORT))
                self.event = threading.Event()
                self.thread1 = SendData(UserChatSocket2,stupidusername)
                self.thread2 = ReceiveData(UserChatSocket2, self.event)
                self.thread2.start()
                root.add_page("Page_Chat",Page_Chat, self.thread1)
            else:
                print("Reply from server: server is full. Retry later.")
        
            
            #print("Login socket status: {}".format(self.se))
            #self.LoadUsers() 
            #root.show_frame("Page_Chat")
        if self.data[0] == "NO LOGIN!":
            print("NOT LOGIN :(")
            self.clear_entry()
            self.title_label.config(text="Incorrect username and/or password!", fg="red", font=('arial',10,'bold'))
            self.se.close()      
            print("Login socket status: {}".format(self.se)) 
           
class Page_UserRegister(tk.Frame):
    def __init__(self,parent,controller):
        tk.Frame.__init__(self,parent)
        
        print("PAGE_USERREGISTER Am I printing this? 1")
         
        self.controller = controller
        self.Username = tk.StringVar()
        self.Password = tk.StringVar()
        
        self.frame1 = tk.Frame(master=self, borderwidth=10, bg="blue")
        self.frame1.pack()
        self.register_title_label = tk.Label(self.frame1, text="User Registration")
        self.register_title_label.pack(side=tk.LEFT)

        self.frame2 = tk.Frame(master=self, borderwidth=10, bg="red")
        self.frame2.pack()
        self.username_label = tk.Label(self.frame2,text="Username:")
        self.username_label.pack(side=tk.LEFT)
        self.username_entry = tk.Entry(self.frame2, width=50,textvariable=self.Username)
        self.username_entry.pack()
        self.username_entry.bind("<Return>",self.key_pressed)
        self.username_entry.focus()

        self.frame3 = tk.Frame(master=self, borderwidth=10, bg="green")
        self.frame3.pack()
        self.pwd_label = tk.Label(self.frame3,text="Password: ")
        self.pwd_label.pack(side=tk.LEFT)
        self.pwd_entry = tk.Entry(self.frame3, width=50,textvariable=self.Password,show="*")
        self.pwd_entry.pack()
        self.pwd_entry.bind("<Return>",self.key_pressed)
        
        self.frame4 = tk.Frame(master=self, borderwidth=10,bg="yellow")
        self.frame4.pack()
        self.register_button = tk.Button(self.frame4, text="Register now",command=lambda:[self.register_user(), self.clear_entry()], bg="#211A52", fg = "white")
        self.register_button.pack(side=tk.LEFT)
        
        
        self.return_button = tk.Button(self.frame4, text="Return",command=lambda : [self.return_to_login(),self.clear_entry()], bg="#211A52", fg = "white")
        self.return_button.pack(side=tk.LEFT)
        self.register_title_label.config(text="User Registration")
    
    def return_to_login(self):
        root.show_frame("Page_Login")
    
    def key_pressed(self, event):
        self.register_user()
        self.clear_entry()
    
    def clear_entry(self):
        self.username_entry.delete(0, 'end')
        self.pwd_entry.delete(0, 'end')
        
    def register_user(self):
        if not self.Username.get():
            self.register_title_label.config(text="No Username was entered!", fg="red", font=('arial',10,'bold'))
        if not self.Password.get():
            self.register_title_label.config(text="No Password was entered!", fg="red", font=('arial',10,'bold'))
        if not self.Username.get() and not self.Password.get():
            self.register_title_label.config(text="No Username or Password was entered!", fg="red", font=('arial',10,'bold'))
        if self.Username.get() and self.Password.get():
            self.Server_Verify()
            
    def Server_Verify(self):
        
        self.se = socket(AF_INET,SOCK_STREAM)
        self.se.connect((SERVER_IP, VERIFY_PORT))
        data_User = self.Username.get()
        data_Pass = self.Password.get()
        data_Check = "userregister"
        self.data_string = pickle.dumps([data_User, data_Pass, data_Check])
        self.se.send(self.data_string)
        data = self.se.recv(BUFFER_SIZE)
        data = pickle.loads(data)
        print("From Server: {}".format(data))
        
        if data == "YES OK!":
            print("OK from server :)")
            print(f"Username: {self.Username.get()} \n" + f"Password: {self.Password.get()}")
            self.register_title_label.config(text="User Registration Successful!", fg="#211A52", font=('arial',10,'bold'))
            self.se.close()
            print("Register socket status: {}".format(self.se))
        if data == "NOT OK!":
            print("NOT OK from server :)")
            self.register_title_label.config(text="User already registered!", fg="red", font=('arial',10,'bold'))
            #self.se.close()
            print("Register socket status: {}".format(self.se))            

class Page_Chat(tk.Frame):
    def __init__(self,parent,controller, thread):
        tk.Frame.__init__(self,parent)
        
        self.controller = controller
        self.thread1 = thread
        print("PAGE_CHAT Am I printing this? 1")
        
        
        # Title label
        self.frame_main = tk.Frame(self,
                                   highlightbackground="red", 
                                   highlightthickness=6,
                                   bg="blue")
        self.frame_main.pack(fill='both',expand=True)
        
        global stupidusername
        stupidusername1 = stupidusername
        print("STUPIDUSERNAME: {}".format(stupidusername1))
        
        self.chat_title = tk.Label(self.frame_main, 
                                   text="Welcome {}!".format(stupidusername), 
                                   font=('Arial',18,'bold'),
                                   bg="black", fg="white",
                                   highlightbackground="blue",
                                   highlightthickness=6)
        self.chat_title.pack(side=tk.TOP,fill=tk.X, expand=False)
                
        # Left side chat menu
        self.main_frame = tk.Frame(self.frame_main, 
                                   bg="green",
                                   borderwidth=1,
                                   highlightbackground="magenta", 
                                   highlightthickness=6)
        self.main_frame.pack(side=tk.LEFT,expand=False,fill=tk.Y)
        # Chat Menu + Settings label - top side in frame1
        self.frame1 = tk.Frame(self.main_frame, bg="orange",borderwidth=10)
        self.frame1.pack(side=tk.TOP,expand=False,fill=tk.X)
        # Users Frame
        self.frame2 = tk.Frame(self.main_frame, bg="blue",borderwidth=5,height=100,width=100,highlightbackground="green", highlightthickness=4)
        self.frame2.pack(side=tk.TOP,expand=True,fill='both', padx=10,pady=10)
        self.frame2.propagate(False)
        
        # Frame for friend list
        self.frame5 = tk.Frame(self.frame2, bg="magenta",highlightbackground="green", highlightthickness=4)
        self.frame5.pack(side=tk.TOP,expand=False,fill=tk.X, pady=15)
        self.FriendList_Label = tk.Label(self.frame5,text="Friend List", bg="green", fg="white",font=('arial',10,'bold'), borderwidth=1)
        self.FriendList_Label.pack(side=tk.TOP,fill='both',expand=True,pady=15)
        self.frame6 = tk.Listbox(self.frame5, bg="yellow",highlightbackground="green", highlightthickness=4)
        self.frame6.pack(side=tk.TOP,expand=False)
        self.LoadUserFriends()
       
        # Exit Frame
        self.frame3 = tk.Frame(self.main_frame, bg="black",borderwidth=5,highlightbackground="yellow", highlightthickness=4)
        self.frame3.pack(side=tk.BOTTOM,expand=False,fill=tk.X)
        
        # Frame references:
        """
        self.chat_label = tk.Label(self.frame1, text="Chat Menu", bg="yellow", fg="black", borderwidth=20)
        self.chat_label = tk.Label(self.frame1, text="Chat Menu",height=1, bg="yellow", fg="black",borderwidth=1,relief="raised")
        """
        
        # Chat + Settings label
        self.chat_label = tk.Button(self.frame1, text="Chat Menu",font=('arial',10,'bold'),height=1, bg="yellow", fg = "black", borderwidth=1,relief="raised")
        self.chat_label.pack(side=tk.LEFT,fill=tk.X, expand=True,padx=1.5, pady=1.5)
        
        self.add_user = tk.Button(self.frame1, text="+",font=('arial',10,'bold'),height=1,command=lambda : [self.Add_Users_Window()], bg="white", fg = "black", borderwidth=1,relief="raised")
        self.add_user.pack(side=tk.LEFT,fill=tk.X, expand=True, padx=1.5, pady=1.5)
        
        self.settings_label = tk.Button(self.frame1, text="Settings",font=('arial',10,'bold'),height=1,command=lambda : [], bg="magenta", fg = "black", borderwidth=1,relief="raised")
        self.settings_label.pack(side=tk.LEFT,fill=tk.X, expand=True, padx=1.5, pady=1.5)
        
        
        # EXIT button
        self.return_button = tk.Button(self.frame3, text="EXIT",command=lambda : [root.show_frame("Page_Login")], bg="#211A52", fg = "white")
        self.return_button.pack(side=tk.TOP,expand=False)
        #self.return_button.pack(side=tk.TOP)
        
        # Chat Window
        self.frame4 = tk.Frame(self.frame_main, 
                               bg="yellow",
                               highlightbackground="magenta", 
                               highlightthickness=6,
                               borderwidth=10)
        self.frame4.pack(side=tk.TOP,fill='both',expand=True)
        self.Chat_Label = tk.Label(self.frame4,text="Chat Window", bg="green", fg="white",font=('arial',10,'bold'), borderwidth=1)
        self.Chat_Label.pack(side=tk.TOP,fill=tk.X,expand=False)
    
    def key_pressed(self, event):
        #self.AddShit()
        self.addUserFriend()
        #self.removeUsers()
        #self.LoadUserFriends()
        self.clear_entry()
        self.Add_User_Frame.withdraw()
          
          
    def clear_entry(self):
        self.usernameadd_entry.delete(0, 'end')
            
    def Add_Users_Window(self):
        self.Add_User_Frame = tk.Toplevel(root)
        self.Add_User_Frame.title("Add User")
        #self.Add_User_Frame.geometry("300x150")
        #self.Add_User_Frame.resizable(False, False)
        
        self.UsernameAdd = tk.StringVar()
        
        self.frameadd = tk.Frame(self.Add_User_Frame, borderwidth=5, bg="red")
        self.frameadd.pack(side=tk.TOP,fill='both',expand=True)
        self.frameadd_User_TRY = tk.Frame(self.frameadd, borderwidth=2, bg="Yellow")
        self.frameadd_User_TRY.pack(side=tk.TOP)
        self.frameadd_User = tk.Frame(self.frameadd, borderwidth=5, bg="Blue")
        self.frameadd_User.pack(side=tk.TOP)
        self.frameadd_User_BUT = tk.Frame(self.frameadd, borderwidth=5, bg="Green")
        self.frameadd_User_BUT.pack()
        
        self.username_tryadd_label = tk.Label(self.frameadd_User_TRY,text="Add user")
        self.username_tryadd_label.pack(side=tk.LEFT,padx=5, pady=5)
        
        
        self.username_label = tk.Label(self.frameadd_User,text="Username:")
        self.username_label.pack(side=tk.LEFT,padx=5, pady=5)
        
        self.usernameadd_entry = tk.Entry(self.frameadd_User, width=35,textvariable=self.UsernameAdd)
        self.usernameadd_entry.pack(side=tk.RIGHT)
        self.usernameadd_entry.bind("<Return>",self.key_pressed)
        self.usernameadd_entry.focus()
            
        self.Add_User_Button = tk.Button(self.frameadd_User_BUT, text="Add user",command=lambda : [self.addUserFriend(),self.clear_entry()], bg="#211A52", fg = "white")
        self.Add_User_Button.pack(side=tk.LEFT)
        self.Add_User_EXIT_Button = tk.Button(self.frameadd_User_BUT, text="EXIT",command=lambda : [self.Add_User_Frame.withdraw(),self.clear_entry()], bg="#211A52", fg = "white")
        self.Add_User_EXIT_Button.pack(side=tk.RIGHT)
        
        
    def addUserFriend(self):
        # After clicking add user button - connect to server and add user to USER_DATA (Which holds data of logged in user)
        self.se = socket(AF_INET,SOCK_STREAM)
        self.se.connect((SERVER_IP, VERIFY_PORT))
        
        TryToAddUser = self.UsernameAdd.get()
        self.data_string = pickle.dumps([TryToAddUser," ", "UserAdd"])
        self.se.send(self.data_string)
        datax = self.se.recv(BUFFER_SIZE)
        datax = pickle.loads(datax)
        print("From Server: {}".format(datax))
        datax = datax.split('#')
        print("From Server2: {}".format(datax))
        print("datax[0]: {}\ndatax[1]: {}".format(datax[0],datax[1]))
        
        if datax[1] == TryToAddUser:
            print("USER ADDED")
            self.Add_User_Frame.withdraw()
            self.removeUsers()
            self.LoadUserFriends()
        if datax[0] == "ALREADY IN FRIENDLIST!":
            print("USER ALREADY IN FRIENDLIST")
            shit1 = "ALREADY IN FRIENDLIST"
            self.username_tryadd_label.config(text="User already in friendlist", fg="red", font=('arial',10,'bold'))
            return shit1
        if datax[0] == "TRIED TO ADD YOURSELF!":
            shit2 = "TRIED TO ADD YOURSELF"
            print("TRIED TO ADD YOURSELF!")
            self.username_tryadd_label.config(text="Tried to add yourself!", fg="red", font=('arial',10,'bold'))
            return shit2
        if datax[0] == "USER DOES NOT EXIST!":
            shit3 = "USER NOT EXIST"
            self.username_tryadd_label.config(text="User does not exist!", fg="red", font=('arial',10,'bold'))
            return shit3
        # In server check if the user, trying to be added, is in database - if in database add user to USER_DATA
         
 
    def LoadUserFriends(self):
        # When logged in, connect to server and load USER_DATA into chat menu window
        # Make added user clickable and when clicked connect to chat server and add chat window to chat window frame
        
        self.LoadSocket = socket(AF_INET,SOCK_STREAM)
        self.LoadSocket.connect((SERVER_IP, LOAD_USER_PORT))
        self.data_string = pickle.dumps([stupidusername,"Load_User"])
        self.LoadSocket.send(self.data_string)
        
        self.dataLoaded = self.LoadSocket.recv(BUFFER_SIZE)
        self.dataLoaded = pickle.loads(self.dataLoaded)
        global UserDataLoaded
        print("Users loaded from server: {}".format(self.dataLoaded))
        count = 0
        self.LoadedUserLabels = []
        tempnameholder = []
        
        
        for x in self.dataLoaded:
            #self.LoadedUserLabel = tk.Label(self.frame2,text="{}".format(self.dataLoaded[count]),cursor="hand2", 
            #                       bg="green", fg="white",font=('arial',10,'bold'), borderwidth=1)
            self.LoadedUserLabel = tk.Button(self.frame6,text="{}".format(self.dataLoaded[count]), 
                                   bg="black", fg="magenta",font=('arial',10,'bold'), borderwidth=1,
                                   anchor="center",
                                   command=lambda count=count,name=self.dataLoaded[count]:self.OpenUserChat(name,count))
            name = self.dataLoaded[count]
            print("This is name: {}".format(name))
            print("Username of friends: {}".format(self.dataLoaded[count]))                         
            #self.LoadedUserLabel.bind("<Button-1>", lambda e:self.shitmyself())
            tempnameholder.append(self.dataLoaded[count])
            #print("tempnameholder: {}".format(tempnameholder))
            global labelClicked
            labelClicked = False
            
            #self.LoadedUserLabel.bind("<Button-1>", lambda e:[self.callback()])
            #self.LoadedUserLabel.bind("<Button-1>", lambda count=count,name=self.dataLoaded[count]:self.OpenUserChat(name,count))
            
            self.LoadedUserLabel.pack(side=tk.TOP,expand=False,pady=3)
            count += 1
            self.LoadedUserLabels.append(self.LoadedUserLabel)
        #print("LoadedUserLabels: {}".format(self.LoadedUserLabels))
        
        #for x in self.LoadedUserLabels:
        #    x.bind("<Button-1>", lambda e:[self.callback(e)])
        #    print("this is x: {}".format(x))
        
    def removeUsers(self):
        for widget in self.frame6.winfo_children():
            print("widgets: {}".format(widget))
            if isinstance(widget,tk.Button):
                widget.destroy()
    def removeChatWindows(self):
        for widget in self.frame4.winfo_children():
            if isinstance(widget,tk.Frame):
                #print("removechatwindow widgets: {}".format(widget))
                #widget.destroy()
                widget.forget()
                
        
    def OpenUserChat(self,friend,count):
        #self.removeChatWindows()
        #print("self.LoadedUserLabels: {}".format(self.LoadedUserLabels))
        #for i in range(len(self.LoadedUserLabels)):
        #    friendlist = self.dataLoaded[i]
            
            print("\nwhat is friend name: {}".format(friend))
            #print("what is friendlist {}".format(friendlist))
            
            self.removeChatWindows()
            
            self.ChatWindowUserFrame = tk.Frame(self.frame4, bg="magenta",highlightbackground="green", highlightthickness=6 )
            self.ChatWindowUserFrame.pack(side=tk.TOP,fill='both',expand=True)  
            self.userchatLabel = tk.Label(self.ChatWindowUserFrame,text="{}'s Chat".format(friend),bg="magenta", fg="black",font=('arial',10,'bold'), borderwidth=1)
            self.userchatLabel.pack(side=tk.TOP,expand=False,anchor='center',pady=3)  
            
            self.ChatTestFrame = tk.Frame(self.ChatWindowUserFrame, bg="yellow",highlightbackground="green", highlightthickness=6,borderwidth=10,height=200,width=500)
            self.ChatTestFrame.pack(side=tk.TOP)
            self.ChatTestFrame.pack_propagate(0)
            
              
            #self.chat_box = tk.Text(self.ChatWindowUserFrame, height=25)
            self.chat_box = tk.Text(self.ChatTestFrame, height=250)
            self.chat_box.configure(state="disabled")
            self.chat_box.pack(fill='both',expand=True)
            
            scrollbar = tk.Scrollbar(self.chat_box)
            scrollbar.pack(side=tk.RIGHT,fill=tk.Y)
            
            self.chat_box.configure(yscrollcommand=scrollbar.set)
            scrollbar.config(command=self.chat_box.yview)
            
            #self.usernameadd_entry = tk.Entry(self.frameadd_User, width=35,textvariable=self.UsernameAdd)
            #self.usernameadd_entry.pack(side=tk.RIGHT)
            self.input_field = tk.Entry(self.ChatWindowUserFrame,width=70,borderwidth=5,highlightbackground="black", highlightthickness=1)
            self.input_field.pack(side=tk.TOP,pady=1)
            
            self.thread1.set(self.chat_box,self.input_field)
            
            self.button = ttk.Button(self.ChatWindowUserFrame, text='Send')
            self.button['command'] = self.send_message_button
            self.button.pack()
            
            #print("global click: {}".format(labelClicked))
        
        
    def send_message_button(self):
        self.thread1.send()
        self.input_field.delete(0, 'end')
        
    def send_message_enter(self, event):
        self.thread1.send()
        self.input_field.delete(0, "end")
        return "break"
    
class SendData():
    def __init__(self,tcp_socket, user):
        self.ds=tcp_socket
        self.uu=user
    def send(self):
            send_data = self.input.get()
            print("send data: {}".format(send_data))
            if len(send_data) > 1:
                chat_data=[self.uu,send_data]
                chat_string = pickle.dumps(chat_data)
                self.ds.send(chat_string)
                self.chat.configure(state="normal")
                self.chat.insert("end","\nYOU: {}".format(send_data))
                self.chat.configure(state="disabled")
                self.chat.see("end")
    def exit(self):
            chat_data=[self.uu, "EEXIT"]
            chat_string = pickle.dumps(chat_data)
            self.ds.send(chat_string)
            print("Connection closed.")
    def set(self, chat_box,input):
        self.chat = chat_box
        self.input = input
           
class ReceiveData(threading.Thread):
    def __init__(self,tcp_socket, event):
        threading.Thread.__init__(self)
        self.ds=tcp_socket
        self.event = event
    def run(self):
        self.ds.setblocking(0)
        while True:
            ready = select.select([self.ds], [], [])
            if ready[0]:
                recv_string = self.ds.recv(BUFFER_SIZE)
                recv_data = pickle.loads(recv_string)
                if (recv_data[0] != "Server"):
                    self.chat.configure(state="normal")
                    self.chat.insert("end","\n{}: {}".format(recv_data[0],recv_data[1]))
                    self.chat.configure(state="disabled")
                    self.chat.see("end")
                else:
                    print(recv_data[1])
                    
    def set(self,chat_box):
        self.chat = chat_box   
 

if __name__=="__main__":
    #myapp = Main_View()
    #myapp.mainloop()

    root = Main_View()
    root.add_page("Page_Login",Page_Login)
    #root.add_page("Page_UserRegister",Page_UserRegister)
    root.show_frame("Page_Login")
    root.mainloop()
