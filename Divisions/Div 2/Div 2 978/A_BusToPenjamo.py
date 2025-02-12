def Happy(n,r,listOfFamily):
    remaining={}
    answer=0
    remFamily=0

    for i in range(n):
        if listOfFamily[i]%2==0:
            r-=int(listOfFamily[i]/2)
            answer+=listOfFamily[i]
        else:
            r-=int((listOfFamily[i]-1)/2)
            answer+=listOfFamily[i]-1
            remFamily+=1
            remaining[i]=1
    for family in remaining.keys():
        if r-remaining[family]>=0 and ((r-1)*2)>=(remFamily-1):
            r-=1
            remFamily-=1
            answer+=1
    return answer

t=int(input())
for i in range(t):
    n,r=map(int,input().split())
    s=str(input()).split()
    L=[int(j) for j in s]
    print(Happy(n,r,L))