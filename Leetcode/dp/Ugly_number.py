n = 10
dp = [1] * (n)
dp[0] = 1
p2 = 0
p3 = 0
p5 = 0
for i in range(1, n):
    c2 = dp[p2] * 2
    c3 = dp[p3] * 3
    c5 = dp[p5] * 5
    dp[i] = min(c2, c3, c5)
    if dp[i] == c2:
        p2 += 1
    if dp[i] == c3:
        p3 += 1
    if dp[i] == c5:
        p5 += 1
print(dp)
print(dp[n - 1])
