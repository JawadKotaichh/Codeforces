def find(a,b):
    if a==0 and b==0:
        return "YES"
    elif (a==0 and b!=0) or (b==0 and a!=0):
        return "NO"
    sumi=a+b
    if max(a,b)-min(a,b)>min(a,b):
        return "NO"
    if sumi%3==0:
        return "YES"
    else:
        return "NO"


t=int(input())
for i in range(t):
    s=str(input()).split()
    a=int(s[0])
    b=int(s[1])
    print(find(a,b))