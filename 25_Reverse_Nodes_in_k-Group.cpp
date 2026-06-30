#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *reverse(ListNode *head)
    {
        ListNode *curr = head;
        ListNode *prev = NULL;
        while (curr)
        {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (!head || k == 1)
        {
            return head;
        }

        ListNode *curr = head;
        ListNode *grp_tail = NULL;

        while (curr)
        {
            ListNode *itr = curr;
            for (int i = 1; i < k; i++)
            {
                itr = itr->next;
                if (itr == NULL)
                {
                    if(grp_tail){
                        grp_tail->next = curr;
                    }
                    return head;
                }
            }

            ListNode* next_grp = itr->next;
            itr->next = NULL;

            ListNode *grp_head = reverse(curr);
            if (grp_tail == NULL)
            {
                head = grp_head;
            }
            else
            {
                grp_tail->next = grp_head;
            }
            grp_tail = curr;
            grp_tail->next = next_grp;
            curr = next_grp;
        }
        return head;
    }
};

int main()
{

    return 0;
}