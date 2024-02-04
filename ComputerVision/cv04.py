import matplotlib, cv2

img_file = cv2.imread("baby.jpg", cv2.IMREAD_UNCHANGED)
img_grey = cv2.imread("baby.jpg", cv2.IMREAD_GRAYSCALE)

cv2.imshow("BABY", img_file)
cv2.imshow("BABY_GREY", img_grey)

cv2.waitKey(0)
cv2.destroyAllWindows()