def find(a,b,c):
    if a==b:
        return c
    elif b==c:
        return a
    else:
        return b 




t =int(input())
for i in range(t):
    L=str(input())
    s=L.split()
    a=int(s[0])
    b=int(s[1])
    c=int(s[2])
    print(find(a,b,c))