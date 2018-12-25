// #1
class Solution {
public:
    TreeNode *addOneRow(TreeNode *root, int v, int d) {
        if (d == 1) {
            auto *newRoot = new TreeNode(v);
            newRoot->left = root;
            return newRoot;
        }
        queue<TreeNode *> que;
        que.push(root);
        int size = 1;
        while (!que.empty()) {
            if (d > 2) {
                TreeNode *temp = que.front();
                que.pop();
                if (temp->left) que.push(temp->left);
                if (temp->right) que.push(temp->right);
                --size;
                if (size == 0) {
                    size = que.size();
                    --d;
                }
            } else {
                TreeNode *temp = que.front();
                que.pop();
                auto *newLeft = new TreeNode(v);
                if (temp->left)
                    newLeft->left = temp->left;
                temp->left = newLeft;
                auto *newRight = new TreeNode(v);
                if (temp->right)
                    newRight->right = temp->right;
                temp->right = newRight;
            }
        }
        return root;
    }
};


// #2
class Solution {
public:
    TreeNode *addOneRow(TreeNode *root, int v, int d) {
        if (d == 1) {
            auto *newRoot = new TreeNode(v);
            newRoot->left = root;
            return newRoot;
        }
        helper(root, v, d + 0);
        return root;
    }

    void helper(TreeNode *root, const int &v, int &&d) {
        if(!root)
            return;
        if (d == 2) {
            auto *newLeft = new TreeNode(v);
            if (root->left) newLeft->left = root->left;
            root->left = newLeft;
            auto *newRight = new TreeNode(v);
            if (root->right) newRight->right = root->right;
            root->right = newRight;
            return;
        }
        helper(root->left, v, d - 1);
        helper(root->right, v, d - 1);
    }
};
