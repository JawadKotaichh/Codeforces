def sakurako(a,b):
    if a%2==0 and b%2==0:
        return "Yes"
    elif a%2==0 and b%2!=0:
        if a>=2:
            return "Yes"
        else:
            return "No"
    else:
        return "No"
t=int(input())
for i in range(t):
    a,b=map(int,input().split())
    print(sakurako(a,b))