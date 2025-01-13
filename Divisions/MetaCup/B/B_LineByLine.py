def line(n,p):
    return (((p/100)**((n-1)/n))-(p/100))*100

def main(input_file, output_file):
    with open(input_file, 'r') as infile, open(output_file, 'w') as outfile:
        T = int(infile.readline().strip())
        
        for i in range(1, T + 1):
            N, P = map(int, infile.readline().strip().split())
            
            increase = line(N, P)
            
            outfile.write(f"Case #{i}: {increase:.6f}\n")

if __name__ == "__main__":
    input_file = r'C:\Users\jawad\OneDrive\Desktop\codeforces\MetaCup\B\input.txt' 
    output_file =r'C:\Users\jawad\OneDrive\Desktop\codeforces\MetaCup\B\output.txt'  
    main(input_file, output_file)
