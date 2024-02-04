import tkinter
import tkinter.font
import time
import serial
import serial.tools.list_ports

def send_servo(val):
    val1 = scale1.get()
    val2 = scale2.get()
    val3 = scale3.get()
    val4 = scale4.get()
    
    sendData = f"SERVO={val1},{val2},{val3},{val4}\n"
    my_serial.write(sendData.encode())
    print(f"val1: {val1},{val2},{val3},{val4}")

if __name__ == '__main__':
    
    ports = list(serial.tools.list_ports.comports())
    for p in ports:
        if 'CH340' in p.description:
            print(f"{p} 포트에 연결하였습니다.")
            my_serial = serial.Serial(p.device, baudrate=9600, timeout=1.0)
            time.sleep(2.0)
    
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
    scale1 = tkinter.Scale(window, variable=var1, command=send_servo, orient="horizontal",
                        showvalue=True, tickinterval=20, to=180, length=500)
    var2 = tkinter.IntVar()
    scale2 = tkinter.Scale(window, variable=var2, command=send_servo, orient="horizontal",
                        showvalue=True, tickinterval=20, to=180, length=500)
    var3 = tkinter.IntVar()
    scale3 = tkinter.Scale(window, variable=var3, command=send_servo, orient="horizontal",
                        showvalue=True, tickinterval=20, to=180, length=500)
    var4 = tkinter.IntVar()
    scale4 = tkinter.Scale(window, variable=var4, command=send_servo, orient="horizontal",
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