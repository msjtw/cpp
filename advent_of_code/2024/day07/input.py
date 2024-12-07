import sys

for line in sys.stdin:
    num = line.split(" ")
    num = len(num)
    print(str(num-1) + " " + line, end="")

