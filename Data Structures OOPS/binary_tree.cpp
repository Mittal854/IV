#include <iostream>
#include <queue>
using namespace std;

class node
{

public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        data = d;
        left = right = NULL;
    }
};

node *buildtree(node *root)
{
    int data;
    cout << "Enter data:";
    cin >> data;
    cout << endl;
    root = new node(data);
    if (data == -1)
    {
        return NULL;
    }
    cout << "Enter the data for left of " << data << endl;
    root->left = buildtree(root->left);
    cout << "Enter the data for right of " << data << endl;
    root->right = buildtree(root->right);

    return root;
}

void *buildtree2(node *&root)
{
    queue<node *> q;
    int data;
    cout << "Enter data for root: ";
    cin >> data;
    root = new node(data);
    q.push(root);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        int leftdata, rightdata;
        cout << endl
             << "Enter data for left of " << temp->data << endl;
        cin >> leftdata;
        cout << endl
             << "Enter data for right of " << temp->data << endl;
        cin >> rightdata;
        if (leftdata != -1)
        {
            temp->left = new node(leftdata);
            q.push(temp->left);
        }
        if (rightdata != -1)
        {
            temp->right = new node(rightdata);
            q.push(temp->right);
        }
    }
}

void printtree(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {

        node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";

            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

void inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void preorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main()
{
    node *root = NULL;
    buildtree2(root);

    cout << "Binary Tree" << endl;
    printtree(root);
    cout << "Inorder Traversal" << endl;
    inorder(root);
    cout << endl;
    cout << "Preorder Traversal" << endl;
    preorder(root);
    cout << endl;
    cout << "Postorder Traversal" << endl;
    postorder(root);
    // 1 2 4 -1 -1 -1 3 5 -1 -1 6 -1 -1
    return 0;
}