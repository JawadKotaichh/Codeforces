# def Major(n,k):
#     leaves=0
#     for i in range(1,n+1):
#         if i+k-1>=n:
#             leaves+=i**i
#     if leaves%2==0:
#         return "YES"
#     else:
#         return "NO"



# t=int(input())
# for i in range(t):
#     s=str(input()).split()
#     n=int(s[0])
#     k=int(s[1])
#     print(Major(n,k))

def Major(n, k):
    if k == 1:
        # If k == 1, simply check if n is even
        return "YES" if n % 2 == 0 else "NO"
    else:
        styear = n - k + 1
        endyear = n
        total_leaves = (endyear - styear + 1) * (styear + endyear) // 2
        
        if total_leaves % 2 == 0:
            return "YES"
        else:
            return "NO"

t = int(input()) 
for _ in range(t):
    n, k = map(int, input().split()) 
    print(Major(n, k))

