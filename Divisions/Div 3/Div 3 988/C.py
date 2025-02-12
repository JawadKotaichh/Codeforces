def is_prime(n):
    if n <= 1:
        return False
    if n <= 3:
        return True
    if n % 2 == 0 or n % 3 == 0:
        return False
    
    i = 5
    while i * i <= n:
        if n % i == 0 or n % (i + 2) == 0:
            return False
        i += 6
    return True

def Permutation(n):
    L = [i for i in range(1, n + 1)]
    if n <= 4:
        return -1

    # List of even numbers
    evens = [i for i in range(2, n + 1, 2)]
    # List of odd numbers
    odds = [i for i in range(1, n + 1, 2)]
    
    # Remove 4 and 5 from the lists (assuming they shouldn't be in evens or odds)
    if 4 in evens: evens.remove(4)
    if 5 in odds: odds.remove(5)
    
    # Concatenate evens, then '4 5' (as a string), then odds
    result = evens + [4, 5] + odds
    return " ".join(map(str, result))

    
t=int(input())
for i in range(t):
    n=int(input())
    print(Permutation(n))

