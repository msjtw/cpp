from sys import stdin

arr = []
res = 0

def Reverse(tup):
    new_tup = tup[::-1]
    return new_tup

for line in stdin:
    line = line[:-1]
    arr.append(line)

arr = list(zip(*arr[::-1]))

for i in range(len(arr)):
    arr[i] = Reverse(arr[i])

for line in arr:
    l = len(line)
    l2 = l
    for c in line:
        if c == 'O':
            res += l
            l-=1
        elif c == '#':
            l = l2-1
        l2 -= 1

print(res)