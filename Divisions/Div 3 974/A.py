def Robin(n,k,L):
    answer=0
    robin=0
    for i in range(n):
        if L[i]==0 and robin!=0:
            answer+=1
            robin-=1
        else:
            if L[i]!=0 and L[i]>=k:
                robin+=L[i]
    return answer


t=int(input())
for i in range(t):
    s1=str(input()).split()
    n=int(s1[0])
    k=int(s1[1])
    L=[int(i) for i in str(input()).split()]
    print(Robin(n,k,L))