def Sweet(n,m,d,L):
    L.sort()
    minTime=0

    if n%2==0:
        midInd=(n//2)-1
    else:
        midInd=(n//2)
    
    newL=L[:midInd+1]
    start=0
    end=midInd
    rem=m
    listoftime=[]
    while start<=end:
        if start==end:
            
            listoftime.append(rem*newL[start]*d)
            break
        else:
            listoftime.append(newL[end]*newL[start]*d)
            rem-=newL[end]
            if rem!=0:
                listoftime.append(newL[end]*newL[start]*d)
                rem-=newL[start]
            else:
                break
    
            start+=1
            end-=1
    return max(listoftime)

1 2 3 4 5

m=100






t=int(input())
for i in range(t):
    s1=str(input()).split()
    n=int(s1[0])
    m=int(s1[1])
    d=int(s1[2])
    s=str(input()).split()
    L=[int(s[i]) for i in range(len(s))]
    print(Sweet(n,m,d,L))