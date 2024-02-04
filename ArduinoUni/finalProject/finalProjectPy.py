import mediapipe, cv2
import time
import serial, serial.tools.list_ports
import speech_recognition as sr
import tkinter as tk

def recognize_speech():
    recognizer = sr.Recognizer()
    
    with sr.Microphone() as source:
        print("입력받는 중~")
        recognizer.adjust_for_ambient_noise(source)  # 환경 소음 조절
        audio = recognizer.listen(source)  # 마이크로폰으로부터 오디오를 듣습니다.

    try:
        print("인식 중~")
        text = recognizer.recognize_google(audio, language='ko-KR')  # 음성을 텍스트로 변환
        # print("인식된 음성:", text)
        
        if text and '안녕' in text:
            sayHello()
            print("안녕")
            time.sleep(1)
        elif text and '악수' in text:
            handShake()
            print("악수")
            time.sleep(1)
        elif text and '춤' in text:
            danceBreak()
            print("다라란~")
            time.sleep(1)
        elif text and '불' in text or '켜줘' in text:
            lightUp()
            print("탁!")
            time.sleep(1)
        else:
            print("그런거 몰라ㅡㅡ")
            time.sleep(1)
            
    except sr.UnknownValueError:
        print("음성을 인식할 수 없습니다.")
    except sr.RequestError as e:
        print("Google Speech Recognition 서비스에 연결할 수 없습니다. 오류: {0}".format(e))

def sayHello():
    sendData = f"DATA=0,90,30,90,90\n"
    my_serial.write(sendData.encode())
    print(f"안녕~")
    pass

def handShake():
    sendData = f"DATA=1,180,90,135,50\n"
    my_serial.write(sendData.encode())
    print(f"반가워~")
    pass

def danceBreak():
    sendData = f"DATA=2,90,90,90,90\n"
    my_serial.write(sendData.encode())
    print(f"둠칫둠칫~")
    pass

def lightUp():
    sendData = f"DATA=3,90,180,135,115\n"
    my_serial.write(sendData.encode())
    print(f"탁!")
    pass
    

if __name__ == '__main__':
    
    ports = list(serial.tools.list_ports.comports())
    for p in ports:
        if 'CH340' in p.description:
            print(f"{p} 포트에 연결하였습니다.")
            my_serial = serial.Serial(p.device, baudrate=9600, timeout=1.0)
            time.sleep(2.0)
    
    root = tk.Tk()
    root.title("음성 인식 프로그램")
    root.geometry("320x200")
    root.resizable(True, True)
    
    button = tk.Button(root, text="음성 인식 시작", command=recognize_speech)
    button.pack()
    
    root.update_idletasks()
    button.place(relx=0.5, rely=0.5, anchor=tk.CENTER)
    
    root.mainloop()
    
    
    