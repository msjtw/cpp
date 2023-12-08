from sys import stdin

res = 1

for line in stdin:
    time = int(line.split()[0])
    record = int(line.split()[1])
    ways = 0
    for speed in range(0,time+1):
        move = speed - time
        if speed * (time-speed) > record:
            ways += 1
    res *= ways

print(res)
