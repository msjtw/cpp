from sys import stdin

pattern = []
res = 0

def diff(a,b):
    ret = 0
    for i in  range(len(a)):
        if a[i] != b[i]:
            ret += 1
    return ret
        

def check(pattern, i):
    ret = 0
    l = len(pattern)
    mini = min(i, l-i-2)
    for k in range(mini+1):
        ret += diff(pattern[i-k] ,pattern[i+1+k])
    return ret


def mirror1(pattern):
    l = len(pattern)
    for i in  range(l-1):
        if check(pattern, i) == 1:
            return i+1
    return 0
    
def mirror2(pattern):
    pattern = list(zip(*pattern[::-1]))
    l = len(pattern)
    for i in  range(l-1):
        if check(pattern, i) == 1:
            return i+1
    return 0


for line in stdin:
    line = line[:-1]
    if(len(line) == 0):
        res += mirror1(pattern)*100
        res += mirror2(pattern)
        pattern = []
        continue
    else:
        pattern.append(line)

print(res)