from collections import deque, defaultdict

def topological_sort(n, adj):
    # Kahn's algorithm for topological sort
    in_degree = [0] * n
    for u in range(n):
        for v in adj[u]:
            in_degree[v] += 1
    
    queue = deque([i for i in range(n) if in_degree[i] == 0])
    topo_sort = []
    
    while queue:
        node = queue.popleft()
        topo_sort.append(node)
        
        for neighbor in adj[node]:
            in_degree[neighbor] -= 1
            if in_degree[neighbor] == 0:
                queue.append(neighbor)
    
    return topo_sort

def solve():
    t = int(input())  # number of test cases
    
    for _ in range(t):
        n = int(input())  # number of vertices
        adj = defaultdict(list)
        
        # Read the adjacency matrix
        matrix = [input().strip() for _ in range(n)]
        
        # Build the directed graph based on the adjacency matrix
        for i in range(n):
            for j in range(n):
                if matrix[i][j] == '1' and i < j:
                    adj[i].append(j)  # i < j, so i -> j
        
        # Get the topological order of vertices
        topo_sort = topological_sort(n, adj)
        
        # Convert 0-indexed to 1-indexed for the result
        result = [i + 1 for i in topo_sort]
        print(" ".join(map(str, result)))

# Call the solve function to read input and output results
solve()
