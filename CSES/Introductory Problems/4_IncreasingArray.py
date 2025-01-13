n=int(input())
s=str(input()).split()
L=[int(x) for x in s]
answer=0
for i in range(1,n):
    if L[i]-L[i-1]<0:
        answer+=-L[i]+L[i-1]
        L[i]=L[i-1]
print(answer)
