s=str(input())
max=1
count=1
curr=s[0]
for i in range(1,len(s)):
    if s[i]==curr:
        count+=1
    else:
        if count>max:
            max=count
        curr=s[i]
        count=1
if count>max:
    max=count
print(max)