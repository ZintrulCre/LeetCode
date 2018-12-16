// #1
class Solution {
public:
    int minDepth(TreeNode *root) {
        if (!root)
            return 0;
        if (root->left && root->right)
            return 1 + min(minDepth(root->left), minDepth(root->right));
        else if (root->left)
            return 1 + minDepth(root->left);
        else if (root->right)
            return 1 + minDepth(root->right);
        return 1;
    }
};


// #2
class Solution {
public:
    int minDepth(TreeNode *root) {
        if (!root)
            return 0;
        int &&dep = 1, &&size = 1;
        queue<TreeNode *> node;
        node.push(root);
        while (!node.empty()) {
            TreeNode *temp = node.front();
            node.pop();
            --size;
            if (!temp->left && !temp->right)
                return dep;
            if (temp->left) node.push(temp->left);
            if (temp->right) node.push(temp->right);
            if (size == 0) {
                ++dep;
                size = node.size();
            }
        }
        return dep;
    }
};
