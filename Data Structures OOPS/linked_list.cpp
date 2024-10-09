#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int value)
    {
        data = value;
        next = NULL;
    }
    Node(int value, Node *next1)
    {
        data = value;
        next = next1;
    }
};

int main()
{
    Node *head;
    Node *second;
    Node *third;
    head = new Node(3);
    second = new Node(5);
    third = new Node(4);
    head->next = second;
    second->next = third;
    Node *slow=head;
    Node *fast=head;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;

    }
    cout<<slow->data;
    return 0;
}