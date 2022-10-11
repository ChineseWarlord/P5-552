from tkinter import *
from tkinter import ttk
window = Tk()
frm = ttk.Frame(window, padding=10)
frm.grid()
ttk.Label(frm, text="Hello World!").grid(column=0, row=0)
ttk.Button(frm, text="Quit", command=window.destroy).grid(column=1, row=0)
window.mainloop()
