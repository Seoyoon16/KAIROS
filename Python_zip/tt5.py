import turtle as t

num = int(input("3에서 9사이의 숫자를 입력하세요: "))
color = input("원하는 색상을 입력하세요: ")

n = 180 - 180*(num-2)/num
arr_c = ["red", "yellow", "green", "blue", "pink", "orange", "black"]

while True:
    if num>=3 and num<=9:
        if color in arr_c:
            t.fillcolor(color)
            t.begin_fill()
            for _ in range(num):
                t.fd(100)
                t.lt(n)
            t.end_fill()
            break;
        else: print("color not available"); break;
    else: print("num must be btw 3~9"); break;
