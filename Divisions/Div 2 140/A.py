def Screen(s1,s2):
    common=0
    i=0
    j=0
    while(i<len(s1) and j<len(s2)):
        if s1[i]==s2[j]:
            common+=1
        else:
            break
        i+=1
        j+=1
    return min(len(s1)+len(s2),len(s1)+len(s2)-common+1)

t=int(input())
for i in range(t):
    s1=str(input())
    s2=str(input())
    print(Screen(s1,s2))