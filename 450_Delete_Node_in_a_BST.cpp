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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return root;
        if(root->val == key){
            if(!root->left){
                TreeNode* newNode = root->right;
                delete root;
                return newNode;
            }
            if(!root->right){
                TreeNode* newNode = root->left;
                delete root;
                return newNode;
            }
            TreeNode* right_most_node = root->left;
            while(right_most_node->right){
                right_most_node = right_most_node->right;
            }
            right_most_node->right = root->right;
            TreeNode* newNode = root->left;
            delete root;
            return newNode;
        }

        TreeNode* temp = root;
        TreeNode* hold = nullptr;

        while(temp && temp->val != key){
            hold = temp;
            if(key < temp->val){
                temp = temp->left;
            }
            else{
                temp = temp->right;
            }
        }

        if(!temp){
            return root;
        }

        TreeNode* replacement;

        if(!temp->left || !temp->right){
            replacement = temp->left ? temp->left:temp->right;
        }
        else{
            TreeNode* right_node = temp->left;
            while(right_node->right){
                right_node = right_node->right;
            }
            right_node->right = temp->right;
            replacement = temp->left;
        }

        if(hold->left == temp){
            hold->left = replacement;
        }
        else{
            hold->right = replacement;
        }
        delete temp;
        return root;
    }
};

int main()
{

    return 0;
}