def Mit(n,L):
    answer=""
    first=[]
    last=[]
    for i in range(n):
        if i%2==0:
            first.append(L[i])
        else:
            last.append(L[i])
    last.reverse()
    result_string = ' '.join(map(str, first+last))




    return result_string







t=int(input())
for i in range(t):
    n=int(input())
    s=str(input()).split()
    l=[int(i) for i in s]
    print(Mit(n,l))

