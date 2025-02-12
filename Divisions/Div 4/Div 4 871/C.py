def perfect(L):

    answer=-1
    sum=0
    min01=0
    min10=0
    min11=0

    for i in range(1,len(L),2):
        if L[i]=="01":
            if min01==0:
                min01=int(L[i-1])
            else:
                if int(L[i-1])<min01:
                    min01=int(L[i-1])
        else:
            if L[i]=="10":
                if min10==0:
                    min10=int(L[i-1])
                else:
                    if int(L[i-1])<min10:
                        min10=int(L[i-1])
            else:
                if  L[i]=="11":
                    if min11==0:
                        min11=int(L[i-1])
                    else:
                        if int(L[i-1])<min11:
                            min11=int(L[i-1])

    if (min01+min10)!=0 and min11!=0:
        return min(min01+min10,min11)
    elif min11==0 and (min01+min10)==0 or min01==0 or min10==0:
        return -1
    elif  min11==0 and (min01+min10)!=0 :
        return min01+min10
    else:
        return min11

    
    
t=int(input())
for i in range(t):
    n=int(input())
    L=[]
    for j in range(n):
        x=str(input())
        L= L + x.split()
    print(perfect(L))