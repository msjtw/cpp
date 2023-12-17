from sys import stdin

for line in stdin:
    row = line.split()[0]
    groups = line.split()[1].split(',')
    print(row, groups)
    for i in range(len(row)):
        break