from collections import deque

class TreeNode:
    def __init__(self, x=0, left=None, right=None):
        self.val = x
        self.left = left
        self.right = right

class Tree:
    def __init__(self):
        self.first = None
        self.second = None
        self.prev = None

    def recoverTree(self, root):
        self.inorderTraversal(root)
        if self.first and self.second:
            self.first.val, self.second.val = self.second.val, self.first.val

    def inorderTraversal(self, root):
        if not root:
            return
        self.inorderTraversal(root.left)

        if self.prev and root.val > self.prev.val:
            if not self.first:
                self.first = self.prev
            self.second = root
        self.prev = root

        self.inorderTraversal(root.right)

def buildTree(parts):
    if not parts or parts[0] == "null":
        return None

    root = TreeNode(int(parts[0]))
    q = deque([root])
    i = 1
    while q and i < len(parts):
        curr = q.popleft()
        if i < len(parts):
            val = parts[i]
            if val != "null":
                curr.left = TreeNode(int(val))
                q.append(curr.left)
            i += 1

        if i < len(parts):
            val = parts[i]
            if val != "null":
                curr.right = TreeNode(int(val))
                q.append(curr.right)
            i += 1

    return root

def serializeTree(root):
    res = []
    if not root:
        return res

    q = deque([root])
    while q:
        curr = q.popleft()
        if curr:
            res.append(str(curr.val))
            q.append(curr.left)
            q.append(curr.right)
        else:
            res.append("null")

    while res and res[-1] == "null":
        res.pop()

    return res

def solve():
    line = input().strip()
    parts = line.split()
    
    root = buildTree(parts)

    tree = Tree()
    tree.recoverTree(root)

    res = serializeTree(root)
    print(" ".join(res))

t = int(input())
for _ in range(t):
	solve()