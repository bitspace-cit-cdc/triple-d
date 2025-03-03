
class MyHashMap:
    def __init__(self):
        self.size = 10007
        self.buckets = [[] for _ in range(self.size)]
    def put(self, key, value):
        idx = key % self.size
        total = sum(value)
        for i, (k, arr, s) in enumerate(self.buckets[idx]):
            if k == key:
                self.buckets[idx][i] = (key, value, total)
                return
        self.buckets[idx].append((key, value, total))
    def get_sum(self, key):
        idx = key % self.size
        for k, arr, s in self.buckets[idx]:
            if k == key:
                return s
        return -1
    def remove(self, key):
        idx = key % self.size
        for i, (k, arr, s) in enumerate(self.buckets[idx]):
            if k == key:
                self.buckets[idx].pop(i)
                return
q = int(input())
ops = input().split()
mp = MyHashMap()
for op in ops:
    if op=="MyHashMap":
        continue
    elif op=="put":
        parts = input().split()
        key = int(parts[0])
        length = int(parts[1])
        arr = list(map(int, input().split()))
        mp.put(key, arr)
    elif op=="get_sum":
        key = int(input())
        print(mp.get_sum(key))
    elif op=="remove":
        key = int(input())
        mp.remove(key)
