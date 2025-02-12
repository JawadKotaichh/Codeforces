def Parity(n,L):
    evens=0
    odds=0
    for i in range(n):
        if L[i]%2==0:
            evens+=1
    odds = n - evens
    
    if evens == n:
        return 0
    
    if max(L) % 2 == 1:
        return evens
    maxodd=0
    even=[]
    for i in range(n):
        if L[i]%2==1:
            maxodd=max(maxodd,L[i])
    
    even = sorted(x for x in L if x % 2 == 0)
    
    answer = evens
    for x in even:
        if x < maxodd:
            maxodd = x + maxodd
        else:
            answer += 1
            maxodd += even[-1]
    
    return answer

t=int(input())
for i in range(t):
    n=int(input())
    s=str(input()).split()
    L=[int(x) for x in s]
    print(Parity(n,L))