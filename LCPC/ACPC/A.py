import math


def f(alphas, k):
    sa = min(alphas)
    ba = max(alphas)
    na = ba - sa
    bestM = 360
    for i in range(k, 0, -1):
        curr = na / i
        if math.floor(curr) == math.ceil(curr):
            if curr < bestM:
                bestM = int(curr)
    return bestM


t = int(input())
while t != 0:
    s1 = str(input()).split()
    n = int(s1[0])
    k = int(s1[1])
    s2 = str(input()).split()
    alphas = [int(s2[i]) for i in range(len(s2))]
    wk = []
    for pi in alphas:
        alphaPrime = []
        for x in alphas:
            if x > pi:
                alphaPrime.append(360 - abs(pi - x))
            else:
                alphaPrime.append(pi - x)
        alphaPrime.sort()
        h = f(alphaPrime, k)
        wk.append(h)
    print(min(wk))
    t -= 1
