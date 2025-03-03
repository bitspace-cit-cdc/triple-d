
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
 
max_diff = 0
def dfs(root):
    global max_diff
    if not root:
        return
    if root.left:
        max_diff = max(max_diff, abs(root.val - root.left.val))
    if root.right:
        max_diff = max(max_diff, abs(root.val - root.right.val))
    dfs(root.left)
    dfs(root.right)
 
s = input().strip()
root = buildTree(s)
dfs(root)
print(max_diff)
