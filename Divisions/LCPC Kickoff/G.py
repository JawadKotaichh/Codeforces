def Pyramid(n):
    answer=0
    answer+=n*(n+1)/2
    answer+=n*(n-1)/2
    return int(answer)
t=int(input())
for i in range(t):
    n=int(input())
    print(Pyramid(n))