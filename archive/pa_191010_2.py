import json
import sys


def win(board, n):
    def check(i, j):
        ti, tj = i, j
        for t in range(5):
            if i >= n or board[i][j] != 1:
                break
            i += 1
        else:
            return True

        i, j = ti, tj
        for t in range(5):
            if j >= n or board[i][j] != 1:
                break
            j += 1
        else:
            return True

        i, j = ti, tj
        for t in range(5):
            if i >= n or j >= n or board[i][j] != 1:
                break
            i += 1
            j += 1
        else:
            return True

        i, j = ti, tj
        for t in range(5):
            if i < 0 or j >= n or board[i][j] != 1:
                break
            i -= 1
            j += 1
        else:
            return True

        return False

    for i in range(n):
        for j in range(n):
            if board[i][j] == 1 and check(i, j):
                return True

    return False


input_file = sys.stdin
# input_file = open('data.txt')
line = input_file.read()
data = json.loads(line)

p1_x = data['p1_x']
p1_y = data['p1_y']
p2_x = data['p2_x']
p2_y = data['p2_y']

print(p1_x)

n = 1000
board = [[0] * n for i in range(n)]
for x, y in zip(p1_x, p1_y):
    board[x][y] = 1
flag1 = win(board, n)

board = [[0] * n for i in range(n)]
for x, y in zip(p2_x, p2_y):
    board[x][y] = 1
flag2 = win(board, n)

# print(flag1, flag2)

if not (flag1 ^ flag2):
    print(0)
elif flag1:
    print(1)
else:
    print(2)
