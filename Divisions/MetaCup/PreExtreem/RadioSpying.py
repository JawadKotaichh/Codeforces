def radio(n,st,m):
    curr=st[0]
    count=1
    duplicate=True
    while duplicate==True:
        for i in range(1,n):
            if st[i]==curr:
                count+=1
                if count==m:
                    count=0
                    st=st[:i+1-m-1]+st[i+1:]
                    break
                if i==n-1:
                    duplicate=False
    return st




s=str(input()).split()
n=int(s[0])
m=int(s[1])
st=str(input())
print(radio(n,st,m))