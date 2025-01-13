# def all_non_contiguous_sums(lst):
#     n = len(lst)
#     sublist_sums = []
    
#     # Generate all subsets using binary representation
#     for mask in range(1, 1 << n):  # 1 to 2^n - 1
#         sublist = [lst[i] for i in range(n) if mask & (1 << i)]
#         sublist_sums.append(sum(sublist))

#     return sublist_sums

def Coin(L):
    L.sort()
    current_sum = 0

    for num in L:
        if num > current_sum + 1:
            return current_sum + 1
        current_sum += num

    return current_sum + 1

# Input handling
# n = int(input())
# L = list(map(int, input().split()))
# print(Coin(L))

    # L.sort()
    # cummulativeSum=0
    # curr=1
    # if L[0]>=2:
    #     return L[0]-1 
    # for i in range(len(L)):
    #     cummulativeSum+=L[i]
    #     # print("i=",i)
    #     # print("Cum",cummulativeSum)
    #     # print("Curr",curr)

    #     if curr==L[i]:
    #         curr=L[i]+1
    #     elif cummulativeSum==curr:
    #         curr=cummulativeSum+1
    #     else:
    #         return curr
    # return sum(L)+1
    
n=int(input())
L=[int(x) for x in str(input()).split()]
print(Coin(L))