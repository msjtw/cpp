from sys import stdin

for line in stdin:
    print(len(line.split()), line, end= "")