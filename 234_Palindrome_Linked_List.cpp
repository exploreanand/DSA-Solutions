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
    bool isPalindrome(ListNode* head) {
        if(head == NULL){return true;}
        ListNode* slow = head;
        ListNode* fast = head;
        bool ans = true;

        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* temp_head = slow->next;
        slow = head;
        ListNode* prev = NULL;

        while(temp_head){
            ListNode* front = temp_head->next;
            temp_head->next = prev;
            prev = temp_head;
            temp_head = front;
        }
        ListNode* temp_head2 = prev;
        while(prev){
            if(slow->val != prev->val){
                ans = false;
                break;
            }
            slow = slow->next;
            prev = prev->next;
        }
        prev = NULL;
        while(temp_head2){
            ListNode* front = temp_head2->next;
            temp_head2->next = prev;
            prev = temp_head2;
            temp_head2 = front;
        }
        return ans;
    }
};

int main()
{

    return 0;
}