from sys import stdin

res = 0

for line in stdin:
    winning = line.split(": ")[1].split(" | ")[0].split()
    winning = [eval(i) for i in winning]
    card = line.split(": ")[1].split(" | ")[1].split()
    card = [eval(i) for i in card]
    p = 0
    for num in card:
        if winning.count(num) > 0:
            p += 1
    print(p-1)
    if(p > 0):
        res += 2**(p-1)

print(res)