n=int(input())
if n==1:
    print(1)
else:
    s=str(n)+" "
    while n!=1:
        if n%2==0:
            n=int(n/2)
        else:
            n=(n*3)+1
        s=s+str(n)+" "
    print(s)