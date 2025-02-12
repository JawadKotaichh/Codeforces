def min_doors_to_lock(t, test_cases):
    results = []
    for case in test_cases:
        l, r, L, R = case
        if r < L:
            results.append(L - r)
        elif R < l:
            results.append(l - R)
        else:
            # Segments overlap, lock all doors in the smaller segment
            overlap_length = min(r - l + 1, R - L + 1)
            results.append(overlap_length)
    return results

# Read input
t = int(input())
test_cases = []
for _ in range(t):
    l, r = map(int, input().split())
    L, R = map(int, input().split())
    test_cases.append((l, r, L, R))

# Get results
results = min_doors_to_lock(t, test_cases)

# Print results
for result in results:
    print(result)
