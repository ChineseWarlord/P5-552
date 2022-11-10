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
BUFFER_SIZE = 1024



class MainView(tk.Tk):
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
        
        self.frame1 = tk.Frame(master=self, borderwidth=1, background="blue")
        self.frame1.pack()
        self.title_label = tk.Label(self.frame1, text="Awesome Chat Program!", font=('Arial',18,'bold'))
        self.title_label.pack(side=tk.LEFT)

        self.frame2 = tk.Frame(master=self, borderwidth=1, background="red")
        self.frame2.pack()
        self.username_label = tk.Label(self.frame2,text="Username")
        self.username_label.pack(side=tk.TOP)
        self.username_entry = tk.Entry(self.frame2, width=50, borderwidth=10)
        self.username_entry.pack(side=tk.LEFT)
        self.username_entry.bind("<Return>",self.key_pressed)


        self.frame3 = tk.Frame(master=self, borderwidth=1, background="black")
        self.frame3.pack()
        self.pwd_label = tk.Label(self.frame3,text="Password")
        self.pwd_label.pack(side=tk.TOP)
        self.pwd_entry = tk.Entry(self.frame3, width=50,borderwidth=10)
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
        if entered_username == "sim" and entered_pwd=="123":
            self.title_label.config(text="Login successful!", fg="#211A52", font=('arial',10,'bold'))
        else:
            self.title_label.config(text="Incorrect username and/or password!", fg="red", font=('arial',10,'bold'))
            
    def register(self):
        register = Page_UserRegistration()
        register.lift()
        

class Page_UserRegistration(tk.Frame):
    def __init__(self,parent,controller):
        
        tk.Frame.__init__(self,parent)
        self.controller = controller
        
        self.ListOfUsernames = tk.StringVar()
        self.ListOfPasswords = tk.StringVar()
        
        self.frame1 = tk.Frame(master=self, borderwidth=10, bg="blue")
        self.frame1.pack()
        self.register_title_label = tk.Label(self.frame1, text="User Registration")
        self.register_title_label.pack(side=tk.LEFT)

        self.frame2 = tk.Frame(master=self, borderwidth=10, bg="red")
        self.frame2.pack()
        self.username_label = tk.Label(self.frame2,text="Username")
        self.username_label.pack(side=tk.LEFT)
        self.username_entry = tk.Entry(self.frame2, width=50,textvariable=self.ListOfUsernames)
        self.username_entry.pack()
        self.username_entry.focus()


        self.frame3 = tk.Frame(master=self, borderwidth=10, bg="green")
        self.frame3.pack()
        self.pwd_label = tk.Label(self.frame3,text="Password")
        self.pwd_label.pack(side=tk.LEFT)
        self.pwd_entry = tk.Entry(self.frame3, width=50,textvariable=self.ListOfPasswords,show="*")
        self.pwd_entry.pack()
        
        self.frame4 = tk.Frame(master=self, borderwidth=10,bg="yellow")
        self.frame4.pack()
        self.register_button = tk.Button(self.frame4, text="Register now",command=lambda:self.register_user(), bg="#211A52", fg = "white")
        self.register_button.pack(side=tk.LEFT)
        
        self.return_button = tk.Button(self.frame4, text="Return",command=lambda : controller.show_frame(Page_Login), bg="#211A52", fg = "white")
        self.return_button.pack(side=tk.LEFT)
        
    def register_user(self):
        # Connect to server
        # Add user credentials to server
        # Receive OK from server
        
        if not self.ListOfUsernames.get():
            self.register_title_label.config(text="No Username was entered!", fg="red", font=('arial',10,'bold'))
        if not self.ListOfPasswords.get():
            self.register_title_label.config(text="No Password was entered!", fg="red", font=('arial',10,'bold'))
        if not self.ListOfUsernames.get() and not self.ListOfPasswords.get():
            self.register_title_label.config(text="No Username or Password was entered!", fg="red", font=('arial',10,'bold'))
        if self.ListOfUsernames.get() and self.ListOfPasswords.get():
            print(f"Username: {self.ListOfUsernames.get()} \n" + f"Password: {self.ListOfPasswords.get()}")
            self.register_title_label.config(text="User Registration Successful!", fg="red", font=('arial',10,'bold'))
            
        # Check with server is user is already registered  
        

if __name__=="__main__":
    myapp = MainView()
    myapp.mainloop()
    
