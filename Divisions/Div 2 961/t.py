def maximize (n,L):
    if len(L)==1:
        return L[0]
    while len(L)!=1:
        if len(L)!=3:
            mini=L[0]+L[1]
            first=0
            for i in range(len(L)-1):
                if L[i]+L[i+1]<mini:
                    mini=L[i]+L[i+1]
                    first=i
            L=L[:first]+L[first+2:]
        else:
            sum1=L[0]+L[1]
            sum2=L[1]+L[2]
            if sum1>sum2:
                return L[0]
            else:
                return L[2]
    return L[0]
t=int(input())
for i in range(t):
    s1=str(input())
    n=int(s1)
    s1=str(input())
    l1=s1.split()
    lst=[int(x) for x in l1]
    print(maximize(n,lst))