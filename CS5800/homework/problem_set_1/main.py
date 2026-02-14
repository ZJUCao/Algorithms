line = input().strip()
a, x, n = map(int, line.split())

binary_digits = []
temp = x
while (temp > 0):
    binary_digits.append(temp % 2)
    temp = temp // 2

binary_digits.reverse()

binary_x = ''.join(map(str, binary_digits))
d = len(binary_digits)

print(binary_x)

powers = []
current = a % n
print(current)
powers.append(current)

for i in range(1, d):
    current = (current * current) % n
    print(current)
    powers.append(current)

result = 1
for i in range(d):
    if (binary_digits[d - 1 - i] == 1):
        result = (result * powers[i]) % n

print(result)
