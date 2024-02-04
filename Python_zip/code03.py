# @1
fruits = {"banana":10, "apple":15, "cherry":8}

while True:
    order = input("주문하실 과일은 무엇인가요?: ")
    if order == 'q':
        break;
    if order not in fruits:
        print("그런 과일은 없습니다.")
    else:
        cnt = fruits[order]
        for fruit in fruits:
            if fruit == order:
                cnt -= 1
                fruits[order] = cnt
                if cnt <= 0:
                    print("재고가 없습니다.")
                else: print(f"이제 {order}는 {cnt}개 남았습니다.")

# instead of for loop
if fruits[order] > 0:
    fruits[order] = fruits[order] - 1

# @2
import random

def add_nums(n1, n2):
    return n1 + n2

while True:
    num1 = random.randint(1, 100)
    num2 = random.randint(1, 100)
    ans_real = add_nums(num1, num2)
    
    print(f"{num1} + {num2} = ?")
    ans = int(input("답: "))
    
    if ans == ans_real:
        print("정답입니다.")
    else:
        print(f"오답입니다. 정답: {ans_real}")
        break;

# @3
import random

nums = []
while True:
    num = random.randint(1, 45)
    if len(nums) == 7:
        break;
    if num not in nums:
        nums.append(num)
print("당첨번호: ", end='')
for elem in nums[:6]:
    print(elem, end=' ')
print(f"+ {nums[6]}")

# random.choice(list) – 랜덤으로 요소 하나를 취득.
# random.sample(list, n) – 랜덤으로 요소 여러 개 취득. 중복 없음.
# random.choices(list, k=n) – 랜덤으로 요소 여러 개 취득. 중복 있음.
# set(list) - 리스트 중복 제거

# @4
class myClass():
    def __init__(self, name, hobby):
        self.nm = name
        self.hob = hobby
    
    def intro(self):
        print("I\'m %s. i\'m into %s" %(self.nm, self.hob))

me = myClass("sy", "zz")
me.intro()

# @5
from tkinter import *

def click():
    print("click")

def clk():
    btn.config(text="success")

main = Tk() # 기본 윈도우 생성

main.title("click the button")
main.geometry("700x500") # 윈도우 크기
lbl = Label(main) # 위젯
lbl["text"] = "click the button"
lbl["font"] = "Arial 20"
lbl.pack() # 위젯 packing

ok_btn = Button(main, text="확인", foreground="Red")
ok_btn.pack()
cc_btn = Button(main, text="취소", foreground="Green")
cc_btn.pack()

btn = Button(main, text="click", command=clk)
btn.pack()

img = PhotoImage(file="img/pic.png")
width, height = 100, 100
resized_img = img.subsample(5, 5)
img_btn = Button(main, image=resized_img)
img_btn.pack()

main.mainloop() # 실행