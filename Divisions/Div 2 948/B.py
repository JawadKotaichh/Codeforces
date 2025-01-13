import math
def list_to_string_with_spaces(int_list):
    return ' '.join(map(str, int_list))
def nearest_power_of_2lower(n):
    if n == 0:
        return 1
    
    log2_n = math.log2(n)
    

    lower_power = 2 ** math.floor(log2_n)
    upper_power = 2 ** math.ceil(log2_n)
    
    return lower_power
def nearest_power_of_2upper(n):
    if n == 0:
        return 1

    log2_n = math.log2(n)
    lower_power = 2 ** math.floor(log2_n)
    upper_power = 2 ** math.ceil(log2_n)
    return upper_power
def nearest_power_of_2(n):
    if n == 0:
        return 1
    log2_n = math.log2(n)  
    lower_power = 2 ** math.floor(log2_n)
    upper_power = 2 ** math.ceil(log2_n)
    if abs(lower_power - n) < abs(upper_power - n):
        return lower_power
    else:
        return upper_power
def BinaryColouring(n):
    nearest=nearest_power_of_2(n)
    if nearest>n:
        rem=n-nearest
        lenght=int(math.log2(nearest))
        L=[0 for i in range(lenght+1)]
        L[lenght]=1
        while rem<-1:
            negnear=nearest_power_of_2lower(-rem)
            rem=negnear+rem
            L[int(math.log2(negnear))]=-1
        
        if rem==0:
            print(lenght+1)
            return list_to_string_with_spaces(L)

        else:
            L[0]=-1
            print(lenght+1)
            return list_to_string_with_spaces(L)
    else:
        rem=n-nearest
        lenght=int(math.log2(nearest))
        L=[0 for i in range(lenght+1)]
        L[lenght]=1
        while rem>0:
            negnear=nearest_power_of_2upper(rem)
            rem=rem-negnear
            if L[int(math.log2(negnear))+1]!=1:
                
                L[int(math.log2(negnear))]=1
            else:
                L[lenght]=0
                lenght+=1
                L.append(1)
                L[int(math.log2(negnear))]=-1

        if rem==0:
            print(lenght+1)
            return list_to_string_with_spaces(L)
        else:
            L[0]=-1
            print(lenght+1)
            return list_to_string_with_spaces(L)

t=int(input())
for i in range(t):
    n=int(input())
    print(BinaryColouring(n))