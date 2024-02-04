# @1
import math

num1 = math.pow(2, 3)
num2 = math.sqrt(9)

print(num1+num2)

# @2
print("\"낮말\"은 새가 듣고, \"밤말\"은 쥐가 듣는다")
print('"낮말"은 새가 듣고, "밤말"은 쥐가 듣는다')

# @3
num1 = int(input("숫자를 입력하세요: "))
num2 = int(input("숫자를 입력하세요: "))

print(f"{num1} + {num2} = {num1+num2}")

# @4
score = int(input("점수: "))
if score >= 80:
    print("합격입니다")
elif score >= 60 and score < 80:
    print("재시험")
else: print("불합격")

# @5
num1 = int(input("점수를 입력하세요: "))
num2 = int(input("점수를 입력하세요: "))

if num1 >= 80 and num2 >= 80:
    print("합격입니다.")
else: print("불합격입니다.")

# @6
score1 = int(input("점수를 입력하세요: "))
score2 = int(input("점수를 입력하세요: "))
score3 = int(input("점수를 입력하세요: "))

if score1 >= 90 or score2 >= 90 or score3 >= 90:
    print("합격입니다.")
else: print("불합격입니다.")

# @7
p1 = int(input("김밥: "))
p2 = int(input("떡볶이: "))
p3 = int(input("라면: "))

res = 3000*p1 + 3500*p2 + 2500*p3
print(f"지불하실 금액은 {res}입니다.")

# @8
price = int(input("물건의 금액을 입력하세요: "))

if price >= 100000:
    rate = 0.1
elif price >= 50000:
    rate = 0.075
elif price >= 10000:
    rate = 0.05
else: rate = 0.0

bargain = int(price*rate)
total = int(price - bargain)

print(f"구매가: {price}원")
print(f"할인율: {rate}")
print(f"할인금액: {bargain}원")
print(f"지불금액: {total}원")

# @9
a = 'a'
while a != 'q':
    a = input("입력: ")

# @10
i = 1
while i>=1 and i<=10:
    if i%2 == 0:
        print(i, end=' ')
    i += 1

# @11
t_str = ""
while True:
    str_ = input("입력: ")
    t_str += str_
    l = len(t_str)
    print(f"출력: {t_str} ({l})")
    if l >= 25:
        break;

# @12
for i in range(1, 6):
    print("*"*i)

# @13
for i in range(5, 0, -1):
    print("*"*i)

# @14
i = 2; j = 5
for k in range(5):
    print(i**(k+1), j-k)