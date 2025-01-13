# array of  integers
# n=lenght of the subarrray
# you are asked to get the max gcd
#  L=[6,9,24]
#len=3
# div 6: 1 2 3 6
# div 9: 1 3 9
# div 24: 1 2 3 4 6 8 12 24

# 10 20 55 43
# len=3
# 10 20 55---> 10: 1 2 5 10



# L=[2,3,4] and len=1
# max(L)

# len=2 gdc of every two adjacent elements
from math import gcd

def max_gcd_subarray(arr):
    max_gcd = 0
    n = len(arr)
    
    for i in range(n):
        for j in range(i + 1, n):
            max_gcd = max(max_gcd, gcd(arr[i], arr[j]))
    
    return max_gcd

t=int(input())
for i in range(t):
    