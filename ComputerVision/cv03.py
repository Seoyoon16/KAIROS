import numpy as np
import cv2

img1 = cv2.imread("lena.jpg")
print(img1)
img2 = cv2.cvtColor(img1, cv2.COLOR_BGR2RGB) # python BGR순, RGB로 바꾸는 함수
print(img2)
# print(type(img))

cv2.imshow('lena', img2)
cv2.waitKey(0)