

#include "../../commonHeader.h"

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if(not root)    return vector<string>();
        string sub = to_string(root->val);
        vector<string> ans;
        dfs(sub, ans, root);
        return ans;
    }

    void dfs(string& sub, vector<string>& ans, TreeNode* root) {
        if(not root->left and not root->right) {
            ans.push_back(sub);
            return;
        }

        int size = sub.size();

        if(root->left) {
            sub += ("->" + to_string(root->left->val));
            dfs(sub, ans, root->left);
            sub.resize(size);
        }

        if(root->right) {
            sub += ("->" + to_string(root->right->val));
            dfs(sub, ans, root->right);
            sub.resize(size);
        }
    }
};



int main() {
    Solution Apple;

	return 0;
}

