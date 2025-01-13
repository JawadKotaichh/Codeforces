def slicematic(test_cases):
    results = []
    
    for case in test_cases:
        N, *angles = case
        if N == 0:
            results.append(1)
            continue
        
        unique_slices = set()
        
        for a in angles:
            normalized_angle = abs(a) % 360 
            if normalized_angle > 180:
                normalized_angle = 360 - normalized_angle 
            
            unique_slices.add(normalized_angle)
        
        num_pieces = len(unique_slices) * 2
        results.append(num_pieces)
    
    return results



T = int(input())  
test_cases = [list(map(int, input().split())) for _ in range(T)]  
result = slicematic(test_cases)


for res in result:
    print(res)
