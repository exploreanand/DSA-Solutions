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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == nullptr) return ans;
        queue<TreeNode*> q;
        q.push(root);
        int zig = 0;

        while(!q.empty()){
            vector<int> curr;
            int n = q.size();
            for(int i = 0; i < n; i++){
                TreeNode* temp = q.front();
                q.pop();
                curr.push_back(temp->val);

                if(temp->left != NULL) q.push(temp->left);
                if(temp->right != NULL) q.push(temp->right);
            }
            if(zig == 1){
                reverse(curr.begin(), curr.end());
            }
            ans.push_back(curr);
            zig = 1 - zig;
        }
        return ans;
    }
};

int main()
{

    return 0;
}