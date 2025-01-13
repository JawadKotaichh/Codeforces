def update_list(L, x):
    sublist = L[-x:]
    min_value = min(sublist)
    
    new_sublist = [elem - min_value for elem in sublist]
    updated_sublist = [elem for elem in new_sublist if elem > 0]
    updated_list = L[:-x] + updated_sublist
    return updated_list

def Karl(numberOfModels,x,numOfCarsPerModel):
    minPeople=0
    while len(numOfCarsPerModel)>0:
        numOfCarsPerModel.sort()
        if len(numOfCarsPerModel)>=x:

            minPeople+=numOfCarsPerModel[-x]
            numOfCarsPerModel=update_list(numOfCarsPerModel,x)
        else:
            minPeople+=numOfCarsPerModel[0]
            numOfCarsPerModel=update_list(numOfCarsPerModel,len(numOfCarsPerModel))

    return minPeople
t=int(input())
for i in range(t):
    numberOfModels,x=map(int,input().split())
    s=str(input()).split()
    L=[int(i) for i in s]
    print(Karl(numberOfModels,x,L))