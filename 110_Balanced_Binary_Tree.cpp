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
    // Naive approach
    // int height(TreeNode* root){
    //     if(root == NULL) return 0;

    //     int a = height(root->left);
    //     int b = height(root->right);

    //     return (1 + max(a, b));
    // }

    // bool isBalanced(TreeNode* root) {
    //     if(root == NULL) return true;
    //     int l_height = height(root->left);
    //     int r_height = height(root->right);
    //     return (abs(l_height - r_height) <= 1) && isBalanced(root->left) && isBalanced(root->right);
    // }


    // This is optimal
    int height(TreeNode* root){
        if(root == NULL) return 0;

        int a = height(root->left);
        if(a == -1) return -1;
        int b = height(root->right);
        if(b == -1) return -1;

        if(abs(a - b) > 1) return -1;

        return (1 + max(a, b));
    }

    bool isBalanced(TreeNode* root) {
        return (height(root) != -1);
    }
};

int main()
{

    return 0;
}