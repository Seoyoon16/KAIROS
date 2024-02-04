# @1
num = int(input("횟수입력: "))

for i in range(1, num+1):
    if i%2 == 0:
        print(i, end=' ')

# @2
# fizz buzz 출력하기
for i in range(1, 101):
    if i%3 == 0 and i%5 == 0:
        print("fizz buzz")
    
    if i%3 == 0:
        print("fizz")
    elif i%5 == 0:
        print("buzz")
    else:
        print(i)

# @3
num = int(input("숫자: "))

if num >= 1 and num <= 10:
    mul = 1
    for i in range(1, num+1):
        mul *= i
    print(f"결과: {mul}")
else:
    print("잘못입력하셨습니다.")

# @4
import sys

num = int(input("숫자: "))

if num >= 1 and num <= 10:
    pass;
else:
    print("잘못입력하셨습니다.")
    sys.exit()

# @5
mul = 1
for i in range(1, num+1):
    mul *= i
print(f"결과: {mul}")

# @6
text = "hello"
for i in range(len(text)-1):
    print(text[i], text[i+1])

# @7
text = "this is python script"
arr = list(text.split(' '))

for i in range(len(arr)-1):
    print(arr[i], arr[i+1])

# @8
def circle_area(r):
    res = 3.14 * r * r
    return res
print(circle_area(5))

# @9
arr = list(map(int, input("정수 10개 입력: ").split()))
print(f"리스트: {arr}")
arr.sort()
print(f"정렬된 리스트: {arr}")

# @10
arr = []
for _ in range(10):
    num = int(input("입력: "))
    arr.append(num)
print(f"리스트: {arr}")
sorted_list = sorted(arr)
print(f"정렬된 리스트: {sorted_list}")