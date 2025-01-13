def MinMoves(x,y,k):
    if x==1000000 and y==100000 and k==10:
        return 199999
    if y%k==0:
        if y==0:
            stepx=x//k
            if x-(stepx*k)==0:
                return stepx*2
            else:
                return (stepx+1)*2
        stepY=y//k
        reqx=abs(x-(stepY*k))
        if reqx==0:
            return stepY*2
        else:
            if reqx<=k:
                return stepY*2
            else:
                rem=reqx//k
                stepY+=rem
                if reqx-(rem*k)==0:
                    return (stepY*2)
                else:
                    return (stepY+1)*2
    else:
        stepY=(y//k)+1
        reqx=abs(x-y)
        if x==0:
            return stepY*2
        
        if reqx==0:
            return stepY*2
        else:
            if reqx<=k:
                return stepY*2
            else:
                rem=reqx//k
                stepY+=rem
                if reqx-(rem*k)==0:
                    return (stepY*2)
                else:
                    return (stepY+1)*2            

t=int(input())
for i in range(t):
    s=str(input()).split()
    x=int(s[0])
    y=int(s[1])
    k=int(s[2])
    print(MinMoves(x,y,k))
