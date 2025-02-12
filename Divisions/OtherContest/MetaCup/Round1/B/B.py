def minimum_speed(N, delivery_windows):
    min_speed = 0  # Start with the lowest possible speed
    max_speed = float('inf')  # Start with no upper limit

    for i in range(N):
        A_i = delivery_windows[2 * i]     # Extract Ai
        B_i = delivery_windows[2 * i + 1] # Extract Bi

        # Calculate the min speed (i+1 / B[i])
        min_allowed_speed = (i + 1) / B_i  # Minimum speed to arrive in time
        
        # Handle A[i] = 0 to avoid division by zero
        if A_i == 0:
            max_allowed_speed = float('inf')  # No upper limit if A[i] = 0
        else:
            max_allowed_speed = (i + 1) / A_i
        
        # Update the max of the minimum speeds
        min_speed = max(min_speed, min_allowed_speed)

        # Check if the calculated min_speed exceeds max_allowed_speed
        if min_speed > max_allowed_speed:
            return -1  # Invalid speed, return -1
      

    return min_speed  # Return the minimum speed that satisfies all conditions



N = 4
L=[0,3,1,4,1,2,0,10]

result = minimum_speed(N,L)
print(result)

N = 2
L=[1,2,4,10]

result = minimum_speed(N,L)
print(result)

N = 2
L=[5,10,0,5]
result = minimum_speed(N,L)
print(result)



# print(Sonic(2,[1,2,4,10]))
# print(Sonic(2,[5,10,0,5]))