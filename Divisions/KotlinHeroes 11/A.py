def Problem(n,L):
    if L[-1]-max(L[:-2])==1:
        return max(L[:-2])
    else:
        return "Ambiguous"





t=int(input())
for i in range(t):
    n=int(input())
    s=str(input()).split()
    L=[int(i) for i in s]
    print(Problem(n,L))