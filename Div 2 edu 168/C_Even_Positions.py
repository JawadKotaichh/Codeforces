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
    stack = []
    for i in range(len(s)):
        if s[i] == '_':
            if stack and stack[-1] == '(':
                s[i] = ')'
                stack.pop()
            else:
                s[i] = '('
                stack.append(s[i])
        elif s[i] == '(':
            stack.append(s[i])
        elif s[i] == ')':
            if stack and stack[-1] == '(':
                stack.pop()
            else:
                stack.append(s[i])

    return sum_indices_diff(s)

t = int(input())
for i in range(t):
    n = int(input())
    s = list(input())
    print(bracket(s))