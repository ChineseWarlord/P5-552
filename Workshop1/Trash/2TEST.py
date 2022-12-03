 #Import the required libraries
import csv
import tkinter as tk
from tkinter import ttk
from socket import *
import threading
import time
import pickle
import os
import sys
import select
from tkinter import messagebox

class Page_Group_Chat(tk.Frame):
    def __init__(self):
        tk.Frame.__init__(self)
 # Frame for Friend List on the left side
        self.FrameFriendList = tk.Frame(root, 
                                   bg="yellow",
                                   borderwidth=1,
                                   highlightbackground="blue", 
                                   highlightthickness=6,
                                   width=800,
                                   height=800)
        self.FrameFriendList.pack(expand=True,fill="both")
        self.FrameFriendList.propagate(0)
        
        self.FrameShit = tk.Frame(self.FrameFriendList, 
                                   bg="green",
                                   borderwidth=1,
                                   highlightbackground="black", 
                                   highlightthickness=6,
                                   height=20,
                                   width=1000)
        self.FrameShit.pack(expand=False)
        self.FrameFriendList.propagate(0)
        
        # Canvas to hold frame
        self.CanvasFriendList = tk.Canvas(self.FrameShit,height=100,width=500)
        self.CanvasFriendList.pack(side=tk.LEFT,expand=False)
        # Scrollbar to canvas
        self.ScrollBarCanvasFriendList = tk.Scrollbar(self.FrameShit, orient="vertical", command=self.CanvasFriendList.yview)
        self.ScrollBarCanvasFriendList.pack(side=tk.LEFT,fill=tk.Y)
        # Configure canvas
        self.CanvasFriendList.configure(yscrollcommand=self.ScrollBarCanvasFriendList.set)
        self.CanvasFriendList.bind("<Configure>",lambda e: self.CanvasFriendList.configure(scrollregion=self.CanvasFriendList.bbox("all")))
        # Frame inside canvas holding friend buttons
        self.FrameFriendListCanvas = tk.Frame(self.CanvasFriendList)
        self.CanvasFriendList.create_window((85,0),window=self.FrameFriendListCanvas,anchor="s")
        
        for buttons in range (100):
           test = tk.Button(self.FrameFriendListCanvas, text=f"Button {buttons}")
           test.pack(pady=5)
           
if __name__=="__main__":
    root = tk.Tk()
    #root.withdraw()
    #root = tk.Toplevel()
    #root.geometry("300x250")
    root.title("TEST!")

   
    #test = PersistentLogs()
    #test.WriteToLog(test,"LORT")
    #test.ReadLog(test)
    
    root = Page_Group_Chat()
    
    #root.add_page("Page_Group_Chat",Page_Group_Chat)
    #root.show_frame("Page_Group_Chat")
    root.mainloop()