"""
n: nb of monsters
i-th monster is located at (x[i],y[i])
Each monster moves toward the wizard at a speed of 1m/s
Wizard is at (0,0)
Wizard can spell and destroy monsters within a distance r
Goal: min number of times the wizard must cast this spell to destroy alll the monsters
"""

import math


def get_distance(x, y):
    return math.sqrt(x * x + y * y)


t = int(input())
while t != 0:
    s = str(input()).split()
    n = int(s[0])
    r = int(s[1])
    s1 = str(input()).split()
    s2 = str(input()).split()
    x = [int(s1[j]) for j in range(len(s1))]
    y = [int(s2[p]) for p in range(len(s2))]
    distances = set()
    for k in range(len(x)):
        current_distance = get_distance(x[k], y[k])
        distances.add(current_distance)

    list_of_set_of_distances = sorted(list(distances))
    count = 0
    min_count = 0
    # print(list_of_set_of_distances)
    for dis in list_of_set_of_distances:
        adj_distance = dis - count
        # print(f"count: {count}")
        # print(f"min_count: {min_count}")
        # print(f"adj_distance: {adj_distance}")
        if adj_distance > r:
            count += adj_distance
            min_count += 1
        else:
            if count == 0:
                min_count += 1
                count += adj_distance
    print(min_count)
    # print(list_of_set_of_distances)
    t -= 1
