def clock(a,b,c,d):
    anglea=int((a-1)*360/12)
    angleb=int((b-1)*360/12)
    anglec=int((c-1)*360/12)
    angled=int((d-1)*360/12)
    if min(anglea,angleb)<anglec<max(anglea,angleb) or min(anglea,angleb)<angled<max(anglea,angleb):
        return "YES"
    else:
        return "NO"










    # if (d-c)*(a-c)<0 and (d-c)*(b-c)<0:
    #     return "YES"
    # else:
    #     return "NO"
t=int(input())
for i in range(t):
    s=str(input())
    l=s.split()
    a=int(l[0])
    b=int(l[1])
    c=int(l[2])
    d=int(l[3])
    print(clock(a,b,c,d))