def perfect(L):
    min_01 = float('inf')
    min_10 = float('inf')
    min_11 = float('inf')
    
    for i in range(1,len(L),2):
        if L[i]=="01":
            if int(L[i-1])<min_01:
                min_01=int(L[i-1])
        elif L[i]=="10":
            if int(L[i-1])<min_10:
                min_10=int(L[i-1])
        elif L[i]=="11":
            if int(L[i-1])<min_11:
                min_11=int(L[i-1])

        sum=min_10 + min_01
        if sum == float('inf') and min_11 == float('inf'):
            return -1
        else:
            return min(sum, min_11)

# def perfect(L):

#     d01={}
#     d10={}
#     d11={}
#     flag11=False
#     flag01=False
#     flag10=False
#     min01=0
#     min10=0
#     min11=0
#     for i in range(1,len(L),2):
#         if L[i]=="01":
#             d01[int(L[i-1])]=2
#             flag01=True
#         if L[i]=="10":
#             d10[int(L[i-1])]=1
#             flag10=True
#         if L[i]=="11":
#             d11[int(L[i-1])]=3
#             flag11=True

#     if flag10==True and flag01==True:
#         min01=min(d01)
#         min10=min(d10)
#     if flag11==True:
#         min11=min(d11)

#     if flag11==True:
#         if (flag01==True and flag10==False ) or (flag01==False and flag10==True ):
#             return min11
#         elif (flag01==False and flag10==False ):
#             return min11
#         else:
#             return min(min10+min01,min11)
#     else:
#         if (flag01==True and flag10==True ):
#             return min10+min01
#         else:
#             return -1
        
t=int(input())
for i in range(t):
    n=int(input())
    L=[]
    for j in range(n):
        x=str(input())
        L= L + x.split()
    print(perfect(L))