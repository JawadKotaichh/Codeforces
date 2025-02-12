def Afternoon(L):
    listOfTime=[]
    answer=0

    while len(L)!=1:
        currx0=0
        for i in range(2,len(L)-2,2):
            if L[i-1]-L[i+1]!=0:
            
            t=(L[i]-L[i-2])/(L[i-1]-L[i+1])
            listOfTime.append(t)
        
        mini=min(listOfTime)
        indx=L.index(mini)
        answer+=mini

        currv=min(L[indx+1],L[indx+3])
        currx0+=(L[indx+1]*mini)+L[indx+2]


        L=L[:indx]+[currv,currx0]+L[indx:]
        return answer
    
    # t=(L[2]-L[0])/(L[1]-L[3])
    # answer+=t
    # currv=0
    # if L[3]<L[1]:
    #     currv=L[3]
    # else:
    #     currv=L[1]
    # currx0=(L[1]*t)+L[0]

    # for i in range(4,len(L),2):
    #     if L[i+1]-currv!=0:
    #         t=(L[i]-currx0)/(L[i+1]-currv)
    #         if t<0:
    #             t=t*(-1)

    #         answer+=t
    #         currv=min(currv,L[i])
    #         currx0=(L[i+1]*t)+currx0



t=int(input())
L=[]
for i in range(t):
    s=str(input()).split()
    L.append(int(s[0]))
    L.append(int(s[1]))
result = Afternoon(L)

print(result)