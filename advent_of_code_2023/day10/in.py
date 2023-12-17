from sys import stdin

print('.'*150)
for line in stdin:
    print('.',line[:-1],'.', sep='')
print('.'*150)