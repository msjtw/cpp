from sys import stdin

i = 0

for line in stdin:
    line = line[:-1]
    n = 0
    for char in line:
        if ord(char) > ord('!'):
            n+=1
    if n == 0:
        i+=1
    else:
        nline=''
        for char in line:
            if ord(char) > ord('!'):
                char = chr(ord(char) + i)
            nline += char
        print(nline)


