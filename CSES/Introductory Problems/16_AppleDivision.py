def Apple(n,L):
    if n==1:
        return L[0]
    if n==2:
        return L[1]-L[0]
    L.sort()
    if L[n-1]>sum(L[:n-1]):
         return L[n-1]-sum(L[:n-1])
    L1=[L[n-1]]
    L2=[L[n-2]]
    x=1
    finalL=[]
    last=0
    while x!=n:
        sumi=sum(L[last:x])
        if sum(L[last:x])<L[x]:
              x+=1
        else:
            finalL.append(sum(L[last:x-1]))
            last=x-1
            x+=1
    p=0
    while p!=len(finalL):
        if p!=len(finalL)-1:

            if sum(L1)>sum(L2):
                L1.append(finalL[p])
                L2.append(finalL[p+1])
            else:
                L2.append(finalL[p])
                L1.append(finalL[p+1])
            p+=2
        else:
            if sum(L1)>sum(L2):
                L2.append(finalL[p])
            else:
                L1.append(finalL[p])
            break
    return abs(sum(L1)-sum(L2))

n=int(input())
s=str(input()).split()
L=[int(i)for i in s]
print(Apple(n,L))


def solve(idx, arr, sum1, sum2, N):
    if idx == N:
        return abs(sum1 - sum2)

    choose = solve(idx + 1, arr, sum1 + arr[idx], sum2, N)

    not_choose = solve(idx + 1, arr, sum1, sum2 + arr[idx], N)

    return min(choose, not_choose)

n=int(input())
s=str(input()).split()
L=[int(i)for i in s]

ans = solve(0, L, 0, 0, n)
print(ans)