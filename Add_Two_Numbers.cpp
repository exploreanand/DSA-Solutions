// Add_Two_Numbers
#include <iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
};
void link_tra(ListNode *head)
{
    while (head != NULL)
    {
        cout << head->val
             << " ";
        head = head->next;
    }
}

void insert_bw(ListNode *head, int a, int index)
{
    for (int i = 0; i < index - 1; i++)
    {
        head = head->next;
    }
    ListNode *ptr = new ListNode;
    ptr->val = a;
    ptr->next = head->next;
    head->next = ptr;
}

ListNode *link_insert(ListNode *head, int a)
{
    ListNode *ptr = new (ListNode);
    ptr->val = a;
    ptr->next = head;
    return ptr;
}

void insert_end(ListNode *head, int a)
{
    while ((head->next) != NULL)
    {
        head = head->next;
    }
    ListNode *ptr = new ListNode;
    ptr->val = a;
    head->next = ptr;
    ptr->next = NULL;
}

void insert_after_node(ListNode *prevNode, int a)
{
    ListNode *ptr = new ListNode;
    ptr->val = a;
    ptr->next = prevNode->next;
    prevNode->next = ptr;
}
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *result = new ListNode;
        string str1, str2;
        while (l1 != nullptr)
        {
            int i = 0;
            str1[i] = l1->val;
            i++;
            l1 = l1->next;
        }
        cout << str1 << endl;
        return 0;
    }
};
int main()
{
    Solution *l1;
    Solution *l2;
    ListNode *head;
    head = new ListNode;
    head = link_insert(head, 1);
    head = link_insert(head, 2);
    head = link_insert(head, 3);
    head = link_insert(head, 3);
    head = link_insert(head, 4);
    head = link_insert(head, 5);
    link_tra(head);

    string str1, str2;
    int i = 0;
    while (head != NULL)
    {
        str1[i] = (head->val);
        i++;
        head = head->next;
    }
    cout << str1 << endl;

    return 0;
}