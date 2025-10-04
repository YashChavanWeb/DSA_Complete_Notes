#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

static int idx = -1;
Node *buildTree(vector<int> preOrder)
{
    idx++;

    if (preOrder[idx] == -1)
        return NULL;

    Node *root = new Node(preOrder[idx]);
    root->left = buildTree(preOrder);
    root->right = buildTree(preOrder);

    return root;
}

int heightOfTree(Node *root)
{
    if (root == NULL)
        return NULL;

    int leftHeight = heightOfTree(root->left);
    int rightHeight = heightOfTree(root->right);

    return max(leftHeight, rightHeight) + 1;
}

int main()
{
    vector<int> preOrder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node *root = buildTree(preOrder);

    cout << heightOfTree(root);

    return 0;
}