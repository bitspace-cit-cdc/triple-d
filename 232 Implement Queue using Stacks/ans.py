
class MyQueue:
    def __init__(self):
        self.inStack = []
        self.outStack = []
        self.totalSum = 0
    def push(self, x: int) -> None:
        self.inStack.append(x)
        self.totalSum += x
    def pop(self) -> int:
        if not self.outStack:
            while self.inStack:
                self.outStack.append(self.inStack.pop())
        x = self.outStack.pop()
        self.totalSum -= x
        return x
    def peek(self) -> int:
        if not self.outStack:
            while self.inStack:
                self.outStack.append(self.inStack.pop())
        return self.outStack[-1]
    def empty(self) -> bool:
        return not self.inStack and not self.outStack
    def size(self) -> int:
        return len(self.inStack) + len(self.outStack)
    def sum(self) -> int:
        return self.totalSum
n = int(input())
commands = input().split()
args = []
for cmd in commands:
    if cmd != "MyQueue" and cmd == "push":
        args.append(int(input()))
mq = MyQueue()
argIndex = 0
for cmd in commands:
    if cmd == "MyQueue":
        print("null")
    elif cmd == "push":
        mq.push(args[argIndex])
        argIndex += 1
        print("null")
    elif cmd == "pop":
        print(mq.pop())
    elif cmd == "peek":
        print(mq.peek())
    elif cmd == "empty":
        print("true" if mq.empty() else "false")
    elif cmd == "size":
        print(mq.size())
    elif cmd == "sum":
        print(mq.sum())
    else:
        print("null")
