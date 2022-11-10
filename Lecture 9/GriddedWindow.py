import tkinter as tk

class GriddedWindow(tk.Tk):
    def __init__(self, x, y):
        super().__init__()
        for i in range(x):
            for j in range(y):
                frame = tk.Frame(master=self,relief=tk.RAISED, borderwidth=1)
                frame.grid(row=i, column=j)
                label = tk.Label(master=frame, text=f"Row {i}\nColumn {j}")
                label.pack()
        self.mainloop()

if __name__=="__main__":
    window = GriddedWindow(10,10)
