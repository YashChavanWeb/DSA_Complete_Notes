#include <bits/stdc++.h>
using namespace std;

/*

// Delete all the occurrences of a key in a Linked List


Approach
- we will be just taking a temp to traverse
- then a next and a previous pointer, and then we will change their links

- Time complexity -> O(N)
- Space complexity -> O(1)

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
        Node *newNode = new Node(arr[i], nullptr, previous);

        // once the node is created, also the previous link needs to be established
        previous->next = newNode;

        // move the prev to the node
        previous = newNode;
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

Node *delete_key_occurrences(Node *head, int key)
{

    // take temp to traverse
    Node *temp = head;
    // take next and prev to change the links
    Node *prevNode = NULL, *nextNode = NULL;

    while (temp)
    {
        if (temp->data == key)
        {
            // check if the deletion that we are making is at the head
            if (temp == head)
            {
                head = head->next;
            }

            // take the previous and the next nodes
            nextNode = temp->next;
            prevNode = temp->prev;

            // to deal with first and last node check for it it is null or not
            // because if not then it will throw the null pointer exception
            if (nextNode)
                nextNode->prev = prevNode;
            if (prevNode)
                prevNode->next = nextNode;

            delete temp;
            temp = nextNode;
        }
        else
        {
            temp = temp->next;
        }
    }

    return head;
}

int main()
{
    vector<int> arr = {10, 4, 10, 10, 6, 10};
    int key = 10;
    Node *head = arraytoDLL(arr);
    head = delete_key_occurrences(head, key);
    traverse_DLL(head);

    return 0;
}