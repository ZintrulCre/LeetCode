// #1
class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        ListNode *l1 = new ListNode(0), *l2 = new ListNode(0);
        ListNode *ret = l1, *temp = l2;
        while (head) {
            if (head->val < x) {
                l1->next = head;
                l1 = head;
            } else {
                l2->next = head;
                l2 = head;
            }
            head = head->next;
        }
        l1->next = temp->next;
        l2->next = nullptr;
        return ret->next;
    }
};


// #2
class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        if (!head || !head->next)
            return head;
        ListNode *iter = head, *prev = nullptr;
        while (iter && iter->val >= x) {
            prev = iter;
            iter = iter->next;
        }
        if (prev && iter) {
            prev->next = iter->next;
            iter->next = head;
            head = iter;
        }
        iter = head->next;
        prev = head;
        ListNode *node = head;
        while (iter) {
            if (iter->val < x) {
                if (prev == node) {
                    node = node->next;
                    prev = prev->next;
                    iter = iter->next;
                } else {
                    prev->next = iter->next;
                    iter->next = node->next;
                    node->next = iter;
                    iter = prev->next;
                    node = node->next;
                }
            } else {
                prev = iter;
                iter = iter->next;
            }
        }
        return head;
    }
};
