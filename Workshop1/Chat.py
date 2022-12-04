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
from PIL import Image, ImageTk
from itertools import count, cycle


#SERVER_IP = "127.0.0.1"
SERVER_IP = ""
SERVER_PORT = 1234
VERIFY_PORT = 2001
LOGS_PORT = 2005
LOAD_USER_PORT = 1000
BUFFER_SIZE = 10000

stupidusername = ""
userfriend = ""
groupname = ""
GroupListFriends = []
UserDataLoaded = []
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
      
      
        self.Main_Window = tk.Toplevel()
        self.Main_Window.attributes('-topmost', True)
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
            global stupidusername
            #print("OK LOGIN :)")
            #print(f"Username: {self.UsernameLogin.get()} \n" + f"Password: {self.PasswordLogin.get()}")
            self.title_label.config(text="Awesome Chat Program!", fg="black", font=('Arial',18,'bold'))
            stupidusername = self.data[1]
            #print("From Server stupidusername: {}".format(stupidusername))
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
               self.event = threading.Event()
               self.thread1 = SendData(self.UserChatSocket2,stupidusername)
               self.thread2 = ReceiveData(self.UserChatSocket2, self.event)
               self.thread2.start()
               #root.add_page("Page_Chat",Page_Chat, self.thread1, self.thread2, self.UserChatSocket1, self.UserChatSocket2)
               self.Main_Window.withdraw()
               Page_Chat(self.thread1, self.thread2, self.UserChatSocket1, self.UserChatSocket2)
               self.se.close()
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


class Page_Chat(tk.Frame):
    def __init__(self,thread1,thread2, socketlogin, socketchat):
        # Same as creating root window, withdrawing it, and running mainloop()
        tk.Frame.__init__(self)

        self.thread1 = thread1
        self.thread2 = thread2
        self.socketlogin = socketlogin
        self.socketchat = socketchat
        

        self.Main_Window = tk.Toplevel()
        self.Main_Window.protocol("WM_DELETE_WINDOW", self.on_closing)
        self.Main_Window.title("Awesome Chat Program!")
        #self.Main_Window.resizable(width=False, height=False)
        #self.Main_Window.configure(width=600, height=300)

        #self.Username = tk.StringVar()
        #self.Password = tk.StringVar()



        ### ------------------ Start of Main Window Frame ------------------ ###
        # Main Window Frame
        self.frame_main = tk.Frame(self.Main_Window,height=700,width=1000)
        self.frame_main.pack(fill='both',expand=True)
        self.frame_main.propagate(0)

        # Frame Title label
        self.chat_title = tk.Label(self.frame_main, 
                                   text=f"Welcome {stupidusername}!", 
                                   font=('Arial',24,'bold'),
                                   bg="black", fg="white",
                                   borderwidth=1,
                                   highlightbackground="grey", 
                                   highlightthickness=2,)
        self.chat_title.pack(side=tk.TOP,fill=tk.X, expand=False,pady=5,padx=5)
        ### ------------------ End of Main Window Frame ------------------ ###


        ### ------------------ Section for LEFT SIDE of chat ------------------ ###
        # Side-Frame Left
        self.FrameLeft = tk.Frame(self.frame_main,
                                   borderwidth=1,
                                   highlightbackground="black", 
                                   highlightthickness=2,                                   
                                   height=600,
                                   width=400)
        self.FrameLeft.pack(side=tk.LEFT,expand=False,fill=tk.Y)
        self.FrameLeft.propagate(0)

        

        # Frame for "Chat Menu" - Includes Add User, Create Group and Add to Group
        self.FrameChatMenuMAIN = tk.Frame(self.FrameLeft,
                                   borderwidth=1,bg="white",
                                   highlightbackground="black", 
                                   highlightthickness=2,)
        self.FrameChatMenuMAIN.pack(side=tk.TOP,expand=False,fill=tk.X,pady=5)
        
        self.FrameChatMenu = tk.Frame(self.FrameChatMenuMAIN,
                                   borderwidth=1,bg="white",)
        self.FrameChatMenu.pack(side=tk.TOP,expand=False,fill="both")
        
         # Frame for "Refreshing groups/chats"
        self.FrameChatMenu2 = tk.Frame(self.FrameChatMenuMAIN,
                                   borderwidth=1,bg="white",)
        self.FrameChatMenu2.pack(side=tk.TOP) # ,expand=False,fill="both"

        # Add user, create group and add to group buttons
        self.AddUser_Button = tk.Button(self.FrameChatMenu, text="Add User ",font=('arial',10,'bold'),height=1, command=lambda : [self.Active_Window("Add users")], fg = "black", borderwidth=1,relief="raised")
        self.AddUser_Button.pack(side=tk.LEFT,fill=tk.X, expand=True,padx=1.5, pady=1.5)

        self.CreateGroup_Button = tk.Button(self.FrameChatMenu, text="Create Group",font=('arial',10,'bold'),height=1,command=lambda : [self.Active_Window("Create group")], fg = "black", borderwidth=1,relief="raised")
        self.CreateGroup_Button.pack(side=tk.LEFT,fill=tk.X, expand=True, padx=1.5, pady=1.5)

        self.AddUserGroup_Button = tk.Button(self.FrameChatMenu, text="Add to Group",font=('arial',10,'bold'),height=1,command=lambda : [self.Active_Window("Add to group")], fg = "black", borderwidth=1,relief="raised")
        self.AddUserGroup_Button.pack(side=tk.LEFT,fill=tk.X, expand=True, padx=1.5, pady=1.5)
        
        # Refresh friendlist and grouplist buttons
        self.Refresh_FriendList_Button = tk.Button(self.FrameChatMenu2, text="Refresh Friends ",font=('arial',10,'bold'),height=1, command=lambda : [self.Update_Friendslist(),self.LoadUserFriends()], fg = "black", borderwidth=1,relief="raised")
        self.Refresh_FriendList_Button.pack(side=tk.LEFT,fill=tk.X, expand=True,padx=1.5)

        self.Refresh_GroupList_Button = tk.Button(self.FrameChatMenu2, text="Refresh Groups",font=('arial',10,'bold'),height=1,command=lambda : [self.Update_Grouplist(),self.LoadGroups()], fg = "black", borderwidth=1,relief="raised")
        self.Refresh_GroupList_Button.pack(side=tk.RIGHT,fill=tk.X, expand=True, padx=1.5)




        ########################### Main Chat Menu Frames ###############################
        # Frame for holding Friend List and Group List
        self.FrameFriendGroupList = tk.Frame(self.FrameLeft,
                                   borderwidth=1,
                                   highlightbackground="black", 
                                   highlightthickness=2,)
        self.FrameFriendGroupList.pack(side=tk.TOP,expand=True,fill="both")
        self.FrameFriendGroupList.propagate(1)

        # Frame for Friend List on the left side
        self.FrameFriendListLeft = tk.Frame(self.FrameFriendGroupList,
                                   borderwidth=1,bg="white",
                                   highlightbackground="black", 
                                   highlightthickness=2,)
        self.FrameFriendListLeft.pack(side=tk.LEFT,expand=True,fill="both",padx=5)
        self.FrameFriendListLeft.propagate(1)

        # Frame for Group List on the right side
        self.FrameGroupListRight = tk.Frame(self.FrameFriendGroupList,
                                   borderwidth=1,bg="white",
                                   highlightbackground="black", 
                                   highlightthickness=2,
                                   height=100,
                                   width=100)
        self.FrameGroupListRight.pack(side=tk.RIGHT,expand=True,fill="both",padx=5)
        self.FrameGroupListRight.propagate(1)
        ########################### Main Chat Menu Frames ###############################

        # Friend list label on the left side
        self.FriendList_Label = tk.Label(self.FrameFriendListLeft,text="Friends List", bg="white",fg="black",font=('arial',10,'bold'),
                                   borderwidth=1,
                                   highlightbackground="black")
        self.FriendList_Label.pack(side=tk.TOP,fill="both",expand=False)

        # Frame for Friend List on the left side
        self.FrameFriendList = tk.Frame(self.FrameFriendListLeft,
                                   borderwidth=1,
                                   highlightbackground="black", 
                                   highlightthickness=2,
                                   width=1)
        self.FrameFriendList.pack(side=tk.TOP,expand=True,fill="both")
        self.FrameFriendList.propagate(1)

        # Canvas to hold frame
        self.CanvasFriendList = tk.Canvas(self.FrameFriendList,width=1,bg="white")
        self.CanvasFriendList.pack(side=tk.LEFT,fill="both",expand=True)
        # Scrollbar to canvas
        self.ScrollBarCanvasFriendList = tk.Scrollbar(self.FrameFriendList, orient="vertical", command=self.CanvasFriendList.yview)
        self.ScrollBarCanvasFriendList.pack(side=tk.RIGHT,fill=tk.Y)
        # Configure canvas
        self.CanvasFriendList.configure(yscrollcommand=self.ScrollBarCanvasFriendList.set)
        self.CanvasFriendList.bind("<Configure>",lambda e: self.CanvasFriendList.configure(scrollregion=self.CanvasFriendList.bbox("all")))
        # Frame inside canvas holding friend buttons
        self.FrameFriendListCanvas = tk.Frame(self.CanvasFriendList,bg="white")
        self.CanvasFriendList.create_window((25,10),window=self.FrameFriendListCanvas,anchor="nw")
        self.FrameFriendListCanvas.bind("<Configure>", self.reset_scrollregion)

        
        ##################################################################################

        # Group list label on the rightside
        self.GroupList_Label = tk.Label(self.FrameGroupListRight,text="Group List",bg="white", fg="black",font=('arial',10,'bold'), borderwidth=1)
        self.GroupList_Label.pack(side=tk.TOP,fill="both",expand=False)

        # Frame for Group List on the right side
        self.FrameGroupList = tk.Frame(self.FrameGroupListRight,
                                   borderwidth=1,
                                   highlightbackground="black", 
                                   highlightthickness=2,
                                   width=150)
        self.FrameGroupList.pack(side=tk.TOP,expand=True,fill="both")
        self.FrameGroupList.propagate(0)

        # Canvas to hold frame
        self.CanvasGroupList = tk.Canvas(self.FrameGroupList,width=1,bg="white")
        self.CanvasGroupList.pack(side=tk.LEFT,expand=True,fill="both")
        
        # Scrollbar to canvas
        self.ScrollBarCanvasGroupList = tk.Scrollbar(self.FrameGroupList, orient="vertical", command=self.CanvasGroupList.yview)
        self.ScrollBarCanvasGroupList.pack(side=tk.RIGHT,fill=tk.Y)
        
        # Configure canvas
        self.CanvasGroupList.configure(yscrollcommand=self.ScrollBarCanvasGroupList.set)
        self.CanvasGroupList.bind("<Configure>",lambda e: self.CanvasGroupList.configure(scrollregion=self.CanvasGroupList.bbox("all")))
        
        # Frame inside canvas holding friend buttons
        self.FrameGroupListCanvas = tk.Frame(self.CanvasGroupList,bg="white")
        self.CanvasGroupList.create_window((25,10),window=self.FrameGroupListCanvas,anchor="nw")
        
        self.FrameGroupListCanvas.bind("<Configure>", self.reset_scrollregion)
        
        # Button for exiting program
        self.EXIT_Button = tk.Button(self.FrameLeft, text="EXIT",font=('Arial',12,'bold'),command=lambda : [self.thread1.exit(),self.Main_Window.withdraw(),self.reset_active_window(),Page_Login()], bg="#211A52", fg = "white")
        self.EXIT_Button.pack(side=tk.TOP)

        ### ------------------ Section for LEFT SIDE of chat ------------------ ###


        ### ------------------ Section for RIGHT SIDE of chat ------------------ ###
        # Side-Frame Right
        self.FrameRight = tk.Frame(self.frame_main,
                                   borderwidth=1,bg="white",
                                   highlightbackground="black", 
                                   highlightthickness=2,
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
                                   borderwidth=1,bg="white",
                                   highlightbackground="black", 
                                   highlightthickness=2,)
        self.FrameChatWindow.pack(side=tk.LEFT,expand=True,fill="both")
        
        self.Update_Friendslist()
        self.Update_Grouplist()
        time.sleep(0.2)
        self.LoadUserFriends()
        time.sleep(0.2)
        self.LoadGroups()

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
            self.CreateGroup()
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
                                   borderwidth=1)
        self.FrameAddUserMain.pack(anchor="center",fill=None,expand=True)
        
        self.UsernameAdd = tk.StringVar()
        
        self.FrameAddUserSub = tk.Frame(self.FrameAddUserMain, borderwidth=5,
                                   highlightbackground="black", 
                                   highlightthickness=2)
        self.FrameAddUserSub.pack(side=tk.TOP,fill='both',expand=False)
        self.FrameAddUserSub.propagate(1)
        
        self.FrameAddUser_Label = tk.Frame(self.FrameAddUserSub, borderwidth=2)
        self.FrameAddUser_Label.pack(side=tk.TOP)
        
        self.FrameAddUser_Entry = tk.Frame(self.FrameAddUserSub, borderwidth=5)
        self.FrameAddUser_Entry.pack(side=tk.TOP)
        
        self.FrameAddUser_Button = tk.Frame(self.FrameAddUserSub, borderwidth=5)
        self.FrameAddUser_Button.pack()
        
        self.AddUser_label = tk.Label(self.FrameAddUser_Label,text="Add user")
        self.AddUser_label.pack(side=tk.LEFT,padx=5, pady=5)
        self.Username_label = tk.Label(self.FrameAddUser_Entry,text="Username:")
        self.Username_label.pack(side=tk.LEFT,padx=5, pady=5)
        
        self.Usernameadd_entry = tk.Entry(self.FrameAddUser_Entry, width=35,textvariable=self.UsernameAdd)
        self.Usernameadd_entry.pack(side=tk.RIGHT)
        self.Usernameadd_entry.bind("<Return>",lambda event, a = "Add users":self.Key_Pressed(a))
        self.Usernameadd_entry.focus()
            
        self.AddUser_Button = tk.Button(self.FrameAddUser_Button, text="Add user",command=lambda : [self.addUserFriend(),self.Clear_Entry("Add users")], bg="#211A52", fg = "white")
        self.AddUser_Button.pack(side=tk.LEFT)
        self.AddUser_EXIT_Button = tk.Button(self.FrameAddUser_Button, text="Return",command=lambda : [self.Remove_Windows("Add user window")], bg="#211A52", fg = "white")
        self.AddUser_EXIT_Button.pack(side=tk.RIGHT)
    
    def addUserFriend(self):
        if not self.Usernameadd_entry.get():
            self.AddUser_label.config(text="No username was entered!", fg="red", font=('arial',10,'bold'))
        else:
            
            # After clicking add user button - connect to server and add user to USER_DATA (Which holds data of logged in user)
            self.AddUserSocket = socket(AF_INET,SOCK_STREAM)
            self.AddUserSocket.connect((SERVER_IP, VERIFY_PORT))

            TryToAddUser = self.UsernameAdd.get()
            # Data structure: [GroupName,UserToAdd,LoginName,CHECKDATA]
            self.data_string = pickle.dumps([TryToAddUser,stupidusername, "UserAdd", ""])
            self.AddUserSocket.send(self.data_string)
            datax = self.AddUserSocket.recv(BUFFER_SIZE)
            datax = pickle.loads(datax)
            print("From Server: {}".format(datax))
            datax = datax.split('#')
            print("From Server2: {}".format(datax))
            print("datax[0]: {}\ndatax[1]: {}".format(datax[0],datax[1]))


            if datax[1] == TryToAddUser:
                print("USER ADDED")
                #self.Add_User_Frame.withdraw()
                time.sleep(0.1)
                self.Update_Friendslist()
                self.AddUser_label.config(text="User added to friends list", fg="green", font=('arial',10,'bold'))
                time.sleep(0.1)
                self.LoadUserFriends()
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
        
    def LoadUserFriends(self):
        # When logged in, connect to server and load USER_DATA into chat menu window
        # Make added user clickable and when clicked connect to chat server and add chat window to chat window frame
        
        
        
        self.LoadUserFriendsSocket = socket(AF_INET,SOCK_STREAM)
        self.LoadUserFriendsSocket.connect((SERVER_IP, LOAD_USER_PORT))
        
        # Data structure: [GroupName,UserToAdd,LoginName,CHECKDATA]
        self.Data_string = pickle.dumps(["","",stupidusername,"Load_Users"])
        self.LoadUserFriendsSocket.send(self.Data_string)
        self.Data_UserFriends = self.LoadUserFriendsSocket.recv(BUFFER_SIZE)
        self.Update_Friendslist()
        self.Data_UserFriends = pickle.loads(self.Data_UserFriends)
        #print("Users loaded from server: {}".format(self.Data_UserFriends))
        count = 0
        for x in self.Data_UserFriends:
            self.UserLoaded_Button = tk.Button(self.FrameFriendListCanvas,text=f"{self.Data_UserFriends[count]}", fg="black",font=('arial',10,'bold'), borderwidth=1,anchor="center", command=lambda name=self.Data_UserFriends[count]:[self.Remove_Windows("User chat window"),self.UserChatWindow(name)])
            name = self.Data_UserFriends[count]
            #print("This is name: {}".format(name))
            #print("Username of friends: {}".format(self.Data_UserFriends[count]))  
            self.UserLoaded_Button.pack(anchor="nw",pady=3)            
            count += 1
            
    def UserChatWindow(self,friend):
        self.chat_title.configure(text="Chat Window!", 
                                   font=('Arial',18,'bold'),
                                   bg="black", fg="white")
        
        global userfriend
        userfriend = friend


        self.UserChatWindowFrame = tk.Frame(self.FrameChatWindow, bg="white")
        self.UserChatWindowFrame.pack(side=tk.TOP,fill='both',expand=True) 

        self.userchatLabel = tk.Label(self.UserChatWindowFrame,text="{}'s Chat".format(friend), bg="white",fg="black",font=('arial',14,'bold'), borderwidth=1)
        self.userchatLabel.pack(side=tk.TOP,expand=False,anchor='center',pady=3) 

        self.UserChatFrame = tk.Frame(self.UserChatWindowFrame, highlightbackground="black", highlightthickness=6,borderwidth=10,height=400,width=500,bg="white")
        self.UserChatFrame.pack(side=tk.TOP)
        self.UserChatFrame.propagate(0)

        self.UserChatFrame2 = tk.Frame(self.UserChatFrame,height=390,width=16)
        self.UserChatFrame2.pack(side=tk.RIGHT)
        self.UserChatFrame2.propagate(0)
        
        
        self.gifFrame1 = tk.Frame(self.UserChatFrame,height=220,width=1,bg="white")
        self.gifFrame1.pack(side=tk.BOTTOM,fill="both")
        self.gifFrame1.propagate(0)
        lbl = ImageLabel(self.gifFrame1,bg="white")
        lbl.pack(anchor="center")
        lbl.load('loading.gif')
        
        self.chat_box = tk.Text(self.UserChatFrame,height=150,width=150, wrap = tk.WORD)
        self.chat_box.configure(state="disabled")
        #self.chat_box.pack(side=tk.LEFT,expand=True,fill="both")
        self.chat_box.propagate(1)
        
        scrollbar1 = tk.Scrollbar(self.UserChatFrame2,orient="vertical",command=self.chat_box.yview)
        scrollbar1.pack(side=tk.RIGHT,fill=tk.Y)
        self.chat_box['yscrollcommand'] = scrollbar1.set
        

        self.input_field = tk.Entry(self.UserChatWindowFrame,width=64,borderwidth=5,highlightbackground="black", highlightthickness=1)
        self.input_field.pack(side=tk.TOP,pady=1)
        self.input_field.bind("<Return>",self.key_sendmsg)
        self.input_field.focus()

        self.thread1.set(self.chat_box,self.input_field, "","")
        self.thread2.set(self.chat_box,"","SINGLE")

        self.stored_logs = []
        ThreadLogs1 = threading.Thread(target=self.ReadLogs,args=("single",""))
        ThreadLogs1.start()
        #ThreadLogs1.join()
        
        #self.ReadLogs("single","")
        #self.stored_logs.remove("STOP!")
        #print("logs: ", logs)
        #self.chat_box.configure(state="normal")
        #self.chat_box.insert("end","\n"+logs) ORIGINAL        

        # set structure: [chatboxSINGLE, inputSINGLE, chatboxGROUP, inputGROUP]
        # set structure: [chatboxSINGLE, chatboxGROUP, state]
        self.thread1.set(self.chat_box,self.input_field, "","")
        self.thread2.set(self.chat_box,"","SINGLE")

        self.button = ttk.Button(self.UserChatWindowFrame, text='Send')
        self.button['command'] = self.send_message_button
        self.button.pack()
    
    def CreateGroupChat(self):
        self.chat_title.configure(text="Create Group Chat", 
                                   font=('Arial',18,'bold'),
                                   bg="black", fg="white")
        self.FrameCreateGroupMain = tk.Frame(self.FrameChatWindow,
                                   borderwidth=1,bg="white",
                                   highlightbackground="black", 
                                   highlightthickness=2,)
        self.FrameCreateGroupMain.pack(anchor="center",fill=None,expand=True)
        
        self.GroupNameCreateGroup = tk.StringVar()
        #self.UsernameAddToGroup = tk.StringVar()
        
        self.FrameaddGroup = tk.Frame(self.FrameCreateGroupMain, borderwidth=5)
        self.FrameaddGroup.pack(side=tk.TOP,fill='both',expand=True)
        
        self.FrameaddGroup_Label = tk.Frame(self.FrameaddGroup, borderwidth=2)
        self.FrameaddGroup_Label.pack(side=tk.TOP)
        
        self.FrameaddGroup_Group = tk.Frame(self.FrameaddGroup, borderwidth=5)
        self.FrameaddGroup_Group.pack(side=tk.TOP)
        
        self.FrameAddGroup_Username = tk.Frame(self.FrameaddGroup, borderwidth=5)
        self.FrameAddGroup_Username.pack(side=tk.TOP)
        
        self.FrameaddGroup_Button = tk.Frame(self.FrameaddGroup, borderwidth=5)
        self.FrameaddGroup_Button.pack()
        
        self.usernameGroup_tryadd_label = tk.Label(self.FrameaddGroup_Label,text="Create a new group")
        self.usernameGroup_tryadd_label.pack(side=tk.TOP,padx=5, pady=5)
    
        self.usernameGroup_label = tk.Label(self.FrameaddGroup_Group,text="Group name:")
        self.usernameGroup_label.pack(side=tk.LEFT,padx=5, pady=5)
        self.usernameaddGroup_entry = tk.Entry(self.FrameaddGroup_Group, width=35,textvariable=self.GroupNameCreateGroup)
        self.usernameaddGroup_entry.pack(side=tk.RIGHT)
        self.usernameaddGroup_entry.bind("<Return>",lambda event, a = "Create group":self.Key_Pressed(a))
        self.usernameaddGroup_entry.focus()
        
        self.Add_User_ButtonGroup = tk.Button(self.FrameaddGroup_Button, text="Create group",command=lambda : [self.CreateGroup()], bg="#211A52", fg = "white")
        self.Add_User_ButtonGroup.pack(side=tk.LEFT)
        
        self.Add_User_EXIT_ButtonGroup = tk.Button(self.FrameaddGroup_Button, text="Return",command=lambda : [self.Remove_Windows("Create group window")], bg="#211A52", fg = "white")
        self.Add_User_EXIT_ButtonGroup.pack(side=tk.RIGHT)
        
    def CreateGroup(self):
        if not self.GroupNameCreateGroup.get() :
            self.usernameGroup_tryadd_label.config(text="No groupname was entered!", fg="red", font=('arial',10,'bold'))
        
        if self.GroupNameCreateGroup.get():
            self.CreateGroupSocket = socket(AF_INET,SOCK_STREAM)
            self.CreateGroupSocket.setsockopt(SOL_SOCKET, SO_REUSEADDR, 1)
            self.CreateGroupSocket.connect((SERVER_IP, VERIFY_PORT))

            GroupNameAdd = self.GroupNameCreateGroup.get()
            # Data structure: [GroupName,UserToAdd,LoginName,CHECKDATA]
            #self.data_string = pickle.dumps([GroupNameAdd,UserAddToGroup,stupidusername, "UserAddGroup"])
            self.data_string = pickle.dumps([stupidusername,GroupNameAdd,"UserAddGroup",""])
            self.CreateGroupSocket.send(self.data_string)
            datax = self.CreateGroupSocket.recv(BUFFER_SIZE)
            datax = pickle.loads(datax)
            print("From Server: {}".format(datax))
            datax = datax.split('#')
            print("From Server2: {}".format(datax))
            print("datax[0]: {}\ndatax[1]: {}".format(datax[0],datax[1]))

            if datax[0] == "GROUP CREATED":
                print("GROUP CREATED")
                time.sleep(0.2)
                self.Update_Grouplist()
                self.usernameGroup_tryadd_label.config(text="Group created!", fg="green", font=('arial',10,'bold'))
                time.sleep(0.2)
                self.LoadGroups()
                #####self.Add_UserGroup_Frame.withdraw()
                #self.removeUsers()
                #self.LoadUserFriends()
                #self.seX.close()
            if datax[0] == "GROUP ALREADY EXISTS":
                print("GROUP ALREADY EXISTS")
                self.usernameGroup_tryadd_label.config(text="Group already exists!", fg="red", font=('arial',10,'bold'))
                self.CreateGroupSocket.close()
                
    def LoadGroups(self):
        # When logged in, connect to server and load USER_DATA into chat menu window
        # Make added user clickable and when clicked connect to chat server and add chat window to chat window frame
        
        self.LoadGroupsSocket = socket(AF_INET,SOCK_STREAM)
        self.LoadGroupsSocket.connect((SERVER_IP, LOAD_USER_PORT))
        
        # Data structure: [GroupName,UserToAdd,LoginName,CHECKDATA]
        self.Data_string = pickle.dumps(["","",stupidusername,"Load_Groups"])
        self.LoadGroupsSocket.send(self.Data_string)
        
        self.Data_Groups = self.LoadGroupsSocket.recv(BUFFER_SIZE)
        self.Data_Groups = pickle.loads(self.Data_Groups)
        #print("Groups loaded from server: {}".format(self.Data_Groups))
        
        count = 0
        if self.Data_Groups == "No group found":
            print("No groups loaded from server")
        else:
            for x in self.Data_Groups:
                self.LoadedGroupLabel = tk.Button(self.FrameGroupListCanvas,text=f"{self.Data_Groups[count]}", fg="black",font=('arial',10,'bold'), borderwidth=1,anchor="center", command=lambda name=self.Data_Groups[count]:[self.Remove_Windows("User chat window"),self.GroupChatWindow(name)])

                name = self.Data_Groups[count]
                #print("This is name: {}".format(name))
                #print("Group name: {}".format(self.Data_Groups[count]))  
                self.LoadedGroupLabel.pack(anchor="nw",pady=3)
                count += 1
    
    def AddToGroup(self):
        self.chat_title.configure(text="Add User to Group Chat", 
                                   font=('Arial',18,'bold'),
                                   bg="black", fg="white")
        self.FrameAddToGroupMain = tk.Frame(self.FrameChatWindow, 
                                   bg="white",
                                   borderwidth=1)
        self.FrameAddToGroupMain.pack(anchor="center",fill=None,expand=True)
        
        #self.GroupNameAddToGroup = tk.StringVar()
        #self.UsernameAddToGroup = tk.StringVar()
        
        self.FrameaddToGroup = tk.Frame(self.FrameAddToGroupMain, borderwidth=5,
                                   highlightbackground="black", 
                                   highlightthickness=2,)
        self.FrameaddToGroup.pack(side=tk.TOP,fill='both',expand=True)
        
        self.FrameaddToGroup_Label = tk.Frame(self.FrameaddToGroup, borderwidth=2)
        self.FrameaddToGroup_Label.pack(side=tk.TOP)
        
        self.FrameaddToGroup_Group = tk.Frame(self.FrameaddToGroup, borderwidth=5)
        self.FrameaddToGroup_Group.pack(side=tk.TOP)
        
        self.FrameAddToGroup_Username = tk.Frame(self.FrameaddToGroup, borderwidth=5)
        self.FrameAddToGroup_Username.pack(side=tk.TOP)
        
        self.FrameaddToGroup_Button = tk.Frame(self.FrameaddToGroup, borderwidth=5)
        self.FrameaddToGroup_Button.pack()
        
        self.usernameToGroup_tryadd_label = tk.Label(self.FrameaddToGroup_Label,text="Add a user to your group")
        self.usernameToGroup_tryadd_label.pack(side=tk.TOP,padx=5, pady=5)
        
        
        self.usernameGroup_label = tk.Label(self.FrameaddToGroup_Group,text="Group name:")
        self.usernameGroup_label.pack(side=tk.LEFT,padx=5, pady=5)
        self.usernameGroup_Menu = ttk.Combobox(self.FrameaddToGroup_Group, value=self.Data_Groups,width=35, state="readonly")
        self.usernameGroup_Menu.set("Choose a group")
        self.usernameGroup_Menu.bind("<<ComboboxSelected>>",self.get_groupname)
        self.usernameGroup_Menu.pack(side=tk.RIGHT)
        
        self.usernameAddToGroup_label = tk.Label(self.FrameAddToGroup_Username,text="     Username:")
        self.usernameAddToGroup_label.pack(side=tk.LEFT,padx=5, pady=5)
        self.AddUsernameToGroup_Menu = ttk.Combobox(self.FrameAddToGroup_Username, value=self.Data_UserFriends,width=35, state="readonly")
        self.AddUsernameToGroup_Menu.set("Choose a user")
        self.AddUsernameToGroup_Menu.bind("<<ComboboxSelected>>",self.get_username)
        self.AddUsernameToGroup_Menu.pack(side=tk.RIGHT)
        
        self.Add_User_ToGroupButton = tk.Button(self.FrameaddToGroup_Button, text="Add to group",command=lambda : [self.addUserToGroup()], bg="#211A52", fg = "white")
        self.Add_User_ToGroupButton.pack(side=tk.LEFT)
        
        self.Add_User_EXIT_ButtonGroup = tk.Button(self.FrameaddToGroup_Button, text="Return",command=lambda : [self.Remove_Windows("Create group window")], bg="#211A52", fg = "white")
        self.Add_User_EXIT_ButtonGroup.pack(side=tk.RIGHT)
        
    def get_groupname(self,event):
        #print("Group name you clicked:",self.usernameGroup_Menu.get())
        self.GetGroupName = self.usernameGroup_Menu.get()
    def get_username(self,event):
        #print("user name you clicked:",self.AddUsernameToGroup_Menu.get())
        self.GetUserName = self.AddUsernameToGroup_Menu.get()
          
    def addUserToGroup(self):
        if self.usernameGroup_Menu.get() == "Choose a group":
            self.usernameToGroup_tryadd_label.config(text="No group was chosen!", fg="red", font=('arial',10,'bold'))
        
        if self.AddUsernameToGroup_Menu.get() == "Choose a user":
            self.usernameToGroup_tryadd_label.config(text="No user was chosen!", fg="red", font=('arial',10,'bold'))
       
        if self.usernameGroup_Menu.get() == "Choose a group" and self.AddUsernameToGroup_Menu.get() == "Choose a user":
             self.usernameToGroup_tryadd_label.config(text="No group or user was chosen !", fg="red", font=('arial',10,'bold'))
             
        if self.AddUsernameToGroup_Menu.get() in self.Data_UserFriends and self.usernameGroup_Menu.get() in self.Data_Groups:
            print("User in friendlist!")
            
            self.AddToGroupSocket = socket(AF_INET,SOCK_STREAM)
            self.AddToGroupSocket.setsockopt(SOL_SOCKET, SO_REUSEADDR, 1)
            self.AddToGroupSocket.connect((SERVER_IP, VERIFY_PORT))

            GroupNameAdd = self.usernameGroup_Menu.get()
            UserAddToGroup = self.AddUsernameToGroup_Menu.get()
            # Data structure: [GroupName,UserToAdd,LoginName,CHECKDATA]
            self.data_string = pickle.dumps([stupidusername,GroupNameAdd,"UserAddToGroup", UserAddToGroup])
            self.AddToGroupSocket.send(self.data_string)
            datax = self.AddToGroupSocket.recv(BUFFER_SIZE)
            datax = pickle.loads(datax)
            print("From Server: {}".format(datax))
            datax = datax.split('#')
            print("From Server2: {}".format(datax))
            print("datax[0]: {}\ndatax[1]: {}:".format(datax[0],datax[1]))

            if datax[0] == "USER ALREADY IN GROUPCHAT":
                print("USER ALREADY IN GROUPCHAT")
                self.usernameToGroup_tryadd_label.config(text="User already in groupchat!", fg="red", font=('arial',10,'bold'))
                self.AddToGroupSocket.close()
            else:
                print("USER ADDED IN GROUPCHAT")
                self.usernameToGroup_tryadd_label.config(text="User added to groupchat!", fg="green", font=('arial',10,'bold'))
                self.Update_Grouplist()
                self.LoadGroups()
                self.AddToGroupSocket.close()
    
    def GroupChatWindow(self,group):
        self.chat_title.configure(text="Chat Window!", 
                                   font=('Arial',18,'bold'),
                                   bg="black", fg="white")
        
        global groupname
        groupname = group
        self.GROUPNAMETOSEND = group
        print("\nwhat is group name: {}".format(self.GROUPNAMETOSEND))
        
        self.GroupChatWindowUserFrame = tk.Frame(self.FrameChatWindow, bg="white")
        self.GroupChatWindowUserFrame.pack(side=tk.TOP,fill='both',expand=True)  
        
        self.userchatLabel = tk.Label(self.GroupChatWindowUserFrame,text="{}'s Chat".format(self.GROUPNAMETOSEND), bg="white",fg="black",font=('arial',14,'bold'), borderwidth=1)
        self.userchatLabel.pack(side=tk.TOP,expand=False,anchor='center',pady=3)
        
        self.MembersInGroup_Label = tk.Label(self.GroupChatWindowUserFrame,text="Members:",bg="white",fg="black",font=('arial',10,'bold'), borderwidth=1)
        self.MembersInGroup_Label.pack(side=tk.TOP,expand=False,anchor='center')
        
        self.MembersInGroup = tk.Text(self.GroupChatWindowUserFrame,height=1,width=70)
        self.MembersInGroup.configure(state="disabled")
        self.MembersInGroup.pack(side=tk.TOP,expand=False) 
        self.MembersInGroup.propagate(0)
        
        self.GroupChatTestFrame = tk.Frame(self.GroupChatWindowUserFrame, highlightbackground="black", highlightthickness=6,borderwidth=10,height=400,width=500,bg="white")
        self.GroupChatTestFrame.pack(side=tk.TOP,pady=5)
        self.GroupChatTestFrame.propagate(0)
        
        self.GroupChatTestFrame2 = tk.Frame(self.GroupChatTestFrame,height=500,width=16)
        self.GroupChatTestFrame2.pack(side=tk.RIGHT)
        self.GroupChatTestFrame2.propagate(0)
        
        self.gifFrame2 = tk.Frame(self.GroupChatTestFrame,height=220,width=1,bg="white")
        self.gifFrame2.pack(side=tk.BOTTOM,fill="both")
        self.gifFrame2.propagate(0)
        lbl = ImageLabel(self.gifFrame2,bg="white")
        lbl.pack(anchor="center")
        lbl.load('loading.gif')
        
        self.Groupchat_box = tk.Text(self.GroupChatTestFrame, wrap = tk.WORD)
        self.Groupchat_box.configure(state="disabled")
        #self.Groupchat_box.pack(side=tk.LEFT,expand=True,fill="both")
        self.Groupchat_box.propagate(1)
        
        scrollbarGroup = tk.Scrollbar(self.GroupChatTestFrame2,orient="vertical",command=self.Groupchat_box.yview)
        scrollbarGroup.pack(side=tk.RIGHT,fill=tk.Y)
        self.Groupchat_box['yscrollcommand'] = scrollbarGroup.set
        
        
        self.input_fieldGroup = tk.Entry(self.GroupChatWindowUserFrame,width=50,borderwidth=5,highlightbackground="black", highlightthickness=1)
        self.input_fieldGroup.pack(side=tk.TOP,pady=1)
        self.input_fieldGroup.bind("<Return>",self.key_sendmsg_group)
        self.input_fieldGroup.focus()
        
        self.thread1.set("","", self.Groupchat_box, self.input_fieldGroup)
        self.thread2.set("", self.Groupchat_box, "GROUP")
        
        self.stored_logs2 = []
        ThreadLogs2 = threading.Thread(target=self.ReadLogs,args=("group",group))
        ThreadLogs2.start()
        #ThreadLogs2.join()
        
        #self.ReadLogs("group",group)
        #self.stored_logs.remove("STOP!")
        #print("logs: ", logs)
        #self.Groupchat_box.configure(state="normal")
        #self.chat_box.insert("end","\n"+logs) ORIGINAL
        
        # Load groupname users to msg
        self.LoadSocket = socket(AF_INET,SOCK_STREAM)
        self.LoadSocket.connect((SERVER_IP, LOAD_USER_PORT))
        # Data structure: [GroupName,UserToAdd,LoginName,CHECKDATA]
        self.data_string = pickle.dumps([self.GROUPNAMETOSEND,"",stupidusername,"Load_Group_Users"])
        self.LoadSocket.send(self.data_string)
        global GroupListFriends
        GroupListFriends = self.LoadSocket.recv(BUFFER_SIZE)
        GroupListFriends = pickle.loads(GroupListFriends)
        self.LoadSocket.close()
        print("Users in group1:",GroupListFriends)
        if stupidusername in GroupListFriends:
            GroupListFriends.remove(stupidusername)
            print("Users in group2:",GroupListFriends)
        
        for i in GroupListFriends:
            print("i:",i)
            self.MembersInGroup.configure(state="normal")
            self.MembersInGroup.insert("end",i+" ")
        self.MembersInGroup.configure(state="disabled")
        
        for x in GroupListFriends:
            print("Users:",x)
        
        
        # set structure: [chatboxSINGLE, inputSINGLE, chatboxGROUP, inputGROUP]
        # set structure: [chatboxSINGLE, chatboxGROUP, state]
        self.thread1.set("","", self.Groupchat_box, self.input_fieldGroup)
        self.thread2.set("", self.Groupchat_box, "GROUP")
        
        self.buttonGroup = ttk.Button(self.GroupChatWindowUserFrame, text='Send')
        self.buttonGroup['command'] = self.send_message_button_group
        self.buttonGroup.pack() 
    
    def ReadLogs(self,state,groupname):
        global userfriend
        GroupOrSingle = state
        groupName = groupname
        self.data = ""

        self.logssocket = socket(AF_INET,SOCK_STREAM)
        self.logssocket.connect((SERVER_IP, LOGS_PORT))

        if GroupOrSingle == "single":
            # Data structure: [usernameLogin, usernameFriend, groupname]
            self.data_string = pickle.dumps([stupidusername, userfriend, "SINGLE"])
            self.logssocket.send(self.data_string)
            while True:
                self.data = self.logssocket.recv(BUFFER_SIZE)
                if self.data:
                    time.sleep(0.01)
                    #print("Getting data!")
                self.data = pickle.loads(self.data)
                self.stored_logs.append(self.data)
                if "STOP!" in self.stored_logs:
                    print(f"STOP! received")
                    print("Finished loading!")
                    self.logssocket.close()
                    self.stored_logs.remove("STOP!")
                    self.gifFrame1.destroy()
                    break
            for i in self.stored_logs:
                self.chat_box.configure(state="normal")
                if i.find("YOU:") == 0:
                    text1 = i.split(":")
                    text1.append(" ")
                    self.chat_box.tag_configure("right",justify="right")
                    self.chat_box.tag_configure('bold', font=("arial",10,"bold"))
                    self.chat_box.insert("end",text1[0]+":",("right","bold"))
                    self.chat_box.insert("end",text1[1],("right"))
                else:
                    if i.find("\n") == 0:
                        self
                    else:
                        text2 = i.split(":")
                        self.chat_box.insert("end",text2[0]+":",("bold"))
                        self.chat_box.insert("end",text2[1])
            self.chat_box.pack(side=tk.LEFT,expand=True,fill="both")
            self.chat_box.configure(state="disabled")
            self.chat_box.see("end")
          
        if GroupOrSingle == "group":
            # Data structure: [usernameLogin, usernameFriend, groupname]
            self.data_string = pickle.dumps([stupidusername, groupName, "GROUP"])
            self.logssocket.send(self.data_string)
      
            while True:
                self.data = self.logssocket.recv(BUFFER_SIZE)
                if self.data:
                    time.sleep(0.01)
                    #print("Getting data!")
                self.data = pickle.loads(self.data)
                self.stored_logs2.append(self.data)
                if "STOP!" in self.stored_logs2:
                    print(f"STOP! received")
                    print("Finished loading!")
                    self.logssocket.close()
                    self.stored_logs2.remove("STOP!")
                    self.gifFrame2.destroy()
                    break
                
            for i in self.stored_logs2:
                self.Groupchat_box.configure(state="normal")
                if i.find("YOU:") == 0:
                    text1 = i.split(":")
                    self.Groupchat_box.tag_configure("right",justify="right")
                    self.Groupchat_box.tag_configure('bold', font=("arial",10,"bold"))
                    self.Groupchat_box.insert("end",text1[0]+":",("right","bold"))
                    self.Groupchat_box.insert("end",text1[1],("right"))
                else:
                    if i.find("\n") == 0:
                        self
                    else:
                        text2 = i.split(":")
                        self.Groupchat_box.insert("end",text2[0]+":",("bold"))
                        self.Groupchat_box.insert("end",text2[1])
            self.Groupchat_box.pack(side=tk.LEFT,expand=True,fill="both")
            self.Groupchat_box.configure(state="disabled")
            self.Groupchat_box.see("end")
            
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
            self.chat.insert("end","\n")
            
            self.chat.tag_configure('bold', font=("arial",10,"bold"))
            self.chat.tag_configure("right",justify="right")
            
            self.chat.insert("end","YOU:".format(send_data),("right","bold"))
            self.chat.insert("end"," {} ".format(send_data),("right"))
            #self.chat.tag_config("bold",font=("arial",10,"bold"))
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
            
            self.chatgroup.insert("end","\n")
            self.chatgroup.tag_configure('bold', font=("arial",10,"bold"))
            self.chatgroup.tag_configure("right",justify="right")
            
            self.chatgroup.insert("end","YOU:".format(send_data),("right","bold"))
            self.chatgroup.insert("end"," {}\n".format(send_data),("right"))
            
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
            time.sleep(0.1)
            recv_string = self.ds.recv(BUFFER_SIZE)
            time.sleep(0.1)
            recv_data = pickle.loads(recv_string)
            if recv_data == "CLOSE CONN":
                break
            if self.state == "SINGLE":
                print("Writing to SINGLE chat window...")
                print("recv_data:", recv_data)
                print(f"userfriend: {userfriend}")
                print(f"recv_data[0]: {recv_data[0]}")
                if userfriend == recv_data[0]:
                    self.chat.configure(state="normal")
                    msg = "{}: {}".format(recv_data[0],recv_data[1])
                    print("====================")
                    print("msg: {}\nFrom: {}".format(recv_data[1],recv_data[0]))
                    print("====================")
                    self.chat.tag_configure('bold', font=("arial",10,"bold"))
                    self.chat.insert("end","\n")
                    self.chat.insert("end",f"{recv_data[0]}:","bold")
                    self.chat.insert("end",f" {recv_data[1]}")
                    #self.chat.insert("end","\n"+msg+"\n")
                    self.chat.configure(state="disabled")
                    self.chat.see("end")
            if self.state == "GROUP":
                print("Writing to GROUP chat window...")
                print("recv_data:", recv_data)
                print(f"userfriend: {userfriend}")
                print(f"groupname: {groupname}")
                print(f"recv_data[3]: {recv_data[3]}")
                if groupname == recv_data[3]:
                    self.chatgroup.configure(state="normal")
                    msg = "{}: {}".format(recv_data[0],recv_data[1])
                    print("====================")
                    print("msg: {}\nFrom: {}".format(recv_data[1],recv_data[0]))
                    print("====================")
                    self.chatgroup.tag_configure('bold', font=("arial",10,"bold"))
                    self.chatgroup.insert("end","\n")
                    self.chatgroup.insert("end",f"{recv_data[0]:}","bold")
                    self.chatgroup.insert("end",f" {recv_data[1]}")
                    #self.chatgroup.insert("end","\n"+msg+"\n")
                    self.chatgroup.configure(state="disabled")
                    self.chatgroup.see("end")
    # set structure: [chatboxSINGLE, chatboxGROUP, state]
    def set(self,chat_box,chat_box_group,state):
        self.state = state
        self.chat = chat_box
        self.chatgroup = chat_box_group  

class ImageLabel(tk.Label):
    """
    A Label that displays images, and plays them if they are gifs
    :im: A PIL Image instance or a string filename
    """
    def load(self, im):
        if isinstance(im, str):
            im = Image.open(im)
        frames = []

        try:
            for i in count(1):
                frames.append(ImageTk.PhotoImage(im.copy()))
                im.seek(i)
        except EOFError:
            pass
        self.frames = cycle(frames)

        try:
            self.delay = im.info['duration']
        except:
            self.delay = 100

        if len(frames) == 1:
            self.config(image=next(self.frames))
        else:
            self.next_frame()

    def unload(self):
        self.config(image=None)
        self.frames = None

    def next_frame(self):
        if self.frames:
            self.config(image=next(self.frames))
            self.after(self.delay, self.next_frame)

if __name__=="__main__":
    SERVER_IP = input("Enter server IP: ")
    print(f"string length: {len(SERVER_IP)}")
    if len(SERVER_IP) == 0:
        SERVER_IP = "127.0.0.1"
    
    Main = Page_Login()
