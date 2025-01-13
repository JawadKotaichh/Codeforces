def love(s):
    count=0
    s1="codeforces"
    for i in range(10):
        if s[i]!=s1[i]:
            count+=1
    return count



t=int(input())
for i in range(t):
    s=str(input())
    print(love(s))