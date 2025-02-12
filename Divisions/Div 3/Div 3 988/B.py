def Get(k, L):
    
    total_grid_values = k - 2
    divisors = []
    for i in range(1, int(total_grid_values**0.5) + 1):
        if total_grid_values % i == 0:
            divisors.append((i, total_grid_values // i))
    
    for n, m in divisors:
        if n in L and m in L:
            return str(n) +" " +str(m)
t=int(input())
for i in range(t):
    k=int(input())
    s=str(input()).split()
    L=[int(i) for i in s]
    print(Get(k,L))