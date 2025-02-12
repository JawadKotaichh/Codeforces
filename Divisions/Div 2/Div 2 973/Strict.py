import bisect

def find_bounds(lst, value):
    # Sort the list
    sorted_lst = sorted(lst)
    
    pos = bisect.bisect_left(sorted_lst, value)
    
    lower_bound = sorted_lst[pos - 1] if pos > 0 else None
    
    upper_bound = sorted_lst[pos] if pos < len(sorted_lst) else None
    
    return (lower_bound, upper_bound)

def strict(numberOfCells,numberOfTecherslistOfT,listOfPos,David):
    if David>=0 and David<min(listOfPos):
        return min(listOfPos)-1
    
    elif David>max(listOfPos):
        return David-max(listOfPos)+(numberOfCells-David)
    
    else:
        p=find_bounds(listOfPos,David)
        lower=p[0]
        upper=p[1]
        return min(David-lower,upper-David)


t=int(input())
for i in range(t):
    n,m,q=map(int,input().split())
    a=str(input()).split()
    listOfPos=[int(i) for i in a]
    David=int(input())
    print(strict(n,m,listOfPos,David))