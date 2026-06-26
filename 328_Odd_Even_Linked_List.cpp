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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL){return head;}
        if(head->next == NULL){return head;}
        ListNode* odd = head;
        ListNode* even = head->next;

        ListNode* even_head = head->next;

        bool if_odd = true;

        while(odd->next && even->next){
            if(if_odd){
                odd->next = odd->next->next;
                odd = odd->next;
                if_odd = false;
            }
            else{
                even->next = even->next->next;
                even = even->next;
                if_odd = true;
            }
        }
        if(if_odd){
            odd->next = even_head;
        }
        else{
            even->next = NULL;
            odd->next = even_head;
        }
        return head;
    }
};

int main()
{

    return 0;
}