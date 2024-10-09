#include <iostream>
#include <queue>
#include <algorithm>
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

node *buildtree(vector<int> nodes)
{
    if (nodes[0] == -1)
    {
        return NULL;
    }
    queue<node *> q;
    node *root = new node(nodes[0]);
    int i = 1;
    q.push(root);
    while (i < nodes.size())
    {
        node *temp = q.front();
        q.pop();
        if (i < nodes.size() && nodes[i] != -1)
        {
            temp->left = new node(nodes[i]);
            q.push(temp->left);
        }
        i++;
        if (i < nodes.size() && nodes[i] != -1)
        {
            temp->right = new node(nodes[i]);
            q.push(temp->right);
        }
        i++;
    }
    return root;
}
void levelorder(node *root)
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

void leftutil(node *root, int level, int &maxlevel, vector<int> &leftv)
{
    if (root == NULL)
    {
        return;
    }
    if (maxlevel < level)
    {
        leftv.push_back(root->data);
        maxlevel = level;
    }
    leftutil(root->left, level + 1, maxlevel, leftv);
    // leftutil(root->right, level + 1, maxlevel, leftv);
}
vector<int> left(node *root)
{
    int maxlevel = 0;
    vector<int> leftv;
    leftutil(root, 1, maxlevel, leftv);
    return leftv;
}

void rightutil(node *root, int level, int &maxlevel, vector<int> &rightv)
{
    if (root == NULL)
    {
        return;
    }
    if (maxlevel < level)
    {
        rightv.push_back(root->data);
        maxlevel = level;
    }
    rightutil(root->right, level + 1, maxlevel, rightv);
    // rightutil(root->left, level + 1, maxlevel, rightv);
}
vector<int> right(node *root)
{
    int maxlevel = 0;
    vector<int> rightv;
    rightutil(root, 1, maxlevel, rightv);
    return rightv;
}

void topview(node *root)
{
    vector<int> left1 = left(root);
    vector<int> right1 = right(root);
    reverse(left1.begin(), left1.end());
    left1.pop_back();
    for (int i = 0; i < left1.size(); i++)
    {
        cout << left1[i] << " ";
    }
    for (int i = 0; i < right1.size(); i++)
    {
        cout << right1[i] << " ";
    }
}

int main()
{
    int n;
    cin >> n;
    int count = 0;
    vector<int> nodes;
    while (count < n)
    {
        int data;
        cin >> data;
        if (data != -1)
            count++;
        nodes.push_back(data);
    }
    node *root = buildtree(nodes);
    levelorder(root);
    vector<int>left2=left(root);
    vector<int>right2=right(root);
    topview(root);
    return 0;
}