###Tkinter Scrolling with Text###

'''Make text scroll to the bottom of the text box as new entries appear'''

from tkinter import *
from tkinter.scrolledtext import *


window = Tk()

window.wm_title("Scroll From Bottom")

TextBox = ScrolledText(window, height='10', width='45', wrap=WORD)

#
#Just adds 100 lines to the TextBox
count = 0
this = input()
if this == "hej":
    while(count<100):
    
        TextBox.insert(END, "The count is: " +str(count)+"\n")
    
        #Pushes the scrollbar and focus of text to the end of the text input.
        TextBox.yview(END)
        count += 1

TextBox.pack()


window = mainloop()