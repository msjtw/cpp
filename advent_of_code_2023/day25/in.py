from sys import stdin

for line in stdin:
    line = line[:-1]
    line = line.split()
    print(line[0][:-1], end= " ")
    line  = line[1:]
    print(len(line), end = " ")
    for adj in line:
        print(adj, end=" ")
    print()