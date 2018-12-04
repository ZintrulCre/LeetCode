// #1: queue
class Solution {
public:
    vector<double> averageOfLevels(TreeNode *root) {
        vector<double> average;
        if (!root)
            return average;
        queue<TreeNode *> que;
        que.push(root);
        while (!que.empty()) {
            int len = que.size();
            double ave = 0.0;
            for (int i = 0; i < len; ++i) {
                TreeNode *temp = que.front();
                ave += temp->val;
                que.pop();
                if (temp->left) que.push(temp->left);
                if (temp->right) que.push(temp->right);
            }
            average.push_back(ave / len);
        }
        return average;
    }
};


// #2: recursion
class Solution {
public:
    vector<double> averageOfLevels(TreeNode *root) {
        vector<double> ave;
        vector<int> num;
        helper(root, 0, ave, num);
        for (int i = 0; i < ave.size(); ++i)
            ave[i] /= num[i];
        return ave;
    }

    void helper(TreeNode *root, int &&level, vector<double> &ave, vector<int> &num) {
        if (!root)
            return;
        if (ave.size() <= level) {
            ave.push_back(root->val);
            num.push_back(1);
        } else {
            ave[level] += root->val;
            ++num[level];
        }
        helper(root->left, level + 1, ave, num);
        helper(root->right, level + 1, ave, num);
    }
};
