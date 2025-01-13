# There is n costumers
# we have a list containg the arrival and leave time for each one of them
# we need to return the maximum number of costumers at the same time

# L=[5,8,2,4,3,9]
# sorted L=[2,4,3,9,5,8]

# 2--->4
# 3--->9
# 5--->8
# listOfStart=[2,3,5]
# listOfEnd=[5,9,8]

# first Start----> last end
# 2---3--4-5--8---9
def getMaxCustomers(times):
    events = []
    
    # Split the start and end times into events
    for start, end in times:
        events.append((start, 1))  # Arrival event
        events.append((end, -1))  # Departure event
    
    # Sort events: prioritize by time, then by type (-1 before 1 for ties)
    events.sort(key=lambda x: (x[0], x[1]))
    
    max_customers = 0
    current_customers = 0
    
    # Process events
    for time, event_type in events:
        current_customers += event_type
        max_customers = max(max_customers, current_customers)
    
    return max_customers
# def getMaxCostumers(listOfStart,listOfEnd):

#     pointerStart=1
#     lastStart=listOfStart[0]
#     lastEnd=D[lastStart]
#     count=1
#     maxCount=1

#     while pointerStart<len(listOfStart)-1:
#         if listOfStart[pointerStart]>=lastStart and listOfStart[pointerStart]<=lastEnd:
#             lastEnd=min(lastEnd,D[listOfStart[pointerStart]])
#             lastStart=max(lastStart,listOfStart[pointerStart])
#             count+=1
#             pointerStart+=1
#         else:
#             if count>maxCount:
#                 maxCount=count
#             count=1

#             lastStart=listOfStart[pointerStart]
#             pointerStart+=1
#             lastEnd=listOfEnd[lastStart]
#     if listOfStart[-1]>=lastStart and listOfStart[-1]<=lastEnd:
#         count+=1
#     if count>maxCount:
#                 maxCount=count
#     return maxCount

def getMaxCostumers(listOfStart, listOfEnd):
    pointerStart = 0
    lastStart = listOfStart[0]
    lastEnd = listOfEnd[lastStart]
    count = 1
    maxCount = 1

    while pointerStart < len(listOfStart) - 1:
        pointerStart += 1  # Move the pointer to the next customer
        currentStart = listOfStart[pointerStart]

        # Check if the current customer's start is within the last interval
        if currentStart >= lastStart and currentStart <= lastEnd:
            lastEnd = min(lastEnd, listOfEnd[currentStart])  # Update the end of the interval
            lastStart = max(lastStart, currentStart)  # Update the start of the interval
            count += 1
        else:
            # If outside the current interval, update maxCount and reset count
            maxCount = max(maxCount, count)
            count = 1
            lastStart = currentStart
            lastEnd = listOfEnd[currentStart]

    # Final check for the last interval
    maxCount = max(maxCount, count)
    return maxCount


t=int(input())
D={}
listOfstart=[]
for j in range(t):
    start,end=map(int,input().split())
    listOfstart.append(start)
    D[start]=end
listOfstart.sort()
print(getMaxCostumers(listOfstart,D))
