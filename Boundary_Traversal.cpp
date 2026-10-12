#include <iostream>
using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
     TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
};

class Solution{
public:
    bool isLeaf(TreeNode* root){
        return root && !root->left && !root->right;
    }

    void leaf_nodes(TreeNode* root, vector<int> &leaf){
        if(root == NULL) return;

        if(isLeaf(root)) {
            leaf.push_back(root->data);
            return;
        }

        leaf_nodes(root->left, leaf);
        leaf_nodes(root->right, leaf);
    }

    vector <int> boundary(TreeNode* root){
    	vector<int> ans;
        if(root == nullptr) return ans;

        if (isLeaf(root)) {
            ans.push_back(root->data);
            return ans;
        }

        ans.push_back(root->data);

        TreeNode* temp = root->left;
        while(temp){
            if(isLeaf(temp)){
                break;
            }
            ans.push_back(temp->data);
            if(temp->left) temp = temp->left;
            else temp = temp->right;
            
        }

        leaf_nodes(root, ans);

        vector<int> right;
        temp = root->right;

        while(temp){
            if(isLeaf(temp)){
                break;
            }
            right.push_back(temp->data);
            if(temp->right) temp = temp->right;
            else temp = temp->left;

        }
        reverse(right.begin(), right.end());
        ans.insert(ans.end(), right.begin(), right.end());

        return ans;
    }
};

int main()
{

    return 0;
}