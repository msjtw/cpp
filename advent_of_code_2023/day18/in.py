from sys import stdin

maxi = 0;

height = 0
width = 0

for line in stdin:
    line = line.split()
    if(line[0] == "R"):
        width += int(line[1])
    if(line[0] == "L"):
        width -= int(line[1])
    if(line[0] == "U"):
        height += int(line[1])
    if(line[0] == "D"):
        height -= int(line[1])
    maxi = max(maxi, abs(height), abs(width))

print(maxi)
