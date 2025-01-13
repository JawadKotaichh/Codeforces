def count_set_bits(n):
    return bin(n).count('1')

n=int(input())
s=str(input()).split()
L=[int(i) for i in s]
ListOfBinGiven=[count_set_bits(j) for j in L]
sortedList=L
sortedList.sort()
ListOfSortedBin=[count_set_bits(i) for i in sortedList]
if ListOfBinGiven==ListOfSortedBin:
    print("Yes") 
else:
    print("No")

