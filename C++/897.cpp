// #1
class Solution {
public:
    TreeNode *increasingBST(TreeNode *root) {
        if (!root)
            return nullptr;
        root->right = increasingBST(root->right);
        if (root->left) {
            TreeNode *temp = increasingBST(root->left), *left = temp;
            while (left->right)
                left = left->right;
            left->right = root;
            root->left = nullptr;
            return temp;
        }
        return root;
    }
};


// #2
class Solution {
public:
    TreeNode *increasingBST(TreeNode *root) {
        vector<int> inorder;
        inorderTraversal(root, inorder);
        TreeNode *origin, *cur;
        if (!inorder.empty()) {
            origin = new TreeNode(inorder[0]);
            cur = origin;
        }
        for (int i = 1; i < inorder.size(); ++i) {
            TreeNode *temp = new TreeNode(inorder[i]);
            cur->right = temp;
            cur = temp;
        }
        return origin;
    }


    void inorderTraversal(TreeNode *root, vector<int> &inorder) {
        if (!root)
            return;
        inorderTraversal(root->left, inorder);
        inorder.push_back(root->val);
        inorderTraversal(root->right, inorder);
    }
};
