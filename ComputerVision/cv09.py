import cv2

cap = cv2.VideoCapture(0)
while (cap.isOpened()):
    ret, img = cap.read()
    cv2.imshow("my win", cv2.flip(img, 1))
    if cv2.waitKey(0) & 0xFF == ord('q'):
        break
cap.release()
cv2.destroyAllWindows()