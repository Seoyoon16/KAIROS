from tkinter import * 

window=Tk()
window. title("지연+서윤")
window. geometry ("640x400+100+100")
window. resizable (True, True)

count=0

def countUP() :
    global count
    count+=1
    lb.config(text=str(count))

def countDOWN():
    global count 
    if count<1 :
        count = 0
    else :
        count-=1
    lb. config(text=str (count) )

def countReset() :
    global count
    count=0
    lb.config(text=str(count))

lb=Label (window, text='0', fg='red')
lb. pack(pady=10)

bt=Button (window, overrelief="solid", width=15, 
command=countUP, repeatdelay=1000, repeatinterval=100, text='+')
bt. pack()

bt1=Button(window, overrelief="solid", width=15, 
command=countDOWN, repeatdelay=1000, repeatinterval=100, text='-')
bt1. pack()

bt2=Button(window, overrelief="solid", width=15, 
command=countReset, repeatdelay=1000, repeatinterval=100, text='zero')
bt2. pack()

window.mainloop()