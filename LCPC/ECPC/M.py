t = int(input())

while t != 0:
    n = int(input())
    # print(s2)
    s1 = str(input()).split()
    # print(s1)
    a = [int(s1[i]) for i in range(len(s1))]
    cost = 0
    for i in range(len(a)):
        sumi = sum(a[0 : i + 1])
        cost = cost ^ sumi
        sumi = 0
        for j in range(i + 1, len(a)):
            sumi += a[j]
        cost = cost ^ sumi
    print(cost)
    t -= 1
