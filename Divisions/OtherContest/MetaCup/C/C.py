import random
def are_collinear(x1, y1, x2, y2, x3, y3):
    area = x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)
    
    if area == 0:
        return True
    else:
        return False

def line(n,L):
    count=50
    while count>0:
        count-=1
        randomElements=random.sample(L,2)
        x1=randomElements[0][0]
        y1=randomElements[0][1]
        x2=randomElements[1][0]
        y2=randomElements[1][1]

        points=2

        for j in range(n):
            if L[j] not in randomElements:
                x=L[j][0]
                y=L[j][1]

                if are_collinear(x1,y1,x2,y2,x,y):
                    points+=1

        if points>=n/2:
            return n-points
    return n

def main(input_file, output_file):
    with open(input_file, 'r') as infile, open(output_file, 'w') as outfile:
        T = int(infile.readline().strip())
        
        for i in range(1, T + 1):

            n=int(infile.readline().strip())
            L=[]
            for j in range(n):
                xi,yi=map(int,infile.readline().strip().split())
                L+=[[xi,yi]]
            
            answer = line(n,L)
            print(f"Case #{i}: {answer}\n")
            outfile.write(f"Case #{i}: {answer}\n")

if __name__ == "__main__":
    input_file = r'C:\Users\jawad\OneDrive\Desktop\codeforces\MetaCup\C\fall_in_line_input.txt' 
    output_file =r'C:\Users\jawad\OneDrive\Desktop\codeforces\MetaCup\C\output.txt'  
    main(input_file, output_file)
