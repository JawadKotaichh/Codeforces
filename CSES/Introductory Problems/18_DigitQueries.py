def Digit(k):
    digitCount=None
    D={}
    curr1=1
    end1=9
    for i in range(0,18):
        

        D[i+1]=(curr1,end1)
        begin1=1*(10**i)
        end1=(10**(i+1))-1
        curr1+=(i+1)*(end1-begin1+1)
        begin2=1*(10**(i+1))
        end2=(10**(i+2))-1
        end1=curr1+((i+2)*(end2-begin2+1))

    for key,value in D.items():
        if value[0]<=k and value[1]>=k:
            digitCount=key

    firstNumberOfRange=(10**(digitCount-1))
    firstIndexInRange=D[digitCount][0]
    additionalNumbers=((k-(firstIndexInRange))//digitCount)

    currNumber=firstNumberOfRange+additionalNumbers

    stringOfCurrNumber=str(currNumber)
    firstIndxInCurrNumber= firstIndexInRange+((additionalNumbers*digitCount))

    return stringOfCurrNumber[k-firstIndxInCurrNumber]
t=int(input())
for i in range(t):
    k=int(input())
    print(Digit(k))