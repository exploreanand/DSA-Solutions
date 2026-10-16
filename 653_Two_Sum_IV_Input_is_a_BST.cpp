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

class Iterator{
private:
    stack<TreeNode*> s;
    bool isReverse = false;
public:
    Iterator(TreeNode* root, bool isReverse){
        this->isReverse = isReverse;
        pushAll(root);
    }
    int next(){
        TreeNode* node = s.top();
        s.pop();
        int ans = node->val;
        if(isReverse){
            pushAll(node->left);
        }
        else{
            pushAll(node->right);
        }
        return ans;
    }

    bool isNext(){
        return !s.empty();
    }

    void pushAll(TreeNode* root){
        while(root){
            s.push(root);
            if(isReverse){
                root = root->right;
            }
            else
                root = root->left;
        }
    }
};


class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        Iterator left(root, false);
        Iterator right(root, true);
        int l = left.next();
        int r = right.next();

        while(l < r){
            if(l + r == k) return true;
            else if((l + r) < k) l = left.next();
            else r = right.next();
        }
        return false;
    }
};

int main()
{

    return 0;
}