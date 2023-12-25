from sys import stdin

for line in stdin:
    line = line[:-1]
    x = line.split(' -> ')
    module = x[0]
    con = x[1].split(', ')
    print(module, end=' ')
    print(len(con), end=' ')
    for c in con:
        print(c, end = ' ')
    print()