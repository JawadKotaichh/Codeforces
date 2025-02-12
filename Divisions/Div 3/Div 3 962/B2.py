t=int(input())
for i in range(t):
    s1=str(input()).split()
    n=int(s1[0])
    k=int(s1[1])
    l = []
    for _ in range(n):
        l.append(input())
    for i in l[::k]:
       print("".join(i[::k]))
