#include <bits/stdc++.h>
using namespace std;

/*

// Find the length of the loop in the Linked List

- we will use the same concept of detection of the loop





1. Brute force approach

- we will just keep a timer that will travel the Linked list
- and if we travel a node more than once, then we can do timer - value which gives us the length

- Time complexity -> O(N *(2*logN))
- Space Complexity -> O(N)





2. Optimal Approach

- here once slow and fast pointer collide then we can say that there is a loop in the LL
- so after they collide, we will move one pointer, it will cover the entire loop and then come back again
- in this way we will get the length of the loop

- Time complexity -> O(N + N) -> O(2N)
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

int find_length_brute(Node *head)
{
    // first we will take a map, temp and timer
    map<Node *, int> mpp;
    Node *temp = head;
    int timer = 1;

    while (temp)
    {
        if (mpp.find(temp) != mpp.end())
        {

            // here is where we get the value and then return the diff if we visit same node again
            int val = mpp[temp];
            return timer - val;
        }

        // if not then we will traverse ahead
        mpp[temp] = timer;
        timer++;

        temp = temp->next;
    }

    // if linear LL then length will be 0
    return 0;
}

int lengOfLoop(Node *slowptr, Node *fastptr)
{
    int cnt = 1;
    fastptr = fastptr->next;

    while (fastptr != slowptr)
    {
        cnt++;
        fastptr = fastptr->next;
    }

    return cnt;
}

int find_length_optimal(Node *head)
{

    Node *fast = head, *slow = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (fast == slow)
        {
            return lengOfLoop(slow, fast);
        }
    }

    return 0;
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

    // int len = find_length_brute(head);
    int len = find_length_optimal(head);
    cout << "The length of the Loop is " << len;

    return 0;
}