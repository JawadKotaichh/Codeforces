t=int(input())
for i in range(t):
    s=str(input())
    L=s.split()
    a=int(L[0])
    b=int(L[1])
    if b<a:
        print(b,a)
    else:
        print(a,b)