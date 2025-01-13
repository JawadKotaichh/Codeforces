
import math
def Triple(l,r):

    output = 0
    multamount = 1

    if l == 1:
        mult = 1
    else:
        mult = l + 1

    isf = True
    for i in range(1, 16):
        left = pow(3, i - 1)
        right = pow(3, i) - 1

        if l > right or r < left:
            continue

        range_start = max(l, left)
        range_end = min(r, right)

        if range_start <= range_end:
            range_len = range_end - range_start + 1
            if isf:
                range_len += 1
                isf = False
            output += i * range_len

    return output

t=int(input())
for i in range(t):
    s=str(input()).split()
    l=int(s[0])
    r=int(s[1])
    print(Triple(l,r))
