def lura(n,s):
    x=s

    c=""+x[0]
    k=0
    for j in range(1,n):
        if j+1<n-1:

            if x[j] in "bcd" and x[j+1] in "bcd":
                if c[k] not in "bcd":
                    c=c+x[j]+'.'
                    k+=2
                else:
                    k+=1
                    c=c+x[j]
            else:
                if x[j] in "bcd" and c[k] in "ae" and x[j+1] in "ae":
                    c=c+'.'+x[j]
                    k+=2
                else:
                    c=c+x[j]
                    k+=1
        else:
            if len(x[j:])==2 and x[j] in "bcd" and c[k]!='.':
                c=c+'.'+x[j:]
                break
            else:
                c=c+x[j:]
                break
    return c

t =int(input())
for i in range(t):
    n=int(input())
    s=str(input())
    
    print(lura(n,s))