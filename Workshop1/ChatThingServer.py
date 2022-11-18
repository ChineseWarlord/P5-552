"""
Project 1: encrypted chat

Design a secure chat system, with the following features:

● A separate server that only handles key and message exchange
● Encrypted group chats
● Persistent chat logs that are loaded if you close and reopen the program

You can assume the server can be trusted for the key exchange, but it should not
be able to decode messages
"""

import tkinter as tk
from tkinter import ttk
from socket import *
import threading
import time
import pickle

SERVER_IP = "127.0.0.1"
SERVER_PORT = 1234
VERIFY_PORT = 65432
BUFFER_SIZE = 1024

root = tk.Tk()
#root.withdraw()
#root = tk.Toplevel()
root.geometry("700x550")
root.title("Awesome Chat Program!")

stupidusername = ""

class Main_View(tk.Tk):
    def __init__(self):
        #super().__init__()
        tk.Frame.__init__(self)
        
        #self.title("Awesome Chat Program!")
        container = tk.Frame(root)
        container.pack(side=tk.TOP,fill="both",expand=True)
        container.grid_rowconfigure(0, weight = 1)
        container.grid_columnconfigure(0, weight = 1)
          
        self.frames = {}
        
        for FRAMES in (Page_Login, Page_UserRegistration, Page_Chat):
            frame = FRAMES(container,self)
            self.frames[FRAMES] = frame
            frame.grid()
            frame.grid(row = 0, column = 0, sticky ="nsew")

        
        self.show_frame(Page_Login)
        #self.show_frame(Page_Chat)
        
    def show_frame(self, cont):
        frame = self.frames[cont]
        frame.tkraise()
        
class Page_Login(tk.Frame):
    def __init__(self, parent, controller):
        tk.Frame.__init__(self, parent)
        
        self.controller = controller
        self.UsernameLogin = tk.StringVar()
        self.PasswordLogin = tk.StringVar()
        

        #self.frame1 = tk.Frame(master=self, borderwidth=1, background="blue")
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
        
        tester = Page_Chat(self,self)
        
        self.login_button = tk.Button(self.frame4, text="Log In",command=lambda : [self.log_in(),self.clear_entry(), ], bg="#211A52", fg = "white")
        self.register_page_button = tk.Button(self.frame4, text="Register now",command=lambda : [controller.show_frame(Page_UserRegistration),self.clear_entry(),tester.ReturnUsername()], bg="#211A52", fg = "white")
        self.login_button.pack(side=tk.LEFT)
        self.register_page_button.pack(side=tk.RIGHT)
        
        
    def key_pressed(self, event):
        self.log_in()
        self.clear_entry()
        
    def clear_entry(self):
        self.username_entry_login.delete(0, 'end')
        self.pwd_entry_login.delete(0, 'end')
        
    def log_in(self):
        print("USER: "+self.UsernameLogin.get())
        print("PASS: "+self.PasswordLogin.get())
        
        self.se = socket(AF_INET,SOCK_STREAM)
        self.se.connect((SERVER_IP, VERIFY_PORT))
        
        
        stupidusername = self.UsernameLogin.get()
        print("stupidusername: {}".format(stupidusername))  
        tester = Page_Chat(self,self)
        cancer = tester.ReturnUsername(stupidusername)
        print("stupidusername11: {}".format(cancer))  
        
        data_User = self.UsernameLogin.get()
        data_Pass = self.PasswordLogin.get()
        
        print("data_User: {}\ndata_Pass: {}".format(data_User, data_Pass))
        
        data_Check = "userlogin"
        self.data_string = pickle.dumps([data_User, data_Pass, data_Check])
        self.se.send(self.data_string)
        data = self.se.recv(BUFFER_SIZE)
        data = pickle.loads(data)
        print("From Server: {}".format(data))
            
        if data == "YES LOGIN!":
            print("OK LOGIN :)")
            print(f"Username: {self.UsernameLogin.get()} \n" + f"Password: {self.PasswordLogin.get()}")
            self.title_label.config(text="Awesome Chat Program!", fg="black", font=('Arial',18,'bold'))
            self.controller.show_frame(Page_Chat)
        if data == "NO LOGIN!":
            print("NOT LOGIN :(")
            self.title_label.config(text="Incorrect username and/or password!", fg="red", font=('arial',10,'bold'))
           
           
class Page_UserRegistration(tk.Frame):
    def __init__(self,parent,controller):
        tk.Frame.__init__(self,parent)
        
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
        
        
        self.return_button = tk.Button(self.frame4, text="Return",command=lambda : [controller.show_frame(Page_Login),self.clear_entry()], bg="#211A52", fg = "white")
        self.return_button.pack(side=tk.LEFT)
        self.register_title_label.config(text="User Registration")
    
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
        if data == "NOT OK!":
            print("NOT OK from server :)")
            self.register_title_label.config(text="User already registered!", fg="red", font=('arial',10,'bold'))            
         
class Page_Chat(tk.Frame):
    def __init__(self,parent,controller):
        tk.Frame.__init__(self,parent)
        
        self.controller = controller
        
        # Title label
        self.frame_main = tk.Frame(self,
                                   highlightbackground="red", 
                                   highlightthickness=6,
                                   bg="blue")
        self.frame_main.pack(fill='both',expand=True)
        self.chat_title = tk.Label(self.frame_main, 
                                   text="Welcome! ", 
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
        # User Frame
        self.frame2 = tk.Frame(self.main_frame, bg="blue",borderwidth=50,height=100,width=250,highlightbackground="green", highlightthickness=4)
        self.frame2.pack(side=tk.TOP,expand=True,fill='both', padx=10,pady=10)
        self.frame2.propagate(False)
        self
        # Exit Frame
        self.frame3 = tk.Frame(self.main_frame, bg="black",borderwidth=5,highlightbackground="yellow", highlightthickness=4)
        self.frame3.pack(side=tk.BOTTOM,expand=False,fill=tk.X)
        
        # Chat + Settings label
        #self.chat_label = tk.Label(self.frame1, text="Chat Menu", bg="yellow", fg="black", borderwidth=20)
        #self.chat_label = tk.Label(self.frame1, text="Chat Menu",height=1, bg="yellow", fg="black",borderwidth=1,relief="raised")
        self.chat_label = tk.Button(self.frame1, text="Chat Menu",font=('arial',10,'bold'),height=1, bg="yellow", fg = "black", borderwidth=1,relief="raised")
        self.chat_label.pack(side=tk.LEFT,fill=tk.X, expand=True,padx=1.5, pady=1.5)
        
        self.add_user = tk.Button(self.frame1, text="+",font=('arial',10,'bold'),height=1,command=lambda : [self.Add_Users_Window()], bg="white", fg = "black", borderwidth=1,relief="raised")
        self.add_user.pack(side=tk.LEFT,fill=tk.X, expand=True, padx=1.5, pady=1.5)
        
        self.settings_label = tk.Button(self.frame1, text="Settings",font=('arial',10,'bold'),height=1,command=lambda : [controller.show_frame(Page_Login)], bg="magenta", fg = "black", borderwidth=1,relief="raised")
        self.settings_label.pack(side=tk.LEFT,fill=tk.X, expand=True, padx=1.5, pady=1.5)
        
        # EXIT button
        self.return_button = tk.Button(self.frame3, text="EXIT",command=lambda : [controller.show_frame(Page_Login)], bg="#211A52", fg = "white")
        self.return_button.pack(side=tk.TOP,expand=False)
        #self.return_button.pack(side=tk.TOP)
        
        # Chat Window
        self.frame4 = tk.Frame(self.frame_main,
                               borderwidth=100, 
                               bg="yellow",
                               highlightbackground="green", 
                               highlightthickness=6)
        self.frame4.pack(side=tk.TOP,fill='both',expand=True)
        self.Chat_Label = tk.Label(self.frame4,text="Chat Window", bg="green", fg="white",font=('arial',10,'bold'), borderwidth=1)
        self.Chat_Label.pack(fill='both',expand=True)
        
    def ReturnUsername(self, stupidusername1):
        self.stupid = stupidusername1
        print("stupid 12312: {}".format(self.stupid))
        self.chat_title.config(text="Welcome!123123 {}".format(self.stupid),
                                    font=('Arial',18,'bold'),
                                   bg="black", fg="white",
                                   highlightbackground="blue",
                                   highlightthickness=6)
        
        return self.stupid
    
    def key_pressed(self, event):
        self.AddShit()
        self.clear_entry()  
          
    def clear_entry(self):
        self.usernameadd_entry.delete(0, 'end')
            
    def Add_Users_Window(self):
        self.Add_User_Frame = tk.Toplevel(root)
        self.Add_User_Frame.title("Add User")
        self.Add_User_Frame.geometry("300x100")
        self.Add_User_Frame.resizable(False, False)
        
        self.UsernameAdd = tk.StringVar()
        
        self.frameadd = tk.Frame(self.Add_User_Frame, borderwidth=10, bg="red")
        self.frameadd.pack(side=tk.TOP,fill='both',expand=True)
        self.frameadd_User = tk.Frame(self.frameadd, borderwidth=5, bg="Blue")
        self.frameadd_User.pack(side=tk.TOP)
        self.frameadd_User_BUT = tk.Frame(self.frameadd, borderwidth=5, bg="Green")
        self.frameadd_User_BUT.pack(side=tk.TOP)
        
        self.username_label = tk.Label(self.frameadd_User,text="Username:")
        self.username_label.pack(side=tk.LEFT,padx=5, pady=5)
        
        self.usernameadd_entry = tk.Entry(self.frameadd_User, width=50,textvariable=self.UsernameAdd)
        self.usernameadd_entry.pack(side=tk.RIGHT)
        self.usernameadd_entry.bind("<Return>",self.key_pressed)
        self.usernameadd_entry.focus()
            
        self.Add_User_Button = tk.Button(self.frameadd_User_BUT, text="Add user",command=lambda : [self.AddShit(),self.clear_entry()], bg="#211A52", fg = "white")
        self.Add_User_Button.pack(side=tk.BOTTOM)
        
        
        
    def AddShit(self):
        # When login - remember username and add a file to store added users.
        # After login read through file with stored added users and load them into frame.
        
        print(self.UsernameAdd.get())
        
        self.UserAdded = tk.Button(self.frame2,text="{}".format(self.UsernameAdd.get()),
                                   command=lambda : [self.doshit()], 
                                   bg="green", fg="white",font=('arial',10,'bold'), borderwidth=1)
        self.UserAdded.pack(side=tk.TOP,expand=False,anchor='w')
        #self.Add_User_Frame.deiconify()
        self.Add_User_Frame.withdraw()
        
    def doshit(self):
        print("Do shit")      
 
 

if __name__=="__main__":
    #myapp = Main_View()
    #myapp.mainloop()

    root = Main_View()
    root.mainloop()
