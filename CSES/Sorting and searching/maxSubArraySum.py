# def maxSubArraySum(L):
#     maxSum=float ('-inf')
#     currSum=0
#     for i in range(len(L)):
#         currSum=L[i]
#         for j in range(i+1,len(L)):
#             if currSum>maxSum:
#                 maxSum=currSum
#             currSum+=L[j]
#             if currSum>maxSum:
#                 maxSum=currSum
#         if currSum>maxSum:
#                 maxSum=currSum
#     return maxSum
def maxSubArraySum(L,n):
    maxSum = L[0]  # max-sum found at or before iteration i 
    aCurrent = 0  # start of the max-sum subsequence ending at i 
    sumCurrent = 0
    for i in range(n):
        sumCurrent = sumCurrent+L[i]
        if sumCurrent>=0:
            if sumCurrent>maxSum:
                maxSum = sumCurrent
                a = aCurrent
                b = i
                # a is the start of max-sum subsequence found at or before iteration i 
                # b is the end of max-sum subsequence found  at or before iteration i 
        else:
            # if sumCurrent<0, rest: 
            sumCurrent = 0
            aCurrent = i+1
    if maxSum<0:
        return max(L)
    return maxSum
n=int(input())
L=[int(x) for x in str(input()).split()]
print(maxSubArraySum(L,n))