def Blend(n,x,y):
    if x<=y:
        if n-((n//x)*x)==0:
            return n//x
        else:
            return (n//x) +1 
    else:
        if n-((n//y)*y)==0:
            return n//y
        else:
            return (n//y) +1 


t=int(input())
for i in range(t):
    n=int(input())
    x,y=map(int, input().split())
    print(Blend(n,x,y))