from collections import deque

class TreeNode:
    def __init__(self, val=0):
        self.val = val
        self.left = None
        self.mid = None
        self.right = None

dp = {}

def dfs(root):
    if not root:
        return (0, 0)
    
    if root in dp:
        return dp[root]
    
    left = dfs(root.left)
    mid = dfs(root.mid)
    right = dfs(root.right)
    
    rob = root.val + left[1] + mid[1] + right[1]
    skip = max(left) + max(mid) + max(right)
    
    dp[root] = (rob, skip)
    return dp[root]

def rob(root):
    return max(dfs(root))

def build_tree(nodes):
    if not nodes or nodes[0] == -1:
        return None

    root = TreeNode(nodes[0])
    queue = deque([root])
    i = 1

    while queue and i < len(nodes):
        curr = queue.popleft()

        if i < len(nodes) and nodes[i] != -1:
            curr.left = TreeNode(nodes[i])
            queue.append(curr.left)
        i += 1

        if i < len(nodes) and nodes[i] != -1:
            curr.mid = TreeNode(nodes[i])
            queue.append(curr.mid)
        i += 1

        if i < len(nodes) and nodes[i] != -1:
            curr.right = TreeNode(nodes[i])
            queue.append(curr.right)
        i += 1

    return root


n = int(input().strip())
nodes = list(map(int, input().strip().split()))
root = build_tree(nodes)
print(rob(root))