# @1
str_list = ["python", "apple", "robot"]
ans_list = ["파이썬", "사과", "로봇"]

cnt = 0
for i, elem in enumerate(str_list):
    my_str = input(f"{ans_list[i]}: ")
    if elem == my_str:
        print("정답")
        cnt += 1
    else:
        print(f"오답, 정답은 {elem}")

print(f"정답개수: {cnt}개, 오답개수: {3-cnt}개")

# @2
import random

for i in range(len(str_list)):
    elem = random.sample(str_list, k=1)
    str_list.remove(elem[0])
    my_input = input(f"{elem[0]}: ")
    if elem[0] == my_input:
        print("정답")
    else: print("오답")

# @3
class Score():
    def __init__(self, k, e, m):
        self.k = k
        self.e = e
        self.m = m
    
    def get_score(self):
        return (self.k + self.e + self.m) / 3

std1 = Score(70, 80, 90)
std2 = Score(80, 90, 100)

print(std1.get_score())
print(std2.get_score())

# @4
import tkinter as tk

def add():
    val1 = int(entry1.get())
    val2 = int(entry2.get())
    res1 = val1 + val2
    
    btn1.config(text=f"{res1}")

def substract():
    val1 = int(entry1.get())
    val2 = int(entry2.get())
    res2 = val1 - val2
    
    btn2.config(text=f"{res2}")
    
def multiplication():
    val1 = int(entry1.get())
    val2 = int(entry2.get())
    res3 = val1 * val2
    
    btn3.config(text=f"{res3}")
    
def division():
    val1 = int(entry1.get())
    val2 = int(entry2.get())
    res4 = val1 / val2
    
    btn4.config(text=f"{res4}")

main = tk.Tk()

main.title("calculator")
main.geometry("700x500")

lbl = tk.Label(main) # 위젯
lbl["text"] = "숫자 두개를 입력하세요."
lbl.pack(pady=5)

entry1 = tk.Entry(main) # 사용자 입력
entry1.pack()
entry2 = tk.Entry(main)
entry2.pack()

btn1 = tk.Button(main, text="더하기", command=add)
btn1.pack()
btn2 = tk.Button(main, text="빼기", command=substract)
btn2.pack()
btn3 = tk.Button(main, text="곱하기", command=multiplication)
btn3.pack()
btn4 = tk.Button(main, text="나누기", command=division)
btn4.pack()

main.mainloop()

# @5
import tkinter as tk
import random

def add():
    ans = int(entry.get())
    if ans == num1+num2:
        lbl_ans.config(text="정답입니다.")
    else:
        lbl_ans.config(text=f"오답입니다. 정답은 {num1+num2}입니다.")

main = tk.Tk()

main.title("addition")
main.geometry("700x500")

num1 = random.randint(1, 100)
num2 = random.randint(1, 100)

lbl = tk.Label(main) # 위젯
lbl["text"] = f"{num1} + {num2} = ?";
lbl.pack(pady=5)

entry = tk.Entry(main) # 사용자 입력
entry.pack(pady=5)

btn1 = tk.Button(main, text="확인", command=add)
btn1.pack(pady=7)

lbl_ans = tk.Label()
lbl_ans.pack()

main.mainloop()

# @6
import numpy as np

a = [1, 2, 3, 4, 5]
b = np.array(a)
c = np.array([1, 3, 5], dtype=int)  # 동일 배열 동일 타입

# np 배열은 , 없음
print(a)
print(b)
print(c)

# 단순복제: b변경 시 a도 변경됨
d = np.array([1, 2, 3])
e = d
# 원본과 별개의 배열 생성
f = d.copy()
print(f)

# np 배열 연산: 원소 하나하나에 연산 적용
g = b + 5
print(g)

# @7
import matplotlib.pyplot as plt

plt.plot([1, 2, 3, 4])
plt.show() # x축 인덱스, y축 리스트

# @8
import csv
import matplotlib.pyplot as plt

f = open("people.csv")
data = csv.reader(f)

arr_seoul = []
arr_incheon = []
for view in data:
    if view[0] == '서울특별시  (1100000000)':
        for i in range(3, len(view)):
            num = view[i].replace(',', '')
            num = int(num)
            arr_seoul.append(num)
    if view[0] == '인천광역시  (2800000000)':
        for i in range(3, len(view)):
            num = view[i].replace(',', '')
            num = int(num)
            arr_incheon.append(num)
print(f"서울특별시: {arr_seoul}")
print(f"인천광역시: {arr_incheon}")

plt.style.use("ggplot") # 격자무늬
plt.rc('font', family="Malgun Gothic")
plt.title("인구구조비교")
plt.plot(arr_seoul, 'r', label="서울특별시")
plt.plot(arr_incheon, 'b', label="인천광역시")

plt.legend()
plt.show()

data_age = []
for view in data:
    if "행정" in view[0]:
        for i in view[3:]:
            data_age.append(i)
    
    if view[0] == '서울특별시  (1100000000)':
        for i in range(3, len(view)):
            num = view[i].replace(',', '')
            num = int(num)
            arr_seoul.append(num)
    if view[0] == '인천광역시  (2800000000)':
        for i in range(3, len(view)):
            num = view[i].replace(',', '')
            num = int(num)
            arr_incheon.append(num)
print(data_age)
print(f"서울특별시: {arr_seoul}")
print(f"인천광역시: {arr_incheon}")

# @9
sco = {"kor": 90, "math": 100}
sco_sum = 0
for item in sco.values():
    sco_sum += item
avg = sco_sum / len(sco)

print(f"총점: {sco_sum}")
print(f"평균: {avg}")

    