// #1: simple solution
class Solution {
public:
    bool flipEquiv(TreeNode *root1, TreeNode *root2) {
        if (!root1 && !root2)
            return true;
        else if (!root1 || !root2)
            return false;
        else if (root1->val != root2->val)
            return false;
        return (flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right)) ||
               (flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left));
    }
};


// #2
class Solution {
public:
    bool flipEquiv(TreeNode *root1, TreeNode *root2) {
        if (!root1) {
            if (!root2)
                return true;
            return false;
        }
        if (!root2) {
            if (root1)
                return false;
        }
        if (root1->val != root2->val)
            return false;
        return checkEquiv(root1, root2);
    }

    bool checkEquiv(TreeNode *root1, TreeNode *root2) {
        if (root1->left && root2->left) {
            if (root1->right && root2->right) {
                if (root1->left->val == root2->left->val && root1->right->val == root2->right->val) {
                    return checkEquiv(root1->left, root2->left) && checkEquiv(root1->right, root2->right);
                } else if (root1->left->val == root2->right->val && root1->right->val == root2->left->val) {
                    return checkEquiv(root1->left, root2->right) && checkEquiv(root1->right, root2->left);
                } else
                    return false;
            } else if (!root1->right && !root2->right) {
                if (root1->left->val == root2->left->val)
                    return checkEquiv(root1->left, root2->left);
                return false;
            } else
                return false;
        } else if (!root1->left && !root2->left) {
            if (root1->right && root2->right) {
                if (root1->right->val == root2->right->val)
                    return checkEquiv(root1->right, root2->right);
                return false;
            }
            return true;
        } else if (root1->left && !root2->left) {
            if (!root1->right && root2->right) {
                if (root1->left->val == root2->right->val)
                    return checkEquiv(root1->left, root2->right);
                return false;
            }
            return false;
        } else if (!root1->left && root2->left) {
            if (root1->right && !root2->right) {
                if (root1->right->val == root2->left->val)
                    return checkEquiv(root1->right, root2->left);
                return false;
            }
            return false;
        }
        return true;
    }
};
