import tkinter as tk
from PIL import ImageTk, Image


class VerticalFrame(tk.Frame):
    def __init__(self, master, width, height, bg_color):
        super().__init__(master, width = width, height = height, bg=bg_color)

    def responsive_pack(self):
        self.pack(fill=tk.BOTH, side=tk.LEFT, expand=True)


   


if __name__=="__main__":      

    colored_window_horizontal = tk.Tk()
    hframe1 = tk.Frame(master=colored_window_horizontal, width=100, height = 300, bg="#211A52")
    hframe2 = tk.Frame(master=colored_window_horizontal, width=100, height = 200, bg="gray")
    hframe3 = tk.Frame(master=colored_window_horizontal, width=100, height = 100, bg="lightblue")
    hframe1.pack(fill=tk.X)
    hframe2.pack(fill=tk.X)
    hframe3.pack(fill=tk.X)
    colored_window_horizontal.mainloop()

    colored_window = tk.Tk()
    vframe1 = VerticalFrame(master=colored_window, width=100, height = 300, bg_color="#211A52")
    vframe2 = VerticalFrame(master=colored_window, width=50, height = 300, bg_color="gray")
    vframe3 = VerticalFrame(master=colored_window, width=150, height = 300, bg_color="lightblue")
    vframe1.responsive_pack()
    vframe2.responsive_pack()
    vframe3.responsive_pack()
    colored_window.mainloop()

    
