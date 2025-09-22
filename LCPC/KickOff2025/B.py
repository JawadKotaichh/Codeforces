n = int(input())
s = str(input()).split()
answer = 0
for i in s:
    if int(i) == 1:
        answer += 1
print(answer)
