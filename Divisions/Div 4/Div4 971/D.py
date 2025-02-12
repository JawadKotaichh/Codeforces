import itertools
def right(p1,p2,p3):
    def distCheck(a,b):
        return (a[0]-b[0])**2 + (a[1]-b[1])**2
    d1=distCheck(p1,p2)
    d2=distCheck(p2,p3)
    d3=distCheck(p1,p3)
    return (d1+d2==d3) or (d1+d3==d2) or (d2+d3==d1)
def check(L):
    count=0
    for p1, p2, p3 in itertools.combinations(L, 3):
        if right(p1,p2,p3):
            count+=1
    return count
t=int(input())
L=[]
for i in range(t):
    L=[]
    n=int(input())
    for j in range(n):
        s=str(input()).split()
        L.append((int(s[0]),int(s[1])))
    print(check(L))



A 1 0--->1
B 1 1--->sqrt(2)
C 3 0--->3
D 5 0 ---->5
E 2 1----sqrt(5)
AB =sqrt(0+1)=1
AC= sqrt(4)=2
AD= sqrt(16)=4
AE= sqrt(1+1)