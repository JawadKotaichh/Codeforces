def is_sublist(sublist, mainlist):
    return all(item in mainlist for item in sublist)

def find(L,R,l,r):
    if l==L and r==R:
        return R-L
    alice=[i for i in range(l,r+2)]
    Bob=[i for i in range(L,R+2)]
    answer=0
    if r!=R:
        return min(max(R,r),min(r,R))-max(l,L)+2
    else:
        return min(max(R,r),min(r,R))-max(l,L)+1

    

t=int(input())
for i in range(t):
    n=str(input()).split()
    l=int(n[0])
    r=int(n[1])
    s=str(input()).split()
    L=int(s[0])
    R=int(s[1])
    print(find(L,R,l,r))
    