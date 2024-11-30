from sys import stdin
import copy

arr = []
res = 0

def up(arr):
    for i in range(len(arr[0])):
        for k in range(len(arr)):
            if arr[k][i] == 'O':
                j = k-1
                while j >= 0 and arr[j][i] == '.':
                    arr[j][i] = 'O'
                    arr[j+1][i] = '.'
                    j -= 1
    return arr

def down(arr):
    for i in range(len(arr[0])):
        for k in range(len(arr)):
            k = len(arr) - k - 1
            if arr[k][i] == 'O':
                j = k+1
                while j < len(arr) and arr[j][i] == '.':
                    arr[j][i] = 'O'
                    arr[j-1][i] = '.'
                    j += 1
    return arr

def left(arr):
    for i in range(len(arr)):
        for k in range(len(arr[0])):
            if arr[i][k] == 'O':
                j = k-1
                while j >= 0 and arr[i][j] == '.':
                    arr[i][j] = 'O'
                    arr[i][j+1] = '.'
                    j -= 1
    return arr

def right(arr):
    for i in range(len(arr)):
        for k in range(len(arr[0])):
            k = len(arr[0]) - k -1
            if arr[i][k] == 'O':
                j = k+1
                while j < len(arr[0]) and arr[i][j] == '.':
                    arr[i][j] = 'O'
                    arr[i][j-1] = '.'
                    j += 1
    return arr

def Reverse(tup):
    new_tup = tup[::-1]
    return new_tup

def press(arr):
    res = 0
    arr = list(zip(*arr[::-1]))

    for i in range(len(arr)):
        arr[i] = Reverse(arr[i])

    for line in arr:
        l = len(line)
        l2 = l
        for c in line:
            if c == 'O':
                res += l2
            l2 -= 1
    return res



for line in stdin:
    line = line[:-1]
    arr.append([*line])


for i in  range(int(1000)):
    arr = up(arr)
    # print(press(copy.deepcopy(arr)))
    arr = left(arr)
    # print(press(copy.deepcopy(arr)))
    arr = down(arr)
    # print(press(copy.deepcopy(arr)))
    arr = right(arr)

    print(press(copy.deepcopy(arr)))
    # for line in arr:
    #     print(line)
    # print()

# cycles = 1

# arr2 = copy.deepcopy(arr)

# arr2 = up(arr2)
# arr2 = left(arr2)
# arr2 = down(arr2)
# arr2 = right(arr2)
# # for line in arr2:
# #     print(line)

# while press(arr) != press(arr2):
#     arr2 = up(arr2)
#     arr2 = left(arr2)
#     arr2 = down(arr2)
#     arr2 = right(arr2)
#     cycles += 1
#     print(cycles)
#     # for line in arr2:
#     #     print(line)


# print(cycles)