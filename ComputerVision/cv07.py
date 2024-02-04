import cv2
import numpy as np
from matplotlib import pyplot as plt

img = cv2. imread('openCV_logo.jpg', cv2.IMREAD_UNCHANGED)

# 이미지 높이
height, _ = img.shape[ :2]
print (height, _)

# Y축 틱 설정
yticks = np.arange(height, -1, -100) # 틱 간격을 조절할 수 있습니다.
print(yticks)
yticklabels = np.arange(0, height+1, 100)# 틱의 레이블을 조절합니다.
print (yticklabels)
plt.yticks(yticks, yticklabels)
plt.imshow(img)
plt.show()
