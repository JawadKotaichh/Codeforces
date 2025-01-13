
def shower(n,s:int,m,L):
    start=0
    for i in range(0,len(L),2):
        end=L[i]

        if end-start>=s:
            return "Yes"
        start=L[i+1]
    if m-start>=s:
        return "Yes"
    return "No"

t=int(input())
for i in range(t):
    L=[]
    s1=str(input()).split()
    n=int(s1[0])
    s=int(s1[1])
    m=int(s1[2])
    for j in range(n):
        s2=str(input()).split()
        L.append(int(s2[0]))
        L.append(int(s2[1]))
    print(shower(n,s,m,L))
        