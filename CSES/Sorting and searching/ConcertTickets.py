# # n tickets
# # m costumers
# # Every costumer can pay a specified amount
# # and he can buy the ticket with the nearest price <=max

# def binarySearch(D,x,n):
#     high=n-1
#     low=0
#     nearest=-1
#     index=None
#     while high>=low:
#         mid=(high+low)//2

#         if D[mid]==x:
#             del D[mid]
#             return (D,x,n-1)
        
#         elif D[mid]>x:
#             high=mid-1

#         else:
#             if D[mid]>nearest:
#                 nearest=D[mid]
#                 index=mid
#             low=mid+1
    
#     if index!=None:
#         del D[index]
#         return (D,nearest,n-1)
#     else:
#         return (D,nearest,-1)

# n,m=map(int,input().split())
# ListOfPrices=[int(i) for i in str(input()).split()]
# ListOfBuy=[int(i) for i in str(input()).split()]
# ListOfPrices.sort()

# D={}
# for i in range(len(ListOfPrices)):
#     if i not in D:
#         D[i] = ListOfPrices[i]

# n=len(ListOfPrices)

# for i in range(len(ListOfBuy)):
#     curr=binarySearch(D,ListOfBuy[i],n)
#     D=curr[0]
#     nearest=curr[1]
#     n=curr[2]
#     if n==-1:
#         print(-1)
#     print(curr)
import bisect

def concertTickets(price,pay):
    maxPrice=sorted(price)
    answerL=[]
    for i in range(len(pay)):

        itr=bisect.bisect_right(maxPrice,pay[i])

        if itr==0:
            answerL.append(-1)
        else:
            itr-=1
            answerL.append(maxPrice[itr])
            maxPrice.remove(maxPrice[itr])

    return "\n".join(map(str, answerL))
n,m=map(int,input().split())
ListOfPrices=[int(i) for i in str(input()).split()]
ListOfBuy=[int(i) for i in str(input()).split()]
print(concertTickets(ListOfPrices,ListOfBuy))