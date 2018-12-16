class Solution {
public:
    bool isCompleteTree(TreeNode *root) {
        if (!root)
            return true;
        queue<TreeNode *> tree;
        tree.push(root);
        int size = tree.size(), &&k = 0;
        bool &&btm = false, &&ret = true, &&over = false;
        while (!tree.empty()) {
            TreeNode *temp = tree.front();
            tree.pop();
            --size;
            if (over && (temp->left || temp->right))
                return false;
            if (temp->right && !temp->left) 
                return false;
            if (!temp->left || !temp->right)
                over = true;
            if (btm && (temp->left || temp->right))
                return false;
            if (temp->left) tree.push(temp->left);
            if (temp->right) tree.push(temp->right);
            if (size == 0) {
                size = tree.size();
                if (pow(2, ++k) != size)
                    btm = true;
            }
        }
        return ret;
    }
};
