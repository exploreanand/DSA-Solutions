#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
void ll_reader(ListNode* head){
    while (head != nullptr)
    {
        cout<<head->val<<" ";
        head=head->next;
    }
    cout<<endl;
}
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode * i = new ListNode;
        ListNode * j = new ListNode;
        i = head;
        j = i->next;
        while (i->next != nullptr)
        {
            while (i->val > j->val)
            {
                (i->next)->val = i->val;
            }
            i = i->next;
        }
        return head;
    }
};

int main()
{
    ListNode * head = new ListNode(5);
    ListNode * sec = new ListNode(7,head);
    ListNode * third = new ListNode(9,sec);
    ListNode * fourth = new ListNode(1,third);
    ListNode * fifth = new ListNode(3,fourth);
    ll_reader(fifth);
    return 0;
}