import re
from itertools import product

def min_presses(target, buttons):
    n = len(target)
    m = len(buttons)

    A = [[0]*m for _ in range(n)]
    for j, btn in enumerate(buttons):
        for i in btn:
            A[i][j] ^= 1

    b = target[:]
    where = [-1]*m

    row = 0
    for col in range(m):
        if row >= n:
            break
        sel = -1
        for i in range(row, n):
            if A[i][col]:
                sel = i
                break
        if sel == -1:
            continue

        A[row], A[sel] = A[sel], A[row]
        b[row], b[sel] = b[sel], b[row]
        where[col] = row

        for i in range(n):
            if i != row and A[i][col]:
                for j in range(col, m):
                    A[i][j] ^= A[row][j]
                b[i] ^= b[row]

        row += 1

    for i in range(row, n):
        if b[i]:
            return float("inf")

    free = [i for i in range(m) if where[i] == -1]
    best = float("inf")

    for mask in product([0,1], repeat=len(free)):
        x = [0]*m
        for i, v in zip(free, mask):
            x[i] = v

        for i in range(m):
            if where[i] != -1:
                s = b[where[i]]
                for j in range(i+1, m):
                    s ^= (A[where[i]][j] & x[j])
                x[i] = s

        best = min(best, sum(x))

    return best

def parse_line(line):
    diagram = re.search(r"\[(.*?)\]", line).group(1)
    target = [1 if c == '#' else 0 for c in diagram]

    button_parts = re.findall(r"\((.*?)\)", line)
    buttons = []
    for part in button_parts:
        if part.strip() == "":
            continue
        buttons.append(list(map(int, part.split(","))))

    return target, buttons

total = 0
with open("data.txt") as f:
    for line in f:
        line = line.strip()
        if not line:
            continue

        target, buttons = parse_line(line)
        presses = min_presses(target, buttons)
        total += presses
print("Minimum total button presses:", total)
