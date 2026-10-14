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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        int width = 0;
        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});
        while(!q.empty()){
            int n = q.size();
            unsigned long long firstIndex = 0;
            unsigned long long lastIndex = 0;
            for(int i = 0; i < n; i++){
                auto temp = q.front();
                q.pop();
                if(i == 0){
                    firstIndex = temp.second;
                }
                if(i == n - 1){
                    lastIndex = temp.second;
                }
                if(temp.first->left){
                    q.push({temp.first->left, (2*(temp.second - firstIndex)+1)});
                }
                if(temp.first->right){
                    q.push({temp.first->right, (2*(temp.second - firstIndex)+2)});
                }
            }
            width = max(width, static_cast<int>(lastIndex - firstIndex + 1));
        }
        return width;
    }
};

int main()
{

    return 0;
}