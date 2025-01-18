#include <bits/stdc++.h>
using namespace std;

/*

// Rotate a Linked List by k times

- we have to return the updated head after rotation
- the range of k can be anything not specific range



Approach

- first we will traverse till the end and connect its next to the head
- after tail is connected to head, go to the node of n - k
- after going to that node, we have to make it's next null
- but before that we also need to update the head, after that we can make that node -> next as null
- and we will get our rotated linked list

- what if the value of k is equal / larger than the length
    - if k is the multiple of the node then no need to do anything, we can simply return the head
    - if it is 13 then for 10 it will be the same as it is multiple, so we will just have to solve for 3 which we have done - no need to do 13

- Time complexity -> O(N + N) - traversal-tail  +  find-new-head
- Space complexity -> O(1)



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

Node *find_nth_node(Node *temp, int k)
{
    int cnt = 1;
    while (temp)
    {
        if (cnt == k)
            return temp;
        cnt++;
        temp = temp->next;
    }

    return temp;
}

Node *rotate_LL(Node *head, int k)
{

    // base case
    if (head == NULL || k == 0)
    {
        return head;
    }

    // calculate the length and also go to the tail
    Node *tail = head;
    int len = 1;

    while (tail->next != NULL)
    {

        len++;
        tail = tail->next;
    }

    // check if k is multiple of length
    if (k % len == 0)
    {
        return head;
    }

    // we will then rotate
    k = k % len; // incase k is larger than the length

    // also connect the next of tail to the head
    tail->next = head;

    Node *endNode = find_nth_node(head, len - k);

    // then just we will modify the links of the end node

    // update the head
    head = endNode->next;

    endNode->next = NULL;

    return head;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 2;

    Node *head = convert_array_to_LL(arr);

    head = rotate_LL(head, k);
    traverseLL(head);

    return 0;
}