class Solution:
    def smallestFromLeaf(self, root: \u0027TreeNode\u0027) -> \u0027str\u0027:
        if not root:
            return ""
        self.ret = "z" * 1000
        self.Traverse(root, "")
        return self.ret


    def Traverse(self, node, st):
        st += chr(97 + node.val)
        if(not node.left and not node.right):
            if st[::-1] < self.ret:
                self.ret = st[::-1]
        if node.left:
            self.Traverse(node.left, st)
        if node.right:
            self.Traverse(node.right, st)
        st = st[:-1]
