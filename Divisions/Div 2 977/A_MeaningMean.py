def getMeanMax(L):
    L.sort()
    lastElement=L[-1]
    L=L[:len(L)-1:]

    while len(L)>1:
        L.sort()
      
        curr=(L[0]+L[1])//2
        
        L=L[2:]

        L.append(curr)
    return (L[0]+lastElement)//2
    
t=int(input())
for i in range(t):
    n=int(input())
    s=str(input()).split()

    L=[ int(i) for i in s]
    print(getMeanMax(L))