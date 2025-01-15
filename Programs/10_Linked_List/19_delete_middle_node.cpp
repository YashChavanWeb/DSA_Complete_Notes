#include <bits/stdc++.h>
using namespace std;

/*

// Delete the middle node of the linked list

- in case of even, delete the second middle




1. Brute force

- find out length of LL
- traverse till N/2 in LL (integer)

- Time complexity O(N + N/2) -> traverse + traverse to mid
- Space complexity -> O(1)




2. Optimal Approach

- we want a one pass solution
- we will find the middle node using the tortoise and hair solution
- we we have to stand at the node that is before the middle node
- so for that we have to skip one step of slow

- Time complexity -> O(N/2)
- Space complexity -> O(N)





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

Node *delete_middle_brute(Node *head)
{

    // base case
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    // initially consider temp to find the length
    Node *temp = head;
    int len = 0;

    while (temp)
    {
        len++;
        temp = temp->next;
    }

    // now we traverse till the mid with the help of the length/2
    int mid = len / 2;
    temp = head;
    while (temp)
    {
        mid--;

        // we have reached the node before the mid node
        if (mid == 0)
        {
            Node *middleNode = temp->next;
            // update the link
            temp->next = temp->next->next;
            delete middleNode;

            break;
        }

        temp = temp->next;
    }

    return head;
}

Node *delete_middle_optimal(Node *head)
{
    // write the base case
    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }

    // take the slow and fast pointer
    Node *slow = head, *fast = head;

    // skip one step for slow
    fast = fast->next->next;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    // now here slow will be pointing to the before middle node
    Node *middleNode = slow->next;
    slow->next = slow->next->next;
    delete middleNode;

    return head;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4};
    Node *head = convert_array_to_LL(arr);
    // traverseLL(head);

    // head = delete_middle_brute(head);
    head = delete_middle_optimal(head);
    traverseLL(head);

    return 0;
}