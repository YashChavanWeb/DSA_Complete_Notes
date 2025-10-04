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

int main()
{
    vector<int> preOrder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node *root = buildTree(preOrder);
    cout << root->data << endl;
    cout << root->left->data << endl;
    cout << root->right->data << endl;

    return 0;
}