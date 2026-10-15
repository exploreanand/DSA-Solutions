#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans = "";
        if(!root) return "#,";
        ans += to_string(root->val);
        ans += ',';
        ans += serialize(root->left);
        ans += serialize(root->right);
        return ans;
    }
    TreeNode* build(string &s, int &i){
        int j = s.find(',', i);
        string token = s.substr(i, j - i);
        i = j + 1;

        if(token == "#") return nullptr;

        TreeNode* node = new TreeNode(stoi(token));
        node->left = build(s, i);
        node->right = build(s, i);
        return node;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int i = 0;
        return build(data, i);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
int main()
{

    return 0;
}