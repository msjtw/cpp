from sys import stdin

for line in stdin:
    row = line.split()[0]
    groups = line.split()[1].split(',')
    print(row, end=' ')
    print(len(groups), end= ' ')
    for group in groups:
        print(group, end=' ')
    print()