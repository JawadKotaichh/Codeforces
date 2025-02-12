def flower(n,m,L):
    if len(L)==1 and L[0]<=m:
        return L[0]
    L.sort()
    
    maxi=0
    csum=0
    for j in range(len(L)):
        if j==len(L)-1:
            csum=L[j]
            if csum>maxi and csum<=m:
                maxi =csum
        temp=[L[j],]
        current=L[j]
        for i in range(j+1,len(L)):
            if L[i]-current==0 or L[i]-current==1:
                temp=temp+[L[i]]
            
            csum=sum(temp)
            if csum>maxi and csum<=m:
                maxi =csum
    return maxi

t=int(input())
for i in range(t):
    s1=str(input())
    l1=s1.split()
    n=int(l1[0])
    m=int(l1[1])
    s2=str(input())
    l2=s2.split()
    L=[int(x) for x in l2]
    print(flower(n,m,L))
