def Collect(n,L):
    D={}
    count=0
    for i in range(len(L)):
        if L[i]-1 not in D:
            D[L[i]]=i
            count+=1
        else:
            del D[L[i]-1]
            D[L[i]]=i
    return count

n,operationNum=map(int,input().split())
L=[int(i) for i in str(input()).split()]
curr=Collect(n,L)
for x in range(operationNum):
    pos1,pos2=map(int,input().split())
    if L[pos1-1]>L[pos2-1]:
        print(curr+1)
    else:
        print(curr)

