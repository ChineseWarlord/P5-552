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
from tkinter import PhotoImage, ttk
from socket import *
import threading
import time
import pickle
import os
import sys
import select
from tkinter import messagebox

SERVER_IP = "127.0.0.1"
SERVER_PORT = 1234
VERIFY_PORT = 2001
LOGS_PORT = 2005
LOAD_USER_PORT = 1000
BUFFER_SIZE = 10000


Active_Window_AddUser = False
Active_Window_CreateGroup = False
Active_Window_AddToGroup = False
active_chat = False


class Page_Login(tk.Frame):
    def __init__(self):
        self.root = tk.Tk()
        self.root.withdraw()
        #self.tkraise()
      
        #tk.Frame.__init__(self)
      
      
        self.Main_Window = tk.Toplevel(self.root)
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
        stopyourself = self.log_in()
        if stopyourself == "no":
            print("no")
        else:
            self.Main_Window.withdraw()
        
    def clear_entry(self):
        self.username_entry_login.delete(0, 'end')
        self.pwd_entry_login.delete(0, 'end')
     
    def register_user(self):
        self.Main_Window.withdraw()
        self = Page_UserRegister()
        #root.add_page("Page_UserRegister",Page_UserRegister) 
                    
    def log_in(self):
        print("USER: "+self.UsernameLogin.get())
        print("PASS: "+self.PasswordLogin.get())
        self.LoginSocket = socket(AF_INET,SOCK_STREAM)
        self.LoginSocket.connect((SERVER_IP, VERIFY_PORT))
        data_User = self.UsernameLogin.get()
        data_Pass = self.PasswordLogin.get()
    
        print("data_User: {}\ndata_Pass: {}".format(data_User, data_Pass))

        data_Check = "userlogin"
        self.data_string = pickle.dumps([data_User, data_Pass, data_Check,""])
        self.LoginSocket.send(self.data_string)
        self.data = self.LoginSocket.recv(BUFFER_SIZE)
        self.data = pickle.loads(self.data)
        print("From Server1: {}".format(self.data))
        self.data = self.data.split('#')
        print("From Server2: {}".format(self.data))

        if self.data[0] == "YES LOGIN!":
            self.AddUsersSocket_FRIEND = socket(AF_INET,SOCK_STREAM)
            self.AddUsersSocket_GROUP = socket(AF_INET,SOCK_STREAM)
            self.AddUsersSocket_TOGROUP = socket(AF_INET,SOCK_STREAM)
    
            self.LoadingSocket_FRIENDS = socket(AF_INET,SOCK_STREAM)
            self.LoadingSocket_GROUP = socket(AF_INET,SOCK_STREAM)
            self.LoadingSocket_GROUPCHAT = socket(AF_INET,SOCK_STREAM)
            
            self.AddUsersSocket_FRIEND.connect((SERVER_IP,VERIFY_PORT))
            self.AddUsersSocket_GROUP.connect((SERVER_IP,VERIFY_PORT))
            self.AddUsersSocket_TOGROUP.connect((SERVER_IP,VERIFY_PORT))
            
            self.LoadingSocket_FRIENDS.connect((SERVER_IP,LOAD_USER_PORT))
            self.LoadingSocket_GROUP.connect((SERVER_IP,LOAD_USER_PORT))
            self.LoadingSocket_GROUPCHAT.connect((SERVER_IP,LOAD_USER_PORT))
            
            self.ReadLogsSocket = socket(AF_INET,SOCK_STREAM)
            self.ReadLogsSocket.connect((SERVER_IP,LOGS_PORT))
            
            
        
            #print("OK LOGIN :)")
            #print(f"Username: {self.UsernameLogin.get()} \n" + f"Password: {self.PasswordLogin.get()}")
            self.title_label.config(text="Awesome Chat Program!", fg="black", font=('Arial',18,'bold'))
            
            self.USERNAMELOGIN = self.data[1]
            
            
            self.clear_entry()
            self.UserChatSocket1 = socket(AF_INET,SOCK_STREAM)
            self.UserChatSocket1.connect((SERVER_IP, SERVER_PORT))
            connect_list=["CONNECT",data_User]
            #print("connect_list: ",connect_list)
            data_string = pickle.dumps(connect_list)
            self.UserChatSocket1.send(data_string)
            data2 = self.UserChatSocket1.recv(BUFFER_SIZE)
            data_list = pickle.loads(data2)
            #print("From server data: {}".format(data_list))
            #print("From server   OK: {}".format(data_list[0]))
            if data_list[0]=="OK":
                NEW_PORT=data_list[3]
                print(NEW_PORT)
                self.UserChatSocket2 = socket(AF_INET,SOCK_STREAM)
                self.UserChatSocket2.connect((SERVER_IP, NEW_PORT))
                self.thread1 = SendData(self.UserChatSocket2,self.USERNAMELOGIN)
                self.thread2 = ReceiveData(self.UserChatSocket2)
                self.thread2.start()
                #root.add_page("Page_Chat",Page_Chat, self.thread1, self.thread2, self.UserChatSocket1, self.UserChatSocket2)
                self.Main_Window.withdraw()
                Page_Chat(self.USERNAMELOGIN,self.thread1, self.thread2, self.UserChatSocket1, self.UserChatSocket2, self.AddUsersSocket_FRIEND,self.AddUsersSocket_GROUP,self.AddUsersSocket_TOGROUP,self.ReadLogsSocket,self.LoadingSocket_FRIENDS,self.LoadingSocket_GROUP,self.LoadingSocket_GROUPCHAT)
                #self.LoginSocket.close()
            else:
                print("Reply from server: server is full. Retry later.")
        if self.data[0] == "NO LOGIN!":
            #print("NOT LOGIN :(")
            self.title_label.config(text="Incorrect username and/or password!", fg="red", font=('arial',10,'bold'))
            self.clear_entry()
            #print("Login socket status: {}".format(self.se))
            stopyourself = "no"
            return  stopyourself 
        
        
class Page_UserRegister(tk.Frame):
    def __init__(self):
        self.Main_Window = tk.Toplevel()
        self.Main_Window.protocol("WM_DELETE_WINDOW", self.on_closing)
        self.Main_Window.title("User Registration")
        self.Main_Window.resizable(width=False, height=False)
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
            self.se.close()
            print("Register socket status: {}".format(self.se))            


class Page_Chat(LoadingChatData,tk.Frame):
    def __init__(self,UsernameLogin,thread1,thread2, socket1, socket2, socket3, socket4, socket5,socket6,socket7,socket8,socket9):
        # Same as creating root window, withdrawing it, and running mainloop()
        tk.Frame.__init__(self)

        self.UsernameLogin = UsernameLogin
        self.thread1 = thread1
        self.thread2 = thread2
        self.socketlogin = socket1
        self.socketchat = socket2
        
        self.AddUsersSocket_FRIEND = socket3
        self.AddUsersSocket_GROUP = socket4
        self.AddUsersSocket_TOGROUP = socket5
        
        self.LoadingSocket_FRIENDS = socket6
        self.LoadingSocket_GROUP = socket7
        self.LoadingSocket_GROUPCHAT = socket8
        
        self.ReadLogsSocket = socket9
        
        self.UserFriend = ""
        self.groupname = ""
        self.GroupListFriends = []

        self.thread3 = LoadingChatData(self.UsernameLogin,self.AddUsersSocket_FRIEND,self.AddUsersSocket_GROUP,self.FrameFriendListCanvas,self.FrameGroupListCanvas)
        self.thread3.join()
        
        self.AddingChatData = AddingChatData(self.UsernameLogin, self.LoadingSocket_FRIENDS,self.LoadingSocket_GROUP,self.LoadingSocket_GROUPCHAT)

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
                                   text=f"Welcome {self.UsernameLogin}!", 
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
        self.EXIT_Button = tk.Button(self.FrameLeft, text="EXIT",command=lambda : [self.thread1.exit(),self.Main_Window.withdraw(),self.reset_active_window(),Page_Login()], bg="#211A52", fg = "white")
        self.EXIT_Button.pack(side=tk.BOTTOM)

        # Frame for "Chat Menu" - Includes Add User, Create Group and Add to Group
        self.FrameChatMenu = tk.Frame(self.FrameLeft, 
                                   bg="green",
                                   borderwidth=1,
                                   highlightbackground="magenta", 
                                   highlightthickness=6)
        self.FrameChatMenu.pack(side=tk.TOP,expand=False,fill="both")

        # Add user, create group and add to group buttons
        self.AddUser_Button = tk.Button(self.FrameChatMenu, text="Add User ",font=('arial',10,'bold'),height=1, command=lambda : [self.Active_Window("Add users")], bg="yellow", fg = "black", borderwidth=1,relief="raised")
        self.AddUser_Button.pack(side=tk.LEFT,fill=tk.X, expand=True,padx=1.5, pady=1.5)

        self.CreateGroup_Button = tk.Button(self.FrameChatMenu, text="Create Group",font=('arial',10,'bold'),height=1,command=lambda : [self.Active_Window("Create group")], bg="white", fg = "black", borderwidth=1,relief="raised")
        self.CreateGroup_Button.pack(side=tk.LEFT,fill=tk.X, expand=True, padx=1.5, pady=1.5)

        self.AddUserGroup_Button = tk.Button(self.FrameChatMenu, text="Add to Group",font=('arial',10,'bold'),height=1,command=lambda : [self.Active_Window("Add to group")], bg="magenta", fg = "black", borderwidth=1,relief="raised")
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
        self.FriendList_Label = tk.Label(self.FrameFriendListLeft,text="Friends List", bg="green", fg="white",font=('arial',10,'bold'), borderwidth=1)
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
        self.FrameFriendListCanvas.bind("<Configure>", self.reset_scrollregion)
        self.CanvasFriendList.create_window((25,10),window=self.FrameFriendListCanvas,anchor="nw")

        # Method call to LoadUserFriends() - Loads all user friends into canvas
        self.LoadUserFriends()

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
        self.FrameGroupListCanvas.bind("<Configure>", self.reset_scrollregion)
        self.CanvasGroupList.create_window((25,10),window=self.FrameGroupListCanvas,anchor="nw")
        
        # Method call to LoadGroups() - Loads all groups associated to user into canvas
        self.LoadGroups()

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
    def reset_scrollregion(self,event):
        self.CanvasFriendList.configure(scrollregion=self.CanvasFriendList.bbox("all"))
        self.CanvasGroupList.configure(scrollregion=self.CanvasGroupList.bbox("all"))
      
    def on_closing(self):
        try:
            self.thread1.exit()
        except:
            exit()
        exit()
    
    def Thread_To_Keep_Loading_Groups(self): # DET HER SKAL GØRES!
        print()    
        ### ------------------ Section for main chat methods ------------------ ###    
    def reset_active_window(self):
        global Active_Window_AddUser
        global Active_Window_CreateGroup
        global Active_Window_AddToGroup
        Active_Window_AddUser = False
        Active_Window_CreateGroup = False
        Active_Window_AddToGroup = False
        
    def Remove_Windows(self, window):
        if window == "User chat window":
            for widget in self.FrameChatWindow.winfo_children():
                if isinstance(widget,tk.Frame):
                    #print("removechatwindow widgets: {}".format(widget))
                    widget.destroy()
        if window == "Add user window":
            self.chat_title.configure(text="Chat Window!", 
                                   font=('Arial',18,'bold'),
                                   bg="black", fg="white")
            for widget in self.FrameChatWindow.winfo_children():
                if isinstance(widget,tk.Frame):
                    #print("removechatwindow widgets: {}".format(widget))
                    widget.destroy()
        if window == "Create group window":
            self.chat_title.configure(text="Chat Window!", 
                                   font=('Arial',18,'bold'),
                                   bg="black", fg="white")
            for widget in self.FrameChatWindow.winfo_children():
                if isinstance(widget,tk.Frame):
                    #print("removechatwindow widgets: {}".format(widget))
                    widget.destroy()
        if window == "Add to group window":
            self.chat_title.configure(text="Chat Window!", 
                                   font=('Arial',18,'bold'),
                                   bg="black", fg="white")
            for widget in self.FrameChatWindow.winfo_children():
                if isinstance(widget,tk.Frame):
                    #print("removechatwindow widgets: {}".format(widget))
                    widget.destroy()
    
    def Clear_Entry(self,window):
        if window == "Add users":
            self.Usernameadd_entry.delete(0,'end')
        if window == "Create group":
            self.usernameaddGroup_entry.delete(0,'end')
        
    def Key_Pressed(self,window):
        if window == "Add users":
            self.addUserFriend()
            self.Clear_Entry("Add users")
        if window == "Create group":
            self.addUserGroup()
            self.Clear_Entry("Create group")
        if window == "Add to group":
            self.addUserToGroup()
            self.Clear_Entry("Add to group")
            
    def Update_Friendslist(self):
        for widget in self.FrameFriendListCanvas.winfo_children():
            if isinstance(widget,tk.Button):
                widget.destroy()
    def Update_Grouplist(self):
        for widget in self.FrameGroupListCanvas.winfo_children():
            if isinstance(widget,tk.Button):
                widget.destroy()
                
    def Active_Window(self, method):
        global Active_Window_AddUser
        global Active_Window_CreateGroup
        global Active_Window_AddToGroup
        
        if method == "Add users":
            if Active_Window_AddUser == False:
                print("Opening add users window")
                self.Remove_Windows("Add user window")
                self.AddUser_Window()
                
        if method == "Create group":
            if Active_Window_CreateGroup == False:
                print("Opening create group window")
                self.Remove_Windows("Create group window")
                self.CreateGroupChat()
                
        if method == "Add to group":
            if Active_Window_AddToGroup == False:
                print("Opening add to group window")
                self.Remove_Windows("Add to group window")
                self.AddToGroup()
                
    def AddUser_Window(self):
        self.chat_title.configure(text="Add Users", 
                                   font=('Arial',18,'bold'),
                                   bg="black", fg="white")
        self.FrameAddUserMain = tk.Frame(self.FrameChatWindow, 
                                   bg="white",
                                   borderwidth=1,
                                   highlightbackground="yellow", 
                                   highlightthickness=6)
        self.FrameAddUserMain.pack(anchor="center",fill=None,expand=True)
        
        self.UsernameAdd = tk.StringVar()
        
        self.FrameAddUserSub = tk.Frame(self.FrameAddUserMain, borderwidth=5, bg="red",
                                        width=500,
                                        height=500)
        self.FrameAddUserSub.pack(side=tk.TOP,fill='both',expand=False)
        self.FrameAddUserSub.propagate(1)
        
        self.FrameAddUser_Label = tk.Frame(self.FrameAddUserSub, borderwidth=2, bg="Yellow")
        self.FrameAddUser_Label.pack(side=tk.TOP)
        
        self.FrameAddUser_Entry = tk.Frame(self.FrameAddUserSub, borderwidth=5, bg="Blue")
        self.FrameAddUser_Entry.pack(side=tk.TOP)
        
        self.FrameAddUser_Button = tk.Frame(self.FrameAddUserSub, borderwidth=5, bg="Green")
        self.FrameAddUser_Button.pack()
        
        self.AddUser_label = tk.Label(self.FrameAddUser_Label,text="Add user")
        self.AddUser_label.pack(side=tk.LEFT,padx=5, pady=5)
        self.Username_label = tk.Label(self.FrameAddUser_Entry,text="Username:")
        self.Username_label.pack(side=tk.LEFT,padx=5, pady=5)
        
        self.Usernameadd_entry = tk.Entry(self.FrameAddUser_Entry, width=35,textvariable=self.UsernameAdd)
        self.Usernameadd_entry.pack(side=tk.RIGHT)
        self.Usernameadd_entry.bind("<Return>",lambda event, a = "Add users":self.Key_Pressed(a))
        self.Usernameadd_entry.focus()
            
        self.AddUser_Button = tk.Button(self.FrameAddUser_Button, text="Add user",command=lambda : [AddingChatData.addUserFriend(self.UsernameAdd.get(),self.AddUser_label,self.usernameGroup_tryadd_label,self.usernameToGroup_tryadd_label,self.usernameGroup_Menu,self.AddUsernameToGroup_Menu,self.Data_UserFriends,self.Data_Groups,self.GroupNameAddGroup),self.Clear_Entry("Add users")], bg="#211A52", fg = "white")
        self.AddUser_Button.pack(side=tk.LEFT)
        self.AddUser_EXIT_Button = tk.Button(self.FrameAddUser_Button, text="Return",command=lambda : [self.Remove_Windows("Add user window")], bg="#211A52", fg = "white")
        self.AddUser_EXIT_Button.pack(side=tk.RIGHT)
 
    def UserChatWindow(self,friend):
      self.UserFriend = friend
      
      #self.tkraise()
      
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
      self.thread1.set(self.chat_box,self.input_field, "","",self.UserFriend)
      self.thread2.set(self.chat_box,"","SINGLE",self.UserFriend,self.groupname)
      
      self.button = ttk.Button(self.UserChatWindowFrame, text='Send')
      self.button['command'] = self.send_message_button
      self.button.pack()
    
    def CreateGroupChat(self):
        self.chat_title.configure(text="Create Group Chat", 
                                   font=('Arial',18,'bold'),
                                   bg="black", fg="white")
        self.FrameCreateGroupMain = tk.Frame(self.FrameChatWindow, 
                                   bg="white",
                                   borderwidth=1,
                                   highlightbackground="yellow", 
                                   highlightthickness=6)
        self.FrameCreateGroupMain.pack(anchor="center",fill=None,expand=True)
        
        self.GroupNameAddGroup = tk.StringVar()
        self.UsernameAddToGroup = tk.StringVar()
        
        self.FrameaddGroup = tk.Frame(self.FrameCreateGroupMain, borderwidth=5, bg="red")
        self.FrameaddGroup.pack(side=tk.TOP,fill='both',expand=True)
        
        self.FrameaddGroup_Label = tk.Frame(self.FrameaddGroup, borderwidth=2, bg="Yellow")
        self.FrameaddGroup_Label.pack(side=tk.TOP)
        
        self.FrameaddGroup_Group = tk.Frame(self.FrameaddGroup, borderwidth=5, bg="Blue")
        self.FrameaddGroup_Group.pack(side=tk.TOP)
        
        self.FrameAddGroup_Username = tk.Frame(self.FrameaddGroup, borderwidth=5, bg="Blue")
        self.FrameAddGroup_Username.pack(side=tk.TOP)
        
        self.FrameaddGroup_Button = tk.Frame(self.FrameaddGroup, borderwidth=5, bg="Green")
        self.FrameaddGroup_Button.pack()
        
        self.usernameGroup_tryadd_label = tk.Label(self.FrameaddGroup_Label,text="Create a new group")
        self.usernameGroup_tryadd_label.pack(side=tk.TOP,padx=5, pady=5)
    
        self.usernameGroup_label = tk.Label(self.FrameaddGroup_Group,text="Group name:")
        self.usernameGroup_label.pack(side=tk.LEFT,padx=5, pady=5)
        self.usernameaddGroup_entry = tk.Entry(self.FrameaddGroup_Group, width=35,textvariable=self.GroupNameAddGroup)
        self.usernameaddGroup_entry.pack(side=tk.RIGHT)
        self.usernameaddGroup_entry.bind("<Return>",lambda event, a = "Create group":self.Key_Pressed(a))
        self.usernameaddGroup_entry.focus()
        
        self.Add_User_ButtonGroup = tk.Button(self.FrameaddGroup_Button, text="Create group",command=lambda : [self.addUserGroup()], bg="#211A52", fg = "white")
        self.Add_User_ButtonGroup.pack(side=tk.LEFT)
        
        self.Add_User_EXIT_ButtonGroup = tk.Button(self.FrameaddGroup_Button, text="EXIT",command=lambda : [self.Remove_Windows("Create group window")], bg="#211A52", fg = "white")
        self.Add_User_EXIT_ButtonGroup.pack(side=tk.RIGHT)
 
    def AddToGroup(self):
        self.chat_title.configure(text="Add User to Group Chat", 
                                   font=('Arial',18,'bold'),
                                   bg="black", fg="white")
        self.FrameAddToGroupMain = tk.Frame(self.FrameChatWindow, 
                                   bg="white",
                                   borderwidth=1,
                                   highlightbackground="yellow", 
                                   highlightthickness=6)
        self.FrameAddToGroupMain.pack(anchor="center",fill=None,expand=True)
        
        self.GroupNameAddToGroup = tk.StringVar()
        self.UsernameAddToGroup = tk.StringVar()
        
        self.FrameaddToGroup = tk.Frame(self.FrameAddToGroupMain, borderwidth=5, bg="red")
        self.FrameaddToGroup.pack(side=tk.TOP,fill='both',expand=True)
        
        self.FrameaddToGroup_Label = tk.Frame(self.FrameaddToGroup, borderwidth=2, bg="Yellow")
        self.FrameaddToGroup_Label.pack(side=tk.TOP)
        
        self.FrameaddToGroup_Group = tk.Frame(self.FrameaddToGroup, borderwidth=5, bg="Blue")
        self.FrameaddToGroup_Group.pack(side=tk.TOP)
        
        self.FrameAddToGroup_Username = tk.Frame(self.FrameaddToGroup, borderwidth=5, bg="Blue")
        self.FrameAddToGroup_Username.pack(side=tk.TOP)
        
        self.FrameaddToGroup_Button = tk.Frame(self.FrameaddToGroup, borderwidth=5, bg="Green")
        self.FrameaddToGroup_Button.pack()
        
        self.usernameToGroup_tryadd_label = tk.Label(self.FrameaddToGroup_Label,text="Add a user to your group")
        self.usernameToGroup_tryadd_label.pack(side=tk.TOP,padx=5, pady=5)
        
        
        self.usernameGroup_label = tk.Label(self.FrameaddToGroup_Group,text="Group name:")
        self.usernameGroup_label.pack(side=tk.LEFT,padx=5, pady=5)
        self.usernameGroup_Menu = ttk.Combobox(self.FrameaddToGroup_Group, value=self.Data_Groups,width=35, state="readonly")
        self.usernameGroup_Menu.set("Choose a group")
        self.usernameGroup_Menu.bind("<<ComboboxSelected>>",self.get_groupname)
        self.usernameGroup_Menu.pack(side=tk.RIGHT)
        
        self.usernameAddToGroup_label = tk.Label(self.FrameAddToGroup_Username,text="Username:")
        self.usernameAddToGroup_label.pack(side=tk.LEFT,padx=5, pady=5)
        self.AddUsernameToGroup_Menu = ttk.Combobox(self.FrameAddToGroup_Username, value=self.Data_UserFriends,width=35, state="readonly")
        self.AddUsernameToGroup_Menu.set("Choose a user")
        self.AddUsernameToGroup_Menu.bind("<<ComboboxSelected>>",self.get_username)
        self.AddUsernameToGroup_Menu.pack(side=tk.RIGHT)
        
        self.Add_User_ToGroupButton = tk.Button(self.FrameaddToGroup_Button, text="Add to group",command=lambda : [self.addUserToGroup()], bg="#211A52", fg = "white")
        self.Add_User_ToGroupButton.pack(side=tk.LEFT)
        
        self.Add_User_EXIT_ButtonGroup = tk.Button(self.FrameaddToGroup_Button, text="EXIT",command=lambda : [self.Remove_Windows("Create group window")], bg="#211A52", fg = "white")
        self.Add_User_EXIT_ButtonGroup.pack(side=tk.RIGHT)
        
    def get_groupname(self,event):
        #print("Group name you clicked:",self.usernameGroup_Menu.get())
        self.GetGroupName = self.usernameGroup_Menu.get()
    def get_username(self,event):
        #print("user name you clicked:",self.AddUsernameToGroup_Menu.get())
        self.GetUserName = self.AddUsernameToGroup_Menu.get()
            
    def GroupChatWindow(self,group):
        self.groupname = group
        self.GROUPNAMETOSEND = group
        print("\nwhat is group name: {}".format(self.GROUPNAMETOSEND))
        
        self.GroupChatWindowUserFrame = tk.Frame(self.FrameChatWindow, bg="magenta",highlightbackground="green", highlightthickness=6 )
        self.GroupChatWindowUserFrame.pack(side=tk.TOP,fill='both',expand=True)  
        self.userchatLabel = tk.Label(self.GroupChatWindowUserFrame,text="{}'s Chat".format(self.GROUPNAMETOSEND),bg="magenta", fg="black",font=('arial',14,'bold'), borderwidth=1)
        self.userchatLabel.pack(side=tk.TOP,expand=False,anchor='center',pady=3)
        
        self.MembersInGroup_Label = tk.Label(self.GroupChatWindowUserFrame,text="Members:",fg="black",font=('arial',10,'bold'), borderwidth=1)
        self.MembersInGroup_Label.pack(side=tk.TOP,expand=False,anchor='center')
        
        self.MembersInGroup = tk.Text(self.GroupChatWindowUserFrame,height=1,width=70)
        self.MembersInGroup.configure(state="disabled")
        self.MembersInGroup.pack(side=tk.TOP,expand=False) 
        self.MembersInGroup.propagate(0)
        
        self.GroupChatTestFrame = tk.Frame(self.GroupChatWindowUserFrame, bg="yellow",highlightbackground="green", highlightthickness=6,borderwidth=10,height=340,width=800)
        self.GroupChatTestFrame.pack(side=tk.TOP,pady=5)
        self.GroupChatTestFrame.pack_propagate(0)
        
          
        #self.chat_box = tk.Text(self.ChatWindowUserFrame, height=25)
        self.Groupchat_box = tk.Text(self.GroupChatTestFrame, wrap = tk.WORD)
        self.Groupchat_box.configure(state="disabled")
        self.Groupchat_box.pack(fill='both',expand=True)
        self.Groupchat_box.pack_propagate(0)
        
        self.stored_logs = []
        self.ReadLogs("group",group)
        self.stored_logs.remove("STOP!")
        #print("logs: ", logs)
        self.Groupchat_box.configure(state="normal")
        #self.chat_box.insert("end","\n"+logs) ORIGINAL
        for i in self.stored_logs:
            self.Groupchat_box.insert("end",i)
        self.Groupchat_box.configure(state="disabled")
        self.Groupchat_box.see("end")
        
        scrollbarGroup = tk.Scrollbar(self.Groupchat_box,command=self.Groupchat_box.yview)
        scrollbarGroup.pack(side=tk.RIGHT,fill=tk.Y)
        self.Groupchat_box['yscrollcommand'] = scrollbarGroup.set
        
        # Load groupname users to msg
        #self.LoadSocket = socket(AF_INET,SOCK_STREAM)
        #self.LoadSocket.connect((SERVER_IP, LOAD_USER_PORT))
        
        # Data structure: [GroupName,UserToAdd,LoginName,CHECKDATA]
        self.data_string = pickle.dumps([self.GROUPNAMETOSEND,"",self.UsernameLogin,"Load_Group_Users"])
        self.LoadingSocket.send(self.data_string)
        self.GroupListFriends = self.LoadingSocket.recv(BUFFER_SIZE)
        self.GroupListFriends = pickle.loads(self.GroupListFriends)
        print("Users in group1:",self.GroupListFriends)
        if self.UsernameLogin in self.GroupListFriends:
            self.GroupListFriends.remove(self.UsernameLogin)
            print("Users in group2:",self.GroupListFriends)
        
        for i in self.GroupListFriends:
            print("i:",i)
            self.MembersInGroup.configure(state="normal")
            self.MembersInGroup.insert("end",i+", ")
        self.MembersInGroup.configure(state="disabled")
        
        for x in self.GroupListFriends:
            print("Users:",x)
        
        self.input_fieldGroup = tk.Entry(self.GroupChatWindowUserFrame,width=50,borderwidth=5,highlightbackground="black", highlightthickness=1)
        self.input_fieldGroup.pack(side=tk.TOP,pady=1)
        self.input_fieldGroup.bind("<Return>",self.key_sendmsg_group)
        self.input_fieldGroup.focus()
        
        # set structure: [chatboxSINGLE, inputSINGLE, chatboxGROUP, inputGROUP]
        # set structure: [chatboxSINGLE, chatboxGROUP, state]
        self.thread1.set("","", self.Groupchat_box, self.input_fieldGroup,self.UserFriend)
        self.thread2.set("", self.Groupchat_box, "GROUP",self.UserFriend,self.groupname)
        
        self.buttonGroup = ttk.Button(self.GroupChatWindowUserFrame, text='Send')
        self.buttonGroup['command'] = self.send_message_button_group
        self.buttonGroup.pack()
    
    def ReadLogs(self,state,groupname):
        GroupOrSingle = state
        groupName = groupname
        self.storeddata = []
        self.data = ""

        self.logssocket = socket(AF_INET,SOCK_STREAM)
        self.logssocket.connect((SERVER_IP, LOGS_PORT))

        if GroupOrSingle == "single":
            # Data structure: [usernameLogin, usernameFriend, groupname]
            self.data_string = pickle.dumps([self.UsernameLogin, self.UserFriend, "SINGLE"])
            self.logssocket.send(self.data_string)
          
        if GroupOrSingle == "group":
            # Data structure: [usernameLogin, usernameFriend, groupname]
            self.data_string = pickle.dumps([self.UsernameLogin, groupName, "GROUP"])
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
    def key_sendmsg_group(self, event):
        self.send_message_button_group()           
        self.input_fieldGroup.delete(0, 'end')     
    def send_message_button(self):
        self.thread1.send()
        self.input_field.delete(0, 'end')
    def send_message_button_group(self):
        self.thread1.send_to_group(self.GROUPNAMETOSEND)
        self.input_fieldGroup.delete(0, 'end')
         
 
class LoadingChatData(threading.Thread):
    def __init__(self,UsernameLogin,socket1, socket2, CanvasFrameFriend, CanvasFrameGroup):
        threading.Thread.__init__(self)
        
        self.UsernameLogin = UsernameLogin
        self.LoadChatSocket = socket1
        self.LoadGroupSocket = socket2
        
        self.FrameFriendListCanvas = CanvasFrameFriend
        self.FrameGroupListCanvas = CanvasFrameGroup
        
        
    def LoadUserFriends(self):
        # When logged in, connect to server and load USER_DATA into chat menu window
        # Make added user clickable and when clicked connect to chat server and add chat window to chat window frame
        
        #self.LoadUserFriendsSocket = socket(AF_INET,SOCK_STREAM)  # ORIGINAL
        #self.LoadUserFriendsSocket.connect((SERVER_IP, LOAD_USER_PORT)) # ORIGINAL
        
        # Data structure: [GroupName,UserToAdd,LoginName,CHECKDATA]
        self.Data_string = pickle.dumps(["","",self.UsernameLogin,"Load_Users"])
        #self.LoadUserFriendsSocket.send(self.Data_string) # ORIGINAL
        self.LoadChatSocket.send(self.Data_string)
        
        #self.Data_UserFriends = self.LoadUserFriendsSocket.recv(BUFFER_SIZE) # ORIGINAL
        self.Data_UserFriends = self.LoadChatSocket.recv(BUFFER_SIZE)
        self.Data_UserFriends = pickle.loads(self.Data_UserFriends)
        print("Users loaded from server: {}".format(self.Data_UserFriends))
        
        count = 0
        for x in self.Data_UserFriends:
            self.UserLoaded_Button = tk.Button(self.FrameFriendListCanvas,text=f"{self.Data_UserFriends[count]}", bg="black", fg="white",font=('arial',10,'bold'), borderwidth=1,anchor="center", command=lambda name=self.Data_UserFriends[count]:[Page_Chat.Remove_Windows("User chat window"),Page_Chat.UserChatWindow(name)])
            
            name = self.Data_UserFriends[count]
            print("This is name: {}".format(name))
            print("Username of friends: {}".format(self.Data_UserFriends[count]))  
            self.UserLoaded_Button.pack(anchor="nw",pady=3)            
            count += 1
            
           
    def LoadGroups(self):
        # When logged in, connect to server and load USER_DATA into chat menu window
        # Make added user clickable and when clicked connect to chat server and add chat window to chat window frame
        
        #self.LoadGroupsSocket = socket(AF_INET,SOCK_STREAM)
        #self.LoadGroupsSocket.connect((SERVER_IP, LOAD_USER_PORT))
        
        # Data structure: [GroupName,UserToAdd,LoginName,CHECKDATA]
        self.Data_string = pickle.dumps(["","",self.UsernameLogin,"Load_Groups"])
        self.LoadGroupSocket.send(self.Data_string)
        
        self.Data_Groups = self.LoadGroupSocket.recv(BUFFER_SIZE)
        self.Data_Groups = pickle.loads(self.Data_Groups)
        print("Groups loaded from server: {}".format(self.Data_Groups))
        
        count = 0
        if self.Data_Groups == "No group found":
            print("No groups loaded from server")
        else:
            for x in self.Data_Groups:
                self.LoadedGroupLabel = tk.Button(self.FrameGroupListCanvas,text=f"{self.Data_Groups[count]}", bg="black", fg="magenta",font=('arial',10,'bold'), borderwidth=1,anchor="center", command=lambda name=self.Data_Groups[count]:[Page_Chat.Remove_Windows("User chat window"),Page_Chat.GroupChatWindow(name)])

                name = self.Data_Groups[count]
                print("This is name: {}".format(name))
                print("Group name: {}".format(self.Data_Groups[count]))  
                self.LoadedGroupLabel.pack(anchor="nw",pady=3)
                count += 1
            print("All Group Names:", self.Data_Groups)
    

class AddingChatData():
    def __init__(self, UsernameLogin,socket1, socket2, socket3):
        self.UsernameLogin = UsernameLogin
        self.AddUsersSocket_FRIEND = socket1
        self.AddUsersSocket_GROUP = socket2
        self.AddUsersSocket_TOGROUP = socket3
      
    def addUserFriend(self,TryToAddUser,adduserlabel,usergrouplabel,usertogrouplabel,usergroupmenu,usertogroupmenu, datafriends,datagroups,groupnameaddgroup):
        # After clicking add user button - connect to server and add user to USER_DATA (Which holds data of logged in user)
        #self.se = socket(AF_INET,SOCK_STREAM) # ORIGINAL
        #self.se.connect((SERVER_IP, VERIFY_PORT)) # ORIGINAL
        
        self.AddUser_label = adduserlabel
        self.usernameGroup_tryadd_label = usergrouplabel
        self.usernameToGroup_tryadd_label = usertogrouplabel
        self.usernameGroup_Menu = usergroupmenu
        self.AddUsernameToGroup_Menu = usertogroupmenu
        self.Data_UserFriends = datafriends
        self.Data_Groups = datagroups
        self.GroupNameAddGroup = groupnameaddgroup
        
        
        # Data structure: [GroupName,UserToAdd,LoginName,CHECKDATA]
        self.data_string = pickle.dumps([TryToAddUser,self.UsernameLogin, "UserAdd", ""])
        #self.se.send(self.data_string) # ORIGINAL
        self.AddUsersSocket_FRIEND.send(self.data_string)
        #datax = self.se.recv(BUFFER_SIZE) # ORIGINAL
        datax = self.AddUsersSocket_FRIEND.recv(BUFFER_SIZE)
        datax = pickle.loads(datax)
        print("From Server: {}".format(datax))
        datax = datax.split('#')
        print("From Server2: {}".format(datax))
        print("datax[0]: {}\ndatax[1]: {}".format(datax[0],datax[1]))
        
        if datax[1] == TryToAddUser:
            print("USER ADDED")
            #self.Add_User_Frame.withdraw()
            Page_Chat.Update_Friendslist()
            self.AddUser_label.config(text="User added to friends list", fg="#211A52", font=('arial',10,'bold'))
            LoadingChatData.LoadUserFriends()
            #self.se.close()
        if datax[0] == "ALREADY IN FRIENDLIST!":
            print("USER ALREADY IN FRIENDLIST")
            shit1 = "ALREADY IN FRIENDLIST"
            self.AddUser_label.config(text="User already in friends list", fg="red", font=('arial',10,'bold'))
            #self.se.close()
        if datax[0] == "TRIED TO ADD YOURSELF!":
            shit2 = "TRIED TO ADD YOURSELF"
            print("TRIED TO ADD YOURSELF!")
            self.AddUser_label.config(text="Tried to add yourself!", fg="red", font=('arial',10,'bold'))
            #self.se.close()
        if datax[0] == "USER DOES NOT EXIST!":
            shit3 = "USER NOT EXIST"
            self.AddUser_label.config(text="User does not exist!", fg="red", font=('arial',10,'bold'))
        
       
    def addUserGroup(self):
        if not self.GroupNameAddGroup.get() :
            self.usernameGroup_tryadd_label.config(text="Group name is missing!", fg="red", font=('arial',10,'bold'))
        
        if self.GroupNameAddGroup.get():
            #self.seX = socket(AF_INET,SOCK_STREAM) #ORIGINAL
            #self.seX.connect((SERVER_IP, VERIFY_PORT)) # ORIGINAL

            GroupNameAdd = self.GroupNameAddGroup.get()
            # Data structure: [GroupName,UserToAdd,LoginName,CHECKDATA]
            self.data_string = pickle.dumps([self.UsernameLogin,GroupNameAdd,"UserAddGroup",""])
            self.AddUsersSocket_GROUP.send(self.data_string)
            datax = self.AddUsersSocket_GROUP.recv(BUFFER_SIZE)
            datax = pickle.loads(datax)
            print("From Server: {}".format(datax))
            datax = datax.split('#')
            print("From Server2: {}".format(datax))
            print("datax[0]: {}\ndatax[1]: {}".format(datax[0],datax[1]))

            if datax[0] == "GROUP CREATED":
                print("GROUP CREATED")
                self.usernameGroup_tryadd_label.config(text="Group created!", fg="green", font=('arial',10,'bold'))
                Page_Chat.Update_Grouplist()
                LoadingChatData.LoadGroups()
                #####self.Add_UserGroup_Frame.withdraw()
                #self.removeUsers()
                #self.LoadUserFriends()
                #self.seX.close()
            if datax[0] == "GROUP ALREADY EXISTS":
                print("GROUP ALREADY EXISTS")
                self.usernameGroup_tryadd_label.config(text="Group already exists!", fg="red", font=('arial',10,'bold'))
     
         
    def addUserToGroup(self):
        if self.usernameGroup_Menu.get() == "Choose a group":
            self.usernameToGroup_tryadd_label.config(text="No group was chosen!", fg="red", font=('arial',10,'bold'))
        
        if self.AddUsernameToGroup_Menu.get() == "Choose a user":
            self.usernameToGroup_tryadd_label.config(text="No user was chosen!", fg="red", font=('arial',10,'bold'))
       
        if self.usernameGroup_Menu.get() == "Choose a group" and self.AddUsernameToGroup_Menu.get() == "Choose a user":
             self.usernameToGroup_tryadd_label.config(text="No group or user was chosen !", fg="red", font=('arial',10,'bold'))
             
        if self.AddUsernameToGroup_Menu.get() in self.Data_UserFriends and self.usernameGroup_Menu.get() in self.Data_Groups:
            print("User in friendlist!")
            
            #self.seY = socket(AF_INET,SOCK_STREAM)
            #self.seY.connect((SERVER_IP, VERIFY_PORT))

            GroupNameAdd = self.usernameGroup_Menu.get()
            UserAddToGroup = self.AddUsernameToGroup_Menu.get()
            # Data structure: [GroupName,UserToAdd,LoginName,CHECKDATA]
            self.data_string = pickle.dumps([self.UsernameLogin,GroupNameAdd,"UserAddToGroup", UserAddToGroup])
            self.AddUsersSocket_TOGROUP.send(self.data_string)
            datax = self.AddUsersSocket_TOGROUP.recv(BUFFER_SIZE)
            datax = pickle.loads(datax)
            print("From Server: {}".format(datax))
            datax = datax.split('#')
            print("From Server2: {}".format(datax))
            print("datax[0]: {}\ndatax[1]: {}:".format(datax[0],datax[1]))

            if datax[0] == "USER ALREADY IN GROUPCHAT":
                print("USER ALREADY IN GROUPCHAT")
                self.usernameToGroup_tryadd_label.config(text="User already in groupchat!", fg="red", font=('arial',10,'bold'))
                #self.seY.close()
            else:
                print("USER ADDED IN GROUPCHAT")
                self.usernameToGroup_tryadd_label.config(text="User added to groupchat!", fg="green", font=('arial',10,'bold'))
                Page_Chat.Update_Grouplist()
                LoadingChatData.LoadGroups()
     

class SendData():
    def __init__(self,tcp_socket, user):
        self.ds=tcp_socket
        self.uu=user
    def send(self):
        send_data = self.input.get()
        print("SINGLE - send data: {}".format(send_data))
        print(len(send_data))
        if len(send_data) > 1:
            # Data structure: [user, msg, msgtofriend, groupname, keyword]
            chat_data=[self.uu,send_data, self.UserFriend,"","SINGLE"]
            chat_string = pickle.dumps(chat_data)
            self.ds.send(chat_string)
            self.chat.configure(state="normal")
            self.chat.insert("end","\nYOU: {}\n".format(send_data))
            self.chat.configure(state="disabled")
            self.chat.see("end") 
                
    def send_to_group(self,groupname):
        send_data = self.input2.get()
        print("GROUP - send data: {}".format(send_data))
        print(len(send_data))
        if len(send_data) > 1:
            # Data structure: [user, msg, msgtofriend, groupname, keyword]
            chat_data=[self.uu,send_data, self.GroupListFriends, groupname, "GROUP"]
            chat_string = pickle.dumps(chat_data)
            self.ds.send(chat_string)
            self.chatgroup.configure(state="normal")
            self.chatgroup.tag_add("YOU","1.0","1.end")
            self.chatgroup.config("YOU",font=('arial',10,'bold'))
            self.chatgroup.insert("end","\nYOU: {}\n".format(send_data))
            self.chatgroup.configure(state="disabled")
            self.chatgroup.see("end")
                      
    def exit(self):
            chat_data=[self.uu, "EEXIT","","",""]
            chat_string = pickle.dumps(chat_data)
            self.ds.send(chat_string)
            print("Connection closed.")
            
    # set structure: [chatboxSINGLE, inputSINGLE, chatboxGROUP, inputGROUP, state]
    def set(self, chat_box,input,chat_box_group,input2,UserFriend):
        self.chat = chat_box
        self.input = input
        self.chatgroup = chat_box_group
        self.input2 = input2
        self.UserFriend = UserFriend


class ReceiveData(threading.Thread):
    def __init__(self,tcp_socket):
        threading.Thread.__init__(self)
        self.ds=tcp_socket
    def run(self):
        while True:
            recv_string = self.ds.recv(BUFFER_SIZE)
            recv_data = pickle.loads(recv_string)
            if recv_data == "CLOSE CONN":
                break
            if self.state == "SINGLE":
                print("Writing to SINGLE chat window...")
                print("recv_data:", recv_data)
                print(f"self.UserFriend: {self.UserFriend}")
                print(f"recv_data[0]: {recv_data[0]}")
                if self.UserFriend == recv_data[0]:
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
                print("recv_data:", recv_data)
                print(f"self.UserFriend: {self.UserFriend}")
                print(f"groupname: {self.groupname}")
                print(f"recv_data[3]: {recv_data[3]}")
                if self.groupname == recv_data[3]:
                    self.chatgroup.configure(state="normal")
                    msg = "{}: {}".format(recv_data[0],recv_data[1])
                    print("====================")
                    print("msg: {}\nFrom: {}".format(recv_data[1],recv_data[0]))
                    print("====================")
                    self.chatgroup.insert("end","\n"+msg+"\n")
                    self.chatgroup.configure(state="disabled")
                    self.chatgroup.see("end")
    # set structure: [chatboxSINGLE, chatboxGROUP, state]
    def set(self,chat_box,chat_box_group,state,UserFriend,groupname):
        self.state = state
        self.chat = chat_box
        self.chatgroup = chat_box_group
        self.UserFriend = UserFriend
        self.groupname = groupname


if __name__=="__main__":
   
   Main = Page_Login()
