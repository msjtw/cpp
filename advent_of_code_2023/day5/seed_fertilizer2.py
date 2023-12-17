from dataclasses import dataclass
import multiprocessing

@dataclass
class val_map:
    a : int
    b : int
    r : int

inp = []
seeds = []
n =7

def calc(rules, seeds):
    res = 1e10
    for i in range(n):
        new_seeds = []
        for seed in seeds:
            for rule in rules[i]:
                if(seed >= rule.a and seed < rule.a+rule.r):
                    seed = seed + (rule.b-rule.a)
                    break
            new_seeds.append(seed)

        seeds = new_seeds
    for seed in seeds:
        res = min(res, seed)
    print(res)


inp = input().split()
inp = [int(i) for i in inp]

rules = [[] for j in range(n)]
print(rules)
for i in range(n):
    while True:
        l = input()
        if l == "":
            break
        l = l.split()
        rules[i].append(val_map(a = int(l[1]), b =int(l[0]), r = int(l[2])))


print(rules)

for i in range(0,len(inp),4):
    # seeds = calc(rules, inp[i], inp[i+1])
    print(i)
    seeds1 = []
    for seed in range(inp[i], inp[i]+inp[i+1]):
        seeds1.append(seed)
    seeds2 = []
    for seed in range(inp[i+2], inp[i+2]+inp[i+3]):
        seeds2.append(seed)
    p1 = multiprocessing.Process(target=calc, args=(rules, seeds1, )) 
    p2 = multiprocessing.Process(target=calc, args=(rules, seeds2, )) 
    p1.start() 
    p2.start()
    p1.join() 
    p2.join() 