

#include "../../commonHeader.h"

class Solution {
public:
    void connect(TreeLinkNode *root) {
    	if(not root)
    		return;

    	if(root->left and root->right)
    		root->left->next = root->right;

    	if(root->next) {
    		TreeLinkNode* node = root->right ? root->right :
    							 root->left ? root->left : nullptr;
    		TreeLinkNode* temp = root->next;
    		while(temp) {
    			if(not temp->left and not temp->right)	temp = temp->next;
    			else break;
    		}
    		if(temp)
    			node->next = temp->left ? temp->left :
    						 temp->right ? temp->right : nullptr;
    	}

    	connect(root->right); 				//注意这里的顺序！！！！！ 先right后left
    	connect(root->left);
    }
};



int main() {
    Solution Apple;

	return 0;
}

