// #1
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *a = headA, *b = headB;
        if (!a || !b)
            return nullptr;
        while (a != b) {
            a = a->next;
            b = b->next;
            if (!a && !b)
                return nullptr;
            if (!a)
                a = headB;
            if (!b)
                b = headA;
        }
        return a;
    }
};


// #2
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *a = headA, *b = headB;
        while (a != b) {
            a = a ? a->next : headB;
            b = b ? b->next : headA;
        }
        return a;
    }
};