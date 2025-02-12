# def goals(l):
#     if len(l)==1:
#         return str(l[0])+" "+ str(l[0])
#     maxi=sum(l)
#     if maxi%2==0:
#         s=str(int(maxi/2))+" " + str(maxi)
#         return s
#     else:
#         s=str(int(maxi/2)+1)+" " + str(maxi)
#         return s


# t = int(input())
# for i in range(t):
#     n=int(input())
#     s=str(input())
#     l=s.split()
#     num_list = [int(num) for num in l]
#     print(goals(num_list))


# def goals(l):
#     if len(l)==1:
#         return str(l[0])+" "+ str(l[0])
    
#     maxi=sum(l)
#     l.sort()
#     assist=0
#     while len(l)!=1:
#         mini1=l[0]
#         maxi1=l[len(l)-1]
#         assist+=mini1
#         l[len(l)-1]=maxi1-mini1
        
#         l=l[1:]
#         l.sort()
#         if len(l)==1:
#             assist+=l[0]
#     return str(assist)+" "+ str(maxi)

# def goals(l):
#     if len(l)==1:
#         return str(l[0])+" "+ str(l[0])
    
#     maxi=sum(l)
#     l.sort()
#     assist=0
#     while len(l)!=1:
#         mini1=l[0]
#         maxi1=l[len(l)-1]
#         assist+=mini1
#         l[len(l)-1]=maxi1-mini1
        
#         l=l[1:]
#         if len(l)==1and l[0]>0:
#             assist+=l[0]
#     return str(assist)+" "+ str(maxi)


# def goals(l):
#     if len(l)==1:
#         return str(l[0])+" "+ str(l[0])
    
#     maxi=sum(l)
    
#     l.sort()
#     assist=0
#     while len(l)!=1:
#         maxi2=l[len(l)-2]
#         maxi1=l[len(l)-1]
        
#         if maxi1-maxi2<0:
#             assist+=maxi1
#             l[len(l)-1]=-maxi1+maxi2
#         else:
#             assist+=maxi2
#             l[len(l)-1]=maxi1-maxi2
            
        
#         l = l[:len(l)-2] + l[len(l)-1:]
#         if len(l)==1 and l[0]>0:
#             assist+=l[0]
#     return str(assist)+" "+ str(maxi)






def goals(L):
    maxi=sum(L)
    L.sort()
    if sum(L[:len(L)-1])<=L[len(L)-1]:
        return str(L[len(L)-1]) + " " + str(maxi)
    else:
        if sum(L)%2==0:
            return str(int(sum(L)/2)) + " " +  str(maxi)
        else:
            return str(int(sum(L)//2)+1)  + " " + str(maxi)


t = int(input())
for i in range(t):
    n=int(input())
    s=str(input())
    l=s.split()
    num_list = [int(num) for num in l]
    print(goals(num_list))