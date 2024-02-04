import tkinter
import tkinter.font
import time

def send_servo1(self):
    value = scale1.get()
    print(value)
    time.sleep(0.3)

def send_servo2(self):
    value = scale2.get()
    print(value)
    time.sleep(0.3)

def send_servo3(self):
    value = scale3.get()
    print(value)
    time.sleep(0.3)

def send_servo4(self):
    value = scale4.get()
    print(value)
    time.sleep(0.3)

if __name__ == '__main__':
    
    
    window = tkinter.Tk()
    window.title("SERVO CONTROL")
    window.geometry("500x500")
    window.resizable(False,False)

    font = tkinter.font.Font(size=20)
    label1 = tkinter.Label(window, text="SERVO DEGREE1", font=font)
    label2 = tkinter.Label(window, text="SERVO DEGREE2", font=font)
    label3 = tkinter.Label(window, text="SERVO DEGREE3", font=font)
    label4 = tkinter.Label(window, text="SERVO DEGREE4", font=font)

    var1 = tkinter.IntVar()
    scale1 = tkinter.Scale(window, variable=var1, command=send_servo1, orient="horizontal",
                        showvalue=True, tickinterval=20, to=180, length=500)
    var2 = tkinter.IntVar()
    scale2 = tkinter.Scale(window, variable=var2, command=send_servo2, orient="horizontal",
                        showvalue=True, tickinterval=20, to=180, length=500)
    var3 = tkinter.IntVar()
    scale3 = tkinter.Scale(window, variable=var3, command=send_servo3, orient="horizontal",
                        showvalue=True, tickinterval=20, to=180, length=500)
    var4 = tkinter.IntVar()
    scale4 = tkinter.Scale(window, variable=var4, command=send_servo4, orient="horizontal",
                        showvalue=True, tickinterval=20, to=180, length=500)
    
    scale1.set(90)       #/슬라이드 초기값을 90으로 정함
    label1.grid(row = 0, column = 0, columnspan=3)
    scale1.grid(row = 1, column = 0, columnspan=3)
    
    scale2.set(90)       #/슬라이드 초기값을 90으로 정함
    label2.grid(row=2, column=0, columnspan=3)
    scale2.grid(row=3, column=0, columnspan=3)
    
    scale3.set(90)       #/슬라이드 초기값을 90으로 정함
    label3.grid(row=4, column=0, columnspan=3)
    scale3.grid(row=5, column=0, columnspan=3)
    
    scale4.set(90)       #/슬라이드 초기값을 90으로 정함
    label4.grid(row=6, column=0, columnspan=3)
    scale4.grid(row=7, column=0, columnspan=3)

    window.mainloop()