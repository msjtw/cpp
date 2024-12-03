import re
import sys

txt = ""

for line in sys.stdin:
    txt += line

x = re.findall("mul\([0-9]{1,3},[0-9]{1,3}\)", txt)

res= 0

for a in x:
    b = re.findall("[0-9]{1,3}", a)
    res += int(b[0]) * int(b[1])

print(res)
