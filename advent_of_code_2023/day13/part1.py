from sys import stdin

pattern = []
res = 0

def check(pattern, i):
    l = len(pattern)
    mini = min(i, l-i-2)
    for k in range(mini+1):
        if(pattern[i-k] != pattern[i+1+k]):
            return False
    return True


def mirror1(pattern):
    l = len(pattern)
    for i in  range(l-1):
        if(pattern[i] == pattern[i+1]):
            if check(pattern, i):
                return i+1
    return 0
    
def mirror2(pattern):
    pattern = list(zip(*pattern[::-1]))
    l = len(pattern)
    for i in  range(l-1):
        if(pattern[i] == pattern[i+1]):
            if check(pattern, i):
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