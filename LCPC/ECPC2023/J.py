s = str(input()).split()
y = int(s[0])
diff = int(s[1])
ly = y - diff
if ly < 2500 and y >= 2500:
    print("Yes")
else:
    print("No")
