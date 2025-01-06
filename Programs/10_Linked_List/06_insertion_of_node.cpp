#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int data1, Node *next1, Node *prev1)
    {
        data = data1;
        next = next1;
        prev = prev1;
    }

    Node(int data1)
    {
        data = data1;
        next = nullptr;
        prev = nullptr;
    }
};

Node *arr_to_DLL(vector<int> arr)
{
    if (arr.size() == 0)
    {
        return NULL;
    }

    Node *head = new Node(arr[0]);
    Node *prev = head;

    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i], nullptr, prev);

        // update the previous
        prev->next = temp;
        prev = temp;
    }

    return head;
}

void traverse_DLL(Node *head)
{
    Node *temp = head;

    while (temp)
    {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "null";
}

Node *insert_head(Node *head, int element)
{
    if (head == NULL)
    {
        return NULL;
    }

    Node *temp = head;
    Node *newNode = new Node(element, temp, nullptr);

    temp->prev = newNode;

    return newNode;
}

Node *insert_tail(Node *head, int element)
{
    if (head == NULL)
        return new Node(element);

    if (head->next == NULL)
    {
        Node *newNode = new Node(element, nullptr, head);
        head->next = newNode;
        return head;
    }

    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    Node *newNode = new Node(element, nullptr, temp);
    temp->next = newNode;
    return head;
}

Node *insert_position(Node *head, int element, int k)
{
    // base case: no DLL
    if (head == NULL)
    {
        if (k == 1)
        {
            Node *newNode = new Node(element);
            return newNode;
        }
    }

    // if position is 1
    if (k == 1)
    {
        Node *newNode = new Node(element, head, nullptr);
        head->prev = newNode;
        return newNode;
    }

    // if other position
    Node *temp = head;
    int cnt = 0;
    while (temp)
    {
        cnt++;
        if (cnt == k)
        {
            break;
        }

        temp = temp->next;
    }

    Node *back = temp->prev;

    // logic
    Node *newNode = new Node(element, temp, back);
    back->next = newNode;
    temp->prev = newNode;

    return head;
}

void insert_node(Node *node, int element)
{

    // we have a node given before which we have to insert the element
    // this node will never be equal to head

    Node *previous = node->prev;
    Node *newNode = new Node(element, node, previous);

    previous->next = newNode;
    node->prev = newNode;
}

int main()
{
    vector<int> arr = {20, 10, 7, 6};
    Node *head = arr_to_DLL(arr);
    // head = insert_head(head, 15);
    // head = insert_tail(head, 45);
    // head = insert_position(head, 27, 4);
    insert_node(head->next->next, 199);
    traverse_DLL(head);

    return 0;
}