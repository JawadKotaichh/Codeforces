def sum_indices_diff(s):
    stack = []
    total_difference = 0

    for index, char in enumerate(s):
        if char == '(':
            stack.append(index)
        elif char == ')' and stack:
            open_index = stack.pop()
            total_difference += (index - open_index)

    return total_difference

def bracket(s):
    x=0
    while '_' in s:
        for j in range(x,len(s)):
            if s[j]==')':
                
                break
            
        
        
        for i in range(x,j+1):
            
            if i<j:
                if s[i]=='_' and s[i+1]==')' and s[i-1]=='(':
                    s[i]=')'
    
                elif s[i]=='_' and s[i+1]=='(' and s[i-1]=='(':
                    s[i]=')'
                    
                else:
                    s[i]='('
        x=j+1
        

    return sum_indices_diff(s)

t=int(input())
for i in range(t):
    n=int(input())
    s=str(input())
    print(bracket(list(s)))