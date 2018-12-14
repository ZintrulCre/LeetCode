// #1
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode *root) {
        vector<vector<int>> ret;
        if (!root)
            return ret;
        vector<int> cur;
        int len = 1;
        queue<TreeNode *> que;
        que.push(root);
        while (!que.empty()) {
            TreeNode *temp = que.front();
            que.pop();
            --len;
            cur.push_back(temp->val);
            if (temp->left) que.push(temp->left);
            if (temp->right) que.push(temp->right);
            if (!len) {
                ret.push_back(cur);
                cur.clear();
                len = que.size();
            }
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};


// #2
class Solution {
public:
    vector<vector<int>> tra;

    vector<vector<int>> levelOrderBottom(TreeNode *root) {
        tra = vector<vector<int>>();
        if(!root)
            return tra;
        Traversal(root, 0);
        return tra;
    }

    void Traversal(TreeNode *root, int &&level) {
        if(!root)
            return;
        if (tra.size() <= level) {
            vector<int> temp;
            temp.push_back(root->val);
            tra.push_back(temp);
        } else
            tra[level].push_back(root->val);
        Traversal(root->left, level + 1);
        Traversal(root->right, level + 1);
    }
};