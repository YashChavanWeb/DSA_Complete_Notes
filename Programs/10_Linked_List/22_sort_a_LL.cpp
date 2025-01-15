#include <bits/stdc++.h>
using namespace std;

/*

// Sort a Linked List
- we have to return the head of the sorted Linked List


1. Brute force Approach

- we can store the values of the linked list in an array
- and then sort the array - we can apply any sorting algorithm
- and then we can replace the elements in the linked lst with the sorted array elements

- Time complexity -> O(n + nlogn + n) - traversing + sorting + replacing
- Space complexity -> O(n) - for the array





2. Optimal Approach

- we are not allowed to use an external space
- we have two sorting algorithms, merge sort and quick sort
- so we will be implementing merge sort for the linked list

- Time complexity -> O(logN *( N + N/2)) -> divide + merge + find middle
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

Node *sort_LL_brute(Node *head)
{

    // first step is to convert LL to array
    Node *temp = head;
    vector<int> arr;
    while (temp)
    {
        arr.push_back(temp->data);
        temp = temp->next;
    }

    // the next step is to sort the array
    sort(arr.begin(), arr.end());

    // after sorting we will replace the linked list with the sorted array elements
    temp = head;
    int i = 0;

    while (temp)
    {
        temp->data = arr[i];
        i++;
        temp = temp->next;
    }

    return head;
}

Node *merge_two_LL_optimal(Node *head1, Node *head2)
{

    // first we will define all the pointers we need
    Node *temp1 = head1, *temp2 = head2;
    Node *dummyNode = new Node(-1);
    Node *temp = dummyNode;

    // we will start the traversal on both the linked lists simultaneously
    while (temp1 != NULL && temp2 != NULL)
    {
        // if temp1 is smaller
        if (temp1->data < temp2->data)
        {
            temp->next = temp1;
            // now move the temp to the next node
            temp = temp->next;
            // also move the smaller element pointer
            temp1 = temp1->next;
        }
        else
        {
            temp->next = temp2;
            // now move the temp to the next node
            temp = temp->next;
            // also move the smaller element pointer
            temp2 = temp2->next;
        }
    }

    // after this we will have either temp1 or temp2 remaining as they are unequal
    // so we have to make the temp point to that so that the rest nodes can be taken directly
    if (temp1)
        temp->next = temp1;
    if (temp2)
        temp->next = temp2;

    return dummyNode->next;
}

Node *find_middle(Node *head)
{
    Node *slow = head;
    Node *fast = head->next; // this is because we want the node before middle node

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
}

Node *sort_LL_optimal(Node *head)
{

    // first the base condition
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    // then take the left and the right
    // for that we have to find the middle
    Node *middle = find_middle(head);

    // now we can divide the linked list
    Node *leftHead = head;
    Node *rightHead = middle->next;
    // also we have to break them from the middle
    middle->next = nullptr;

    // then we will call the merge sort again for the left and right recursively
    // and it will return the head
    leftHead = sort_LL_optimal(leftHead);
    rightHead = sort_LL_optimal(rightHead);

    // then finally we will merge the two heads of the two sorted Linked lists
    Node *result = merge_two_LL_optimal(leftHead, rightHead);

    return result;
}

int main()
{
    vector<int> arr = {3, 4, 2, 1, 5};
    Node *head = convert_array_to_LL(arr);

    // head = sort_LL_brute(head);
    head = sort_LL_optimal(head);
    traverseLL(head);

    return 0;
}