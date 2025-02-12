def checkRedCases(indexOfMAx,n,maximum):
    rightAvailableCases=indexOfMAx-1
    leftAvailbleCases=n-2-indexOfMAx

    if rightAvailableCases%2==0:
        rightRedCases=rightAvailableCases//2
    else:
        rightRedCases=((rightAvailableCases-1)//2)+1

    if leftAvailbleCases%2==0:
        leftRedCases=leftAvailbleCases//2
    else:
        leftRedCases=((leftAvailbleCases-1)//2)+1
    score=maximum+leftRedCases+rightRedCases+1
    return score

def maxPlusSize(n,L):
    maximum=max(L)
    indexOfMAx=L.index(maximum)
    score=checkRedCases(indexOfMAx,n,maximum)
    
    tempIndexOfMax=indexOfMAx

    for i in range(indexOfMAx+1,n):
        if L[i]==maximum:
            if score<checkRedCases(i,n,maximum):
                score=checkRedCases(i,n,maximum)
    
    return score

t=int(input())
for i in range(t):
    n=int(input())
    s=str(input()).split()
    L=[ int(j) for j in s]
    print(maxPlusSize(n,L))