
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def dfs(node, path, depth, total_sum, result):
    if not node:
        return
    if path:
        path += "->"
    path += str(node.val)
    total_sum += node.val
    if not node.left and not node.right:
        result.append((path, depth, total_sum))
        return
    dfs(node.left, path, depth + 1, total_sum, result)
    dfs(node.right, path, depth + 1, total_sum, result)

def binary_tree_paths(root):
    result = []
    dfs(root, "", 1, 0, result)
    return result

def build_tree(nodes):
    if not nodes or nodes[0] == "null":
        return None
    root = TreeNode(int(nodes[0]))
    queue = [root]
    i = 1
    while i < len(nodes):
        curr = queue.pop(0)
        if nodes[i] != "null":
            curr.left = TreeNode(int(nodes[i]))
            queue.append(curr.left)
        i += 1
        if i < len(nodes) and nodes[i] != "null":
            curr.right = TreeNode(int(nodes[i]))
            queue.append(curr.right)
        i += 1
    return root

n = int(input())
nodes = input().split()
root = build_tree(nodes)
result = binary_tree_paths(root)
for path, depth, total_sum in result:
    print(path, depth, total_sum)
