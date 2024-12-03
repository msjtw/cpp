import re
import sys

txt = ""

for line in sys.stdin:
    txt += line

x = re.findall("(mul\([0-9]{1,3},[0-9]{1,3}\))|(do\(\))|(don't\(\))", txt)

do = True
res= 0

for a in x:
    b = a[0] + a[1] + a[2]
    if b[0] == 'm':
        if do:
            c = re.findall("[0-9]{1,3}", b)
            res += int(c[0]) * int(c[1])
    elif b == "do()":
        do = True
    else:
        do = False

print(res)
