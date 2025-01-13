
t=int(input())
for x in range(t):
    s=str(input()).split()
    L=[int(i) for i in s]
    xc=L[0]
    yc=L[1]
    k=L[2]
    gg=k%2==0
    for i in range(int(-k/2),int(k/2)+1,1):
        x = xc + i
        y = yc
        if k%2==0 and i==0:
            continue
        print(x,y)
