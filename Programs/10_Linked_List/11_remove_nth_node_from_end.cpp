#include <bits/stdc++.h>
using namespace std;

/*

// Remove the nth node from the end of the linked list

- we are given the head of the linked list and also value of N
- we have to delete the Nth node from the back of the linked list



1. Brute force Approach

- take a temp and and a cnt variable that counts the length of the linked list
- so if n=2 then I have to reach to the 3rd node in order to break the links
- so node we want to reach is count - n

- after traversing for the length, we once again traverse to reach to the node

- Time complexity -> O(Len + Len-n) -> O(2*len)
- Space complexity -> O(1)

Note: the delete we have to only do in c++ as in Java, the garbage collector helps





2. Optimal Approach

- we are computing the length for going to the node previous of the deleting node
- this operation can be optimized by taking a fast and a slow pointer
- we will place the fast pointer n places from the head and the slow pointer on the head
- then we will will move the fast and slow pointer together
- when the fast pointer moves to the end then the slow pointer moves to the node before the nth node from the back

- this happened as we started the fast two steps ahead
- so this will work for all the cases, except for n = length of the linked list

- Time Complexity -> O(len) -> how much did the fast pointer moved
- Space Complexity -> O(1)


*/

// creating the class
class Node
{
public:
    int data;
    Node *next;

public:
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

// function to convert array to linked list
Node *convert_array_to_LL(vector<int> arr)
{
    // first initialize the head with the first element
    Node *head = new Node(arr[0]);

    // then we will create a mover that initially points to head
    Node *mover = head;

    // traverse from 1st till the end
    for (int i = 1; i < arr.size(); i++)
    {
        // initialize the temp with the new element
        Node *temp = new Node(arr[i]);

        // update the mover's next to the temp
        mover->next = temp;

        // also now move the mover to the next position to follow the same process
        mover = temp;
    }

    // just return head later then can traverse the entire linked list
    return head;
}

void traverseLL(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "null";
}

Node *remove_nth_node_brute(Node *head, int n)
{
    // first take a temp and cnt and find the length of the linked list
    int cnt = 0;
    Node *temp = head;

    while (temp)
    {
        cnt++;
        temp = temp->next;
    }

    // when we have the length of the linked list, then we traverse again till the second last of the given counter

    // also we have an edge case of the first node
    if (n == cnt)
    {
        // this means that we have to delete the first node
        Node *newhead = head->next;
        delete head;

        return newhead;
    }

    temp = head;
    int res = cnt - n;

    while (temp)
    {
        res--;

        // this means that we are at the back node of the deleting one
        // so we break here
        if (res == 0)
            break;

        temp = temp->next;
    }

    // first save the node we are deleting
    Node *deleteNode = temp->next;

    // also attach the link properly
    temp->next = temp->next->next;

    // and then finally free the space
    delete deleteNode;

    return head;
}

Node *remove_nth_node_optimal(Node *head, int n)
{

    // first we will take the fast and slow pointers
    Node *fast = head;
    for (int i = 0; i < n; i++)
    {
        fast = fast->next;
    }

    Node *slow = head;

    // but after this what if fast is pointing to null
    // this means that the entire list is traversed and we are at the end
    // so that means we have to delete the head of the linked list
    if (fast == NULL)
    {
        // delete the head
        Node *deleteNode = head;
        head = head->next;
        delete deleteNode;

        return head;
    }

    // then until fast reaches the last node we will move both fast and slow pointers
    while (fast->next != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }

    // here it means that our slow pointer is pointing to the node before the node we want to delete
    // store the node
    Node *deleteNode = slow->next;
    // update the link
    slow->next = slow->next->next;
    // delete the link
    delete deleteNode;

    return head;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};

    Node *head = convert_array_to_LL(arr);

    // head = remove_nth_node_brute(head, 1);
    head = remove_nth_node_optimal(head, 4);
    traverseLL(head);

    return 0;
}