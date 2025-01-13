n=int(input())
L=[i for i in range(1,n+1)]
even=[i for i in range(2,n+1,2)]
odd=[i for i in range(1,n+1,2)]
sumev=sum(even)
sumod=sum(odd)
ev=len(even)
od=len(odd)
if sumev==sumod:
    print("YES")
    print(ev)
    print(even)
    print(od)
    print(odd)
elif sumev>sumod:
    diff=sumev-sumod
    if diff%2==0:
        pev=0
        pod=0
        while diff!=0:
            diff-=2
            odd[pod]+=1
            pod+=1
            even[pev]-=1
            pev+=1
            if diff==0:
                print("YES")
                print(ev)
                output_string1 = ' '.join(map(str, even))
                output_string2 = ' '.join(map(str, odd))
                print(output_string1)
                print(od)
                print(output_string2)
    else:
        print("NO")

else:
    diff=sumod-sumev
    if diff%2==0:
        pev=0
        pod=1
        while diff!=0:
            diff-=2
            odd[pod]-=1
            pod+=1
            even[pev]+=1
            pev+=1
            if diff==0:
                print("YES")
                print(ev)
                output_string1 = ' '.join(map(str, even))
                output_string2 = ' '.join(map(str, odd))
                print(output_string1)
                print(od)
                print(output_string2)
    else:
        print("NO")