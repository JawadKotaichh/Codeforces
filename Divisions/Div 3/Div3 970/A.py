def skarouku(num1,num2):
    if num2%2==0 and num1%2==0:
        return "Yes"
    elif num2%2!=0 or num1%2!=0:
        num2=num2%2
        if num2*2==num1:
            return "YES"
        else:
            return "No"
    else:
        return "No"
t=int(input())
for i in range(t):
    s=str(input()).split()
    num1=int(s[0])
    num2=int(s[1])
    print(skarouku(num1,num2))
    