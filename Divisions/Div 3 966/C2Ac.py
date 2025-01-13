for t in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    
    m = int(input())
    for _ in range(m):
        q = input().strip()
        
        if len(q) != n:
            print("NO")
            continue
        
        dict = {}
        track = [False] * 26
        chars = [0] * 26
        
        yes = True
        for i in range(n):
            d = ord(q[i]) - ord('a')
            if not track[d]:
                if a[i] in dict:
                    yes = False
                dict[a[i]] = True
                track[d] = True
                chars[d] = a[i]
            
            if chars[d] != a[i]:
                yes = False
        
        print('YES' if yes else 'NO')