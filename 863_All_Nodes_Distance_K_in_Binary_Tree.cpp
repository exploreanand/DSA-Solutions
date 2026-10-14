#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    void map_parents(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &parents)
    {
        if (root == NULL)
            return;
        if (root->left)
        {
            parents.insert({root->left, root});
        }
        if (root->right)
        {
            parents.insert({root->right, root});
        }
        map_parents(root->left, parents);
        map_parents(root->right, parents);
    }

    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        vector<int> ans;
        unordered_map<TreeNode *, TreeNode *> parents;
        map_parents(root, parents);

        unordered_set<TreeNode *> visited;
        queue<TreeNode *> q;
        q.push(target);
        visited.insert(target);
        for (int i = 0; i < k; i++)
        {
            int n = q.size();
            for (int j = 0; j < n; j++)
            {
                TreeNode *temp = q.front();
                q.pop();
                if (temp->left && !visited.count(temp->left))
                {
                    q.push(temp->left);
                    visited.insert(temp->left);
                }
                if (temp->right && !visited.count(temp->right))
                {
                    q.push(temp->right);
                    visited.insert(temp->right);
                }
                auto it = parents.find(temp);
                if (it != parents.end() && !visited.count(it->second))
                {
                    q.push(it->second);
                    visited.insert(it->second);
                }
            }
        }
        while (!q.empty())
        {
            TreeNode *temp = q.front();
            q.pop();
            ans.push_back(temp->val);
        }
        return ans;
    }
};

int main()
{

    return 0;
}