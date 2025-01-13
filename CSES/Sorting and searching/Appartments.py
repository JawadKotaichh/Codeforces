def find_apartment_matches(n, m, k, ListOfPeople, ListOfApp):
    ListOfPeople.sort()
    ListOfApp.sort()

    count = 0
    i = 0  
    j = 0  

    while i < n and j < m:
        if ListOfPeople[i] - k <= ListOfApp[j] <= ListOfPeople[i] + k:
            count += 1  
            i += 1      
            j += 1      
        elif ListOfApp[j] < ListOfPeople[i] - k:
            j += 1
        else:
            i += 1

    return count

n, m, k = map(int, input().split())
ListOfPeople = list(map(int, input().split()))
ListOfApp = list(map(int, input().split()))

print(find_apartment_matches(n, m, k, ListOfPeople, ListOfApp))
