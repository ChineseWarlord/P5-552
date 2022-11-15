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
VERIFY_PORT_REGISTER = 65432
VERIFY_PORT_LOGIN = 65433
BUFFER_SIZE = 1024



class Main_View(tk.Tk):
    def __init__(self):
        #tk.Tk.__init__(self)
        super().__init__()
        self.title("Awesome Chat Program!")
        container = tk.Frame(self)
        container.pack(side="top",fill="both",expand=True)
        container.grid_rowconfigure(0, weight = 1)
        container.grid_columnconfigure(0, weight = 1)
          
        self.frames = {}
        
        for FRAMES in (Page_Login, Page_UserRegistration):
            frame = FRAMES(container,self)
            self.frames[FRAMES] = frame
            frame.grid()
            frame.grid(row = 0, column = 0, sticky ="nsew")
  
        self.show_frame(Page_Login)
        
    def show_frame(self, cont):
        frame = self.frames[cont]
        frame.tkraise()
        
class Page_Login(tk.Frame):
    def __init__(self, parent, controller):
        
        tk.Frame.__init__(self, parent)
        self.controller = controller
        self.Username = tk.StringVar()
        self.Password = tk.StringVar()
        
        self.frame1 = tk.Frame(master=self, borderwidth=1, background="blue")
        self.frame1.pack()
        self.title_label = tk.Label(self.frame1, text="Awesome Chat Program!", font=('Arial',18,'bold'))
        self.title_label.pack(side=tk.LEFT)

        self.frame2 = tk.Frame(master=self, borderwidth=1, background="red")
        self.frame2.pack()
        self.username_label = tk.Label(self.frame2,text="Username")
        self.username_label.pack(side=tk.TOP)
        self.username_entry = tk.Entry(self.frame2, width=50, borderwidth=10,textvariable=self.Username)
        self.username_entry.pack(side=tk.LEFT)
        self.username_entry.bind("<Return>",self.key_pressed)
        self.username_entry.get()


        self.frame3 = tk.Frame(master=self, borderwidth=1, background="black")
        self.frame3.pack()
        self.pwd_label = tk.Label(self.frame3,text="Password")
        self.pwd_label.pack(side=tk.TOP)
        self.pwd_entry = tk.Entry(self.frame3, width=50,borderwidth=10,textvariable=self.Password)
        self.pwd_entry.pack(side=tk.LEFT)
        self.pwd_entry.bind("<Return>",self.key_pressed)

        self.frame4 = tk.Frame(master=self, borderwidth=10, background="green")
        self.frame4.pack()
        self.login_button = tk.Button(self.frame4, text="Log In",command=self.log_in, bg="#211A52", fg = "white")
        self.register_page_button = tk.Button(self.frame4, text="Register now",command=lambda : controller.show_frame(Page_UserRegistration), bg="#211A52", fg = "white")
        self.login_button.pack(side=tk.LEFT)
        self.register_page_button.pack(side=tk.RIGHT)
        
        
    def key_pressed(self, event):
        self.log_in()
        
    def log_in(self):
        entered_username = self.username_entry.get()
        self.username_entry.delete(0, 'end')
        entered_pwd = self.pwd_entry.get()
        self.pwd_entry.delete(0, 'end')
        
        self.se = socket(AF_INET,SOCK_STREAM)
        self.se.connect((SERVER_IP, VERIFY_PORT_LOGIN))
        data_User = self.Username.get()
        data_Pass = self.Password.get()
        self.data_string = pickle.dumps([data_User, data_Pass])
        self.se.send(self.data_string)
        data = self.se.recv(BUFFER_SIZE)
        data = pickle.loads(data)
        print("From Server: {}".format(data))
            
        if data == "YES OK!":
            print("OK from server :)")
            print(f"Username: {self.Username.get()} \n" + f"Password: {self.Password.get()}")
            self.title_label.config(text="Login successful!", fg="#211A52", font=('arial',10,'bold'))
        if data == "NOT OK!":
            print("NOT OK from server :)")
            self.title_label.config(text="Incorrect username and/or password!", fg="red", font=('arial',10,'bold'))        
    
            
    def register(self):
        register = Page_UserRegistration()
        register.lift()       

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
        self.username_label = tk.Label(self.frame2,text="Username")
        self.username_label.pack(side=tk.LEFT)
        self.username_entry = tk.Entry(self.frame2, width=50,textvariable=self.Username)
        self.username_entry.pack()
        self.username_entry.bind("<Return>",self.key_pressed)

        self.frame3 = tk.Frame(master=self, borderwidth=10, bg="green")
        self.frame3.pack()
        self.pwd_label = tk.Label(self.frame3,text="Password")
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
    
    def key_pressed(self, event):
        self.register_user()
        self.clear_entry()
    
    def clear_entry(self):
        self.username_entry.delete(0, 'end')
        self.pwd_entry.delete(0, 'end')
        
    def register_user(self):
        # Connect to server
        # Add user credentials to server
        # Receive OK from server
        
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
        self.se.connect((SERVER_IP, VERIFY_PORT_REGISTER))
        data_User = self.Username.get()
        data_Pass = self.Password.get()
        self.data_string = pickle.dumps([data_User, data_Pass])
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
        
        #self.s = socket(AF_INET,SOCK_STREAM)
        #self.s.connect((SERVER_IP, SERVER_PORT))
        #UserRegister = self.Username.get()
        #self.connect_list=["CONNECT", UserRegister]
        #self.data_string = pickle.dumps(self.connect_list)
        #self.s.send(self.data_string)
        #data = self.s.recv(BUFFER_SIZE)
        #data_list = pickle.loads(data)
        #if data_list[0] == "OK":
            #print("Server replied with: OK")
            #NEW_PORT=data_list[3]
            #print(NEW_PORT)
            #ds = socket(AF_INET,SOCK_STREAM)
            #ds.connect((SERVER_IP, NEW_PORT))
            #Name = UserRegister
            #self.SendData(ds,Name)
            
    def SendData(self, tcp_socket, user):
        self.ds=tcp_socket
        self.uu=user
        send_data = self.Password.get()
        chat_data=[self.uu,send_data]
        chat_string = pickle.dumps(chat_data)
        self.ds.send(chat_string)
        
        send_data2 = "EEXIT"
        print(send_data)
        cancer_data = [self.uu, send_data2]
        chat_cancer = pickle.dumps(cancer_data)
        self.ds.send(chat_cancer)
                
        
if __name__=="__main__":
    myapp = Main_View()
    myapp.mainloop()
    
