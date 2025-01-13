def sq(s):
    summ=sum(s)
    if (sum(s)**0.5)-int(sum(s)**0.5)==0:
        return "YES"
    else:
        return "NO"



t =int(input())
for i in range(t):
    n=int(input())
    L1=str(input())
    s=list(map(int,L1.split()))
    
    print(sq(s))