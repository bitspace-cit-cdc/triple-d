
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

def sortedArrayToBST(nums, l, r):
    if l > r:
        return None
    mid = (l + r) // 2
    root = TreeNode(nums[mid])
    root.left = sortedArrayToBST(nums, mid + 1, r)
    root.right = sortedArrayToBST(nums, l, mid - 1)
    return root

def levelOrder(root):
    res = []
    if not root:
        return res
    queue = [root]
    while queue:
        node = queue.pop(0)
        if node:
            res.append(str(node.val))
            queue.append(node.left)
            queue.append(node.right)
        else:
            res.append("null")
    while res and res[-1] == "null":
        res.pop()
    return res

n = int(input())
nums = list(map(int, input().split()))
root = sortedArrayToBST(nums, 0, n - 1)
ans = levelOrder(root)
print(",".join(ans))
