def Right(n, L, s):
    prefix_sum = [0] * (n + 1)
    for i in range(1, n + 1):
        prefix_sum[i] = prefix_sum[i - 1] + L[i - 1]
    
    answer = 0
    pl = 0
    pr = n - 1
    
    while pr > pl:
        if s[pl] == "L" and s[pr] == "R":
            answer += prefix_sum[pr + 1] - prefix_sum[pl]
            pr -= 1
            pl += 1
        elif s[pl] != "L":
            pl += 1
        elif s[pr] != "R":
            pr -= 1
    return answer
t=int(input())
for i in range(t):
    n=int(input())
    s=str(input()).split()
    L=[int(i) for i in s]
    s=str(input())
    print(Right(n,L,s))