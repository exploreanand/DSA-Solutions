#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* merge(ListNode* left, ListNode* right){
        ListNode dummy(0);
        ListNode* temp = &dummy;

        while(left && right){
            if(left->val <= right->val){
                temp->next = left;
                left = left->next;
            }
            else{
                temp->next = right;
                right = right->next;
            }
            temp = temp->next;
        }
        temp->next = (left) ? left : right;
        return dummy.next;
    }

    ListNode* sortList(ListNode* head){
        if(!head || !head->next) {
            return head;
        }
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* left = head;
        ListNode* right = slow->next;
        slow->next = nullptr;

        left = sortList(left);
        right = sortList(right);

        return merge(left, right);
    }
};

int main()
{
    Solution obj;

    return 0;
}