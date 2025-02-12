x=int(input())
sum=0
while x>0:
    y=x%10
    if y%2==0:
        sum+=y
    x=x//10
print(sum)
