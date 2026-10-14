#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    unordered_map<int, int> inorder_index;
    TreeNode* build(vector<int>& preorder,int pre_start, int pre_end, int in_start, int in_end){
        if (pre_start > pre_end || in_start > in_end)
            return nullptr;
        int root = preorder[pre_start];
        int index = inorder_index[root];
        int last_size = index - in_start;

        TreeNode* node = new TreeNode(root);
        node->left = build(preorder, pre_start + 1, pre_start + last_size, in_start, index - 1);
        node->right = build(preorder, pre_start + last_size + 1, pre_end, index + 1, in_end);

        return node;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty()) return nullptr;

        // Hash the inorder
        int n = inorder.size();
        for(int i = 0; i < n; i++){
            inorder_index[inorder[i]] = i;
        }

        return build(preorder, 0, n - 1, 0, n - 1);
    }
};

int main()
{

    return 0;
}