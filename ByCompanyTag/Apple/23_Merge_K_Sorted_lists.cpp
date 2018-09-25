

#include "../../commonHeader.h"

class Solution {
public:
    //s1: compare one by one
    //O(n) = k * n, k = number of lists, n = total nodes
    //O(1) space

    //s2: priority queue
    //O(n) = logK * N
    //O(k) space

    //s3: merge list one by one, time and space is the same as s1


    //s4: divide and conquer
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty())   return nullptr;
        queue<ListNode*> q;
        for(ListNode* list : lists)     q.push(list);

        while(q.size() > 1) {
            ListNode* a = q.front();
            q.pop();
            ListNode* b = q.front();
            q.pop();
            q.push(merge2Lists(a, b));
        }

        return q.front();
    }

    ListNode* merge2Lists(ListNode* a, ListNode* b) {
        if(a == nullptr)    return b;
        if(b == nullptr)    return a;

        if(a->val < b->val) {
            a->next = merge2Lists(a->next, b);
            return a;
        } else {
            b->next = merge2Lists(a, b->next);
            return b;
        }
    }
};



int main() {
    Solution Apple;

	return 0;
}

