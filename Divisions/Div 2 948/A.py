t=int(input())
for i in range(t):
    s=str(input()).split()
    n=int(s[0])
    m=int(s[1])
    if n<m:
        print("No")
    elif (n-m)%2==0:
        print("Yes")
    else:
        print("No")
