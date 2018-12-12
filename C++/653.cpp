// #1
class Solution {
public:
    bool findTarget(TreeNode *root, int k) {
        if (!root)
            return false;
        unordered_set<int> num;
        queue<TreeNode *> val;
        val.push(root);
        while (!val.empty()) {
            TreeNode *temp = val.front();
            int &&tempNum = k - temp->val;
            if (num.find(tempNum) != num.end())
                return true;
            else
                num.insert(temp->val);
            val.pop();
            if (temp->left) val.push(temp->left);
            if (temp->right) val.push(temp->right);
        }
        return false;
    }
};


// #2
class Solution {
public:
    bool findTarget(TreeNode *root, int k) {
        if (!root)
            return false;
        queue<TreeNode *> num;
        num.push(root);
        while (!num.empty()) {
            TreeNode *temp = num.front();
            auto *tempRoot = findMinus(root, k - temp->val);
            if (tempRoot && tempRoot != temp)
                return true;
            if (temp->left) num.push(temp->left);
            if (temp->right) num.push(temp->right);
            num.pop();
        }
        return false;
    }

    TreeNode *findMinus(TreeNode *root, const int &k) {
        if (!root)
            return nullptr;
        if (root->val == k)
            return root;
        else if (root->val < k)
            return findMinus(root->right, k);
        else
            return findMinus(root->left, k);
    }
};
