import cv2
from matplotlib import pyplot as plt

img = cv2.imread("openCV_logo.jpg", cv2.IMREAD_UNCHANGED)

plt.imshow(img)
plt.show()