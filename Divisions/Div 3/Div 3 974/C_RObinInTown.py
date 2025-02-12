def Town(n,L):
    if n//2 ==0:
        return -1
    L.sort()
    mid=n//2
    if mid==n-1:
        return -1
    x=(2*L[mid]*n)-sum(L)+1
    if x<0:
        return 0
    return x

t=int(input())
for i in range(t):
    n=int(input())
    L=[int(i) for i in str(input()).split()]
    print(Town(n,L))
