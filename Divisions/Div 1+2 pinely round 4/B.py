def good(x,b):
    n = len(b) + 1
    a = [0] * n
    
    a[0] = b[0]
    
    for i in range(1, n - 1):
        a[i] = b[i - 1] | b[i]
        
    a[n - 1] = b[n - 2]
    

    for i in range(n - 1):
        if (a[i] & a[i + 1]) != b[i]:
            return -1
    s=""
    for k in range(len(a)):
        s+=a[i]+" "
    return s
t=int(input())
for i in range(t):
    s1=str(input())
    n=int(s1)
    s1=str(input())
    l1=s1.split()
    lst=[int(x) for x in l1]
    print(good(n,lst))