#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }

    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

/*

// Deletion of a node in linked list
4 types
Deletion of the:
- head
- end
- position
- value




*/

Node *convert_arr_to_LL(vector<int> arr)
{
    if (arr.size() == 0)
    {
        return NULL;
    }

    Node *head = new Node(arr[0]);

    Node *mover = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = mover->next;
    }
    return head;
}

void traverse_LL(Node *head)
{
    Node *temp = head;

    while (temp)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "null";
}

Node *delete_head(Node *head)
{
    // base condition
    if (head == NULL)
        return head;

    // point temp to the head
    Node *temp = head;

    // move the head to the next pointer
    head = head->next;

    // delete / free the temp
    // delete temp;
    free(temp); // both can be used

    // return the new head
    return head;
}

Node *delete_tail(Node *head)
{

    // base case
    if (head == NULL || head->next == NULL)
    {
        // here the linked list has no element or single element
        // so we return null
        return NULL;
    }

    // traverse till the second last position of the linkedlist
    Node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }

    // first we will free the tail node
    delete temp->next;

    // then the temp will point to null
    temp->next = nullptr;

    return head;
}

Node *delete_position(Node *head, int k)
{
    if (head == NULL)
        return head;

    if (k == 1)
    {
        // this means we have to delete the first Node
        Node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    // this means that k is more than 1
    int cnt = 0;
    Node *temp = head;

    Node *previous = NULL;
    while (temp)
    {
        // until temp reaches end we will traverse
        cnt++;
        if (cnt == k)
        {
            // we are on the position
            previous->next = previous->next->next;
            delete temp;
            break;
        }

        // if we are just traversing then just move the pointers
        previous = temp;
        temp = temp->next;
    }
    return head;
}

Node *delete_element(Node *head, int element)
{
    // base condition
    if (head == NULL)
        return head;

    // if the linked list is the first element
    if (head->data == element)
    {
        Node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    Node *temp = head;
    Node *previous = NULL;

    while (temp)
    {
        if (temp->data == element)
        {
            previous->next = previous->next->next;
            free(temp);
            break;
        }
        previous = temp;
        temp = temp->next;
    }

    return head;
}

int main()
{
    vector<int> arr = {12, 1, 3, 4, 23};

    Node *head = convert_arr_to_LL(arr);
    // traverse_LL(head);

    // head = delete_head(head);
    // head = delete_tail(head);
    // head = delete_position(head, 5);
    // head = delete_element(head, 12);
    traverse_LL(head);

    return 0;
}