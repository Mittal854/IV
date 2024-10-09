// reverse linked link
// #include <iostream>
// #include <stack>
// using namespace std;

// class Node
// {
// public:
//     int data;
//     Node *next;
// };
// class LinkedList
// {
// private:
//     Node *first;

// public:
//     LinkedList()
//     {
//         first = NULL;
//     }
//     void create(int a[], int n)
//     {
//         Node *last = NULL, *p;
//         first = new Node;
//         first->data = a[0];
//         first->next = NULL;
//         last = first;

//         for (int i = 1; i < n; i++)
//         {
//             p = new Node;
//             p->data = a[i];
//             p->next = NULL;
//             last->next = p;
//             last = p;
//         }
//     }
//     void display()
//     {
//         Node *p = first;
//         while (p)
//         {
//             cout << p->data << " ";
//             p = p->next;
//         }
//     }
//     void reverseUsingStack()
//     {
//         Node *p = first;
//         stack<int> st;
//         int count = 0;
//         while (p)
//         {
//             st.push(p->data);
//             p = p->next;
//             count++;
//         }
//         first = NULL;
//         Node *last = NULL;
//         for (; count >= 0; count--)
//         {
//             Node *t = new Node;
//             t->data = st.top();
//             st.pop();
//             if (first == NULL)
//             {
//                 first = t;
//                 last = t;
//             }
//             else
//             {
//                 last->next = t;
//                 last = t;
//             }
//         }
//     }
// };

// int main()
// {

//     return 0;
// }
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class LinkedList
{
private:
    Node *first;

public:
    LinkedList()
    {
        first = NULL;
    }
    void create(int a[], int n)
    {
        Node *last = NULL, *p;
        first = new Node;
        first->data = a[0];
        first->next = NULL;
        last = first;

        for (int i = 1; i < n; i++)
        {
            p = new Node;
            p->data = a[i];
            p->next = NULL;
            last->next = p;
            last = p;
        }
    }
    void display()
    {
        Node *p = first;
        while (p)
        {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }
    void reverseUsingStack()
    {
        Node *p = first;
        stack<int> st;
        while (p)
        {
            st.push(p->data);
            p = p->next;
        }
        first = NULL;
        Node *last = NULL;
        while (!st.empty())
        {
            Node *t = new Node;
            t->data = st.top();
            t->next = NULL;
            st.pop();
            if (first == NULL)
            {
                first = t;
                last = t;
            }
            else
            {
                last->next = t;
                last = t;
            }
        }
        last->next = NULL;
    }

    void reverse(Node *p, Node *q)
    {
        while (p)
        {
            Node *t = p->next;
            p->next = q;
            q = p;
            p = t;
        }
        first = q;
    }

    void reverse1(Node *p, Node *q)
    {
        if (p)
        {
            reverse1(p->next, p);
            p->next = q;
        }
        else
            first = q;
    }
};

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    LinkedList l1;
    l1.create(arr, 5);
    l1.display();
    l1.reverseUsingStack();
    l1.display();

    return 0;
}