
//http://www.1point3acres.com/bbs/thread-445554-1-1.html

#include "../../commonHeader.h"

class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        if (head == nullptr) {
            head = new Node(insertVal, nullptr);
            head->next = head;
            return head;
        }
        
        Node* prev = head;
        Node* next = head->next;
        while (!(prev->val <= insertVal && insertVal <= next->val) 
               && !(prev->val > next->val && insertVal < next->val)
               && !(prev->val > next->val && insertVal > prev->val)) {
            prev = prev->next;
            next = next->next;
            if (prev == head)
                break;
        }
        
        prev->next = new Node(insertVal, next);
        
        return head;
    }

};

int main() {
    Solution Facebook;

	return 0;
}

