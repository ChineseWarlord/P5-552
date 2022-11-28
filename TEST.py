from tkinter import *
window = Tk()

T = Text(window, bg="white", fg="green", font=("bold", 12))
# Create a tag named "blue" and set the color of it to blue
T.tag_config("here", foreground="white",background="#086dbf")
T.grid()

def addMessage(text):
    # apply the tag while inserting
    T.insert(END, "me asdasd asd: ", "here")
    T.insert(END, text+"\n")

addMessage("test")
addMessage("lort")
addMessage("cancer")
addMessage(input())

window.mainloop()