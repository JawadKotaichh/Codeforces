s1 = str(input()).split()

n = int(s1[0])
x = int(s1[1])
y = int(s1[2])
if x * y >= n:
    print("YES")
else:
    print("NO")
