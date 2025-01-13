def Stick(L):
    # 1 2 2 3 5
    # 1 0 0 1 3
    L.sort()
    mid=L[len(L)//2]
    answer=0
    for i in range(len(L)):
        answer+=abs(L[i]-mid)
    return answer

n=int(input())
L=[int(x) for x in str(input()).split()]
print(Stick(L))
