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
    class Compare{
        public:
            bool operator()(ListNode* a, ListNode* b){
                return a->val > b->val;
            }
    };

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;
        for(ListNode* head : lists){
            if(head != nullptr){
                pq.push(head);
            }
        }
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;

        while(!pq.empty()){
            ListNode* small = pq.top();
            pq.pop();

            temp->next = small;
            temp = temp->next;
            if(small->next != nullptr){
                pq.push(small->next);
            }
        }
        temp->next = nullptr;

        return dummy->next;
    }
};

int main()
{

    return 0;
}