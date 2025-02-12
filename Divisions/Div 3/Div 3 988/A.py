def maxScore(L):
    L.sort()
    score=0
    pointer1=0
    pointer2=1
    last=L[0]
    count=1
    for i in range(1,len(L)):
        if L[i]==last:
            count+=1
        else:
            score+=(count//2)
            last=L[i]
            count=1
    score+=count//2

    return score


t=int(input())
for i in range(t):
    n=int(input())
    s=str(input()).split()
    L=[int(i) for i in s]
    print(maxScore(L))