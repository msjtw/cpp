from sys import stdin

res = 0

for line in stdin:
    time = int(line.split()[0])
    record = int(line.split()[1])
    for speed in range(0,time+1):
        move = speed - time
        if speed * (time-speed) > record:
            res += 1


print(res)
