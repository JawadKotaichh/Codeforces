def binpow(a, b, m=10**9 + 7):
    a %= m
    res = 1
    while b:
        if b and 1:
            res = res * a % m
        a = a * a % m
        b >>= 1
    return res

def solve():
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    for i in range(n):
        print(binpow(2, b[i]))

if __name__ == "__main__":
    import sys
    input = sys.stdin.read
    data = input().split()
    
    index = 0
    T = int(data[index])
    index += 1
    
    for _ in range(T):
        solve()
