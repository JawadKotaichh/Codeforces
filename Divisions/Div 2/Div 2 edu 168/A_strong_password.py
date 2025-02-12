def strong(s):
    l="abcdefghigklmnopqrstuvwxyz"
    if len(s)==1:
        for j in l:
            if s[0]!=j:
                return s[0]+j

    
    for i in range(0,len(s)):
        current=s[i]
        if i!=len(s)-1:
            
            if s[i+1]==current:
                for j in l:
                    if s[i]!=j:
                        return s[:i+1]+j+s[i+1:]
        else:
            if s[i-1]==s[i]:
                for j in l:
                    if s[i]!=j:
                        return s[:i+1]+j+s[i+1:]
            else:
                for j in l:
                    if s[i]!=j:
                        return s+j

t=int(input())
for i in range(t):
    s=str(input())
    print(strong(s))