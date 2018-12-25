// #1
class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> vec;
        stack<TreeNode *> s;
        while (root || !s.empty()) {
            if (root) {
                s.push(root);
                root = root->left;
            } else {
                root = s.top();
                s.pop();
                vec.push_back(root->val);
                root = root->right;
            }
        }
        return vec;
    }
};


// #2
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
