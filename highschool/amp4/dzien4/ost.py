import math
t = int(input())
for i in range (t):
    ar=input().split()
    a=int(ar[0])
    b=int(ar[1])
    c=int(ar[2])
    d=int(ar[3])
    harry=b*math.log(a,10)
    vold=d*math.log(c,10)
    if harry>vold:
        print("Harry Bajter")
    elif vold>harry:
        print("Lord Bajtemort")
    else:
        print("Remis")
    
