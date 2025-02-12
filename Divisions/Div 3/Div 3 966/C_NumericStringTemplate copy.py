def have_equal_values(dict1, dict2):
    values1 = sorted(dict1.values())
    values2 = sorted(dict2.values())
    return values1 == values2
def Numeric(n,L,s):
    if len(s)!=n:
        return "No"
    else:
        D={}
        for i in range(n):
            if L[i] not in D:
                D[L[i]]=[i]
            else:
                D[L[i]].append(i)
        D2={}        
        for i in range(n):
            if s[i] not in D2:
                D2[s[i]]=[i]
            else:
                D2[s[i]].append(i)
        if have_equal_values(D,D2):
            return "Yes"
        else:
            return "No"
        
t=int(input())
for i in range(t):
    n=int(input())
    s=str(input()).split()
    L=[int(i) for i in s]
    l=int(input())
    for j in range(l):
        s=str(input())
        print(Numeric(n,L,s))