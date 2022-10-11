import tkinter as tk
from PIL import ImageTk, Image


class LabelWindow(tk.Tk):
    def __init__(self, message, img_filename, img_width):
        super().__init__()
        self.title = tk.Label(text=message)
        self.title.pack()
        self.img = Image.open(img_filename)
        self.resized_image = ImageTk.PhotoImage(self.img.resize((img_width,int(self.img.size[1]*float(img_width/self.img.size[0]))), Image.ANTIALIAS))
        self.img_label = tk.Label(image = self.resized_image)
        self.img_label.pack()

def recolor(img_filename,bright_color, dark_color, new_img_filename):
    img = Image.open(img_filename)
    img = img.convert("RGB")
     
    d = img.getdata()
     
    new_image = []
    for item in d:
        if item[0] in list(range(125, 256)):
            new_image.append(bright_color)
        else:
            new_image.append(dark_color)
             
    img.putdata(new_image)
    img.save(new_img_filename)

def accentuate_color(img_filename,factors,new_img_filename):
    img = Image.open(img_filename)
    img = img.convert("RGB")
     
    data = img.getdata()
    new_image = []
    for item in data:
        new_red = min(int(item[0]*factors[0]),255)
        new_green = min(int(item[1]*factors[1]),255)
        new_blue = min(int(item[2]*factors[2]),255)
        new_image.append((new_red, new_green, new_blue))       
    img.putdata(new_image)
    img.save(new_img_filename)

if __name__=="__main__":
    img_filename = "Profile_ILM.jpg"
    bright_color = (65,171,93)
    dark_color = (34,94,168)
    new_img_filename = "recolored_img.jpg"

    recolor(img_filename, bright_color, dark_color, new_img_filename)

    window = LabelWindow("Recolored image", new_img_filename, 400)
    window.mainloop()

    new_img_filename = "altered_img.jpg"
    accentuate_color(img_filename, (0.3,0.3,2), new_img_filename)

    window2 = LabelWindow("Altered image", new_img_filename, 400)
    window2.mainloop()
