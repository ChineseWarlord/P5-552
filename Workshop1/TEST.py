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
from tkinter import PhotoImage, mainloop, ttk
from socket import *
import threading
import time
import pickle
import os
import sys
import select
from tkinter import messagebox
from PIL import Image, ImageTk

SERVER_IP = "127.0.0.1"
SERVER_PORT = 1234
VERIFY_PORT = 2001
LOGS_PORT = 2005
LOAD_USER_PORT = 1000
BUFFER_SIZE = 10000

stupidusername = ""
userfriend = ""
GroupListFriends = []
UserDataLoaded = []
active_window = False
active_window2 = False
active_chat = False


class Page_Login(tk.Frame):
    def __init__(self):
        self.root = tk.Tk()
        self.root.withdraw()
        #self.tkraise()
      
        #tk.Frame.__init__(self)
      
      
        self.Main_Window = tk.Toplevel()
        self.Main_Window.protocol("WM_DELETE_WINDOW", self.on_closing)
        self.Main_Window.title("Login Screen")
        self.Main_Window.resizable(width=False, height=False)
        self.Main_Window.configure(width=600, height=300)

        self.UsernameLogin = tk.StringVar()
        self.PasswordLogin = tk.StringVar()

        self.frame_master = tk.Frame(self.Main_Window)
        self.frame_master.pack(side=tk.TOP, fill='both',expand=True)
        #self.frame_master.propagate(0)
        self.frame1 = tk.Frame(self.frame_master)
        self.frame1.pack(side=tk.TOP,expand=True)
        self.title_label = tk.Label(self.frame1, text="Awesome Chat Program!", font=('Arial',18,'bold'))
        self.title_label.pack(side=tk.TOP,expand=False)

        self.frame2 = tk.Frame(self.frame1)
        #self.frame2 = tk.Frame(root, borderwidth=10, background="red")
        self.frame2.pack(side=tk.TOP,expand=False)
        self.username_label = tk.Label(self.frame2,text="Username:")
        self.username_label.pack(side=tk.LEFT,fill='both',expand=True)
        self.username_entry_login = tk.Entry(self.frame2, width=50,textvariable=self.UsernameLogin)
        self.username_entry_login.pack(side=tk.TOP,fill='both',expand=True)
        self.username_entry_login.bind("<Return>",self.key_pressed)
        self.username_entry_login.focus()
        self.frame3 = tk.Frame(self.frame1, borderwidth=10)
        #self.frame3 = tk.Frame(root, borderwidth=10, background="black")
        self.frame3.pack(side=tk.TOP,expand=False)
        self.pwd_label = tk.Label(self.frame3,text="Password: ")
        self.pwd_label.pack(side=tk.LEFT)
        self.pwd_entry_login = tk.Entry(self.frame3, width=50,textvariable=self.PasswordLogin,show="*")
        self.pwd_entry_login.pack(side=tk.TOP,fill='both',expand=True)
        self.pwd_entry_login.bind("<Return>",self.key_pressed)

        self.frame4 = tk.Frame(self.frame1, borderwidth=10)
        #self.frame4 = tk.Frame(root, borderwidth=10, background="green")
        self.frame4.pack(side=tk.TOP,expand=False)

        self.login_button = tk.Button(self.frame4, text="Log In",command=lambda : [self.log_in(),self.clear_entry()], bg="#211A52", fg = "white")
        self.register_page_button = tk.Button(self.frame4, text="Register now",command=lambda : [self.register_user(),self.clear_entry()], bg="#211A52", fg = "white")
        self.login_button.pack(side=tk.LEFT)
        self.register_page_button.pack(side=tk.RIGHT)

        self.frame_master.mainloop()
      
    def on_closing(self):
        exit()   
        
    def key_pressed(self, event):
        self.log_in()
        self.Main_Window.withdraw()
        
    def clear_entry(self):
        self.username_entry_login.delete(0, 'end')
        self.pwd_entry_login.delete(0, 'end')
     
    def register_user(self):
        self.Main_Window.withdraw()
        self = Page_UserRegister()
        #root.add_page("Page_UserRegister",Page_UserRegister)

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
        self.data_string = pickle.dumps([data_User, data_Pass, data_Check,""])
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
            connect_list=["CONNECT",data_User]
            print("connect_list: ",connect_list)
            data_string = pickle.dumps(connect_list)
            self.UserChatSocket1.send(data_string)
            data2 = self.UserChatSocket1.recv(BUFFER_SIZE)
            data_list = pickle.loads(data2)
            print("From server data: {}".format(data_list))
            print("From server   OK: {}".format(data_list[0]))
            if data_list[0]=="OK":
               NEW_PORT=data_list[3]
               print(NEW_PORT)
               self.UserChatSocket2 = socket(AF_INET,SOCK_STREAM)
               self.UserChatSocket2.connect((SERVER_IP, NEW_PORT))
               self.event = threading.Event()
               self.thread1 = SendData(self.UserChatSocket2,stupidusername)
               self.thread2 = ReceiveData(self.UserChatSocket2, self.event)
               self.thread2.start()
               #root.add_page("Page_Chat",Page_Chat, self.thread1, self.thread2, self.UserChatSocket1, self.UserChatSocket2)
               self.Main_Window.withdraw()
               Page_Chat(self.thread1, self.thread2, self.UserChatSocket1, self.UserChatSocket2)
            else:
                print("Reply from server: server is full. Retry later.")
        if self.data[0] == "NO LOGIN!":
            print("NOT LOGIN :(")
            self.title_label.config(text="Incorrect username and/or password!", fg="red", font=('arial',10,'bold'))
            self.clear_entry()
            print("Login socket status: {}".format(self.se)) 
        
        
class Page_UserRegister(tk.Frame):
   def __init__(self):
      #tk.Frame.__init__(self)
        
      self.Main_Window = tk.Toplevel()
      self.Main_Window.protocol("WM_DELETE_WINDOW", self.on_closing)
      self.Main_Window.title("User Registration")
      #self.Main_Window.resizable(width=False, height=False)
      self.Main_Window.configure(width=600, height=300)
      
      self.Username = tk.StringVar()
      self.Password = tk.StringVar()
      
      self.frame1 = tk.Frame(self.Main_Window,height=580,width=750)
      self.frame1.pack(fill='both',expand=True)
      self.register_title_label = tk.Label(self.frame1, text="User Registration",font=('Arial',14,'bold') )
      self.register_title_label.pack(side=tk.TOP)
      
      self.frame2 = tk.Frame(self.frame1)
      self.frame2.pack(side=tk.TOP,expand=False)
      self.username_label = tk.Label(self.frame2,text="Username:")
      self.username_label.pack(side=tk.LEFT,fill='both',expand=True)
      self.username_entry_login = tk.Entry(self.frame2, width=50,textvariable=self.Username)
      self.username_entry_login.pack(side=tk.TOP,fill='both',expand=True)
      self.username_entry_login.bind("<Return>",self.key_pressed)
      self.username_entry_login.focus()
      self.frame3 = tk.Frame(self.frame1, borderwidth=10)
      self.frame3.pack(side=tk.TOP,expand=False)
      self.pwd_label = tk.Label(self.frame3,text="Password: ")
      self.pwd_label.pack(side=tk.LEFT)
      self.pwd_entry_login = tk.Entry(self.frame3, width=50,textvariable=self.Password,show="*")
      self.pwd_entry_login.pack(side=tk.TOP,fill='both',expand=True)
      self.pwd_entry_login.bind("<Return>",self.key_pressed)
      
      self.frame4 = tk.Frame(self.frame1, borderwidth=10)
      #self.frame4 = tk.Frame(root, borderwidth=10, background="green")
      self.frame4.pack(side=tk.TOP,expand=False)
      
      
      self.register_button = tk.Button(self.frame4, text="Register now",command=lambda:[self.register_user(), self.clear_entry()], bg="#211A52", fg = "white")
      self.register_button.pack(side=tk.LEFT)
      
      self.return_button = tk.Button(self.frame4, text="Return",command=lambda : [self.return_to_login(),self.clear_entry(),self.Main_Window.withdraw()], bg="#211A52", fg = "white")
      self.return_button.pack(side=tk.RIGHT)
      
      self.frame1.mainloop()
      
   def on_closing(self):
      exit() 
   def return_to_login(self):
      self.Main_Window.withdraw()
      Page_Login()
    
   def key_pressed(self, event):
        self.register_user()
        self.clear_entry()
    
   def clear_entry(self):
        self.username_entry_login.delete(0, 'end')
        self.pwd_entry_login.delete(0, 'end')
        
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
        self.data_string = pickle.dumps([data_User, data_Pass, data_Check,""])
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
    def __init__(self,thread1,thread2, socketlogin, socketchat):
        # Same as creating root window, withdrawing it, and running mainloop()
        tk.Frame.__init__(self)

        self.thread1 = thread1
        self.thread2 = thread2
        self.socketlogin = socketlogin
        self.socketchat = socketchat

        #self.tkraise()

        self.Main_Window = tk.Toplevel()
        self.Main_Window.protocol("WM_DELETE_WINDOW", self.on_closing)
        self.Main_Window.title("Awesome Chat Program!")
        #self.Main_Window.resizable(width=False, height=False)
        #self.Main_Window.configure(width=600, height=300)

        self.Username = tk.StringVar()
        self.Password = tk.StringVar()



        ### ------------------ Start of Main Window Frame ------------------ ###
        # Main Window Frame
        self.frame_main = tk.Frame(self.Main_Window,
                                   highlightbackground="red",
                                   highlightthickness=6,
                                   bg="blue",height=700,width=1000)
        self.frame_main.pack(fill='both',expand=True)
        self.frame_main.propagate(0)

        # Frame Title label
        self.chat_title = tk.Label(self.frame_main, 
                                   text=f"Welcome {stupidusername}!", 
                                   font=('Arial',24,'bold'),
                                   bg="black", fg="white")
        self.chat_title.pack(side=tk.TOP,fill=tk.X, expand=False)
        ### ------------------ End of Main Window Frame ------------------ ###


        ### ------------------ Section for LEFT SIDE of chat ------------------ ###
        # Side-Frame Left
        self.FrameLeft = tk.Frame(self.frame_main, 
                                   bg="green",
                                   borderwidth=1,
                                   highlightbackground="magenta", 
                                   highlightthickness=6,
                                   height=600,
                                   width=400)
        self.FrameLeft.pack(side=tk.LEFT,expand=False,fill=tk.Y)
        self.FrameLeft.propagate(0)

        # Button for exiting program
        self.EXIT_Button = tk.Button(self.FrameLeft, text="EXIT",command=lambda : [self.thread1.exit(),self.Main_Window.withdraw(),Page_Login()], bg="#211A52", fg = "white")
        self.EXIT_Button.pack(side=tk.BOTTOM)

        # Frame for "Chat Menu" - Includes Add User, Create Group and Add to Group
        self.FrameChatMenu = tk.Frame(self.FrameLeft, 
                                   bg="green",
                                   borderwidth=1,
                                   highlightbackground="magenta", 
                                   highlightthickness=6)
        self.FrameChatMenu.pack(side=tk.TOP,expand=False,fill="both")

        # Add user, create group and add to group buttons
        self.AddUser_Button = tk.Button(self.FrameChatMenu, text="Add User ",font=('arial',10,'bold'),height=1, command=lambda : [], bg="yellow", fg = "black", borderwidth=1,relief="raised")
        self.AddUser_Button.pack(side=tk.LEFT,fill=tk.X, expand=True,padx=1.5, pady=1.5)

        self.CreateGroup_Button = tk.Button(self.FrameChatMenu, text="Create Group",font=('arial',10,'bold'),height=1,command=lambda : [], bg="white", fg = "black", borderwidth=1,relief="raised")
        self.CreateGroup_Button.pack(side=tk.LEFT,fill=tk.X, expand=True, padx=1.5, pady=1.5)

        self.AddUserGroup_Button = tk.Button(self.FrameChatMenu, text="Add to Group",font=('arial',10,'bold'),height=1,command=lambda : [], bg="magenta", fg = "black", borderwidth=1,relief="raised")
        self.AddUserGroup_Button.pack(side=tk.LEFT,fill=tk.X, expand=True, padx=1.5, pady=1.5)




        ########################### Main Chat Menu Frames ###############################
        # Frame for holding Friend List and Group List
        self.FrameFriendGroupList = tk.Frame(self.FrameLeft, 
                                   bg="green",
                                   borderwidth=1,
                                   highlightbackground="magenta", 
                                   highlightthickness=6)
        self.FrameFriendGroupList.pack(side=tk.TOP,expand=True,fill="both")
        self.FrameFriendGroupList.propagate(1)

        # Frame for Friend List on the left side
        self.FrameFriendListLeft = tk.Frame(self.FrameFriendGroupList, 
                                   bg="green",
                                   borderwidth=1,
                                   highlightbackground="black", 
                                   highlightthickness=6)
        self.FrameFriendListLeft.pack(side=tk.LEFT,expand=True,fill="both")
        self.FrameFriendListLeft.propagate(1)

        # Frame for Group List on the right side
        self.FrameGroupListRight = tk.Frame(self.FrameFriendGroupList, 
                                   bg="green",
                                   borderwidth=1,
                                   highlightbackground="yellow", 
                                   highlightthickness=6,
                                   height=100,
                                   width=100)
        self.FrameGroupListRight.pack(side=tk.RIGHT,expand=True,fill="both")
        self.FrameGroupListRight.propagate(1)
        ########################### Main Chat Menu Frames ###############################

        # Friend list label on the left side
        self.FriendList_Label = tk.Label(self.FrameFriendListLeft,text="Friend List", bg="green", fg="white",font=('arial',10,'bold'), borderwidth=1)
        self.FriendList_Label.pack(side=tk.TOP,fill="both",expand=False)

        # Frame for Friend List on the left side
        self.FrameFriendList = tk.Frame(self.FrameFriendListLeft, 
                                   bg="yellow",
                                   borderwidth=1,
                                   highlightbackground="blue", 
                                   highlightthickness=6,
                                   width=1)
        self.FrameFriendList.pack(side=tk.TOP,expand=True,fill="both")
        self.FrameFriendList.propagate(1)

        # Canvas to hold frame
        self.CanvasFriendList = tk.Canvas(self.FrameFriendList,width=1)
        self.CanvasFriendList.pack(side=tk.LEFT,fill="both",expand=True)
        # Scrollbar to canvas
        self.ScrollBarCanvasFriendList = tk.Scrollbar(self.FrameFriendList, orient="vertical", command=self.CanvasFriendList.yview)
        self.ScrollBarCanvasFriendList.pack(side=tk.RIGHT,fill=tk.Y)
        # Configure canvas
        self.CanvasFriendList.configure(yscrollcommand=self.ScrollBarCanvasFriendList.set)
        self.CanvasFriendList.bind("<Configure>",lambda e: self.CanvasFriendList.configure(scrollregion=self.CanvasFriendList.bbox("all")))
        # Frame inside canvas holding friend buttons
        self.FrameFriendListCanvas = tk.Frame(self.CanvasFriendList)
        self.CanvasFriendList.create_window((35,10),window=self.FrameFriendListCanvas,anchor="nw")

        # Method call to LoadUserFriends() - Loads all user friends in to canvas
        self.LoadUserFriends()


        #for buttons in range (100):
        #   test = tk.Button(self.FrameFriendListCanvas, text=f"Button {buttons}")
        #   test.pack(pady=5)

        ##################################################################################

        # Group list label on the rightside
        self.GroupList_Label = tk.Label(self.FrameGroupListRight,text="Group List", bg="green", fg="white",font=('arial',10,'bold'), borderwidth=1)
        self.GroupList_Label.pack(side=tk.TOP,fill="both",expand=False)

        # Frame for Group List on the right side
        self.FrameGroupList = tk.Frame(self.FrameGroupListRight, 
                                   bg="orange",
                                   borderwidth=1,
                                   highlightbackground="red", 
                                   highlightthickness=6,
                                   width=150)
        self.FrameGroupList.pack(side=tk.TOP,expand=True,fill="both")
        self.FrameGroupList.propagate(0)

        # Canvas to hold frame
        self.CanvasGroupList = tk.Canvas(self.FrameGroupList,width=1)
        self.CanvasGroupList.pack(side=tk.LEFT,expand=True,fill="both")
        # Scrollbar to canvas
        self.ScrollBarCanvasGroupList = tk.Scrollbar(self.FrameGroupList, orient="vertical", command=self.CanvasGroupList.yview)
        self.ScrollBarCanvasGroupList.pack(side=tk.RIGHT,fill=tk.Y)
        # Configure canvas
        self.CanvasGroupList.configure(yscrollcommand=self.ScrollBarCanvasGroupList.set)
        self.CanvasGroupList.bind("<Configure>",lambda e: self.CanvasGroupList.configure(scrollregion=self.CanvasGroupList.bbox("all")))
        # Frame inside canvas holding friend buttons
        self.FrameGroupListCanvas = tk.Frame(self.CanvasGroupList)
        self.CanvasGroupList.create_window((65,10),window=self.FrameGroupListCanvas,anchor="nw")

        #for buttons in range (100):
        #   test = tk.Button(self.FrameGroupListCanvas, text=f"Button {buttons}")
        #   test.pack(pady=5)

        ### ------------------ Section for LEFT SIDE of chat ------------------ ###


        ### ------------------ Section for RIGHT SIDE of chat ------------------ ###
        # Side-Frame Right
        self.FrameRight = tk.Frame(self.frame_main, 
                                   bg="green",
                                   borderwidth=1,
                                   highlightbackground="magenta", 
                                   highlightthickness=6,
                                   height=600,
                                   width=500)
        self.FrameRight.pack(side=tk.RIGHT,expand=True,fill="both")
        self.FrameRight.propagate(0)

        self.chat_title = tk.Label(self.FrameRight, 
                                   text="Chat Window!", 
                                   font=('Arial',18,'bold'),
                                   bg="black", fg="white")
        self.chat_title.pack(side=tk.TOP,fill=tk.X, expand=False)

        self.FrameChatWindow = tk.Frame(self.FrameRight, 
                                   bg="green",
                                   borderwidth=1,
                                   highlightbackground="blue", 
                                   highlightthickness=6)
        self.FrameChatWindow.pack(side=tk.LEFT,expand=True,fill="both")

        self.Main_Window.mainloop()
        ### ------------------ Section for RIGHT SIDE of chat ------------------ ###
      
        ### ------------------ Section for main chat methods ------------------ ###    
    def on_closing(self):
        self.thread1.exit()
        exit()
    def Active_Window(self, method):
        print()
          
    def LoadUserFriends(self):
        # When logged in, connect to server and load USER_DATA into chat menu window
        # Make added user clickable and when clicked connect to chat server and add chat window to chat window frame
        
        self.LoadUserFriendsSocket = socket(AF_INET,SOCK_STREAM)
        self.LoadUserFriendsSocket.connect((SERVER_IP, LOAD_USER_PORT))
        
        # Data structure: [GroupName,UserToAdd,LoginName,CHECKDATA]
        self.Data_string = pickle.dumps(["","",stupidusername,"Load_Users"])
        self.LoadUserFriendsSocket.send(self.Data_string)
        
        self.Data_UserFriends = self.LoadUserFriendsSocket.recv(BUFFER_SIZE)
        self.Data_UserFriends = pickle.loads(self.Data_UserFriends)
        print("Users loaded from server: {}".format(self.Data_UserFriends))
        
        count = 0
        for x in self.Data_UserFriends:
            self.UserLoaded_Button = tk.Button(self.FrameFriendListCanvas,text="{}".format(self.Data_UserFriends[count]), bg="black", fg="white",font=('arial',10,'bold'), borderwidth=1,anchor="center", command=lambda name=self.Data_UserFriends[count]:self.UserChatWindow(name))
            
            name = self.Data_UserFriends[count]
            print("This is name: {}".format(name))
            print("Username of friends: {}".format(self.Data_UserFriends[count]))  
            self.UserLoaded_Button.pack(pady=3)            
            count += 1
            
    def UserChatWindow(self,friend):
      global userfriend
      userfriend = friend
      
      self.tkraise()
      
      self.UserChatWindowFrame = tk.Frame(self.FrameChatWindow, bg="white",highlightbackground="red", highlightthickness=6 )
      self.UserChatWindowFrame.pack(side=tk.TOP,fill='both',expand=True)  
      self.userchatLabel = tk.Label(self.UserChatWindowFrame,text="{}'s Chat".format(friend),bg="magenta", fg="black",font=('arial',14,'bold'), borderwidth=1)
      self.userchatLabel.pack(side=tk.TOP,expand=False,anchor='center',pady=3) 
      
      self.UserChatFrame = tk.Frame(self.UserChatWindowFrame, bg="yellow",highlightbackground="green", highlightthickness=6,borderwidth=10,height=400,width=400)
      self.UserChatFrame.pack(side=tk.TOP)
      self.UserChatFrame.pack_propagate(0)
      
      self.chat_box = tk.Text(self.UserChatFrame, wrap = tk.WORD)
      self.chat_box.configure(state="disabled")
      self.chat_box.pack(fill='both',expand=True)
      self.chat_box.pack_propagate(0)
      
      self.stored_logs = []
      self.ReadLogs("single","")
      self.stored_logs.remove("STOP!")
      #print("logs: ", logs)
      self.chat_box.configure(state="normal")
      #self.chat_box.insert("end","\n"+logs) ORIGINAL
      for i in self.stored_logs:
          self.chat_box.insert("end",i)
      self.chat_box.configure(state="disabled")
      self.chat_box.see("end")
      
      scrollbar = tk.Scrollbar(self.chat_box,command=self.chat_box.yview)
      scrollbar.pack(side=tk.RIGHT,fill=tk.Y)
      self.chat_box['yscrollcommand'] = scrollbar.set
      
      self.input_field = tk.Entry(self.UserChatWindowFrame,width=64,borderwidth=5,highlightbackground="black", highlightthickness=1)
      self.input_field.pack(side=tk.TOP,pady=1)
      self.input_field.bind("<Return>",self.key_sendmsg)
      self.input_field.focus()
      
      # set structure: [chatboxSINGLE, inputSINGLE, chatboxGROUP, inputGROUP]
      # set structure: [chatboxSINGLE, chatboxGROUP, state]
      self.thread1.set(self.chat_box,self.input_field, "","")
      self.thread2.set(self.chat_box,"","SINGLE")
      
      self.button = ttk.Button(self.UserChatWindowFrame, text='Send')
      self.button['command'] = self.send_message_button
      self.button.pack()
      
       
    def ReadLogs(self,state,groupname):
        global userfriend
        GroupOrSingle = state
        groupName = groupname
        self.storeddata = []
        self.data = ""

        self.logssocket = socket(AF_INET,SOCK_STREAM)
        self.logssocket.connect((SERVER_IP, LOGS_PORT))

        if GroupOrSingle == "single":
            # Data structure: [usernameLogin, usernameFriend, groupname]
            self.data_string = pickle.dumps([stupidusername, userfriend])
            self.logssocket.send(self.data_string)
          
        if GroupOrSingle == "group":
            # Data structure: [usernameLogin, usernameFriend, groupname]
            self.data_string = pickle.dumps([stupidusername, groupName])
            self.logssocket.send(self.data_string)
      
        while True:
            self.data = self.logssocket.recv(BUFFER_SIZE)
            self.data = pickle.loads(self.data)
            self.stored_logs.append(self.data)
            if "STOP!" in self.stored_logs:
                self.logssocket.close()
                break
            
    def key_sendmsg(self, event):
        self.send_message_button() 
        self.input_field.delete(0, 'end')
         
    def send_message_button(self):
        self.thread1.send()
        self.input_field.delete(0, 'end')
         
         
         
         
         
         
         
         
         
         
         
class SendData():
    def __init__(self,tcp_socket, user):
        self.ds=tcp_socket
        self.uu=user
    def send(self):
        global userfriend
        send_data = self.input.get()
        print("SINGLE - send data: {}".format(send_data))
        print(len(send_data))
        if len(send_data) > 1:
            # Data structure: [user, msg, msgtofriend, groupname, keyword]
            chat_data=[self.uu,send_data, userfriend,"","SINGLE"]
            chat_string = pickle.dumps(chat_data)
            self.ds.send(chat_string)
            self.chat.configure(state="normal")
            self.chat.insert("end","\nYOU: {}\n".format(send_data))
            self.chat.configure(state="disabled")
            self.chat.see("end") 
                
    def send_to_group(self,groupname):
        global GroupListFriends
        send_data = self.input2.get()
        print("GROUP - send data: {}".format(send_data))
        print(len(send_data))
        if len(send_data) > 1:
            # Data structure: [user, msg, msgtofriend, groupname, keyword]
            chat_data=[self.uu,send_data, GroupListFriends, groupname, "GROUP"]
            chat_string = pickle.dumps(chat_data)
            self.ds.send(chat_string)
            self.chatgroup.configure(state="normal")
            self.chatgroup.insert("end","\nYOU: {}\n".format(send_data))
            self.chatgroup.configure(state="disabled")
            self.chatgroup.see("end")
                      
    def exit(self):
            chat_data=[self.uu, "EEXIT","","",""]
            chat_string = pickle.dumps(chat_data)
            self.ds.send(chat_string)
            print("Connection closed.")
            
    # set structure: [chatboxSINGLE, inputSINGLE, chatboxGROUP, inputGROUP, state]
    def set(self, chat_box,input,chat_box_group,input2):
        self.chat = chat_box
        self.input = input
        self.chatgroup = chat_box_group
        self.input2 = input2


class ReceiveData(threading.Thread):
    def __init__(self,tcp_socket, event):
        threading.Thread.__init__(self)
        self.ds=tcp_socket
        self.event = event
    def run(self):
        while True:
            recv_string = self.ds.recv(BUFFER_SIZE)
            recv_data = pickle.loads(recv_string)
            print("recv_data:", recv_data)
            if recv_data == "CLOSE CONN":
                break
            if self.state == "SINGLE":
                print("Writing to SINGLE chat window...")
                if userfriend == recv_data[0]:
                    self.chat.configure(state="normal")
                    msg = "{}: {}".format(recv_data[0],recv_data[1])
                    print("====================")
                    print("msg: {}\nFrom: {}".format(recv_data[1],recv_data[0]))
                    print("====================")
                    self.chat.insert("end","\n"+msg+"\n")
                    self.chat.configure(state="disabled")
                    self.chat.see("end")
            if self.state == "GROUP":
                print("Writing to GROUP chat window...")
                if userfriend == recv_data[0]:
                    self.chatgroup.configure(state="normal")
                    msg = "{}: {}".format(recv_data[0],recv_data[1])
                    print("====================")
                    print("msg: {}\nFrom: {}".format(recv_data[1],recv_data[0]))
                    print("====================")
                    self.chatgroup.insert("end","\n"+msg+"\n")
                    self.chatgroup.configure(state="disabled")
                    self.chatgroup.see("end")
    # set structure: [chatboxSINGLE, chatboxGROUP, state]
    def set(self,chat_box,chat_box_group,state):
        self.state = state
        self.chat = chat_box
        self.chatgroup = chat_box_group  



if __name__=="__main__":
   #root = tk.Tk()
   #root.withdraw()
   #root = tk.Toplevel()
   #root.geometry("300x250")
   #root.title("TEST!")
   
   #root = Main_View2()
   #root.add_page("Page_Login",Page_Login)
   #root.show_frame("Page_Login")
   
   Page_Login()
   #root.tkraise()
   #test = PersistentLogs()
   #test.WriteToLog(test,"LORT")
   #test.ReadLog(test)
   
   #root = Page_Group_Chat()
   
   #root.add_page("Page_Group_Chat",Page_Group_Chat)
   #root.show_frame("Page_Group_Chat")
   #root.mainloop()