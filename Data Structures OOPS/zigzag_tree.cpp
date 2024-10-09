#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        data = d;
        left = right = NULL;
    }
};

Node *buildTree(vector<int> nodes)
{
    if (nodes[0] == -1)
    {
        return NULL;
    }
    int i = 0;
    queue<Node *> q;
    Node *root = new Node(nodes[i++]);
    q.push(root);
    while (i < nodes.size())
    {
        Node *temp = q.front();
        q.pop();
        if (i < nodes.size() && nodes[i] != -1)
        {
            temp->left = new Node(nodes[i]);
            q.push(temp->left);
        }
        i++;
        if (i < nodes.size() && nodes[i] != -1)
        {
            temp->right = new Node(nodes[i]);
            q.push(temp->right);
        }
        i++;
    }
    return root;
}

void levelorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *temp = q.front();
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

vector<vector<int>> zigzag(Node *root)
{
    if (root == NULL)
    {
        return {};
    }
    vector<vector<int>> zigzag;
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    vector<int> a;
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            zigzag.push_back(a);
            a.clear();
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            a.push_back(temp->data);
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
    for (int i = 0; i < zigzag.size(); i++)
    {
        if (i % 2 != 0)
        {
            reverse(zigzag[i].begin(), zigzag[i].end());
        }
    }
    return zigzag;
}

Node *bst(vector<int> &nodes, int start, int end)
{
    if (start > end)
    {
        return NULL;
    }
    int mid = start + (end - start) / 2;
    Node *root = new Node(nodes[mid]);
    root->left = bst(nodes, start, mid - 1);
    root->right = bst(nodes, mid + 1, end);

    return root;
}

int main()
{
    int n;
    cin >> n;
    vector<int> nodes(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nodes[i];
    }
    Node *root = buildTree(nodes);
    levelorder(root);
    sort(nodes.begin(), nodes.end());
    Node *root1 = bst(nodes, 0, nodes.size() - 1);
    levelorder(root1);
    vector<vector<int>> zig = zigzag(root);
    for (int i = 0; i < zig.size(); i++)
    {
        for (int j = 0; j < zig[i].size(); j++)
        {
            cout << zig[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}