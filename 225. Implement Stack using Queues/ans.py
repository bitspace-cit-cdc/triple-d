from collections import deque

class MyStack:
    def __init__(self):
        self.que = deque()
        self.summation = 0

    def push(self, x):
        self.que.append(x)
        self.summation += x
        for _ in range(len(self.que) - 1):
            self.que.append(self.que.popleft())

    def pop(self):
        res = self.que.popleft()
        self.summation -= res
        return res

    def top(self):
        return self.que[0]

    def empty(self):
        return len(self.que) == 0

    def size(self):
        return len(self.que)

    def sum(self):
        return self.summation


def solve():
    s1 = input().strip()
    s2 = input().strip()
    
    ss1 = s1.split()
    ss2 = list(map(int, s2.split()))
    
    command = ss1[0]
    num = ss2[0]
    
    if command != "MyStack":
        return
    
    stack = MyStack()
    print("null", end=" ")

    i = 1
    while i < len(ss1):
        command = ss1[i]
        x = ss2[i]
        
        if command == "push":
            stack.push(x)
            print("null", end=" ")
        elif command == "pop":
            print(stack.pop(), end=" ")
        elif command == "top":
            print(stack.top(), end=" ")
        elif command == "empty":
            print("true" if stack.empty() else "false", end=" ")
        elif command == "size":
            print(stack.size(), end=" ")
        elif command == "sum":
            print(stack.sum(), end=" ")

        i += 1
    print()  



t = int(input())
for _ in range(t):
	solve()