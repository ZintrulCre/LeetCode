// #1
class Solution {
public:
    TreeNode *prev;
    int k, maxNum;
    vector<int> ret;

    vector<int> findMode(TreeNode *root) {
        ret.clear();
        if (!root)
            return ret;
        prev = nullptr;
        k = 0;
        maxNum = 0;
        inOrder(root);
        return ret;
    }

    void inOrder(TreeNode *root) {
        if (!root)
            return;
        inOrder(root->left);

        if (prev) {
            if (root->val == prev->val) {
                ++k;
                if (k > maxNum) {
                    maxNum = k;
                    ret.clear();
                    ret.push_back(root->val);
                } else if (k == maxNum)
                    ret.push_back(root->val);
            } else {
                k = 1;
                if (k == maxNum)
                    ret.push_back(root->val);
            }
        } else {
            ret.push_back(root->val);
            k = 1;
            maxNum = 1;
        }
        prev = root;

        inOrder(root->right);
    }
};


// #2
class Solution {
public:
    vector<int> findMode(TreeNode *root) {
        vector<int> ret;
        if (!root)
            return ret;
        queue<TreeNode *> node;
        unordered_map<int, int> mode;
        node.push(root);
        while (!node.empty()) {
            TreeNode *temp = node.front();
            node.pop();
            ++mode[temp->val];
            if (temp->left) node.push(temp->left);
            if (temp->right) node.push(temp->right);
        }
        int maxNum = 0;
        for (auto iter:mode) {
            if (maxNum < iter.second) {
                ret.clear();
                maxNum = iter.second;
                ret.push_back(iter.first);
            } else if (maxNum == iter.second)
                ret.push_back(iter.first);
        }
        return ret;
    }
};
