def prefix_sum(nums):
    n = len(nums)
    prefix = [0] * n
    prefix[0] = nums[0]

    for i in range(1, n):
        prefix[i] = prefix[i - 1] + nums[i]

    return prefix

def flower(n, m, L):
    L.sort()
    prefx=prefix_sum(L)
    current=0
    
    for i in range(len(L)):
        current=L[i]

        




t=int(input())
for i in range(t):
    s1=str(input())
    l1=s1.split()
    n=int(l1[0])
    m=int(l1[1])
    s2=str(input())
    l2=s2.split()
    L=[int(x) for x in l2]
    print(flower(n,m,L))