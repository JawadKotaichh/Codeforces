n=int(input())
if n==3 or n==2:
    print("NO SOLUTION")
elif n==4:
    print("2 4 1 3")
else:
    answer=""
    m=""
    L=[x for x in range(1,n+1)]
    for j in range(1,n+1):
        if j%2==0:
            m+=str(j)+" "
        else:
            answer+=str(j)+" "
    print(answer+m)



