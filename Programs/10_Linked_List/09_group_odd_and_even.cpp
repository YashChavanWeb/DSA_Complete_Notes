#include <iostream>
#include <vector>
using namespace std;

/*

// Group odd and even linked list

- 1 2 3 4 5 6
so odd indexes element first 1 3 5
and then even indexes elements after that 1 3 5 2 4 6
and then replace the original LL with it and then return its head

1. Brute force approach

- Time complexity - O(n/2) + O(n/2)  + O(n) -> O(2n) -> odd indexes, even indexes, iterate
- Space complexity - O(n) - we are using an extra array



2. Optimal Approach

- the even will always be in front of the odd

- Time complexity -> O(n/2)*2 -> O(n)
- Space complexity -> O(1)




*/

class Node
{
public:
    int data;
    Node *next;

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

Node *insert_end(Node *head, int element)
{
    if (head == NULL)
    {
        return new Node(element);
    }

    // common condition
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    Node *newNode = new Node(element);
    temp->next = newNode;

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

Node *oddEvenGroup_brute(Node *head)
{

    // base condition: there should be atleast 2 nodes in ll
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    // array for storing the result
    vector<int> arr;

    // Odd indexes
    Node *temp = head;
    while (temp != NULL && temp->next != NULL)
    {
        arr.push_back(temp->data);
        temp = temp->next->next;
    }
    // take the last element
    if (temp)
        arr.push_back(temp->data);

    // even indexes
    temp = head->next;
    while (temp != NULL && temp->next != NULL)
    {
        arr.push_back(temp->data);
        temp = temp->next->next;
    }
    if (temp)
        arr.push_back(temp->data);

    // we have the new array - replace in the linked list
    int i = 0;
    temp = head;

    while (temp)
    {
        temp->data = arr[i];
        i++;
        temp = temp->next;
    }

    return head;
}

Node *oddEvenGroup_optimal(Node *head)
{

    // base ccondition
    if (head == NULL)
        return head;

    Node *odd = head;
    Node *even = head->next;
    Node *evenNode = head->next; // to link the even after the odd

    while (even != NULL && even->next != NULL)
    {
        // break the links
        odd->next = odd->next->next;
        even->next = even->next->next;

        // increment both
        odd = odd->next;
        even = even->next;
    }

    // link the ending node to the odd Node
    odd->next = evenNode;

    return head;
}

int main()
{

    Node *head = new Node(1);
    insert_end(head, 3);
    insert_end(head, 4);
    insert_end(head, 2);
    insert_end(head, 5);
    insert_end(head, 6);

    // head = oddEvenGroup_brute(head);
    head = oddEvenGroup_optimal(head);
    traverseLL(head);

    return 0;
}