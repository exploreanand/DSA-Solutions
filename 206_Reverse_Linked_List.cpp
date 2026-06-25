#include <iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Iterative approach
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* temp = head;
        ListNode* prev = NULL;

        while(temp){
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }
};

// Recursive Approach
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
        if(head == NULL && head->next == NULL){
            return head;
        }

        ListNode* head = reverseList(head->next);

        return ;
    }
};

int main()
{

    return 0;
}