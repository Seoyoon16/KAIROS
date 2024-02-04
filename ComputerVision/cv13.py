import cv2
import mediapipe as mp
import numpy as np

def getDistance(ax, ay, bx, by):
    a = np.array([ax, ay])
    b = np.array([bx, by])
    
    distance = np.sqrt(np.sum(np.square(a-b)))
    # 최소 거리 갱신
    distance = 0 if distance < 10 else distance
    return distance

mp_hands = mp.solutions.hands
hands = mp_hands.Hands()
mp_drawing = mp.solutions.drawing_utils

bar_x, bar_y, bar_width, bar_height = 500, 50, 20, 255
bar_max_color = (0, 255, 0)
max_distance = 200
led_bright_max = 255

cap = cv2.VideoCapture(0)

while True:
    ret, frame = cap.read()
    frame = cv2.flip(frame, 1)
    rgb_frame = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)

    results = hands.process(rgb_frame)

    if results.multi_hand_landmarks:
        hand_landmarks = results.multi_hand_landmarks[0]
        thumb_tip = hand_landmarks.landmark[mp_hands.HandLandmark.THUMB_TIP]
        index_tip = hand_landmarks.landmark[mp_hands.HandLandmark.INDEX_FINGER_TIP]

        img_height, img_width, _ = frame.shape
        thumb_x, thumb_y = int(thumb_tip.x * img_width), int(thumb_tip.y * img_height)
        index_x, index_y = int(index_tip.x * img_width), int(index_tip.y * img_height)

  
        cv2.circle(frame, (thumb_x, thumb_y), 5, (0, 255, 0), -1)  # 엄지 동그라미 그리기
        cv2.circle(frame, (index_x, index_y), 5, (0, 255, 0), -1)  # 검지 동그라미 그리기
    
        distance = getDistance(thumb_x, thumb_y, index_x, index_y)
        
        # Scale the distance to match the range of the slider bar
        scaled_distance = min(max_distance, max(0, distance))
        bar_height = int(scaled_distance / max_distance * 255)
        
        # Update slider bar position based on the scaled distance
        bar_y = 305 - bar_height
        
        # Draw white background for slider bar
        cv2.rectangle(frame, (bar_x, 50), (bar_x + bar_width, 305), (255, 255, 255), -1)
        
        # Draw green fill based on the scaled distance
        fill_height = int(bar_height)
        fill_y = 305 - fill_height
        cv2.rectangle(frame, (bar_x, fill_y), (bar_x + bar_width, 305), bar_max_color, -1)
    
    cv2.imshow('Hand Landmarks', frame)

    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

cap.release()
cv2.destroyAllWindows()