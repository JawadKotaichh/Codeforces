def matrix_to_binary_string(matrix):
    binary_string = '\n'.join(''.join(map(str, row)) for row in matrix)
    return binary_string
def scale(n,k,L):
    if k==1:
        return matrix_to_binary_string(L)
    if n==k:
        return str(L[0][0])
    answer=[[0 for _ in range(int(n/k))] for _ in range(int(n/k))]

    for i in L:
        current=L[i][0]
        count=1
        for j in range(1,n):
            if L[i][j]==current:
                count+=1
            if count==k:
                answer[int(i/k)][int(j/k)]=current
                count=1
                if j!=n-1:
                    current=L[i][j+1]
    return matrix_to_binary_string(answer)

t=int(input())
for i in range(t):
    s1=str(input()).split()
    n=int(s1[0])
    k=int(s1[1])
    matrix = []
    for i in range(n):
        binary_string = input().strip()
        row = list(map(int, binary_string))
        matrix.append(row)
    print(scale(n,k,matrix))