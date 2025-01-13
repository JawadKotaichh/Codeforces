import math

def getSumMutipleOf3And5(n):
    sum=0

    for i in range(n):
       if i%3==0 or i%5==0:
           sum+=i

    return sum

n=int(input())
print(getSumMutipleOf3And5(n))
# print(math.log(n,3))
# print(math.log(n,5))