import heapq

def Karl(numberOfModels, x, numOfCarsPerModel):
    max_heap = [-cars for cars in numOfCarsPerModel]
    heapq.heapify(max_heap)
    
    minPeople = 0
    while max_heap:
        if len(max_heap) >= x:
            largest_x = [-heapq.heappop(max_heap) for _ in range(x)]
            min_value = largest_x[-1]
            minPeople += min_value
            
            for elem in largest_x:
                remaining = elem - min_value
                if remaining > 0:
                    heapq.heappush(max_heap, -remaining)
        else:
            min_value = -heapq.heappop(max_heap)
            minPeople += min_value
            break  

    return minPeople


t = int(input())
for _ in range(t):
    numberOfModels, x = map(int, input().split())
    numOfCarsPerModel = list(map(int, input().split()))
    print(Karl(numberOfModels, x, numOfCarsPerModel))
