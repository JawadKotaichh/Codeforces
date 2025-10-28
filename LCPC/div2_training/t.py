t = int(input())
while t != 0:
    s = str(input()).split()
    n = int(s[0])
    k = int(s[1])
    inpu = str(input())
    ans = 0
    last_one = -k
    for j in range(len(inpu)):
        if inpu[j] == "1":
            if j - last_one >= k:
                ans += 1
            last_one = j

    print(ans)

    t -= 1
