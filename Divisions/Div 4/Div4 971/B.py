def check(n,L):
    answer=[]
    x=0
    for i in range(len(L)):
        for j in range(len(L[i])):
            if L[i][j]=="#":
                answer.append(j+1)

    result = ' '.join(map(str, answer))
    return result[::-1]

t = int(input())
for _ in range(t):
    n = int(input())
    L = []
    for _ in range(n):
        s = input().strip()  
        L += [list(s)]
    print(check(n, L))
