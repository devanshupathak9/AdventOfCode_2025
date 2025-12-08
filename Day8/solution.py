from heapq import heapify, heappop

class DisjointSet:
    def __init__(self, lines):
        self.ds = {line: line for line in lines}
        self.sz = {line: 1 for line in lines}

    def find_node(self, line):
        if self.ds[line] != line:
            self.ds[line] = self.find_node(self.ds[line])
        return self.ds[line]

    def make_union(self, line1, line2):
        root1 = self.find_node(line1)
        root2 = self.find_node(line2)
        if root1 == root2:
            return
        if self.sz[root1] > self.sz[root2]:
            self.ds[root2] = root1
            self.sz[root1] += self.sz[root2]
        else:
            self.ds[root1] = root2
            self.sz[root2] += self.sz[root1]

    def get_size(self, line):
        return self.sz[self.find_node(line)]

def find_distance(line1, line2):
    v1 = [int(x) for x in line1.strip().split(",") if x]
    v2 = [int(x) for x in line2.strip().split(",") if x]
    return sum((a-b)**2 for a,b in zip(v1,v2))**0.5

def solve_part1(lines):
    min_heap = []
    for i in range(len(lines)):
        for j in range(i+1, len(lines)):
            d = find_distance(lines[i], lines[j])
            min_heap.append([d, lines[i], lines[j]])
    heapify(min_heap)

    iteration = 1000
    ds = DisjointSet(lines)
    while iteration and min_heap:
        iteration -= 1
        min_val = heappop(min_heap)
        ds.make_union(min_val[1], min_val[2])

    max_size = set()
    sizes = []
    for line in lines:
        node = ds.find_node(line)
        size = ds.get_size(node)
        if node not in max_size:
            max_size.add(node)
            sizes.append(size)
    sizes.sort(reverse=True)
    return sizes[0]*sizes[1]*sizes[2]

def solve_part2(lines):
    min_heap = []
    for i in range(len(lines)):
        for j in range(i+1, len(lines)):
            d = find_distance(lines[i], lines[j])
            min_heap.append([d, lines[i], lines[j]])
    heapify(min_heap)

    ds = DisjointSet(lines)
    min_val = []
    while True:
        min_val = heappop(min_heap)
        ds.make_union(min_val[1], min_val[2])
        if ds.get_size(min_val[1]) == len(lines):
            break
    return int(min_val[1].split(",")[0])*int(min_val[2].split(",")[0])

def main():
    lines = []
    with open("data.txt", "r") as f:
        coordinates = f.read()
    for line in coordinates.split("\n"):
        lines.append(line)
    
    print(solve_part1(lines))
    print(solve_part2(lines))

main()