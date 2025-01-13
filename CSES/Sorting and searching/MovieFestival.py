def Movie(L):
    # 3 5 / 4 9 / 5 8
    # L=[(3,5),(4,9),(5,8)]
    # {3:5, 4:9, }
    # 3--->5 4--->9 5--->8
    # 3-5 5-8
    maxi=0
    D={}
    L.sort(key=lambda x: x[1])
    answerL=[L[0]]
    for i in range(1,len(L)):
        if L[i][0]>=answerL[-1][1]:
            answerL.append(L[i])
    return len(answerL)

n=int(input())
L=[]
for i in range(n):
    start,end = map(int,input().split())
    L.append((start,end))
print(Movie(L))