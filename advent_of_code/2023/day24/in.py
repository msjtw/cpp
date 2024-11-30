from sys import stdin

for line in stdin:
    line = line[:-1]
    poz = line.split(" @ ")[0]
    vel = line.split(" @ ")[1]
    poz = poz.split(", ")
    vel = vel.split(", ")
    for a in poz:
        print(a, end=" ")
    for a in vel:
        print(a, end=" ")
    print()