proc = True

while True:
    inp = input()
    if(inp == ""):
        proc = False
        print()
        continue
    if(proc):
        inp = inp.split("{")
        line = inp[1][:-1]
        line = line.split(',')
        print(inp[0], len(line), end = " ")
        for rule in line:
            print(rule, end=' ')
        print()
    else:
        line = inp[1:-1]
        line = line.split(',')
        for a in line:
            print(a[2:], end=" ")
        print()