def spiral(row,col):
    if row==1 and col==1:
        return 1
    if row==col:
        return (row**2)-row+1
    
    if col==1:
        if row%2==0:
            return row**2
        else:
            return ((row-1)**2)+1
    if col==2:
        if row%2==0:
            return (row**2)-1
        else:
            return ((row-1)**2)+2
    

    if col<row:
        if row%2==0:
            return (row**2)-col+1
        else:
            return ((row-1)**2)+col
    else:
        if col%2==0:
            return ((col-1)**2)+row
        else:
            return (col**2)-row+1

t=int(input())
for i in range(t):
    s=str(input()).split()
    row=int(s[0])
    col=int(s[1])
    print(spiral(row,col))
    
