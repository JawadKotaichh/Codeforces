def check(L,t):
    
    D={}
    for j,num in enumerate(L):
        complement = t- num 
        if complement in D:
            return f"{D[complement] + 1} {j + 1}"
        D[L[j]]=j
        
    # for i in range(len(L)):
    #     if t-L[i] in D:
    #         if L[i]*2!=t:
    #             return str(D[L[i]][0])+ " "+str(D[t-L[i]][0])
    #         else:
    #             if len(D[L[i]])>=2:
    #                 return str(D[L[i]][0])+ " "+str(D[t-L[i]][1])

    # L.sort()       
    # start=0
    # end=len(L)-1
    
    # while start<end:
      
    #     if L[start]+L[end]>t:
    #         end-=1
    #     elif L[start]+L[end]==t:
    #         if L[start]==L[end]:
    #             return str(D[L[start]][0]) +" "+str(D[L[end]][1])
    #         else: 
    #             return str(D[L[start]][0]) +" "+str(D[L[end]][0])
    #     else:
    #         start+=1
    return "IMPOSSIBLE"
    
n,x=map(int,input().split())
s=str(input()).split()

L=[int(i) for i in s]
print(check(L,x))
