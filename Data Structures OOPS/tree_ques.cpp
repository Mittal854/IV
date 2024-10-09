#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
    Node(int d)
    {
        data = d;
        left = right = NULL;
    }
};

Node *buildtree(vector<int> nodes, Node *root)
{
    int i = 0;
    queue<Node *> q;
    root = new Node(nodes[i]);
    i++;
    q.push(root);
    while (!q.empty() && i < nodes.size())
    {
        Node *temp = q.front();
        q.pop();

        if (i < nodes.size())
        {
            temp->left = new Node(nodes[i]);
            i++;
            q.push(temp->left);
        }
        if (i < nodes.size())
        {
            temp->right = new Node(nodes[i]);
            i++;
            q.push(temp->right);
        }
    }
    return root;
}

void printtree(Node *root)
{
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
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

int height(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int lh = height(root->left);
    int rh = height(root->right);
    int h = max(lh, rh) + 1;

    return h;
}

int diameter(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int lh = height(root->left);
    int rh = height(root->right);
    int dl = diameter(root->left);
    int dr = diameter(root->right);

    return max(max(dl, dr), rh + lh + 1);
}

void leftView(Node *root, vector<int> &l)
{

    if (root == NULL)
        return;
    cout << root->data << " ";
    l.push_back(root->data);
    leftView(root->left, l);
}

void rightView(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    rightView(root->right);
}

void topView(Node *root, vector<int> &l)
{
    for (int i = l.size() - 1; i < l.size(); i--)
    {
        cout << l[i] << " ";
    }
    rightView(root->right);
}

void printLevel(Node *root, int level)
{
    if (root == NULL)
    {
        return;
    }
    if (level == 1)
    {
        cout << root->data << " ";
        return;
    }
    else if (level > 1)
    {
        printLevel(root->left, level - 1);
        printLevel(root->right, level - 1);
    }
}

void printLeafNodes(Node *root)
{
    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL)
    {
        cout << root->data << " ";
        return;
    }
    if (root->left != NULL)
        printLeafNodes(root->left);

    if (root->right != NULL)
        printLeafNodes(root->right);
}

Node *LCA(Node *root, int n1, int n2)
{
    if (root == NULL)
        return NULL;

    // If either n1 or n2 matches the root's data, then the root is the LCA
    if (root->data == n1 || root->data == n2)
        return root;

    // Recur for left and right subtrees
    Node *left_lca = LCA(root->left, n1, n2);
    Node *right_lca = LCA(root->right, n1, n2);

    // If one node is found in left subtree and the other in right subtree,
    // then the root is the LCA
    if (left_lca && right_lca)
        return root;

    // Otherwise, the LCA is in either the left subtree or the right subtree
    return (left_lca != NULL) ? left_lca : right_lca;
}

int main()
{
    int n;
    int level;
    cout << "Which level?? :";
    cin >> level;
    cin >> n;
    vector<int> l;
    vector<int> nodes(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nodes[i];
    }

    Node *root = NULL;
    root = buildtree(nodes, root);

    printtree(root);

    cout << "\nHeight: " << height(root);

    cout << "\nDiameter: " << diameter(root);

    cout << "\nLeft View:";
    leftView(root, l);

    cout << "\nRight View:";
    rightView(root);

    cout << "\nTop View:";
    topView(root, l);

    cout << "\nElements at given level: ";
    printLevel(root, level);

    cout << "\nLeaf Nodes : ";
    printLeafNodes(root);

    cout << "\nEnter elements to check for LCA";
    int n1, n2;
    cin >> n1 >> n2;
    Node *lca_node = LCA(root, n1, n2);
    if (lca_node != NULL)
    {
        cout << "Lowest Common Ancestor of " << n1 << " and " << n2 << " is: " << lca_node->data << endl;
    }
    else
    {
        cout << "Lowest Common Ancestor does not exist!" << endl;
    }
}