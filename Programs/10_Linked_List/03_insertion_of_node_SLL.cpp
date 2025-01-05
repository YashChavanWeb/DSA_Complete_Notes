#include <bits/stdc++.h>
using namespace std;

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

/*

// Insertion of a node in linked list
4 types
Insertion at the:
- head
- end
- position
- value




*/

Node *convert_arr_to_LL(vector<int> arr)
{
    if (arr.size() == 0)
    {
        return NULL;
    }

    Node *head = new Node(arr[0]);

    Node *mover = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = mover->next;
    }
    return head;
}

void traverse_LL(Node *head)
{
    Node *temp = head;

    while (temp)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "null";
}

Node *insert_head(Node *head, int element)
{
    // next of temp will point to the current head
    Node *temp = new Node(element, head);

    // return temp as the new head
    return temp;

    // we can also return
    // return new Node(element, head);
}

Node *insert_tail(Node *head, int element)
{

    // edge case
    if (head == NULL)
    {
        // the element that we add will be the first element
        Node *temp = new Node(element);
        return temp;

        // or we can directly return the new node
        // return new Node(element);
    }
    Node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    // here it means that we are on the last node
    Node *el = new Node(element);
    temp->next = el;

    return head;
}

Node *insert_position(Node *head, int element, int k)
{

    // first case where the linkedlist is empty
    if (head == NULL)
    {

        // we have to insert the element as the first
        if (k == 1)
        {
            return new Node(element);
        }
        else
        {
            return head;
        }
    }

    // if k=1 that means we have to insert at the first position
    if (k == 1)
    {
        // temp's next will be pointing to the head
        Node *temp = new Node(element, head);
        return temp;
    }

    // for all the other cases from k=2 to n+1
    int cnt = 0;

    Node *temp = head;
    while (temp)
    {
        cnt++;

        // we have to stop one position before the actual position to establish the linking
        if (cnt == k - 1)
        {

            // this is where we write our logic
            Node *newNode = new Node(element, temp->next);
            temp->next = newNode;

            // first make connection of the new node to the temp's next
            // then make connection of the temp's next to the new node
            break;
        }

        // until that we will keep moving forward
        temp = temp->next;
    }

    // the last tail case also gets covered by the while loop

    return head;
}

Node *insert_element(Node *head, int element, int val)
{
    // base case
    if (head == NULL)
    {

        // as the value is not present in the linked list
        return head;
    }

    // if we want to insert at the first
    if (head->data == val)
    {
        Node *temp = new Node(element, head);
        return temp;
    }

    // in other cases
    Node *temp = head;

    // never go to the last element so write while condition for that
    while (temp->next != NULL)
    {
        // so that we can go to one position behind
        if (temp->next->data == val)
        {
            Node *newNode = new Node(element, temp->next);
            temp->next = newNode;
            break;
        }

        temp = temp->next;
    }

    return head;
}

int main()
{
    vector<int> arr = {12, 1, 3, 4, 23};

    Node *head = convert_arr_to_LL(arr);

    // head = insert_head(head, 100);
    // head = insert_tail(head, 113);
    // head = insert_position(head, 98, 5);
    head = insert_element(head, 72, 4);
    traverse_LL(head);

    return 0;
}