class Solution {
public:
    ListNode *reverseList(ListNode *head) {
        if (!head) return nullptr;
        ListNode *prev = nullptr, *curr = head, *next;
        while (curr && curr->next) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        curr->next = prev;
        return curr;
    }
};
