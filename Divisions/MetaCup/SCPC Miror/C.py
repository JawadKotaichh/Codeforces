def never(n,c,L):
    if c==1:
        return 0
    else:
        return sum(L)
    


s=str(input()).split()
L=[int(i) for i in s]
n=L[0]
c=L[1]
s1=str(input()).split()
newL=[int(i) for i in s1]
print(never(n,c,newL))
