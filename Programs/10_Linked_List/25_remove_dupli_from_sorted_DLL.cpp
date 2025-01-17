#include <bits/stdc++.h>
using namespace std;

/*

// Remove Duplicates from a sorted Linked Lists

- so we have to just keep single occurrences and remove the duplicates


Approach

- we will keep a temp pointer
- then next node that will traverse from temp->next to identify duplicates
- as the DLL is sorted, so the nextNode can be started from temp->next
- we will move next node until next unique node, and once we get then we will alter the next and prev links fo temp and newNode
- follow this cycle everytime


- Time complexity -> O(N) - while for duplicates + while for unique - len of DLL
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

Node *remove_duplicates(Node *head)
{

    // first consider the temp
    Node *temp = head;

    while (temp != NULL && temp->next != NULL)
    {

        // first declare the nextNode
        Node *nextNode = temp->next;

        // traverse the next node till unique
        while (nextNode != NULL && nextNode->data == temp->data)
            if (nextNode->data == temp->data)
            {
                Node *back = nextNode;
                nextNode = nextNode->next;
                delete back;
            }

        // after that if we get unique then we can just modify the links
        temp->next = nextNode;
        nextNode->prev = temp;

        // after we connect the links simply move the temp pointer
        temp = temp->next;
    }

    return head;
}

int main()
{
    vector<int> arr = {1, 1, 1, 2, 3, 3, 4};
    Node *head = arraytoDLL(arr);

    head = remove_duplicates(head);
    traverse_DLL(head);

    return 0;
}