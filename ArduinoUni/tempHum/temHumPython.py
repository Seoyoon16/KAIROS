# import tkinter
# import tkinter.font

# window = tkinter.Tk()
# window.title("온도표시")
# window.geometry("300x200")
# window.resizable(False,False)

# label=tkinter.Label(window, text="hello")
# label.pack()

# font = tkinter.font.Font(size = 50)
# label=tkinter.Label(window, text="hello", font=font)
# label.pack()

# window.mainloop()

import time
import serial
import serial.tools.list_ports
import threading
import tkinter
import tkinter.font

def send_object_temperature():
    sendData = f"TEMPERATURE=?\n"
    my_serial.write( sendData.encode() )
    
def send_object_humidity():
    sendData = f"HUMIDITY=?\n"
    my_serial.write( sendData.encode() )

def send_object_temperature_100mS():
    t2 = threading.Timer(0.1, send_object_temperature_100mS)
    t2.daemon = True
    t2.start()
    send_object_temperature()

def send_object_humidity_100mS():
    t2 = threading.Timer(0.1, send_object_humidity_100mS)
    t2.daemon = True
    t2.start()
    send_object_humidity()

def serial_read_thread():
    global object_temperature_value, object_humidity_value
    while True:
        read_data = my_serial.readline()
        serial_receive_data = read_data.decode()
        if "TEMPERATURE=" in serial_receive_data:
            object_temperature_value = serial_receive_data[12:]
            print("온도:", object_temperature_value)
        if "HUMIDITY=" in serial_receive_data:
            object_humidity_value = serial_receive_data[9:]
            print("습도:", object_humidity_value)
            window.after(100, gui_object_temperature_view)
        


object_temperature_value = ""
object_humidity_value = ""
def gui_object_temperature_view():
    global object_temperature_value, object_humidity_value
    temperature_label.config(text=f"온도: {object_temperature_value}")
    if float(object_temperature_value) > 22.5:
        temperature_label.configure(bg='red')
    else:
        temperature_label.configure(bg='green')
        
    humidity_label.config(text=f"습도: {object_humidity_value}")
    if float(object_humidity_value) > 30:
        humidity_label.configure(bg='yellow')
    else:
        humidity_label.configure(bg='blue')
    window.after(100, gui_object_temperature_view)

if __name__ == '__main__':
    
    ports = list(serial.tools.list_ports.comports())
    for p in ports:
        if 'CH340' in p.description:
            print(f"{p} 포트에 연결하였습니다.")
            my_serial = serial.Serial(p.device, baudrate=9600, timeout=10.0)
            time.sleep(2.0)
    
    t1 = threading.Thread(target=serial_read_thread)
    t1.daemon = True
    t1.start()
    
    send_object_temperature_100mS()
    time.sleep(1.0)
    send_object_humidity_100mS()
    
    window = tkinter.Tk()
    window.title("온습도표시")
    window.geometry("300x200")
    window.resizable(False,False)
    
    font = tkinter.font.Font(size=20)
    temperature_label = tkinter.Label(window, text="", font=font)
    temperature_label.pack()

    humidity_label = tkinter.Label(window, text="", font=font)
    humidity_label.pack()

    
    gui_object_temperature_view()
    
    window.mainloop()
    
    my_serial.close()