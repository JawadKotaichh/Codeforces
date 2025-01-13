# def factorial(n):
#     if n == 0:
#         return 1
#     else:
#         return n * factorial(n-1)
                             


# def Binomial(n,k):
#     if n==k:
#         return 1
#     if k==0:
#         return 1
    
#     answer=1/factorial(k)
#     for i in range(0,k):
#         answer*=(n-i)
#     return int(answer)

MOD = 10**9 + 7

def calculateWrongValues(n,k):
    C = [[0] * (n + 1) for _ in range(n + 1)]
    for n in range(n + 1):
        C[n][0] = 1
        C[n][n] = 1
        for x in range(1, n):
            C[n][x] = (C[n][x - 1] + C[n - 1][x - 1]) % MOD
    return C[n][k]

t=int(input())
s1=str(input()).split()
listOfn=[int(i) for i in s1]
s2=str(input()).split()
listOfk=[int(i) for i in s2]
for j in range(t):
    print(calculateWrongValues(listOfn[j],listOfk[j]))