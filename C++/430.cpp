// #1
class Solution {
public:
    Node *flatten(Node *head) {
        auto node = head;
        while (node) {
            if (node->child) {
                auto next = node->next;
                auto child = flatten(node->child);
                node->next = child;
                child->prev = node;
                node->child = nullptr;
                while (child->next)
                    child = child->next;
                child->next = next;
                if (next)
                    next->prev = child;
                node = next;
            } else
                node = node->next;
        }
        return head;
    }
};


// #2
class Solution {
public:
    Node *flatten(Node *head) {
        if (!head)
            return nullptr;
        stack<Node *> s;
        Node *root = head;
        s.push(head);
        while (!s.empty()) {
            head = s.top();
            s.pop();
            if (head->next) s.push(head->next);
            if (head->child) s.push(head->child);
            head->child = nullptr;
            if (!s.empty()) {
                head->next = s.top();
                s.top()->prev = head;
            }
        }
        return root;
    }
};
