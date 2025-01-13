n=int(input())
s=str(input()).split()
L=[int(x) for x in s]
sumi=n*(n+1)/2
suml=sum(L)
print(int(sumi-suml))