
//http://www.1point3acres.com/bbs/thread-445554-1-1.html

#include "../../commonHeader.h"

class Solution {
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        curr = head;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int step = 1;
        ListNode* temp = curr;
        ListNode* ans = nullptr;

        while(temp) {
        	if(rand() % step == 0)
        		ans = temp;
        	temp = temp->next;
        	step++;
        }

        return ans->val;
    }
private:
	ListNode* curr;
};

int main() {


	return 0;
}

