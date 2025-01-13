def getAllPath(r, c, grid, path_len,currCharacter,givenPath):
    
    if path_len!=0 and givenPath[path_len-1]!=currCharacter and givenPath[path_len-1]!="?":
        return 0
    
    if r < 0 or c < 0 or r >= len(grid) or c >= len(grid[0]):
      return 0

    if grid[r][c] == 1:
      return 0

    if r == len(grid) - 1 and c == 0:
      if path_len == len(grid) * len(grid[0]) - 1:
        return 1
      return 0


    grid[r][c] = 1

    # if you reach a T shape, then you can't complete the path
    if ((r == 0 or grid[r - 1][c] == 1)
        and (r == len(grid) - 1 or grid[r + 1][c] == 1)
        and (c > 0 and grid[r][c - 1] == 0)
        and (c < len(grid[0]) - 1 and grid[r][c + 1] == 0)):
        
        grid[r][c] = 0
        return 0

    if ((r > 0 and grid[r - 1][c] == 0)
        and (r < len(grid) - 1 and grid[r + 1][c] == 0)
        and (c == 0 or grid[r][c - 1] == 1)
        and (c == len(grid[0]) - 1 or grid[r][c + 1] == 1)):
        
        grid[r][c] = 0
        return 0

     
    result = 0
    result += getAllPath(r + 1, c, grid, path_len + 1,"D",givenPath)
    result += getAllPath(r, c + 1, grid, path_len + 1,"R",givenPath)
    result += getAllPath(r - 1, c, grid, path_len + 1,"U",givenPath)
    result += getAllPath(r, c - 1, grid, path_len + 1,"L",givenPath)


    grid[r][c] = 0
    
    return result

n = 7

grid = [[0] * n for _ in range(n)]
currPath=""

import time
start_time = time.time()

givenPath=str(input())
result = getAllPath(0, 0, grid, 0,currPath,givenPath)
end_time = time.time()
print("Total time:", end_time - start_time)
print(result)

