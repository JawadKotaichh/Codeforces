import math
def MinMoves(x,y,k):
    reqx=math.ceil(x/k)
    reqy=math.ceil(y/k)       
    answer=max(reqx,reqy)*2
    if reqx>reqy:
        return answer-1
    else:
        return answer


t=int(input())
for i in range(t):
    s=str(input()).split()
    x=int(s[0])
    y=int(s[1])
    k=int(s[2])
    print(MinMoves(x,y,k))
