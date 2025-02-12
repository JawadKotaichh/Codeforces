def largest(n,k,L):
    r = [0] * n
    sum_odd = sum(L[i] for i in range(1, n, 2))
    sum_even = sum(L[i] for i in range(0, n, 2))
    r[0] = (k + sum_odd - sum_even) / 2
    for i in range(1, n):
        r[i] = k - L[i-1] - r[i-1]
    max_index = r.index(max(r))+1
    return max_index

t=int(input())
for i in range(t):
    s=str(input()).split()
    n=int(s[0])
    k=int(s[1])
    s1=str(input()).split()
    L=[int(i) for i in s1]
    print(largest(n,k,L))