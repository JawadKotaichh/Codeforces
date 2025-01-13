import math
def countDivisors(x):
    num = x
    divisors_count = 1
    for i in range(2, int(math.sqrt(x)) + 1):
        exponent = 0
        while num % i == 0:
            num //= i
            exponent += 1
        divisors_count *= (exponent + 1)

    if num > 1:
        divisors_count *= 2

    return divisors_count

def Brightness(k):
    if k==1:
        return 2
    for i in range(k+1,(2*k)+1):
        if countDivisors(i)>=k+1:
            return i-1


t=int(input())
for i in range(t):
    k=int(input())
    print(Brightness(k))