def Right(n,L,s):
    if len(s)==2:
        if s[0]=="L" and s[1]=="R":
            return L[0]+L[1]
        else:
            return 0
    l_ind=[]
    r_ind=[]
    
    for i in range(n):
        if s[i]=="L":
            l_ind.append(i)
        elif s[i]=="R":
            r_ind.append(i)
    if len(l_ind)==0 or len(r_ind)==0:
        return 0
    answer=sum(L[l_ind[0]:r_ind[-1]+1])
    pr=len(r_ind)-2
    if pr >=0:
        for j in range(1,len(l_ind)):
            if r_ind[pr] > l_ind[j] and pr>=0:
                answer+=sum(L[l_ind[j]:r_ind[pr]+1])
                pr-=1
            if pr<0:
                break
    return answer
t=int(input())
for i in range(t):
    n=int(input())
    s=str(input()).split()
    L=[int(i) for i in s]
    s=str(input())
    print(Right(n,L,s))