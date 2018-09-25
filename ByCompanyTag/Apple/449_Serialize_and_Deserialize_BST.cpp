

#include "../../commonHeader.h"

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream out;
        serialize(root, out);
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream in(data);
        return deserialize(in);                     //be careful!!! Here is in! Not Data.
    }

private:
    void serialize(TreeNode* root, ostringstream& out) {
        if(not root) {
            out << string("# ");
            return;
        }

        out << root->val << " ";
        serialize(root->left, out);
        serialize(root->right, out);
    }

    TreeNode* deserialize(istringstream& in) {
        string data;
        in >> data;
        if(data == "#")     return nullptr;
        TreeNode* root = new TreeNode(stoi(data));
        root->left = deserialize(in);
        root->right = deserialize(in);
        return root;
    }
};

int main() {


	return 0;
}

