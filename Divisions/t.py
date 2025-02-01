import math
a = float(input("Enter a (nonzero): "))
b = float(input("Enter b: "))
c = float(input("Enter c: "))
delta = (b**2) - (4*a*c)
if abs(delta) <1E-9:
    z = -b/(2*a)
    print("The equation has one root:", z)
elif delta < 0:
    print("The equation has no roots")
else :
    x= (-b + (math.sqrt(delta)))/ (2*a)
    w = (-b - (math.sqrt(delta)))/ (2*a)
    print("The equation has two roots:", x , "and", w)