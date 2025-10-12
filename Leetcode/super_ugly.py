n = 10
primes = [2, 7, 13, 19]
dp = [1] * (n)
dp[0] = 1
pointers = [0] * len(primes)

for i in range(1, n):
    candidates = [dp[pointers[j]] * primes[j] for j in range(len(primes))]
    mini = min(candidates)
    dp[i] = mini
    for j in range(len(primes)):
        if candidates[j] == mini:
            pointers[j] += 1
print(dp[-1])
