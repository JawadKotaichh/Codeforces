# import math
# def power(n,k):
#     if n==0:
#         return 0
#     if k==1 or k==0:
#         return n
#     count=0

#     while n!=0:
#         if n==k:
#             return count+1
#         else:

#             lower_power = k ** (int(math.log(n,k)))
#             count+=1
#             n-=(lower_power)
#     if n==0:
#         return count
# t=int(input())
# for i in range(t):
#     s=str(input()).split()
#     n=int(s[0])
#     k=int(s[1])
#     print(power(n,k))

import math
def power(n,k):
    if k==1:
        return n
    count=0

    while n>0:
       count+=n%k
       n//=k
    return count

t=int(input())
for i in range(t):
    s=str(input()).split()
    n=int(s[0])
    k=int(s[1])
    print(power(n,k))

