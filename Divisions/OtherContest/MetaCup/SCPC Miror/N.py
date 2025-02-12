def pointer(n,m,k,s,p):
    pointer=0
    for i in range(n):
        if s[i] in p








        if s[i] in p:
            for j in range(i+1,k):
                if s[j] in p:
                    pointer+=1
        i=pointer
    if pointer!=n-1:
        return "No"

    else:
        return "yes"

t=int(input())
for i in range(t):
    s1=str(input()).split()
    n=int(s1[0])
    m=int(s1[1])
    k=int(s1[2])
    s=str(input())
    p=str(input())
    print(pointer(n,m,k,s,p))
