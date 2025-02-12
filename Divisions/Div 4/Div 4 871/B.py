def blank(s):
    maxi=0
    count=0
    for i in range(len(s)):
        if s[i]=="0":
            count+=1
        else:
            if count>maxi:
                maxi=count
            count=0
    if count>maxi:
        maxi=count


    return maxi

t=int(input())
for i in range(t):
    n=int(input())
    s=str(input())
    L=s.split()
    print(blank(L))