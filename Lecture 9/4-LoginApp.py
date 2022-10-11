import tkinter as tk

class PackLoginApp(tk.Tk):
    def __init__(self):
        super().__init__()
        self.title("University Log In")
        self.frame1 = tk.Frame(master=self, borderwidth=1)
        self.frame1.pack()
        self.title_label = tk.Label(self.frame1, text="Log In")
        self.title_label.pack(side=tk.LEFT)

        self.frame2 = tk.Frame(master=self, borderwidth=1)
        self.frame2.pack()
        self.username_label = tk.Label(self.frame2,text="Username")
        self.username_label.pack(side=tk.LEFT)
        self.username_entry = tk.Entry(self.frame2, width=50)
        self.username_entry.pack(side=tk.LEFT)


        self.frame3 = tk.Frame(master=self, borderwidth=1)
        self.frame3.pack()
        self.pwd_label = tk.Label(self.frame3,text="Password")
        self.pwd_label.pack(side=tk.LEFT)
        self.pwd_entry = tk.Entry(self.frame3, width=50)
        self.pwd_entry.pack(side=tk.LEFT)

        self.frame4 = tk.Frame(master=self, borderwidth=1)
        self.frame4.pack()
        self.login_button = tk.Button(self.frame4, text="Log In",command=self.log_in, bg="#211A52", fg = "white")
        self.login_button.pack(side=tk.LEFT)
        #self.login_button.bind("<Button-1>", self.on_press)
    def log_in(self):
        entered_username = self.username_entry.get()
        self.username_entry.delete(0, 'end')
        entered_pwd = self.pwd_entry.get()
        self.pwd_entry.delete(0, 'end')
        if entered_username == "JohnDoe" and entered_pwd=="drowssap":
            self.title_label.config(text="Login successful!", fg="#211A52")
        else:
            self.title_label.config(text="Incorrect username and/or password!", fg="red")


class GridLoginApp(tk.Tk):
    def __init__(self):
        super().__init__()
        self.title("University Log In")
        frame = tk.Frame(master=self, borderwidth=1)
        frame.grid(row=0, column=0)
        self.title_label = tk.Label(frame, text="Log In")
        self.title_label.pack()

        frame = tk.Frame(master=self, borderwidth=1)
        frame.grid(row=1, column=0)
        self.username_label = tk.Label(frame,text="Username")
        self.username_label.pack()

        frame = tk.Frame(master=self, borderwidth=1)
        frame.grid(row=1, column=1)
        self.username_entry = tk.Entry(frame, width=50)
        self.username_entry.pack()


        frame = tk.Frame(master=self, borderwidth=1)
        frame.grid(row=2, column=0)
        self.pwd_label = tk.Label(frame,text="Password")
        self.pwd_label.pack()
        frame = tk.Frame(master=self, borderwidth=1)
        frame.grid(row=2, column=1)
        self.pwd_entry = tk.Entry(frame, width=50)
        self.pwd_entry.pack()

        frame = tk.Frame(master=self, borderwidth=1)
        frame.grid(row=3, column=0)
        self.login_button = tk.Button(frame, text="Log In",command=self.log_in, bg="#211A52", fg = "white")
        self.login_button.pack()
    def log_in(self):
        entered_username = self.username_entry.get()
        self.username_entry.delete(0, 'end')
        entered_pwd = self.pwd_entry.get()
        self.pwd_entry.delete(0, 'end')
        if entered_username == "JohnDoe" and entered_pwd=="drowssap":
            self.title_label.config(text="Login successful!", fg="#211A52")
        else:
            self.title_label.config(text="Incorrect username and/or password!", fg="red")



        

if __name__=="__main__":
    myapp = PackLoginApp()
    myapp.mainloop()

    myapp = GridLoginApp()
    myapp.mainloop()

    