class BrowserHistory:
    class Node:
        def __init__(self, data):
            self.data = data
            self.prev = None
            self.next = None

    def __init__(self, homepage: str):
        self.head = self.Node(homepage)

    def visit(self, url: str):
        node = self.Node(url)
        if self.head.next:
            self.head.next.prev = None
        node.prev = self.head
        self.head.next = node
        self.head = node

    def back(self, steps: int) -> str:
        while self.head.prev and steps:
            self.head = self.head.prev
            steps -= 1
        return self.head.data

    def forward(self, steps: int) -> str:
        while self.head.next and steps:
            self.head = self.head.next
            steps -= 1
        return self.head.data

    def deleteUrl(self):
        if not self.head.prev:
            return
        if self.head.next:
            self.head.next.prev = self.head.prev
            self.head.prev.next = self.head.next
            self.head = self.head.prev



operations = []
params = []

n = int(input())
for _ in range(n):
	operation = input().split()
	operations.append(operation[0])
	params.append(operation[1:])

obj = None
result = []

for i in range(len(operations)):
	if operations[i] == "BrowserHistory":
		obj = BrowserHistory(params[i][0])
		result.append("null")
	elif operations[i] == "visit":
		obj.visit(params[i][0])
		result.append("null")
	elif operations[i] == "back":
		result.append(obj.back(int(params[i][0])))
	elif operations[i] == "forward":
		result.append(obj.forward(int(params[i][0])))
	elif operations[i] == "delete":
		obj.deleteUrl()
		result.append("null")

for res in result:
	print(res)