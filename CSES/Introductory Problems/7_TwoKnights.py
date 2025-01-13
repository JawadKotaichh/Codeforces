n=int(input())
for i in range(1,n+1):
    if i==1:
        print(0)
    elif i==2:
        print(6)
    else:
        answer=((i**2)*((i**2)-1))/2
        answer-=4*(i-1)*(i-2)
        print(int(answer))