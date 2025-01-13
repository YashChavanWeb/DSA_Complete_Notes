#include <bits/stdc++.h>
using namespace std;

/*

// Detect a Loop or a cycle in a singly Linked list

- if there exits a minimum of 1 node where you start and reach back then we can say that linked list has a loop



1. Brute force Approach

- we will store the count of visiting the node
- for that we will use a hashmap, and when count is more than 1 then we can say that LL has a loop

- Time complexity -> O(N + 2*logN) - Traverse + map operations
- Space complexity -> O(N)







2. Optimal Approach

- we will be using the tortoise and the hair approach
- we will move the slow pointer once and the fast pointer twice
- if they meet at any node, then it means that there is a loop in the LL

if we have a linear linked list, even or odd nodes, then the stop condition will be any of one reaches fast->next == NULL or fast==NULL

- why will they not cross over? How are we so sure that they will collide?

- if fast is moving by 2 and slow is moving by 1, and fast is moving towards slow
- if their distance is d then after an operation the distance between fast and slow will become d-1
- and so it will go on decreasing to 0 and they will finally collide
- because the difference in the distance is 1 (fast 2 - slow 1 = 1) that is why we can reach 0

- Time complexity -> O(N)
= Space complexity -> O(1)



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

bool detect_loop_brute(Node *head)
{

    // store the occurrences of the node
    map<Node *, int> mpp;
    Node *temp = head;

    while (temp)
    {
        // as the LL can be linear as well so this condition in while

        if (mpp.find(temp) != mpp.end())
        {
            return true;
        }

        // store the occurrence of node in the hashmap
        mpp[temp] = 1;

        temp = temp->next;
    }

    return false;
}

bool detect_loop_optimal(Node *head)
{

    // consider the fast and slow pointers
    Node *fast = head, *slow = head;

    // start the traversal
    while (fast->next != NULL && fast != NULL)
    {
        // move the pointers
        fast = fast->next->next;
        slow = slow->next;

        // write condition after moving as head so they will be on same node initially

        // have a check if they are meeting
        if (fast == slow)
        {
            return true;
        }
    }

    return false;
}

int main()
{

    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    Node *head = convert_array_to_LL(arr);

    // make a loop in the linked list
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = head->next->next;
    // traverseLL(head);

    // bool result = detect_loop_brute(head);
    bool result = detect_loop_optimal(head);
    if (result)
    {
        cout << "The LL has a loop";
    }
    else
    {
        cout << "The LL does not have a Loop";
    }

    return 0;
}