// #1
class Solution {
public:
    vector<int> vec;

    int kthSmallest(TreeNode *root, int k) {
        stack<TreeNode *> stk;
        while (root || !stk.empty()) {
            if (root) {
                stk.push(root);
                root = root->left;
            } else {
                root = stk.top();
                stk.pop();
                --k;
                if (k == 0)
                    return root->val;
                root = root->right;
            }
        }
    }
};


// #2
class Solution {
public:
    vector<int> vec;

    int kthSmallest(TreeNode *root, int k) {
        vec.clear();
        inorder(root);
        return vec[k - 1];
    }

    void inorder(TreeNode *node) {
        if (!node)
            return;
        inorder(node->left);
        vec.push_back(node->val);
        inorder(node->right);
    }
};
