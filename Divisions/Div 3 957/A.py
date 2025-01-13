def Only(a,b,c):
    L=[a,b,c]
    L.sort()
    count=5
    if L[0]!=L[1]:
        if L[1]-L[0]<=5:
            count-=L[1]-L[0]
            L[0]=L[1]
            if count==0:
                return L[0]*L[2]*L[1]
        else:
            return (L[0]+5)*L[2]*L[1]
    if L[2]!=L[1]:
        diff=2*(L[2]-L[1])
        if count==diff:
            return L[2]**3

        else:
            if diff>count:
                if count%2==0:
                    L[1]+=count//2
                    L[0]+=count//2
                    return L[0]*L[2]*L[1]
                else:
                    L[0]+=count//2
                    L[1]+=count-count//2
                    return L[0]*L[2]*L[1]
            else:
                count-=diff
                L[0]=L[2]
                L[1]=L[2]
                if count==0:
                    return L[0]*L[2]*L[1]
                else:
                    x=0
                    while count!=0:
                        count-=1
                        L[x]+=1
                        x+=1
                        if x==3:
                            x=0
                    return L[0]*L[2]*L[1]
    else:
        x=0
        while count!=0:
            count-=1
            L[x]+=1
            x+=1
            if x==3:
                x=0
        return L[0]*L[2]*L[1]
    
t=int(input())
for i in range(t):
    s=str(input()).split()
    a=int(s[0])
    b=int(s[1])
    c=int(s[2])
    print(Only(a,b,c))
