from itertools import permutations

def generate_all_permutations(s):
    unique_permutations = {''.join(p) for p in permutations(s)}
    
    return sorted(unique_permutations)

s=str(input())
perms = generate_all_permutations(s)
print(len(perms))
for i in perms:
    print(i)


