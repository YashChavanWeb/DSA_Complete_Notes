#include <bits/stdc++.h>
using namespace std;

/*

// Reveres a doubly linked list

Head of a doubly linked list will be given, and we have to return the reversed doubly linked list


1. Brute force approach

- we can push the data of the linked list into the stack
- and then place it back into the linked list
- as the stack is LIFO data structure, so the data will be reversed when we again place it

- Time complexity -> O(n+n) = O(2n)
- Space complexity -> O(n) - as we are using the stack





2. Optimal Approach

- we can do this in single pass
- we have to just swap the prev and the next pointers of each node
- and for moving forward, apparently we will have to call the back and not the next

- Time complexity -> O(n)
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
        // for this we maintain the previous pinter
        Node *newNode = new Node(arr[i], nullptr, previous);

        // once the node is created, also the previous link needs to be established
        previous->next = newNode;

        // once the node is created we can move the prev to the node
        previous = newNode;
    }

    return head;
}

void traverse_DLL(Node *head)
{

    // traversing the entire linkedlist
    Node *temp = head;

    while (temp)
    {
        // run until temp is not equal to null
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "null";
}

Node *reveres_DLL_brute(Node *head)
{
    // declare stack
    stack<int> st;

    Node *temp = head;
    // first pass to push all the elements in the stack
    while (temp)
    {
        st.push(temp->data);
        temp = temp->next;
    }

    // second pass to store the data back into the linked list
    // it is LIFO

    Node *temp1 = head;
    while (temp1)
    {
        temp1->data = st.top();
        st.pop();
        temp1 = temp1->next;
    }

    return head;
}

Node *reverse_DLL_optimal(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        // this means that it is a single element
        // and single element cannot be reversed so return it as it is
        return head;
    }

    // now consider a back pointer that keeps track of the back node
    Node *back = NULL;

    // also consider temp to traverse
    Node *temp = head;
    while (temp)
    {
        // here we will swap the pointers - 2<->5 - temp is on 5
        back = temp->prev;
        temp->prev = temp->next; // we swap the temp prev 2->5
        temp->next = back;       // we also swap the temp next 2<-5

        // now to move to the ahead locations, as the pointer of the back is ahead now
        temp = temp->prev;
    }

    // now with this the back will be pointing to the second last and the temp will be at the null after end
    // so to return the new head we have to return the tail
    // so we will simply return the back->next

    return back->prev;
}

int main()
{
    vector<int> arr = {21, 2, 3, 12};
    Node *head = arraytoDLL(arr);

    // head = reveres_DLL_brute(head);
    head = reverse_DLL_optimal(head);
    traverse_DLL(head);

    return 0;
}