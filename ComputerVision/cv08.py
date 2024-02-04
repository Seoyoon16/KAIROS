import cv2
import numpy as np
from matplotlib import pyplot as plt

img = cv2. imread('openCV_logo.jpg', cv2.IMREAD_COLOR)

plt.imshow(img)
# np.arange(start, stop, step)
# img.shape[1]는 이미지의 너비(열의 수), img.shape[0]은 이미지의 높이(행의 수)
plt.xticks(np.arange(0, img.shape[1], 100))  # x축 눈금 표시 설정

yticks = np.arange(img.shape[0],-1, -100) # 틱 간격을 조절할 수 있습니다.
yticklabels = np.arange(0, img.shape[0]+1, 100)# 틱의 레이블을 조절합니다.
plt.yticks(yticks, yticklabels)
# plt.gca().invert_yaxis(), plt.ylim(0, img.shape[0]) # y축반전, 이미지도 반전됨...
plt.show()