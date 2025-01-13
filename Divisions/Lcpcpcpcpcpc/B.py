# 0 1 1 1 1

# 0
# 0 1 1 1 1
# 1 1 1 1


# 0 0 0 1 1 1 1 

# get number of zeros 
# 
# check if there a sum of ones div x + number of 0   
#      
# check the combination between 0 and 
# if sum of ones is div x


# 0 1 1 1 1
# 4C4

# number of ones =50
# get all mutliple of x less than or equal to number of ones
# 

# 20 ones and 3 zeros
# you can take 16 8 4 0
# 20C16 ones ---> 0 0 0 00 00 00 000 --> 3C1+3C2+3C3 --> multipl
# 
MOD = 10**9 + 7

def Divisors(N, X, A):
    dp = [0] * X 
    dp[0] = 1  
    
    for num in A:
        new_dp = dp[:]
        for r in range(X):
            new_r = (r + num) % X
            new_dp[new_r] = (new_dp[new_r] + dp[r]) % MOD
        dp = new_dp
    
    return (dp[0] - 1) % MOD


t=int(input())
for i in range(t):
    n,x=map(int,input().split())
    s=str(input()).split()
    A=[int(i) for i in s]
    print(Divisors(n,x,A))