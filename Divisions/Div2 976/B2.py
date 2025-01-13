def check(n,k):
    return n*(n+1)<=k
def Brightnesss(k):
    if k<=2:
        return k+1
    low=0
    high=k
    while low<high:
        if low==high-1:
            if check(high,k):low=high
            break
        mid=(low+high)//2
        if check(mid,k):
            low=mid
        else:
            high=mid-1
    n=low
    return n+1+k if n*(n+1)!=k else n+k

for t in range(int(input())):
    k=int(input())
    print(Brightnesss(k))

    
    