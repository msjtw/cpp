proc = True

while True:
    inp = input()
    if(inp == ""):
        proc = False
        print()
        continue
    if(proc):
        inp.split("{")
        # print(inp[0], end=" ")
        print(inp)
        line = inp[1][:-1]
        line.split(',')
        for rule in line:
            print(rule, end=' ')
        print()
    else:
        line = inp[1:-1]
        line.split(',')
        for a in line:
            print(a, end=" ")
        print()