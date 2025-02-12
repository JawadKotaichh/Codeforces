def Bus(n,L):
    newl=[i for i in range(1,n+1)]
    newl[L[0]-1]="X"
    for j in range(1,n):
        if L[j]==n:
            if newl[L[j]-2]=="X":
                newl[n-1]="X"
            else:
                return "No"
        elif L[j]==1:
            if newl[L[j]]=="X":
                newl[L[j]-1]="X"
            else:
                return "No"
        else:
            if newl[L[j]]=="X":
                newl[L[j]-1]="X"
            
            elif newl[L[j]-2]=="X":
                newl[L[j]-1]="X"
            else:
                return "No"
                
    return "Yes"
t=int(input())
for i in range(t):
    n=int(input())
    s=str(input()).split()
    L=[int(i) for i in s]
    print(Bus(n,L))