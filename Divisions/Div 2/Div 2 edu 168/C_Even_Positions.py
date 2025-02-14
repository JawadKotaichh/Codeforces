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

    for i in range(0,len(s),2):
        if s[i]=='_' and s[i+1]=='_':
            s[i]='('
            s[i+1]==')'
            
        elif s[i]=='_' and s[i+1]==')' and s[i-1]=='(':
            s[i]=')'

        elif s[i]=='(' and s[i+1]=='_' and s[i+2]==')':
            s[i+1]=='('
            
        elif s[i]=='(' and s[i+1]=='_':
            s[i+1]='('

        elif s[i]=='_' and s[i+1]=='_':
            s[i]=='_'

        elif s[i]=='_' and s[i+1]=='(':
            s[i]='('

        else:
            s[i]='('
            
    s=''.join(s)

    return sum_indices_diff(s)


t=int(input())
for i in range(t):
    n=int(input())
    s=str(input())
    print(bracket(list(s)))