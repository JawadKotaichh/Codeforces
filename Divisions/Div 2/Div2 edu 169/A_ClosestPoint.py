def l(n,L):
    if len(L)==1:
        return "Yes"
    else:
        if len(L)==2 and L[0]+1!=L[1]:
            return "Yes"
        else:
            return "No"

t=int(input())
for i in range(t):
    n=int(input())
    s=str(input()).split()
    L=[int(x) for x in s]
    print(l(n,L))
    
        