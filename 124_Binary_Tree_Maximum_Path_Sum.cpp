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
    int height(TreeNode* root, int &path_sum){
        if(root == NULL) return 0;

        int a = max(0, height(root->left, path_sum));
        int b = max(0, height(root->right, path_sum));

        path_sum = max(path_sum, a + b + root->val);

        return (root->val + max(a, b));
    }
    int maxPathSum(TreeNode* root) {
        int path_sum = INT_MIN;
        height(root, path_sum);
        return path_sum;
    }
};

int main()
{

    return 0;
}