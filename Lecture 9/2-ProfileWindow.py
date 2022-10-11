import tkinter as tk
from PIL import ImageTk, Image

class ProfileWindow(tk.Tk):
    def __init__(self, message, img_filename, img_width):
        super().__init__()
        self.title("A profile window")                          # Sets the window title
        self.title_label = tk.Label(text=message)               # Creates a label to display the text in message
        self.title_label.pack()                                 # Places the label
        self.img = Image.open(img_filename)                     # Opens image using Pillow
        self.resized_image = ImageTk.PhotoImage(self.img.resize((img_width,int(self.img.size[1]*float(img_width/self.img.size[0]))), Image.ANTIALIAS))
        self.img_label = tk.Label(image = self.resized_image)   # Creates a label to display image
        self.img_label.pack()                                   # Places the label

if __name__=="__main__":
    profile_window = ProfileWindow("Profile picture", "Profile_ILM.jpg", 500)
    profile_window.mainloop()

    profile_window_dog = ProfileWindow("Profile picture for Scoobert", "greatdane.png", 200)
    profile_window_dog.mainloop()