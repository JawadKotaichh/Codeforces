import random
def check(s):
    d={}
    for i in range(len(s)):
        if s[i] not in d:
            d[s[i]]=1
        else:
            d[s[i]]+=1

    if len(d)==1:
        return "NO"
    else:
        print("YES")
        l=list(s)
        random.shuffle(l)
        s_different = ''.join(l)
        if s_different ==s:
            
            while s_different==s:
                l=list(s)
                random.shuffle(l)
                s_different = ''.join(l)
                if s_different!=s:
                    return s_different
        else:
            return s_different


t=int(input())
for i in range(t):
    s=str(input())
    print(check(s))