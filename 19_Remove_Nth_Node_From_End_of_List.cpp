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

// Sub optimal Solution
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {

        if (head == NULL)
        {
            return head;
        }

        ListNode *slow = head;
        ListNode *fast = head;
        int counter = 1;
        int llen = 1;

        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            counter++;
        }
        if (fast)
        {
            llen = counter * 2 - 1;
        }
        else
        {
            llen = (counter - 1) * 2;
        }

        ListNode *temp = NULL;
        if (n == llen)
        {
            return head = head->next;
        }
        else
        {
            temp = head;
            int step = 1;
            int res = llen - n;
            while (step != res)
            {
                step++;
                temp = temp->next;
            }
            ListNode *del_node = temp->next;
            temp->next = temp->next->next;
            delete del_node;
        }
        return head;
    }
};

// Optimal
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        if (head == NULL)
        {
            return head;
        }

        ListNode *slow = head;
        ListNode *fast = head;

        for (int i = 0; i < n; i++)
        {
            fast = fast->next;
            if (fast == NULL)
            {
                ListNode *del = head;
                head = head->next;
                delete del;
                return head;
            }
        }
        while (fast->next)
        {
            slow = slow->next;
            fast = fast->next;
        }
        ListNode *del = slow->next;
        slow->next = slow->next->next;
        delete del;
        return head;
    }
};

int main()
{

    return 0;
}