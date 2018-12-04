// #1: queue
class Solution {
public:
    vector<vector<int>> levelOrder(Node *root) {
        vector<vector<int>> order;
        if (!root)
            return order;
        queue<Node *> que;
        que.push(root);
        while (!que.empty()) {
            vector<int> temp;
            auto len = que.size();
            for (int i = 0; i < len; ++i) {
                Node *currentNode = que.front();
                temp.push_back(currentNode->val);
                que.pop();
                for (auto child:currentNode->children)
                    que.push(child);
            }
            order.push_back(temp);
        }
        return order;
    }
};


// #2: recursion
class Solution {
public:
    vector<vector<int>> levelOrder(Node *root) {
        vector<vector<int>> order;
        if (!root)
            return order;
        traversal(root, 0, order);
        return order;
    }

    void traversal(Node *root, int &&level, vector<vector<int>> &order) {
        if (!root)
            return;
        if (order.size() <= level) {
            vector<int> temp;
            temp.push_back(root->val);
            order.push_back(temp);
        } else
            order[level].push_back(root->val);
        for (auto node:root->children)
            traversal(node, level + 1, order);
    }
};
