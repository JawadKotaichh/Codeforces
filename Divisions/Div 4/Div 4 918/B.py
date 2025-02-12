def Latin(L1,L2,L3):
    x=""
    if '?' in L1:
         x=L1
    elif '?' in L2:
         x=L2
    else:
         x=L3

    if 'A' in x and 'C' in x:
            return 'B'
    elif 'A' in x and 'B' in x:
            return 'C'
    else:
          return 'A'



t =int(input())
for i in range(t):
    L1=str(input())
    L2=str(input())
    L3=str(input())
    
    print(Latin(L1,L2,L3))