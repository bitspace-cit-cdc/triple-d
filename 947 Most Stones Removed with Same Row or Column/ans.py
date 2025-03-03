
class DSU:
    def __init__(self):
        self.parent = {}
        self.rank = {}
        self.components = 0

    def find(self, x):
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]

    def unite(self, x, y):
        xr, yr = self.find(x), self.find(y)
        if xr != yr:
            if self.rank[xr] > self.rank[yr]:
                xr, yr = yr, xr
            self.parent[xr] = yr
            if self.rank[xr] == self.rank[yr]:
                self.rank[yr] += 1
            self.components -= 1

    def add(self, x):
        if x not in self.parent:
            self.parent[x] = x
            self.rank[x] = 0
            self.components += 1

def max_stones_removed(stones):
    dsu = DSU()
    for x, y in stones:
        dsu.add(x)
        dsu.add(~y)
        dsu.add(x - y)
        dsu.add(x + y)
        dsu.unite(x, ~y)
        dsu.unite(x, x - y)
        dsu.unite(x, x + y)
    return len(stones) - dsu.components

n = int(input())
stones = [list(map(int, input().split())) for _ in range(n)]
print(max_stones_removed(stones))
