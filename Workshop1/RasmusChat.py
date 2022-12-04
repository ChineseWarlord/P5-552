import tkinter as tk
from tkinter import ttk
from socket import *
import threading
import time
import pickle
import select

SERVER_IP = "127.0.0.1"
SERVER_PORT = 1234
BUFFER_SIZE = 1024

class GUI():
    def __init__(self):
        self.Window = tk.Tk()
        self.Window.withdraw()

        self.test = tk.Toplevel()
        self.test.title("Opening Screen")
        self.test.resizable(width=False, height=False)
        self.test.configure(width=600, height=300)

        row = tk.Frame(self.test)
        row.pack(side=tk.TOP, fill=tk.X, padx=5, pady=0)
        tk.Label(row, text="Name:").pack(side=tk.BOTTOM)

        row = tk.Frame(self.test)
        row.pack(side=tk.TOP, fill=tk.X, padx=5, pady=0)
        self.e1 = tk.Entry(row)
        self.e1.pack(side=tk.RIGHT, expand=tk.YES, fill=tk.X)

        self.go = ttk.Button(self.test, text="Login")
        self.go['command'] = self.login
        self.go.pack(side=tk.LEFT, padx=5, pady=5)

        self.quit = ttk.Button(self.test, text="Quit")
        self.quit['command'] = self.Window.quit
        self.quit.pack(side=tk.LEFT, padx=5, pady=5)

        self.Window.mainloop()

    def login(self):
        self.name = self.e1.get()
        self.test.destroy()
        self.chat()

    def chat(self):
        self.Window.deiconify()
        self.Window.title("Awesome Chat Program")

        row = tk.Frame(self.Window)
        row.pack(side=tk.TOP, fill=tk.X, padx=5, pady=0)
        tk.Label(row, text=f"Name: {self.name}").pack(side=tk.LEFT)

        self.chat_box = tk.Text(self.Window, height=8)
        self.chat_box.configure(state="disabled")
        self.chat_box.pack()

        self.input_field = tk.Text(self.Window, height= 3)
        self.input_field.pack()

        self.button = ttk.Button(self.Window, text='Send')
        self.button['command'] = self.send_message_button
        self.button.pack()

        self.s = socket(AF_INET,SOCK_STREAM)
        self.s.connect((SERVER_IP, SERVER_PORT))
        connect_list=["CONNECT",self.name]
        data_string = pickle.dumps(connect_list)
        self.s.send(data_string)
        data = self.s.recv(BUFFER_SIZE)
        data_list = pickle.loads(data)
        print("{}".format(data_list[0]))

        if data_list[0]=="OK":
            self.chat_box.configure(state="normal")
            self.chat_box.insert('1.0', 'Reply from server: you are now connected.\n')
            self.chat_box.insert('2.0', 'There {} online users right now.'.format(data_list[2]))
            self.chat_box.configure(state="disabled")
            NEW_PORT=data_list[3]
            print(NEW_PORT)
            ds = socket(AF_INET,SOCK_STREAM)
            ds.connect((SERVER_IP, NEW_PORT))
            self.event = threading.Event()
            self.thread1 = SendData(ds,self.name, self.input_field, self.chat_box)
            self.thread2 = ReceiveData(ds, self.chat_box, self.event)
            self.thread2.start()
        
        else:
            print("Reply from server: server is full. Retry later.")
        
        self.input_field.bind("<Return>", self.send_message_enter)

        self.quit = ttk.Button(self.Window, text="Quit")
        self.quit['command'] = self.quit_program
        self.quit.pack(side=tk.RIGHT, padx=5, pady=5)

    def send_message_button(self):
        self.thread1.send()
        self.input_field.delete("1.0", "end")
    
    def send_message_enter(self, event):
        self.thread1.send()
        self.input_field.delete("1.0", "end")
        return "break"
    
    def quit_program(self):
        self.thread1.exit()
        self.event.set()
        self.thread2.join()
        self.Window.quit()
        
class SendData():
    def __init__(self,tcp_socket, user, input_field, chat_box):
        self.ds=tcp_socket
        self.uu=user
        self.input = input_field
        self.chat = chat_box
    def send(self):
            test_string = input()
            #send_data = self.input.get("1.0", "end")
            send_data = self.input.get(test_string)
            print("What is send_data: {}".format(send_data))
            #test_string = ""
            if len(send_data) > 1:
                chat_data=[self.uu, test_string]
                chat_string = pickle.dumps(chat_data)
                self.ds.send(chat_string)
                self.chat.configure(state="normal")
                self.chat.insert("1.0","YOU: {}".format(send_data))
                self.chat.configure(state="disabled")
    def exit(self):
            chat_data=[self.uu, "EEXIT"]
            chat_string = pickle.dumps(chat_data)
            self.ds.send(chat_string)
            print("Connection closed.")

                
class ReceiveData(threading.Thread):
    def __init__(self,tcp_socket, chat_box, event):
        threading.Thread.__init__(self)
        self.ds=tcp_socket
        self.chat = chat_box
        self.event = event
    def run(self):
        self.ds.setblocking(0)
        while True:
            if self.event.is_set():
                break
            ready = select.select([self.ds], [], [])
            if ready[0]:
                recv_string = self.ds.recv(BUFFER_SIZE)
                recv_data = pickle.loads(recv_string)
                if (recv_data[0] != "Server"):
                    self.chat.configure(state="normal")
                    self.chat.insert("1.0","{}: {}".format(recv_data[0],recv_data[1]))
                    self.chat.configure(state="disabled")
                else:
                    print(recv_data[1])

if __name__ == "__main__":
    gui = GUI()
    
    import tkinter as tk
from tkinter import ttk

root = tk.Tk()
root.resizable(False, False)
root.title("Scrollbar Widget Example")

# apply the grid layout
root.grid_columnconfigure(0, weight=1)
root.grid_rowconfigure(0, weight=1)

# create the text widget
text = tk.Text(root, height=10)
text.grid(row=0, column=0, sticky=tk.EW)

# create a scrollbar widget and set its command to the text widget
scrollbar = ttk.Scrollbar(root, orient='vertical', command=text.yview)
scrollbar.grid(row=0, column=1, sticky=tk.NS)

#  communicate back to the scrollbar
text['yscrollcommand'] = scrollbar.set

# add sample text to the text widget to show the screen
for i in range(1,50):
    position = f'{i}.0'
    text.insert(position,f'Line {i}\n');

root.mainloop()