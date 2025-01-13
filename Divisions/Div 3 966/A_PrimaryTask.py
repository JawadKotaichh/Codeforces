def primary(n):
    s=str(n)
    if len(s)<=2:
        return "NO"
    if s[0]!="1":
        return "no"
    elif s[0]=="1" and s[1]!="0":
        return "No"
    
    newn=n%10**(len(s)-2)
    news=str(newn)
    
    if newn==0 or newn==1:
        return "No"
    if s[2]=="0":
        return "no"
    return "yes"
t=int(input())
for i in range(t):
    n=int(input())
    print(primary(n))