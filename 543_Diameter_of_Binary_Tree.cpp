#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int height(TreeNode *root, int &h)
    {
        if (root == NULL)
            return 0;

        int a = height(root->left, h);
        int b = height(root->right, h);

        if ((a + b) > h)
        {
            h = a + b;
        }

        return (1 + max(a, b));
    }
    int diameterOfBinaryTree(TreeNode *root)
    {
        int h = 0;
        height(root, h);
        return h;
    }
};

int main()
{

    return 0;
}