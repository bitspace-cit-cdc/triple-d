
class EnhancedHashSet:
    def __init__(self):
        self.freq = [0] * 1000001

    def add(self, key: int) -> None:
        self.freq[key] += 1

    def remove(self, key: int) -> None:
        self.freq[key] = 0

    def contains(self, key: int) -> bool:
        return self.freq[key] > 0

    def getFrequency(self, key: int) -> int:
        return self.freq[key]

n = int(input())
commands = input().split()
values = list(map(int, input().split())) if len(commands) > 1 else []

hash_set = EnhancedHashSet()
index = 0

for command in commands:
    if command == "add":
        hash_set.add(values[index])
        print("null")
        index += 1
    elif command == "remove":
        hash_set.remove(values[index])
        print("null")
        index += 1
    elif command == "contains":
        print("true" if hash_set.contains(values[index]) else "false")
        index += 1
    elif command == "getFrequency":
        print(hash_set.getFrequency(values[index]))
        index += 1
    else:
        print("null")
