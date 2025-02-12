def HandSahke(n,m):
    answer=0
    curr=0
    answer=(m+1)*((2*n)-m-2)
    answer=answer/2

    #sum(n-1-m) for each values of m
    # while curr!=m+1:
    #     answer+=n-1-curr
    #     curr+=1
    return int(answer)

# sum(n-1-i) for i going from i from 0 to m


t=int(input())
for i in range(t):
    n,m=map(int,input().split())
    print(HandSahke(n,m))
            