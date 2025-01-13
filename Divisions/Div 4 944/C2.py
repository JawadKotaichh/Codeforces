def circle(a,b,c,d):
    dicti={0:(1,0),60:(0.5,(3**0.5)/2),30:((3**0.5)/2,0.5),90:(1,0),-270:(0,1),-30:((3**0.5)/2,-0.5),-60:(0.5,-(3**0.5)/2),-90:(0,-1),-120:(-0.5,-(3**0.5)/2),-150:(-(3**0.5)/2,-0.5),-180:(-1,0),-210:(-(3**0.5)/2,0.5),-240:(-0.5,(3**0.5)/2)}
    A=int((3-a)*30)
    B=int((3-b)*30)
    C=int((3-c)*30)
    D=int((3-d)*30)
    
    xa=dicti[A][0]
    ya=dicti[A][1]
    
    xb=dicti[B][0]
    yb=dicti[B][1]
    
    xc=dicti[C][0]
    yc=dicti[C][1]
    
    xd=dicti[D][0]
    yd=dicti[D][1]
    
    if xb-xa==0 or xc-xd==0:
        if xc-xd==0 and xb-xa!=0:
            pab=(yb-ya)/(xb-xa)
            y1=(pab*xd)+yb-(pab*xb)
            if ((y1)**2+(xd**2))**0.5<1:
                return "YES"
            else:
                return "NO"
        elif xc-xd!=0 and xb-xa==0:
            pcd=(yc-yd)/(xc-xd)
            y2=(pcd*xa)+yc-(pcd*xc)
            if ((y2)**2+(xa)**2)**0.5<1:
                return "YES"
            else:
                return "NO"
        else:
            return "NO"
        
    elif yc-yd==0 or ya-yb==0:
 
        if  yc-yd==0 and ya-yb!=0:

            pab=(yb-ya)/(xb-xa)
            x1=((pab*xb)-yb+yc)/pab
            if ((yc)**2+(x1**2))**0.5<1:
                return "YES"
            else:
                return "NO"
            
        elif yc-yd!=0 and ya-yb==0:
            pcd=(yc-yd)/(xb-xa)
            x1=((pcd*xc)-yc+ya)/pcd
            if ((ya)**2+(x1**2))**0.5<1:
                return "YES"
            else:
                return "NO"
            
        else:
            return "NO"

    else:
        pab=(yb-ya)/(xb-xa)
        pcd=(yc-yd)/(xc-xd)
        if pcd==pab:
            return "NO"
        x1=(yd-yb-(pcd*xd)+(pab*xb))/(pab-pcd)
        y1=(pcd*x1)+yd-(pcd*xd)
        r=((x1**2)+(y1**2))**0.5 
        
        if r<1:
            return "YES"
        else:
            return "NO"
        

t=int(input())       
for i in range(t):
    s=str(input())
    l=s.split()
    a=int(l[0])      
    b=int(l[1]) 
    c=int(l[2]) 
    d=int(l[3])    
    print(circle(a,b,c,d)) 
