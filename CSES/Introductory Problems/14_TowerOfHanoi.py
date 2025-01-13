def mini(n):
    if n==2:
        return 3
    else:

        return 2*mini(n-1)+1

def tower_of_hanoi(n, source='1', destination='3', auxiliary='2'):
    if n == 1:
        return [(source, destination)]
    
    moves = []
    moves += tower_of_hanoi(n - 1, source, auxiliary, destination)
    moves.append((source, destination))
    moves += tower_of_hanoi(n - 1, auxiliary, destination, source)
    return moves
n=int(input())
if n==1:
    print(1)
    print("1" + " " +"3")
else:
        
    print(mini(n))
    moves = tower_of_hanoi(n)
    for move in moves:
        print(move[0]+" " + move[1]) 
