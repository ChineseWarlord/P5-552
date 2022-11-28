#Import the required libraries
from tkinter import *
from tkinter import ttk

#Create an instance of Tkinter Frame
win = Tk()

#Set the geometry of Tkinter Frame
win.geometry("700x350")

#Create an object of Scrollbar widget
s = Scrollbar()

#Create a horizontal scrollbar
scrollbar = ttk.Scrollbar(win, orient= 'vertical')
scrollbar.pack(side= RIGHT, fill= BOTH)

#Add a Listbox Widget
listbox = Listbox(win, width= 350, font= ('Helvetica 15 bold'))
listbox.pack(side= LEFT, fill= BOTH)

#Add values to the Listbox
for values in range(1,101):
   listbox.insert(END, values)

listbox.config(yscrollcommand= scrollbar.set)

#Configure the scrollbar
scrollbar.config(command= listbox.yview)

win.mainloop()