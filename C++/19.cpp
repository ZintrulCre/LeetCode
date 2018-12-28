// #1
class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *l = new ListNode(0);
        l->next = head;
        ListNode *fast = head, *slow = head;
        ListNode *prev = l;
        while (n > 0) {
            fast = fast->next;
            --n;
        }
        while (fast) {
            fast = fast->next;
            prev = slow;
            slow = slow->next;
        }
        prev->next = slow->next;
        return l->next;
    }
};


// #2
class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if (!head)
            return head;
        ListNode *iter = head, *prev = head;
        while (n > 0) {
            if (!iter)
                return head;
            iter = iter->next;
            --n;
        }
        if (!iter) {
            ListNode *temp = head->next;
            delete head;
            return temp;
        }
        while (iter && iter->next) {
            iter = iter->next;
            prev = prev->next;
        }
        ListNode *temp = prev->next;
        if (temp) {
            prev->next = temp->next;
            delete temp;
        }
        return head;
    }
};
