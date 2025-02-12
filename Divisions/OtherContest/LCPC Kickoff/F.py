def SAT(n,m,L):
    D={}
    for i in range(1,m+1):
        D[i]='-'
    count=0
    for j in range(n):
        if L[j]>0:
            count+=1
    if count >=m:
        asnwer="1 "*(m-1)
        answer+="1"
        return answer 




    if L[0]>0:
        D[L[0]]=1
    else:
        D[-L[0]]=0

    if L[1]>0:
        D[L[1]]=1
    else:
        D[-L[1]]=0

    for i in range(2,n*2,2):
        if L[i]<0:
            if D[-L[i]]==1:
                if L[i+1]<0:
                    if D[-L[i+1]]==1:
                        return -1
                    else:
                        D[-L[i+1]]=0
                else:
                    if D[L[i+1]]==0:
                        return -1
                    else:
                        D[L[i+1]]=1
            else:
                D[L[i]]=0
        
        else:
            if D[L[i]]==0:
                if L[i+1]<0:
                    if D[-L[i+1]]==1:
                        return -1
                    else:
                        D[-L[i+1]]=0
                else:
                    if D[L[i+1]]==0:
                        return -1
                    else:
                        D[L[i+1]]=1
            else:
                D[L[i]]=1
    
    values=list(D.values())
    for j in range(len(values)):
        if values[j]=='-':
            values[j]=0

    result_string = ' '.join(map(str, values))
    return result_string


s=str(input()).split()
n=int(s[0])
m=int(s[1])
L=[]
for i in range(n):
    s1=str(input()).split()
    L.append(int(s1[0]))
    L.append(int(s1[1]))

print(SAT(n,m,L))