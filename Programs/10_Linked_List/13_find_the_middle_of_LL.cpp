#include <bits/stdc++.h>
using namespace std;

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

/*

// To find the middle node of the linked list

- if the length of the LL is odd then it is easy to give the middle element
- if the length of LL is even then we  have to return the 2nd node contributing to the middle





1. Brute force approach

- first we find the length of the linked list
- then if we know the length of it then the middle node is n/2 + 1
- for finding the length we will be using the traversal technique
- then we will go on finding till the mid, so mid counter when turns zero then that is the middle node

- Time complexity -> O(N + N/2)
- Space complexity -> O(1)






2. Optimal Approach (Tortoise and the Hare Algorithm)

- we will take a slow and a fast pointer pointing to the head
- we will move the fast twice and slow once simultaneously
- the moment the fast pointer reaches the last node, we can say that the slow pointer is at the middle node

- in case of even linked list the fast pointer will point to the null
- so if fast pointer is at the end or at the null then we can return the slow pointer as it is pointing to the middle node

- Logic
if P1 is traveling with speed x and P2 is traveling with speed x/2
then if P1 covers n distance then P2 will cover n/2 distance

- Time complexity -> O(N/2)
- Space complexity -> O(1)



*/

Node *find_middle_brute(Node *head)
{

    // first find the length of the linked list
    Node *temp = head;
    int cnt = 0;
    while (temp)
    {
        cnt++;
        temp = temp->next;
    }

    // get the middle of the length
    int mid = cnt / 2 + 1;
    temp = head;
    while (temp)
    {
        // first decrement if temp is valid
        mid--;

        // then check if mid is zero as temp will point to the middle node in the case
        if (mid == 0)
        {
            break;
        }

        // else move the temp
        temp = temp->next;
    }
    return temp;
}

Node *find_middle_optimal(Node *head)
{

    // two pointers fast and slow
    Node *fast = head, *slow = head;

    while (fast != NULL && fast->next != NULL)
    {
        // if fast is null then it means odd length LL
        // if fast->next is null then it means even length LL
        fast = fast->next->next;
        slow = slow->next;
    }

    // after this the slow will be poinitng to the middle Node
    return slow;
}

int main()
{
    vector<int> arr = {1, 2, 4, 3, 5};
    Node *head = convert_array_to_LL(arr);

    // Node *middleNode = find_middle_brute(head);
    Node *middleNode = find_middle_optimal(head);
    cout << "The middle node is " << middleNode->data;

    return 0;
}