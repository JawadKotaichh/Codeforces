def sort_dict_by_values(my_dict):
    sorted_dict = dict(sorted(my_dict.items(), key=lambda item: (item[1] % 2 != 0, item[1])))
    return sorted_dict
def palindrome(s):
    if s==s[-1::-1]:
        return s
    else:
        d={}
        for i in range(len(s)):
            if s[i] not in d:
                d[s[i]]=1
            else:
                d[s[i]]+=1
        s=""
        count=0
        d=sort_dict_by_values(d)
        for i in d:
            if d[i]%2==0 and s=="":
                s+=i*d[i]
                count=int(d[i]/2)
            else:
                if d[i]%2==0:
                    s=s[:count]+i*d[i]+s[count:]
                    count+=int(d[i]/2)
                else:
                    if i==list(d.keys())[-1]:
                        s=s[:count]+i*d[i]+s[count:]
                        break
                    else:
                        return "NO SOLUTION"
    return s
s=str(input())
print(palindrome(s))
