from sys import stdin

mini = 200
maxi = 0

for line in stdin:
    line = line[:-1]
    line = line.split("~")
    a = line[0].split(',')
    b = line[1].split(',')
    for x in a:
        print(x, end =" ")
    for x in b:
        print(x, end=" ")
    print();

