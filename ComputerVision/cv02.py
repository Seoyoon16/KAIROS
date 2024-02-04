import cv2
# print(cv2.__version__)

def detect_faces():
    img_ = cv2.imread("lena.jpg")
    gray = cv2.cvtColor(img_, cv2.COLOR_BGR2GRAY)

    face_cascade = cv2.CascadeClassifier(cv2.data.haarcascades + 'haarcascade_frontalface_default.xml')

    # 이미지에서 얼굴 검출
    faces = face_cascade.detectMultiScale(gray, scaleFactor=1.1, minNeighbors=5, minSize=(30, 30))

    # 검출된 얼굴 주위에 사각형 표시
    for (x, y, w, h) in faces:
        cv2.rectangle(img_, (x, y), (x+w, y+h), (0, 255, 0), 2)

    # 결과
    cv2.imshow('Face Detection', img_)
    cv2.waitKey(0)
    cv2.destroyAllWindows()

detect_faces()
