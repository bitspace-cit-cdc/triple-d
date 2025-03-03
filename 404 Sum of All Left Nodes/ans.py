
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
        node = queue.pop(0)
        if i < len(tokens) and tokens[i] != "null":
            node.left = TreeNode(int(tokens[i]))
            queue.append(node.left)
        i += 1
        if i < len(tokens) and tokens[i] != "null":
            node.right = TreeNode(int(tokens[i]))
            queue.append(node.right)
        i += 1
    return root

def sumOfLeftNodes(root, isLeft):
    if not root:
        return 0
    s = root.val if isLeft else 0
    s += sumOfLeftNodes(root.left, True)
    s += sumOfLeftNodes(root.right, False)
    return s

s = input().strip()
root = buildTree(s)
print(sumOfLeftNodes(root, False))
