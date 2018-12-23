// #1
class Solution {
public:
    int findBottomLeftValue(TreeNode *root) {
        queue<TreeNode *> que;
        que.push(root);
        int &&size = 1;
        int val = root->val;
        while (!que.empty()) {
            TreeNode *temp = que.front();
            --size;
            que.pop();
            if (temp->left) que.push(temp->left);
            if (temp->right) que.push(temp->right);
            if (size == 0) {
                size = que.size();
                if (size != 0)
                    val = que.front()->val;
            }
        }
        return val;
    }
};


// #2
class Solution {
public:
    int ret;
    int maxLvl;

    int findBottomLeftValue(TreeNode *root) {
        ret = 0;
        maxLvl = 0;
        searchBottomLeft(root, 1);
        return ret;
    }

    void searchBottomLeft(TreeNode *root, int &&lvl) {
        if (maxLvl < lvl) {
            maxLvl = lvl;
            ret = root->val;
        }
        if (root->left) searchBottomLeft(root->left, lvl + 1);
        if (root->right) searchBottomLeft(root->right, lvl + 1);
    }
};
