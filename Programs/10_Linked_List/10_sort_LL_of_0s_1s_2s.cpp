#include <iostream>
#include <vector>
using namespace std;

/*

// Sort a Linked List of 0's, 1's, 2's

- we are given a linked list of the three and we have to sort it



1. Brute force Approach
- Traverse the list and count the number of 0's, 1's, 2's
- Traverse the original list and append the elements to the list by decrementing the counter

- Time complexity -> O(2n) - as we are traversing it twice
- Space complexity -> O(1)





2. Optimal Approach

- we have to do it in a single pass
- so we cannot use data replacement

- so we will take 3 lists and their heads as dummy nodes
- when we encounter their corresponding digit, eg 1 then we don't have to create a new node
- we just have to connect the link to the node of the 1 in the main linked list

- Time complexity -> O(N)
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
        // mover = mover->next;

        // or we can also write
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

Node *sortedLL_brute(Node *head)
{
    Node *temp = head;

    // first pass for counting the occurrences
    int cnt0 = 0, cnt1 = 0, cnt2 = 0;
    while (temp)
    {
        if (temp->data == 0)
            cnt0++;
        else if (temp->data == 1)
            cnt1++;
        else
            cnt2++;

        temp = temp->next;
    }

    // second pass to store the data
    temp = head;
    while (temp)
    {
        if (cnt0)
        {
            temp->data = 0;
            cnt0--;
        }
        else if (cnt1)
        {
            temp->data = 1;
            cnt1--;
        }
        else
        {
            temp->data = 2;
            cnt2--;
        }

        temp = temp->next;
    }

    return head;
}

Node *sortedLL_optimal(Node *head)
{

    // base condition where there is null or only one node
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    // now first we create three dummy nodes
    Node *zeroHead = new Node(-1);
    Node *oneHead = new Node(-1);
    Node *twoHead = new Node(-1);

    // also then we keep three pointers to these 3 lists
    Node *zero = zeroHead;
    Node *one = oneHead;
    Node *two = twoHead;

    // now we also consider a temp pointer to traverse the list
    Node *temp = head;

    // traverse the list
    while (temp)
    {

        // first do the linking part of the nodes
        if (temp->data == 0)
        {
            zero->next = temp;
            zero = zero->next;
        }
        else if (temp->data == 1)
        {
            one->next = temp;
            one = one->next;
        }
        else
        {
            two->next = temp;
            two = two->next;
        }

        temp = temp->next;
    }

    // now we have to connect the separate lists to each other
    // as all the zero, one, two pointes will be at the end of their lists so we can use them

    // first connect the zero head
    if (oneHead->next != NULL)
    {
        zero->next = oneHead->next;
    }
    else
    {
        zero->next = twoHead->next;

        // this else part is fine as, even if there are no 2's then to it will then point to the null
    }

    // now connect the one head
    one->next = twoHead->next;

    // finally two head
    two->next = nullptr;

    // store the zeroHead as the newHead
    Node *newHead = zeroHead->next;

    // after we have got the linked list correctly, we will delete the dummy nodes
    delete zeroHead;
    delete oneHead;
    delete twoHead;

    // return the head
    return newHead;
}

int main()
{
    vector<int> arr = {1, 0, 1, 2, 0, 2, 1};
    Node *head = convert_array_to_LL(arr);

    head = sortedLL_optimal(head);
    traverseLL(head);

    return 0;
}