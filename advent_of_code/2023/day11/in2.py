from sys import stdin

for line in stdin:
    for char in line:
        if char == '.':
            print('!',sep='',end='')
        else:
            print(char, end='')
