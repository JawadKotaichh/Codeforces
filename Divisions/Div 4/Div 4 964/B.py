def card(n1,n2,n3,n4):
    if n1==n2==n3==n4:
        return 0
    answer=0

    if n1>n3:
        if n2>n4:
            answer+=1
    if n1>n4:
        if n2>n3:
            answer+=1
    if n2>n3:
        if n1>n4:
            answer+=1
    if n2>n4:
        if n1>n3:
            answer+=1

    if n2>n3 and n1==n4:
        answer+=2
    if n1>n3 and n2==n4:
        answer+=2
    if n1>n4 and n2==n3:
        answer+=2
    if n2>n4 and n1==n3:
        answer+=2

    return answer
  

t=int(input())
for i in range(t):
    s=str(input()).split()
    n1=int(s[0])
    n2=int(s[1])
    n3=int(s[2])
    n4=int(s[3])
    print(card(n1,n2,n3,n4))