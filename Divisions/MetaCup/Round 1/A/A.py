def Sonic(n,L):
    listOfStarts=[L[i] for i in range(n*2) if i%2==0]
    ListOfEnds=[L[i] for i in range(n*2) if i%2!=0]
    minSpeed=0
    maxSpeed=2**31 - 1


    for i in range(0,n):
        if listOfStarts[i]!=0:
            maxAllowedSpeed=(i+1)/listOfStarts[i]
        else:
            maxAllowedSpeed= 2**31 - 1
        minAllowedSpeed=(i+1)/ListOfEnds[i]

        minSpeed=max(minSpeed,minAllowedSpeed)
        maxSpeed=min(maxSpeed,maxAllowedSpeed)

    if minSpeed>maxSpeed:
        return -1
    else:
        return minSpeed

def main(input_file, output_file):
    with open(input_file, 'r') as infile, open(output_file, 'w') as outfile:
        T = int(infile.readline().strip())
        
        for i in range(1, T + 1):
            N=int(infile.readline().strip())
            L=[]
            for j in range(N):
                x,y=map(int, infile.readline().strip().split())
                L.append(x)
                L.append(y)
            answer = Sonic(N, L)
            # print(f"Case #{i}: {answer:.6f} \n")
            outfile.write(f"Case #{i}: {answer:.6f}\n")

if __name__ == "__main__":
    input_file = r'C:\Users\jawad\OneDrive\Desktop\codeforces\MetaCup\Round 1\A\subsonic_subway_validation_input.txt' 
    output_file =r'C:\Users\jawad\OneDrive\Desktop\codeforces\MetaCup\Round 1\A\ProblemA_output.txt'  
    main(input_file, output_file)

