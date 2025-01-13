def legs(n):
    if n%4==0:
        return int(n/4)
    else:
        if n<4:
            c=int(n/2)
            return c
        
        cows=int(n/4)
        c2=n-(4*cows)
        c=int(c2/2)
        return c+cows
 
t = int(input())
for i in range(t):
    n=int(input())
    print(legs(n))
