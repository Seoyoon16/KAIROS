import cv2

def main():
    camera = cv2.VideoCapture(0)
    camera.set(3,320)
    camera.set(4,240)
        
    while True:
        _, frame = camera.read()  

        hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)
        
        # HSV 값 범위
        lower_blue = (100,100,120)                              #색깔을 나타내주는 영역데이터 100~150
        upper_blue = (150,255,255)
        
        lower_green = (50, 150, 50)
        upper_green = (80, 255, 255)
        
        lower_red = (150, 50, 50)
        upper_red = (180, 255, 255)
        
        lower_yellow = (20, 100, 100)
        upper_yellow = (30, 255, 255)
        
        lower_olive = (40, 50, 50)
        upper_olive = (80, 255, 255)
        
        lower_purple = (130, 50, 50)
        upper_purple = (170, 255, 255)
                
        redMask = cv2.inRange(hsv, lower_red, upper_red)        #배열병합
        greenMask = cv2.inRange(hsv, lower_green, upper_green)  
        blueMask = cv2.inRange(hsv, lower_blue, upper_blue)
        
        yellowMask = cv2.inRange(hsv, lower_yellow, upper_yellow)
        oliveMask = cv2.inRange(hsv, lower_olive, upper_olive)
        purpleMask = cv2.inRange(hsv, lower_purple, upper_purple) 

        red = cv2.bitwise_and(frame, frame, mask=redMask)       #비트연산(and reamask)
        green = cv2.bitwise_and(frame, frame, mask=greenMask)  
        blue = cv2.bitwise_and(frame, frame, mask=blueMask)
        
        yellow = cv2.bitwise_and(frame, frame, mask=yellowMask)
        olive = cv2.bitwise_and(frame, frame, mask=oliveMask)
        purple = cv2.bitwise_and(frame, frame, mask=purpleMask) 

        cv2.imshow('frame',frame)
        # cv2.imshow('red', red)
        # cv2.imshow('Green', green)
        # cv2.imshow('Blue', blue)
        
        cv2.imshow('Yellow', yellow)
        cv2.imshow('Olive', olive)
        cv2.imshow('Purple', purple)
        
        
        if cv2.waitKey(1) == ord('q'):
            break

    cv2.destroyAllWindows()

if __name__ == '__main__':
    main()