class Solution {
public:
    vector<int> inorderVec;

    vector<int> inorderTraversal(TreeNode *root) {
        inorderVec.clear();
        inorder(root);
        return inorderVec;
    }

    void inorder(TreeNode *root) {
        if (!root)
            return;
        inorder(root->left);
        inorderVec.push_back(root->val);
        inorder(root->right);
    }
};
