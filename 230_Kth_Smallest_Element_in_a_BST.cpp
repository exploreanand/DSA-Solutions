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
    int kthSmallest(TreeNode* root, int k) {
        if(!root) return 0;
        int count = k;
        int ans = -1;
        TreeNode* cur = root;
        while(cur){
            if(cur->left){
                TreeNode* temp = cur->left;
                while(temp->right && temp->right != cur){
                    temp = temp->right;
                }
                if(temp->right == cur){
                    temp->right = nullptr;
                    count--;
                    if(count == 0){
                        ans = cur->val;
                    }
                    cur = cur->right;
                }
                else{
                    temp->right = cur;
                    cur = cur->left;
                }
            }
            else{
                count--;
                if(count == 0){
                    ans = cur->val;
                }
                cur = cur->right;
            }
        }
        return ans;
    }
};

int main()
{

    return 0;
}