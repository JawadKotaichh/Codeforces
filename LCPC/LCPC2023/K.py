import math

t = int(input())

while t != 0:
    s = str(input()).split()
    x = float(s[0])
    y = float(s[1])
    z = float(s[2])
    height = 2 * x
    xy = math.sqrt((x + y) ** 2 - (x - y) ** 2)
    yz = math.sqrt((y + z) ** 2 - (y - (height - z)) ** 2)
    width = x + xy + yz + z
    area = height * width
    print(f"{area:.4f}")
    t -= 1
