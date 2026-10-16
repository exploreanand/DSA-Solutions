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
private:
    TreeNode* first = nullptr;
    TreeNode* prev = nullptr;
    TreeNode* mid = nullptr;
    TreeNode* last = nullptr;
public:
    void recoverTree(TreeNode* root) {
        TreeNode* cur = root;
        while(cur){
            if(cur->left){
                TreeNode* temp = cur->left;
                while(temp->right && temp->right != cur){
                    temp = temp->right;
                }
                if(temp->right == cur){
                    temp->right = nullptr;
                    if(prev && cur->val < prev->val){
                        if(first == nullptr){
                            first = prev;
                            mid = cur;
                        }
                        else{
                            last = cur;
                        }
                    }
                    prev = cur;
                    cur = cur->right;
                }
                else{
                    temp->right = cur;
                    cur = cur->left;
                }
            }
            else{
                if(prev && cur->val < prev->val){
                    if(first == nullptr){
                        first = prev;
                        mid = cur;
                    }
                    else{
                        last = cur;
                    }
                }
                prev = cur;
                cur = cur->right;
            }
        }
        if(first && last){
            int temp = first->val;
            first->val = last->val;
            last->val = temp;
        }
        else{
            int temp = first->val;
            first->val = mid->val;
            mid->val = temp;
        }
    }
};

int main()
{

    return 0;
}