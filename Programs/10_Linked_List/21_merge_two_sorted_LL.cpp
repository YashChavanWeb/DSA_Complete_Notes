#include <bits/stdc++.h>
using namespace std;

/*

// Merge two sorted Linked Lists

- combine the elements, sort them put in new list and then return head of new list



1. Brute force Approach

- put all the elements of both the linked list in an array
- then we will sort that array
- and then convert the sorted array into LL and then return its head

- Time complexity -> N = N1 + N2 -> O(N + NlogN + N) - traverse x2 + sort + convert
- Space complexity -> O(N + N) - arr + new LL







2. Optimal Approach

- use property of sorted and concept of two pointers
- we will take a dummy node and then keep on pointing to the nodes which are in sorted order
- for that we will compare the nodes in the LL and then connect the pointer from dummy node to it and also move ahead

- Time complexity -> N = N1 + N2 ->  O(N)
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

Node *merge_two_LL_brute(Node *head1, Node *head2)
{

    // first insert both the linked list elements into the array
    vector<int> result;
    Node *temp1 = head1, *temp2 = head2;

    while (temp1)
    {
        result.push_back(temp1->data);
        temp1 = temp1->next;
    }

    while (temp2)
    {
        result.push_back(temp2->data);
        temp2 = temp2->next;
    }

    // then we will sort this array
    sort(result.begin(), result.end());

    // then we can covert this array to linked list
    Node *sorted_head = convert_array_to_LL(result);

    // or we can directly return convert_array_to_LL(result)

    return sorted_head;
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

int main()
{
    vector<int> arr1 = {2, 4, 8, 10};
    vector<int> arr2 = {1, 3, 3, 6, 11, 14};

    Node *head1 = convert_array_to_LL(arr1);
    Node *head2 = convert_array_to_LL(arr2);

    // Node *resultHead = merge_two_LL_brute(head1, head2);
    Node *resultHead = merge_two_LL_optimal(head1, head2);
    traverseLL(resultHead);

    return 0;
}