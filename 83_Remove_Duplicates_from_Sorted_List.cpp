// Remove Duplicates from Sorted List
#include <iostream>
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* superHead = new ListNode;
        superHead = head;
        if (head != nullptr) {
            ListNode* ptr = new ListNode;
            ptr = head->next;
            while (ptr != nullptr) {
                if (head->val == ptr->val) {
                    ptr = ptr->next;
                    if (ptr == nullptr) {
                        head->next = ptr;
                    }
                } else {
                    head->next = ptr;
                    ptr = ptr->next;
                    head = head->next;
                }
            }
            delete ptr;
        }
        head = superHead;
        return head;
    }
};

int main()
{
    Solution obj;
    ListNode *head;
    head = new ListNode;
    head = link_insert(head, 1);
    head = link_insert(head, 2);
    head = link_insert(head, 3);
    head = link_insert(head, 3);
    head = link_insert(head, 4);
    head = link_insert(head, 5);
    link_tra(head);

    head = obj.deleteDuplicates(head);
    link_tra(head);
    return 0;
}