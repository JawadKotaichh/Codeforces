t = int(input())
while t != 0:
    s1 = str(input()).split()
    n = int(s1[0])
    k = int(s1[1])
    x = int(s1[2])
    s = str(input()).split()
    a = [int(s[i]) for i in range(len(s))]
    a = sorted(a)
    b = a[0 : len(a) - k]
    c = a
    sumi = 0
    sumi2 = 0
    x1 = x
    if len(b) <= x:
        sumi = sum(b) * (-1)
    else:
        j = len(b) - 1
        while j > -1:
            if x > 0:
                sumi -= b[j]
                x -= 1
            else:
                sumi += b[j]
            j -= 1
    # print(f"b = {b}")
    # print(f"c = {c}")

    j = len(c) - 1
    # print(j)
    while j > -1:
        # print(f"x1 = {x1}")
        # print(f"sumi2 {sumi2}")
        if x1 > 0:
            sumi2 -= c[j]
            x1 -= 1
        else:
            sumi2 += c[j]
        j -= 1
    print(max(sumi, sumi2))

    t -= 1
