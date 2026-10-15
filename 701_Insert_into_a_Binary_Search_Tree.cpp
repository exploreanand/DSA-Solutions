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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* node = new TreeNode(val);
        if(!root) return node;
        TreeNode* temp = root;
        while(true){
            if(val < temp->val){
                if(temp->left == nullptr){
                    temp->left = node;
                    break;
                }
                temp = temp->left;
            }
            else{
                if(temp->right == nullptr){
                    temp->right = node;
                    break;
                }
                temp = temp->right;
            }
        }
        return root;
    }
};

int main()
{

    return 0;
}