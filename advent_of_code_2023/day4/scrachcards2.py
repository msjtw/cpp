from sys import stdin
from dataclasses import dataclass

@dataclass
class Card:
    cardNum: int
    winning: list

cards = {}

for line in stdin:
    cardId = int(line.split(": ")[0].split()[1])
    winning = line.split(": ")[1].split(" | ")[0].split()
    winning = [eval(i) for i in winning]
    nums = line.split(": ")[1].split(" | ")[1].split()
    nums = [eval(i) for i in nums]
    win  = []
    for n in nums:
        if winning.count(n) > 0:
            win.append(n)
    cards[cardId] = Card(1,win)

for i in range(1,195):
    n = len(cards[i].winning)
    for k in range(i + 1, min(i+n+1, 195)):
        cards[k].cardNum += cards[i].cardNum

res = 0

for card in cards:
    res += cards[card].cardNum

print(res)
