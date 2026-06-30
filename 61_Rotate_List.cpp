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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next){return head;}
        int llen = 1;
        ListNode* tail = head;
        while(tail->next){
            tail = tail->next;
            llen++;
        }
        k %= llen;
        if(k == 0){return head;}

        tail->next = head;
        
        for(int i = 0; i < (llen - k); i++){
            tail = tail->next;
        }
        head = tail->next;
        tail->next = NULL;
        return head;
    }
};

int main()
{

    return 0;
}