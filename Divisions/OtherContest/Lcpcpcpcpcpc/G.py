def Winner(s):
    countOfm=0
    countOfy=0
    for i in range(len(s)):
        if s[i]=="m":
            countOfm+=1
        else:
            countOfy+=1

    if countOfm>countOfy:
        return "Mostafa"
    
    elif countOfy>countOfm:
        return "Yassin"
    else:
        return "Draw"

s=str(input())
print(Winner(s))