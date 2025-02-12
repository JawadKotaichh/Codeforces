def minimize(a,b):
    return b-a



t=int(input())
for i in range(t):
    s=str(input()).split()
    a=int(s[0])
    b=int(s[1])
    print(minimize(a,b))