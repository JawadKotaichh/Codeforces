def walk(n,L,k):
    mini=min(L)
    if n==1:
        if L[0]<=k:
            return "YES"
        else:
            return "NO"
        
    time=mini*((2*n)-3)
    if time<=k:
        return "YES"
    else:
        return "NO"

def main(input_file, output_file):
    with open(input_file, 'r') as infile, open(output_file, 'w') as outfile:
        T = int(infile.readline().strip())
        
        for i in range(1, T + 1):
            n,k=map(int, infile.readline().strip().split())
            L=[]
            L = [int(infile.readline().strip()) for _ in range(n)]
            
            answer = walk(n,L,k)
            
            outfile.write(f"Case #{i}: {answer}\n")

if __name__ == "__main__":
    input_file = r'C:\Users\jawad\OneDrive\Desktop\codeforces\MetaCup\A\walk_the_line_input.txt' 
    output_file =r'C:\Users\jawad\OneDrive\Desktop\codeforces\MetaCup\A\output.txt'  
    main(input_file, output_file)



















# def walk(n,L,k):NO
#     if len(L)==1:
#         if L[0]<=k:
#             return "YES"
#         else:
#             return "NO"
#     curr=0
#     L.sort()
#     if sum(L[:len(L)-1:])<=k:
#         return "YES"
#     else:
#         return "NO"

    
# def main(input_file, output_file):
#     with open(input_file, 'r') as infile, open(output_file, 'w') as outfile:
#         T = int(infile.readline().strip())
        
#         for i in range(1, T + 1):
#             n,k=map(int, infile.readline().strip().split())
#             L=[]
#             L = [int(infile.readline().strip()) for _ in range(n)]
            
#             answer = walk(n,L,k)
            
#             outfile.write(f"Case #{i}: {answer}\n")

# if __name__ == "__main__":
#     input_file = r'C:\Users\jawad\OneDrive\Desktop\codeforces\MetaCup\A\walk_the_line_input.txt' 
#     output_file =r'C:\Users\jawad\OneDrive\Desktop\codeforces\MetaCup\A\output.txt'  
#     main(input_file, output_file)

