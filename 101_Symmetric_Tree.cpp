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
    bool symmetricCheck(TreeNode* left, TreeNode* right){
        if(left == NULL || right == NULL){
            return left == right;
        }
        return (left->val == right->val) && symmetricCheck(left->left, right->right) && symmetricCheck(left->right, right->left);
    }

    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        return symmetricCheck(root->left, root->right);
    }
};

int main()
{

    return 0;
}