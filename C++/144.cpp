// #1
class Solution {
public:
    vector<int> vec;

    vector<int> preorderTraversal(TreeNode *root) {
        vec.clear();
        preorder(root);
        return vec;
    }

    void preorder(TreeNode *node) {
        if (!node)
            return;
        vec.push_back(node->val);
        preorder(node->left);
        preorder(node->right);
    }
};


// #2
class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        if (!root)
            return {};
        vector<int> vec;
        stack<TreeNode *> s;
        s.push(root);
        while (!s.empty()) {
            TreeNode *temp = s.top();
            vec.push_back(temp->val);
            s.pop();
            if (temp->right) s.push(temp->right);
            if (temp->left) s.push(temp->left);
        }
        return vec;
    }
};
