def Pizza(n,L):
    count=1
    if n==0:
        return count
    for j in range(len(L)):
        L[j]=abs(L[j])
        if L[j]%90==0 and L[j]!=0 and L[j]!=180 and L[j]<360:
            L[j]=90
        elif L[j]==180:
            L[j]=0
        else:
            if L[j]>360:
                if L[j]%180==0:
                    L[j]=180
                else:
                    if L[j]%90==0:
                        L[j]=90
                    
            elif L[j]==360:
                L[j]=0
            else:
                L[j]=L[j]%180
                L[j]=L[j]%90
        

    s=set(L)
    count=len(s)*2
    return count





t=int(input())
for i in range(t):
    L=[int(i) for i in str(input()).split()]
    print(Pizza(L[0],L[1:]))

# print(Pizza(7,[0 ,90 ,180 ,-90 ,270 ,45 ,95] ))

# print(Pizza(2,[0,90]))
# print(Pizza(3,[45,180,630]))
# print(Pizza(3,[-90,90,270]))
# print(Pizza(0,[]))
