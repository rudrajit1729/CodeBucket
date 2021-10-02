#=====================Libraries============================================
from tkinter import *
from pytube import YouTube
from tkinter import messagebox


#=====================Settings=============================================

root = Tk()
root.title('YouTube Downloader')
root.geometry('500x380')
root.resizable(width=False, height=False)
root.configure(bg="red")

#=====================Functions============================================

quality = IntVar()

def clearurl():
    u.delete(0, END)

def clearpath():
    p.delete(0, END)

def clearall():
    clearurl()
    clearpath()

def download_video():
    youtube_url = str(u.get().strip())
    if youtube_url.startswith('https://www.youtube.com/'):
        if quality.get() == 0:
            myStream = YouTube(youtube_url).streams.first()
            myStream.download(str(p.get().strip()))
            #video = videos[0]
        else:
            myStream = YouTube(youtube_url).streams.last()
            myStream.download(str(p.get().strip()))
        clearall()
    else:
        # ==================================================Update User========================
        info = "You might forgot to enter a correct Url or path or haven't checked the Quality"
        messagebox.showinfo("Information", info)

        
#====================RadioButton===============================================

rdbtn1 = Radiobutton(root, text="High Quality", activeforeground='green',bg = "red", variable=quality,  value=0)
rdbtn1.place(x=110, y=65)

rdbtn2 = Radiobutton(root, text="Low Quality", activeforeground='green',bg = "red", variable=quality, value=1)
rdbtn2.place(x=260, y=65)


#====================Creating Label=============================================

title_label = Label(root, text='YOUTUBE DOWNLOADER', font=('sans-serif', 28, 'bold', 'underline'), fg="white", bg = "red")
title_label.place(x=10, y=6)

path_label = Label(root, text='Path :', font=('sans-serif', 20, 'bold'), bg = "red", fg = "white")
path_label.place(x=10, y=160)

url_label = Label(root, text='URL :', font=('sans-serif', 20, 'bold'), bg = "red", fg = "white")
url_label.place(x=10, y=100)


#====================Creating Entry=============================================

u = Entry(root, width=30, bd=3, font=('sans-serif', 15), selectbackground='#886A08')
u.place(x=110, y=105)

p = Entry(root, width=30, bd=3, font=('sans-serif', 15), selectbackground='#886A08')
p.place(x=110, y=165)

#====================Buttons====================================================

clear_url = Button(root, text='Clear URL', bd=4,bg = "white",fg = "red", activebackground="white", activeforeground="red", cursor="hand2", font=('arial', 14), command= lambda : clearurl())
clear_url.place(x=30, y=215)

clear_path = Button(root, text='Clear Path', bd=4, fg = "red", bg = "white",activebackground="white", activeforeground="red", cursor="hand2", font=('arial', 14), command= lambda : clearpath())
clear_path.place(x=200, y=215)

clear_all = Button(root, text='Clear All', bd=4,fg = "red", bg = "white", activebackground="white", activeforeground="red", cursor="hand2", font=('arial', 14), command = lambda : clearall())
clear_all.place(x=380, y=215)

download = Button(root, text='Download', bd=4, fg = "red", bg = "white", activebackground="#452B09", activeforeground="white", cursor="hand2", width=40, font=('arial', 14), command= lambda : download_video())
download.place(x=30, y=300)


root.mainloop()
