from sys import stdin
import functools
from dataclasses import dataclass


@dataclass
class Hand:
    s: str
    v: int


vals = {
    '2' : 1,
    '3' : 2,
    '4' : 3,
    '5' : 4,
    '6' : 5,
    '7' : 6,
    '8' : 7,
    '9' : 8,
    'T' : 9,
    'J' : 10,
    'Q' : 11,
    'K' : 12,
    'A' : 13,
}

def compare(l, r):
    l = l.s
    r = r.s
    l_s = hand_strenth(l)
    r_s = hand_strenth(r)
    if(l_s == r_s):
        for i in range(0,5):
            if vals[l[i]] != vals[r[i]]:
                if vals[l[i]] > vals[r[i]]:
                    return 1
                else:
                    return -1
    else:
        if l_s > r_s:
            return 1
        else:
            return -1

def hand_strenth(hand):
    cards = {}
    for v in vals:
        cards[v] = 0
    for c in hand:
        cards[c] += 1
    types = {}
    for b in range(0,6):
        types[b] = 0
    for key in cards:
        types[cards[key]] += 1



    if types[5] == 1:
        return 10
    if types[4] == 1:
        return 9
    if types[3] == 1 and types[2] == 1:
        return 8
    if types[3] == 1:
        return 7
    if types[2] == 2:
        return 6
    if types[2] == 1:
        return 5
    return 4


hands = []

for line in stdin:
    hands.append(Hand(line.split()[0], int(line.split()[1])))
    
hands = sorted(hands, key=functools.cmp_to_key(compare))

print(hands)

res = 0

for i in range(0,len(hands)):
    res += (i+1)*hands[i].v

print(res)