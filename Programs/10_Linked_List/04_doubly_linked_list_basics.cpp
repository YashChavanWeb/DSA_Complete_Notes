#include <bits/stdc++.h>
using namespace std;

/*

// Doubly Linked List Basics


// What is DLL?
- in doubly linked list we also store the previous pointer
- the previous pointer points to the address of the previous node


// Representation in C++ and java
- just we have to add a prev pointer in the struct
- and in the constructor also just add a parameter prev1


// Array to DLL
- first we will create the head
- then we with the help of previous pointer create the other elements


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

int main()
{

    vector<int> arr = {32, 41, 55, 26, 77};

    Node *head = arraytoDLL(arr);
    traverseDLL(head);

    return 0;
}