#include <bits/stdc++.h>
using namespace std;

/*

// Delete a node in doubly linked list
- head
- tail
- position
- element - element will not be head

*/

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

Node *arraytoDLL(vector<int> arr)
{

    // initially head will be created
    Node *head = new Node(arr[0]);

    // also maintain a prev pointer pointing to the head
    Node *previous = head;

    for (int i = 1; i < arr.size(); i++)
    {
        // now first we will create Node
        // for this we maintain the previous pinter
        Node *newNode = new Node(arr[i], nullptr, previous);

        // once the node is created, also the previous link needs to be established
        previous->next = newNode;

        // once the node is created we can move the prev to the node
        previous = newNode;
    }

    return head;
}

void traverseDLL(Node *head)
{
    Node *temp = head;

    while (temp)
    {
        cout << temp->data << "<-> ";
        temp = temp->next;
    }
    cout << "null";
}

Node *delete_head(Node *head)
{
    // if there is no element or single element
    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }

    Node *temp = head;

    // move the head by one position
    head = head->next;

    temp->next = nullptr;
    head->prev = nullptr;

    delete temp;

    return head;
}

Node *delete_tail(Node *head)
{
    // edge case
    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }

    // for the other cases
    Node *temp = head;

    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }

    temp->next->prev = nullptr;
    temp->next = nullptr;

    delete temp->next;

    return head;
}

Node *delete_position(Node *head, int k)
{
    if (head == NULL)
    {
        return NULL;
    }

    // first let's reach on the node which we have to delete
    Node *temp = head;

    int cnt = 0;
    while (temp)
    {
        cnt++;

        // stop when the count is equal to k which means we are on the element that we want to delete
        if (cnt == k)
        {
            break;
        }

        temp = temp->next;
    }

    // now here we are standing at the element which we want to delete
    // find its back and front element

    Node *back = temp->prev;
    Node *front = temp->next;

    // now that we have the front and the back, we can arise with 3 conditions

    // Condition 1: single element in the linked list
    if (back == NULL && front == NULL)
    {
        // this means that there is single element in the linkedlist

        delete head;
        return NULL;
    }

    // Condition 2: delete the first element in the linked list
    else if (back == NULL)
    {
        head = head->next;

        head->prev = nullptr;
        temp->next = nullptr;

        delete temp;

        return head;
    }

    // Condition 3: delete the last element in the linked list
    else if (front == NULL)
    {
        temp->prev = nullptr;
        back->next = nullptr;

        delete temp;

        return head;
    }

    // Condition 3: delete the element in the position
    else
    {

        back->next = front;
        front->prev = back;

        temp->next = nullptr;
        temp->prev = nullptr;

        delete temp;

        return head;
    }
}

void delete_node(Node *temp)
{

    // we will never be told to delete the head

    Node *back = temp->prev;
    Node *front = temp->next;

    // condition 1 : if it is the last element
    if (front == NULL)
    {
        back->next = nullptr;
        temp->prev = nullptr;
        delete temp;

        return;
    }

    // condition 2: if the element is in the middle
    back->next = front;
    front->prev = back;

    temp->next = nullptr;
    temp->prev = nullptr;

    delete temp;

    return;
}

int main()
{
    vector<int> arr = {32, 41, 55, 26, 77};

    Node *head = arraytoDLL(arr);

    // head = delete_head(head);
    // head = delete_tail(head);
    // head = delete_position(head, 3);
    delete_node(head->next->next);
    traverseDLL(head);

    return 0;
}