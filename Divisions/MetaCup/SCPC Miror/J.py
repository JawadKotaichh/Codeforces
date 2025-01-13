def original(n,m,s,t):
    long=""
    if s in t and len(s)<len(t):
        return -1
    else:
        start=""
        end=""
        for i in range(m):
            if t[i] in s and start=="":
               start=t[i]
            elif t[i] in s and start!="" and end=="":
                end=t[i]
        strtind=0
        endind=0
        for j in range(n):
            if s[j]==start:
                long+=s[j]
                strtind=j
            
            elif s[j]==end and len(long)!=0 and j>strtind:
                endind=j
            if s[j]==end and len(long)==0 and j==n-1:
                return -1
        long=s[strtind:endind+1]
    if long!="":
        return long
    return -1

t=int(input())
for i in range(t):
    s1=str(input()).split()
    n=int(s1[0])
    m=int(s1[1])
    s=str(input())
    t=str(input())
    print(original(n,m,s,t))