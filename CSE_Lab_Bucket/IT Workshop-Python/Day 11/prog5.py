from Tkinter import *
root=Tk()
def leftClick(event):
    print("Left")
def rightClick(event):
    print("Right")
def middleClick(event):
    print("Middle")

frame=Frame(root,width=300,height=250)
frame.bind("<Button-1>",leftClick)
frame.bind("<Button-2>",middleClick)
frame.bind("<Button-3>",rightClick)
frame.pack()
root.mainloop()
