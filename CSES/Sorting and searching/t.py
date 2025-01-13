
def Startup(n, k, L):
    D = {}
    for s1, s2 in L:
        if s1 in D:
            D[s1]+=s2
        else:
            D[s1]=s2
         
    sortedDict = sorted(D.values(), reverse=True)
    
    return sum(sortedDict[:n])

t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    L = [tuple(map(int, input().split())) for _ in range(k)]
    print(Startup(n, k, L))


# # def Coil(L):
# #     if len(L)<=1:
# #         return "YES"
# #     for j in range(1,len(L)):
# #         if abs(L[j]-L[j-1])!=7 and abs(L[j]-L[j-1])!=5:
# #             return "NO"
# #     return "YES"
 
# # t=int(input())
# # for i in range(t):
# #     n=int(input())
# #     L=[int(x) for x in str(input()).split()]
# #     print(Coil(L))

# def Startup(n,k,L):
#     # if k<=n:
#     #     answer=0
#     #     for x in range(len(L)):
#     #         answer+=L[x][1]
#     #     return answer
#     # (2,6) (2,7) (1,15)
#     # D={2:[6,7], 1:[15]}

#     # D={}
#     # answer=0
#     # for i in range(len(L)):
#     #     if L[i][0] not in D:
#     #         D[L[i][0]]=[L[i][1]]
#     #     else:
#     #         D[L[i][0]].append(L[i][1])
#     # answer=0
#     # L.sort(key=lambda x:x[1])
#     # pointer=len(L)-1
#     # count=0
#     # the problem is that if there is a better otion to take we should take
#     # the problem remains,
#     # for each number I get its corresponding values
#     D={}
#     for i in range(len(L)):
#         if L[i][0] not in D:
#             D[L[i][0]]=L[i][1]
#         else:
#             D[L[i][0]]+=L[i][1]
#     sortedDict=sorted(D.values(), reverse=True)
#     return sum(sortedDict[:n])
#     # count=0    
#     # answer=0
#     # for x in range(len(sortedDict)-1,-1,-1):
#     #     answer+=sortedDict[x][1]
#     #     count+=1
#     #     if count==n:
#     #         return answer
#     # last attempt
#     # alreadyShelter={}
#     # temp=0
#     # while pointer>=0:
#     #     if L[pointer][0] in alreadyShelter:
#     #         answer+=L[pointer][1]
#     #     else:
#     #         if count!=n:
#     #             alreadyShelter[L[pointer][0]]=pointer
#     #             answer+=L[pointer][1]
#     #             count+=1
#     #         else:
#     #             temp+=L[pointer][1]
#     #     pointer-=1
#     # return answer
    

    
# t=int(input())
# for i in range(t):
#     n,k=map(int,input().split())
#     L=[]
#     for j in range(k):
#         s1,s2=map(int,input().split())
#         L.append((s1,s2))
#     print(Startup(n,k,L))
