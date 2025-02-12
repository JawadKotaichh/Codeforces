def check(a, b):
    if a == b:
        return 0
    diff = abs(a - b)
    count = 0
    sum_d = 0
    while True:
        count += 1
        sum_d += count
        if sum_d >= diff and (sum_d - diff) % 2 == 0:
            break
    return count

t = int(input())
for i in range(t):
    a, b = map(int, input().split())
    print(check(a, b))
