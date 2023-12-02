from sys import stdin

res = 0

for line in stdin:
    line = line[:-1]
    id = int(line.split(': ')[0].split()[1])
    shows = line.split(': ')[1].split('; ')
    red = 0
    green = 0
    blue = 0
    for show in shows:
        colors = show.split(', ')
        for color in colors:
            num = color.split()
            if num[1] == 'green':
                green = max(green, int(num[0]))
            elif num[1] == 'red':
                red = max(red, int(num[0]))
            else:
                blue = max(blue, int(num[0]))
        
    #if red <= 12 and green <= 13 and blue <= 14:
    res += red*green*blue

print(res)
