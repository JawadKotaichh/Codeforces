def Delevery(n,L,G):
    D={}
    
    
    L_sorted = sorted(L, reverse=True)
    D = {i: None for i in range(1, n + 1)}
    for i, key in enumerate(D):
        D[key] = L_sorted[i]
    answer=abs(D[1]-G)
    indxanswer=1
    for key, value in D.items():
        if abs(value-G)<answer:
            answer=abs(value-G)
            indxanswer=key


    return indxanswer,answer

def main(input_file, output_file):
    with open(input_file, 'r') as infile, open(output_file, 'w') as outfile:
        T = int(infile.readline().strip())
        
        for i in range(1, T + 1):
            N, G = map(int, infile.readline().strip().split())
            L=[]
            for j in range(N):
                x=int(infile.readline().strip())
                L+=[x]
            answer = Delevery(N, L,G)
            print(f"Case #{i}: {answer[0]} {answer[1]}\n")
            outfile.write(f"Case #{i}: {answer[0]} {answer[1]}\n")

if __name__ == "__main__":
    input_file = r'C:\Users\jawad\OneDrive\Desktop\codeforces\MetaCup\D1\line_of_delivery_part_1_input.txt' 
    output_file =r'C:\Users\jawad\OneDrive\Desktop\codeforces\MetaCup\D1\output.txt'  
    main(input_file, output_file)

                

