from sys import stdin

verx = []

x = 0
y = 0

mini = 0
paramier = 0

for line in stdin:
    a = line.split()[2]
    dist = int(a[2:7], 16)
    paramier += dist
    d = int(a[7])
    if d == 0:
        # R
        x += dist    
    elif d == 1:
        # D
        y -= dist
    elif d == 2:
        # L
        x -= dist
    elif d == 3:
        # U
        y += dist
    mini = min(mini, x, y)
    verx.append((x,y))
# verx.append(verx[1])

print(mini)

mini = abs(mini)

# for i in range(len(verx)):
#     verx[i] = (verx[i][0] + mini, verx[i][1] + mini)

res = 0
res2 = 0


for ver in verx:
    print(ver)

for i in range(len(verx)-1):
    res += verx[i][0] * (verx[i+1][1] - verx[i-1][1])
    res2 += verx[i][1] * (verx[i-1][0] - verx[i+1][0])

res = abs(res)/2
res2 = abs(res2)/2
print(res)
print(res2)
print(abs(res2) == abs(res))
print((res + (paramier/2) + 1))