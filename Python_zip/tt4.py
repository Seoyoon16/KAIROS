import turtle as t
num = int(input("숫자를 입력하세요: "))

n = 180 - 180*(num-2)/num

if num>=3 and num<=8:
    for _ in range(num):
        t.fd(100)
        t.lt(n)
else: print("num btw 3~8")
