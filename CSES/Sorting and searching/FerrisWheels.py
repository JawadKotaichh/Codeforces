def Feris(n,x,L):
    L.sort()
    count=0
    start=0
    end=n-1
    rem=0
    while start<end:
        if L[start]+L[end]<=x:
            count+=1
            start+=1
            end-=1        
        else:
            count+=1
            end-=1
            rem+=1
            
    if n%2==0 and rem%2!=0:
        return count+1
    if n%2!=0 and rem==0:
        return count+1
    return count

n,x=map(int,input().split())
s=str(input()).split()
L=[int(i) for i in s]
print(Feris(n,x,L))