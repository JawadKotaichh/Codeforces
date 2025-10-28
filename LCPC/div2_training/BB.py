L = []

t = int(input())
while t != 0:
    n = int(input())
    s = str(input()).split()
    L = [int(s[i]) for i in range(len(s))]
    prefix_max = [L[0]]
    for i in range(1, len(L)):
        if L[i] > prefix_max[-1]:
            prefix_max.append(L[i])
        else:
            prefix_max.append(prefix_max[-1])
    cost = 0
    end = n - 1 if (n % 2 == 0) else n - 2

    # print(f"end = {end}")
    # print(L)
    for i in range(end, 0, -2):
        L[i] = prefix_max[i]
        # print(f"i= {i}")
        if i + 1 < n:
            if L[i + 1] >= L[i]:
                c = L[i + 1] - L[i] + 1
                cost += c
                L[i + 1] = L[i] - 1
        if i - 1 >= 0:
            if L[i - 1] >= L[i]:
                c = L[i - 1] - L[i] + 1
                cost += c
                L[i - 1] = L[i] - 1
        # print(L)
    print(cost)
    t -= 1
