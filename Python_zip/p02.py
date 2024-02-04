import numpy as np

# a = np.zeros((2, 5), np.uint8)
# b = np.ones((3, 1), np.int8)
# c = np.empty((1, 5), np.float32) # empty는 메모리가 초기화되지 않고 값이 할당되기 때문에 쓰레기값이 있을 수 있다.
# d = np.full(5, 15, np.float32)

# print(a, '\n', b, '\n', c, '\n', d, '\n')
# print(c.shape, d.shape)

list1, list2 = [1, 2, 3], [4, 5, 6]
a, b = np.array(list1), np.array(list2)

c = a + b
d = a - b
e = a * b
f = a / b
g = a * 2
h = a + 2

print(c, d, e)
print(f, g, h)