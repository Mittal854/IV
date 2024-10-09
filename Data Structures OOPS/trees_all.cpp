#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <stack>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int d) : data(d), left(nullptr), right(nullptr) {}
};

Node *buildTree(vector<int> nodes)
{
    if (nodes.empty())
        return nullptr;

    int i = 0;
    Node *root = new Node(nodes[i++]);
    queue<Node *> q;
    q.push(root);

    while (!q.empty() && i < nodes.size())
    {
        Node *temp = q.front();
        q.pop();

        if (i < nodes.size())
        {
            if (nodes[i] != -1)
            {
                temp->left = new Node(nodes[i]);
                q.push(temp->left);
            }
            i++;
        }

        if (i < nodes.size())
        {
            if (nodes[i] != -1)
            {
                temp->right = new Node(nodes[i]);
                q.push(temp->right);
            }
            i++;
        }
    }
    return root;
}

void inorderTraversal(Node *root, vector<int> &values)
{
    if (root == nullptr)
        return;
    inorderTraversal(root->left, values);
    values.push_back(root->data);
    inorderTraversal(root->right, values);
}

Node *convertToBST(const vector<int> &values, int start, int end)
{
    if (start > end)
        return nullptr;

    int mid = start + (end - start) / 2;
    Node *root = new Node(values[mid]);

    root->left = convertToBST(values, start, mid - 1);
    root->right = convertToBST(values, mid + 1, end);

    return root;
}

Node *binaryTreeToBST(Node *root)
{
    vector<int> values;
    inorderTraversal(root, values);
    sort(values.begin(), values.end());
    return convertToBST(values, 0, values.size() - 1);
}

void levelorder(Node *root)
{
    if (root == nullptr)
        return;

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int levelSize = q.size();

        for (int i = 0; i < levelSize; ++i)
        {
            Node *current = q.front();
            q.pop();
            cout << current->data << " ";

            if (current->left)
                q.push(current->left);
            if (current->right)
                q.push(current->right);
        }
        cout << endl;
    }
}

int height(Node *root)
{
    if (root == nullptr)
        return 0;
    return max(height(root->left), height(root->right)) + 1;
}

int diameterUtil(Node *root, int &diameter)
{
    if (root == nullptr)
        return 0;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    diameter = max(diameter, leftHeight + rightHeight);

    return max(leftHeight, rightHeight) + 1;
}

int diameter(Node *root)
{
    int diameter = 0;
    diameterUtil(root, diameter);
    return diameter;
}

void topViewUtil(Node *root, int hd, int level, unordered_map<int, pair<int, int>> &map)
{
    if (root == nullptr)
        return;

    if (map.find(hd) == map.end() || map[hd].second > level)
    {
        map[hd] = {root->data, level};
    }

    topViewUtil(root->left, hd - 1, level + 1, map);
    topViewUtil(root->right, hd + 1, level + 1, map);
}

void topView(Node *root)
{
    unordered_map<int, pair<int, int>> map;
    topViewUtil(root, 0, 0, map);

    for (auto it = map.begin(); it != map.end(); ++it)
    {
        cout << it->second.first << " ";
    }
    cout << endl;
}

void printLeftViewUtil(Node *root, int level, int &maxLevel)
{
    if (root == nullptr)
        return;

    if (maxLevel < level)
    {
        cout << root->data << " ";
        maxLevel = level;
    }

    printLeftViewUtil(root->left, level + 1, maxLevel);
    printLeftViewUtil(root->right, level + 1, maxLevel);
}

void leftView(Node *root)
{
    int maxLevel = 0;
    printLeftViewUtil(root, 1, maxLevel);
    cout << endl;
}

void printRightViewUtil(Node *root, int level, int &maxLevel)
{
    if (root == nullptr)
        return;

    if (maxLevel < level)
    {
        cout << root->data << " ";
        maxLevel = level;
    }

    printRightViewUtil(root->right, level + 1, maxLevel);
    printRightViewUtil(root->left, level + 1, maxLevel);
}

void rightView(Node *root)
{
    int maxLevel = 0;
    printRightViewUtil(root, 1, maxLevel);
    cout << endl;
}

void printLeaves(Node *root)
{
    if (root == nullptr)
        return;

    if (!root->left && !root->right)
    {
        cout << root->data << " ";
    }

    printLeaves(root->left);
    printLeaves(root->right);
}

bool isBalanced(Node *root)
{
    if (root == nullptr)
        return true;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return abs(leftHeight - rightHeight) <= 1 && isBalanced(root->left) && isBalanced(root->right);
}

void printSpecificLevel(Node *root, int level)
{
    if (root == nullptr)
        return;
    if (level == 1)
    {
        cout << root->data << " ";
    }
    else if (level > 1)
    {
        printSpecificLevel(root->left, level - 1);
        printSpecificLevel(root->right, level - 1);
    }
}

void zigzagTraversal(Node *root)
{
    if (root == nullptr)
        return;

    stack<Node *> currentLevel;
    stack<Node *> nextLevel;
    bool leftToRight = true;

    currentLevel.push(root);

    while (!currentLevel.empty())
    {
        Node *node = currentLevel.top();
        currentLevel.pop();

        if (node)
        {
            cout << node->data << " ";

            if (leftToRight)
            {
                if (node->left)
                    nextLevel.push(node->left);
                if (node->right)
                    nextLevel.push(node->right);
            }
            else
            {
                if (node->right)
                    nextLevel.push(node->right);
                if (node->left)
                    nextLevel.push(node->left);
            }
        }

        if (currentLevel.empty())
        {
            leftToRight = !leftToRight;
            swap(currentLevel, nextLevel);
            cout << endl;
        }
    }
}

bool isComplete(Node *root)
{
    if (root == nullptr)
        return true;

    queue<Node *> q;
    q.push(root);
    bool flag = false;

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp)
        {
            if (flag)
                return false;

            q.push(temp->left);
            q.push(temp->right);
        }
        else
        {
            flag = true;
        }
    }
    return true;
}

Node *findLCA(Node *root, int n1, int n2)
{
    if (root == nullptr)
        return nullptr;

    if (root->data == n1 || root->data == n2)
        return root;

    Node *leftLCA = findLCA(root->left, n1, n2);
    Node *rightLCA = findLCA(root->right, n1, n2);

    if (leftLCA && rightLCA)
        return root;

    return (leftLCA != nullptr) ? leftLCA : rightLCA;
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
    cout << "Original Tree (Level Order):" << endl;
    levelorder(root);

    cout << "BST Tree (Level Order):" << endl;
    Node *bstRoot = binaryTreeToBST(root);
    levelorder(bstRoot);

    cout << "Height of the tree: " << height(root) << endl;
    cout << "Diameter of the tree: " << diameter(root) << endl;

    cout << "Top View: ";
    topView(root);
    cout << endl;

    cout << "Left View: ";
    leftView(root);

    cout << "Right View: ";
    rightView(root);

    cout << "Leaf Nodes: ";
    printLeaves(root);
    cout << endl;

    cout << "Is the tree balanced? " << (isBalanced(root) ? "Yes" : "No") << endl;

    int specificLevel;
    cout << "Enter level to print specific level nodes: ";
    cin >> specificLevel;
    cout << "Nodes at level " << specificLevel << ": ";
    printSpecificLevel(root, specificLevel);
    cout << endl;

    cout << "Zigzag Traversal: " << endl;
    zigzagTraversal(root);

    cout << "Is the tree complete? " << (isComplete(root) ? "Yes" : "No") << endl;

    int n1, n2;
    cout << "Enter two nodes to find their LCA: ";
    cin >> n1 >> n2;
    Node *lca = findLCA(root, n1, n2);
    if (lca != nullptr)
    {
        cout << "Least Common Ancestor of " << n1 << " and " << n2 << " is: " << lca->data << endl;
    }
    else
    {
        cout << "LCA does not exist for " << n1 << " and " << n2 << " in the tree." << endl;
    }

    return 0;
}
