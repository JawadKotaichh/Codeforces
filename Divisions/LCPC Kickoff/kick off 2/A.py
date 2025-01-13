def Check(n,L):
    count=0
    indx=0
    indx1=0

    for i in range(1,n):
        if L[i]>L[i-1]:
            if count==0:
                indx=i
            elif count==1:
                indx1=i
            else:
                break
            count+=1
            
                
    k=L[indx]
    L[indx]=L[indx1]
    L[indx1]=k
    if L is sorted:
        return "Jamhoor"
    else:
        return "Farhat"

n=int(input())
s=str(input()).split()
L=[int(i) for i in s]
print(Check(n,L))