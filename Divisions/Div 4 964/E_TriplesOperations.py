import math

def nearest_power_of_3lower(n):
    if n == 0:
        return 1
    log3_n = math.log(n,3)
    lower_power = 3 ** math.floor(log3_n)    
    return lower_power

def nearest_power_of_3upper(n):
    if n == 0:
        return 1
    log3_n = math.log(n,3)
    upper_power = 3 ** math.ceil(log3_n)
    if upper_power==n:
        upper_power=3 ** math.ceil(log3_n+1)
    return upper_power

def Triple(l,r):
    answer=0
    mini=nearest_power_of_3upper(l)
    maxi=nearest_power_of_3lower(r)
    if mini>maxi:
        answer+=math.floor(math.log(l, 3))+1
        answer+=(math.floor(math.log(l+1, 3)) + 1)+math.floor(math.log(l, 3)) + 1
        answer+=((r-l-1)*(math.ceil(math.log(l,3))+1))
    else:
        if math.log(r,3).is_integer():
            answer+=math.floor(math.log(l, 3)) + 1
            answer+=(math.floor(math.log(l+1, 3)) + 1)+math.floor(math.log(l, 3)) + 1  
            answer+=(math.floor(math.log(r, 3)) + 1)
            answer+=(math.floor(math.log(l+2, 3)) + 1)*(r-l-2)
        else:

            if l%3!=0:
                answer+=math.floor(math.log(l, 3)) + 1
            answer+=(math.floor(math.log(l+1, 3)) + 1)+math.floor(math.log(l, 3)) + 1  
            if l+2<mini:
                answer+=(mini-l-2)*(math.ceil(math.log(mini,3)))
            answer+=((r-maxi)*(math.ceil(math.log(maxi,3))+1))
            if mini!=l+1:
                answer+=(math.ceil(math.log(mini,3))+1)
            if r-maxi>1:
                answer+=(math.ceil(math.log(maxi,3))+1)
            while mini<maxi:
                nearst=nearest_power_of_3upper(mini)
                answer+=(nearst-mini-1)*(math.ceil(math.log(nearst,3)))
                mini=nearst
    return answer
# t=int(input())
# for i in range(t):
#     s=str(input()).split()
#     l=int(s[0])
#     r=int(s[1])
#     print(Triple(l,r))
## 21 18 6 263 36 5
print(Triple(1,10)) 
print(Triple(1,9))
print(Triple(2,4))
print(Triple(19,84))
print(Triple(199999,200000))
print(Triple(1,3))
