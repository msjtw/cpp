from dataclasses import dataclass

@dataclass
class val_map:
    a : int
    b : int
    r : int

seeds =[]

seeds = input().split()
seeds = [eval(i) for i in seeds]

n =7
while True:
    rules = []
    while True:
        l = input()
        if l == "":
            break
        l = l.split()
        rules.append(val_map(a = int(l[1]), b =int(l[0]), r = int(l[2])))

    if len(rules) == 0:
       break

    print(len(rules))
    for rule in rules:
        print(rule)

    print("")

    new_seeds = []

    for seed in seeds:
        for rule in rules:
            if(seed >= rule.a and seed < rule.a+rule.r):
                seed = seed + (rule.b-rule.a)
                break
        new_seeds.append(seed)

    seeds = new_seeds

res = seeds[0]
for seed in seeds:
    res = min(res, seed)

print(res)