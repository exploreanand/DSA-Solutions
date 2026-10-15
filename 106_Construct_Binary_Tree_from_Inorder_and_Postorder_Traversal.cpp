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
    unordered_map<int, int> inorder_map;
    TreeNode* build(vector<int>& postorder,int poStart,int poEnd,int inStart,int inEnd){
        if (poStart > poEnd || inStart > inEnd)
            return nullptr;
        int root = postorder[poEnd];
        int index = inorder_map[root];
        int leftBatch = index - inStart;

        TreeNode* node = new TreeNode(root);
        node->left = build(postorder, poStart, poStart + leftBatch - 1, inStart, index - 1);
        node->right = build(postorder, poStart + leftBatch, poEnd - 1, index + 1, inEnd);
        return node;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // Let's Hash first
        int n = inorder.size();
        for(int i = 0; i < n; i++){
            inorder_map[inorder[i]] = i;
        }
        return build(postorder, 0, n - 1, 0, n - 1);
    }
};

int main()
{

    return 0;
}