def can_sort_with_one_swap(N, A):
    # Find the indices where the array is out of order
    out_of_order = []
    for i in range(N - 1):
        if A[i] > A[i + 1]:
            out_of_order.append(i)
            out_of_order.append(i + 1)
    
    # Remove duplicates and sort the indices
    out_of_order = sorted(set(out_of_order))
    
    # If there are no out-of-order elements, the array is already sorted
    if not out_of_order:
        return "Jamhoor"
    
    # If there are more than 2 out-of-order elements, it cannot be sorted with one swap
    if len(out_of_order) > 2:
        return "Farhat"
    
    # Try swapping the two out-of-order elements
    i, j = out_of_order[0], out_of_order[1]
    A[i], A[j] = A[j], A[i]
    
    # Check if the array is sorted after the swap
    if all(A[k] <= A[k + 1] for k in range(N - 1)):
        return "Jamhoor"
    else:
        return "Farhat"

# Example usage:
N = int(input())
A = list(map(int, input().split()))
print(can_sort_with_one_swap(N, A))
