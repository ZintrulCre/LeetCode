// #1
class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        if (!head)
            return nullptr;
        int len = 0;
        ListNode *fast = head, *slow = head, *prev = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }
        auto root = new TreeNode(slow->val);
        if (fast != slow) {
            prev->next = nullptr;
            root->left = sortedListToBST(head);
            root->right = sortedListToBST(slow->next);
        }
        return root;
    }
};


// #2
class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        if (!head)
            return nullptr;
        int len = 0;
        ListNode *temp = head, *prev = temp;
        while (temp) {
            ++len;
            temp = temp->next;
        }
        len /= 2;
        temp = head;
        while (len > 0 && temp) {
            --len;
            prev = temp;
            temp = temp->next;
        }
        if (!temp)
            return nullptr;
        auto root = new TreeNode(temp->val);
        if (prev != temp) {
            prev->next = nullptr;
            root->left = sortedListToBST(head);
            root->right = sortedListToBST(temp->next);
        }
        return root;
    }
};
