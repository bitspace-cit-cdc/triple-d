
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

def buildTree(s):
    tokens = s.split()
    if not tokens:
        return None
    root = TreeNode(int(tokens[0]))
    queue = [root]
    i = 1
    while queue and i < len(tokens):
        curr = queue.pop(0)
        if i < len(tokens) and tokens[i] != "null":
            curr.left = TreeNode(int(tokens[i]))
            queue.append(curr.left)
        i += 1
        if i < len(tokens) and tokens[i] != "null":
            curr.right = TreeNode(int(tokens[i]))
            queue.append(curr.right)
        i += 1
    return root

def rangeSum(root, low, high, k, height):
    if not root or height >= k:
        return 0
    s = 0
    if low <= root.val <= high:
        s += root.val
    s += rangeSum(root.left, low, high, k, height + 1)
    s += rangeSum(root.right, low, high, k, height + 1)
    return s

treeStr = input().strip()
root = buildTree(treeStr)
low = int(input())
high = int(input())
k = int(input())
print(rangeSum(root, low, high, k, 0))
