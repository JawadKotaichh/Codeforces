def region(s1,s2):
    answer=0
    for i in range(len(s1)):
        if i<len(s1)-2:
            if (s1[i]=='x' and s1[i+1]=='.' and s1[i+2]=='x' and s2[i]=='.'  and s2[i+1]=='.'  and s2[i+2]=='.') or(s2[i]=='x' and s2[i+1]=='.' and s2[i+2]=='x' and s1[i]=='.'  and s1[i+1]=='.'  and s1[i+2]=='.'):
                answer+=1
    return answer






t=int(input())
for i in range(t):
    n=int(input())
    s1=str(input())
    s2=str(input())
    print(region(s1,s2))