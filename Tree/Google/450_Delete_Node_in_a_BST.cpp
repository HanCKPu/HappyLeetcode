
#include "../../commonHeader.h"

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
    	if(not root)
    		return root;

    	if(root->val == key) {
    		if(not root->left)			return root->right;
    		else if(not root->right)	return root->left;
    		else {
    			TreeNode* node = root->left;
    			while(node->right)
    				node = node->right;
    			swap(root->val, node->val);
    			root->left = deleteNode(root->left, key);
    			return root;
    		}
    	}

    	if(root->val > key)
    		root->left = deleteNode(root->left, key);
    	if(root->val < key)
    		root->right = deleteNode(root->right, key);
    	return root;
    }
};


int main() {
    Solution Microsoft;

	return 0;
}

