def Parity(n,L):
    odd=0
    even=0
    evli=[]
    odli=[]
    for i in range(n):
        if L[i]%2==0:
            even+=1
            evli.append(L[i])
        else:
            odd+=1 
            odli.append(L[i])
    if even==0 or odd==0:
        return 0
    else:
        answer=0
        while even!=0:
            evli.sort()
            odli.sort()
            mini=evli[0]
            maxi=odli[-1]
            if mini>maxi:
                mini=evli[-1]
                
            miniindex=0
            
            maxiindex=-1
            if mini<maxi:
                evli[miniindex]=mini+maxi
                even-=1
                odli.append(evli[miniindex])
                evli=evli[:miniindex]+evli[miniindex+1:]
                
                answer+=1
            else:
                answer+=1
                if (mini+maxi)%2==0:
                    evli.append(mini+maxi)
                    odli=odli[:maxiindex]+odli[maxiindex+1:]
                    even+=1
                else:
                    
                    odli[maxiindex]=mini+maxi 
    return answer
     
t=int(input())
for i in range(t):
    n=int(input())
    s=str(input()).split()
    L=[int(x) for x in s]
    print(Parity(n,L))