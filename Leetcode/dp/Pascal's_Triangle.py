numRows = 5
matrix = []
j = 1
for i in range(numRows):
    matrix.append([1] * j)
    j += 1
for k in range(2, numRows):
    for x in range(1, len(matrix[k]) - 1):
        matrix[k][x] = matrix[k - 1][x - 1] + matrix[k - 1][x]
print(matrix)
