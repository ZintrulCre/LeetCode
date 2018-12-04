// #1: stack


// #2: recursion
class Solution {
public:
    TreeNode *invertTree(TreeNode *root) {
        if (!root)
            return nullptr;
        root->left = invertTree(root->left);
        root->right = invertTree(root->right);
        TreeNode *temp = root->left;
        root->left = root->right;
        root->right = temp;
        return root;
    }
};
