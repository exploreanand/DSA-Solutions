#include <iostream>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (!head)
            return nullptr;
        
        Node* curr = head;

        while(curr){
            Node* copy = new Node(curr->val);
            copy->next = curr->next;
            curr->next = copy;
            curr = copy->next;
        }

        curr = head;
        while(curr){
            if(curr->random)
                curr->next->random = curr->random->next;
            curr = curr->next->next;
        }
         
        curr = head;
        Node* copy_head = head->next;
        while(curr){
            Node* copy = curr->next;
            curr->next = copy->next;
            if(copy->next)
                copy->next = copy->next->next;
            curr = curr->next;
        }
        return copy_head;
    }
};

int main()
{

    return 0;
}