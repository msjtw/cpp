from sys import stdin

print("."*142)

for line in stdin:
    print(".", line[:-1], ".", sep="")

print("."*142)