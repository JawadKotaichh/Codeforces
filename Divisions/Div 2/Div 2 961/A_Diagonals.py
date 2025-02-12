def diagonal(n,k):
    if k==0:
        return 0
    if k<=n:
        return 1
    newk=k-n
    answer=1
    c=n-1
    count=1
    if newk-(2*c)<=0:
        if newk>c:
            answer=answer+2
            return answer
        else:
            return answer+1
    while newk-(2*c)>0:
        answer+=2
        newk=newk-(2*c)
        count+=1
        if count!=n-1:
            c=n-count
            if newk-(2*c)<=0:
                if newk>c:
                    answer=answer+2
                    return answer
                else:
                    return answer+1
        else:
            c=1
            if newk-(2*c)<=0:
                if newk>c:
                    answer=answer+2
                    return answer
                else:
                    return answer+1

    return answer

t =int(input())
for i in range(t):
    s=str(input())
    l=s.split()
    n=int(l[0])
    k=int(l[1])
    print(diagonal(n,k))
