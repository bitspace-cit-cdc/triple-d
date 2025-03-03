
import random

class RandomizedSet:
    def __init__(self):
        self.vals = []
        self.pos = {}
        self.total_sum = 0

    def insert(self, val: int) -> bool:
        if val in self.pos:
            return False
        self.pos[val] = len(self.vals)
        self.vals.append(val)
        self.total_sum += val
        return True

    def remove(self, val: int) -> bool:
        if val not in self.pos:
            return False
        idx = self.pos[val]
        last_val = self.vals[-1]
        self.vals[idx] = last_val
        self.pos[last_val] = idx
        self.vals.pop()
        self.total_sum -= val
        del self.pos[val]
        return True

    def getRandom(self) -> int:
        return random.choice(self.vals)

    def getSum(self) -> int:
        return self.total_sum

t = int(input().strip())
rs = RandomizedSet()
for _ in range(t):
    parts = input().split()
    op = parts[0]
    if op == "RandomizedSet":
        print("null")
    elif op == "insert":
        print("true" if rs.insert(int(parts[1])) else "false")
    elif op == "remove":
        print("true" if rs.remove(int(parts[1])) else "false")
    elif op == "getRandom":
        print(rs.getRandom())
    elif op == "getSum":
        print(rs.getSum())
