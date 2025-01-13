def generate_gray_code(n):
    if n == 0:
        return ["0"]
    elif n == 1:
        return ["0", "1"]
    else:
        prev_gray_code = generate_gray_code(n - 1)
        first_half = ["0" + code for code in prev_gray_code]
        second_half = ["1" + code for code in reversed(prev_gray_code)]
    return first_half+second_half

    
n=int(input())
L=generate_gray_code(n)
for i in range(len(L)):
    print(L[i])
