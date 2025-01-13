def afternon(L):
    answer=0
    converge=False
    while converge==False:
        listOfTimes=[]
        for i in range(0,len(L)-2,2):
            if L[i+1]!=L[-1]:
                if (L[-1]-L[i+1])!=0:
                    t=(L[-2]-L[i])/(L[-1]-L[i+1])
                    listOfTimes.append(t)
                    converge=True
    if converge==True:
        return abs(min(listOfTimes))
    else:
        return -1
t=int(input())
L=[]
for i in range(t):
    s=str(input()).split()
    L.append(int(s[0]))
    L.append(int(s[1]))
result = afternon(L)

print(result)