def Slavic(s,t):
    ref="abcdefghijklmnopqrstwxyz"
    if t in s:
        print("Yes")
        return s.replace('?', ref[0])
    s=list(s)
    if len(t)==len(s):
        for j in range(len(t)):
            if t[j]!=s[j]:
                if s[j]=="?":
                    s[j]=t[j]
                else:
                    return "No"
        print("Yes")
        return ''.join([c if c != '?' else s[i - 1] for i, c in enumerate(s)])
    
    else:
        l=0
        count=len(t)
        for j in range(len(s)):
            if l<=len(t)-1:
                if t[l]==s[j]:
                    l+=1
                    count-=1
                else:
                    if s[j]!="?":
                        if len(s)-j-1<count:
                            return "No"
                    else:
                        s[j]=t[l]
                        l+=1
                        count-=1
        print("Yes")
        return ''.join([c if c != '?' else t[0] for c in s])

t=int(input())
for i in range(t):
    s=str(input())
    t=str(input())
    print(Slavic(s,t))