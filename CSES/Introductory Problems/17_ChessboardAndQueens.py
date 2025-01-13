def is_safe(board, row, col, n):
    # Check the column
    for i in range(row):
        if board[i][col] == 'Q':
            return False
    
    # Check the main diagonal (top-left to bottom-right)
    for i, j in zip(range(row, -1, -1), range(col, -1, -1)):
        if board[i][j] == 'Q':
            return False
    
    # Check the anti-diagonal (top-right to bottom-left)
    for i, j in zip(range(row, -1, -1), range(col, n)):
        if board[i][j] == 'Q':
            return False
    
    return True

def count_queens(board, row, n):
    if row >= n:
        return 1  # A valid arrangement is found
    
    count = 0
    for col in range(n):
        if board[row][col] == '.' and is_safe(board, row, col, n):
            # Place the queen
            board[row][col] = 'Q'
            
            # Recur to place the next queen and count solutions
            count += count_queens(board, row + 1, n)
            
            # Backtrack
            board[row][col] = '.'
    
    return count

# Input and execution
board = []
for _ in range(8):
    board.append(list(input().strip()))

n = 8
total_solutions = count_queens(board, 0, n)
print(total_solutions)
