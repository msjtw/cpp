from sys import stdin

for line in stdin:
    line = line[:-1]
    line = line.split()
    for val in line:
        print(val,',',  sep='', end='')
    print()