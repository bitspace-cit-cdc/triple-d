class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def buildTree(preorder, inorder):
    if not preorder or not inorder:
        return None
    
    root_val = preorder.pop(0)
    root = TreeNode(root_val)
    mid = inorder.index(root_val)
    
    root.left = buildTree(preorder, inorder[:mid])
    root.right = buildTree(preorder, inorder[mid+1:])
    
    return root

# Example usage:
preorder = [3,9,20,15,7]
inorder = [9,3,15,20,7]
tree = buildTree(preorder, inorder)


def printTree(root):
    if root:
        printTree(root.left)
        print(root.val, end=' ')
        printTree(root.right)

printTree(tree)