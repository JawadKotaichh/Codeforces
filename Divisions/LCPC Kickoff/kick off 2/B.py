def Alice(n,L):
    mini=min(L)
    cost=0
    return sum(L)+(mini*(len(s)-2))





t=int(input())
for i in range(t):
    n=int(input())
    s=str(input()).split()
    L=[int(s[i]) for i in range(len(s))]
    print(Alice(n,L))