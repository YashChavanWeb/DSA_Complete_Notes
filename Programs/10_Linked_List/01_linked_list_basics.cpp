#include <bits/stdc++.h>
using namespace std;

/*

// What is a linked list?

- similar to array
- not in contigious locations
- size can be increased at any moment
- next helps in telling where is the next element




// Where it is used?

- used in stack and queue - no fixed size
- cannot use array
- in real life, we use it in the browser


// Implementation
- struct and class concepts

    int x = 2;
    int* y = &x;

    // ########## to store the pointer of integer value (x) we write int*


    // similarly for the linked list as it is storing 2 values, so there is no datatype we can use to store its pointer
    // so we ourselves create the datatype using struct

    struct Node
    {
        int data;
        Node *next; // as node will be storing the address of the other Node


    //#########  to initialize these values we need a constructor
    // constructor is a special method which is called when an object is created
    // it is used to initialize the values of the object

    Node(data1, next1)
    {
        data = data1;
        next = next1;
    }

    };


    //########## to initialize any value

    Node x = Node(2, nullptr);
    Node* y = &x;

    // also we can use the new keyword instead of this



    // ######
    but in the struct we cannot use object oriented programming concepts
    so we can use class instead



// Memory space?
32 bit system -> int - 4 bytes, ptr - 4 bytes -> total 8 bytes
64 bit system -> int - 4 bytes, ptr - 8 bytes -> total 12 bytes



// Converting an Array into C++ / Java
- the head will be always pointing to the first variable
- and the head is the starting point of the linked list

- so first we will store just the first element of the array in the linked list and then  point the head there
- and the go on traversing all the elements to store them one after the other

- Time complexity -> O(n)



// Traversing in linked list
- we dont have to change the head
- so we create a temp variable pointing to the head and then we move it

- Time complexity -> O(n)




// Length of the linked list
- just like the traversal, we just do count++
- and then whatever is the count is the length of LL

- Time complexity -> O(n)



// Searching element in Linked List
- we just traverse the linked list and check if the element is there or not

- Time complexity -> O(n)


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

// function to find length of linked list
int length_of_LL(Node *head)
{
    int count = 0;

    Node *temp = head;
    while (temp)
    {
        count++;
        temp = temp->next;
    }

    return count;
}

// function to search in the linkedlist
bool check_in_LL(Node *head, int element)
{
    // we will be given always the head of the linked list
    Node *temp = head;

    while (temp)
    {
        if (temp->data == element)
        {
            return true;
        }

        temp = temp->next;
    }

    return false;
}

int main()
{
    int x;
    cin >> x;

    // Node y = new Node(x, nullptr);
    // if we initialize like this then we can do
    // cout<<y.data<<y.next;

    Node *y = new Node(x, nullptr);
    // here we cannot do y.data or y.next
    // we have to do y-> data

    cout << y << endl;
    cout << y->data << ", " << y->next;

    // ## Converting array to linked list

    vector<int> arr = {21, 2, 3, 12};
    Node *head = convert_array_to_LL(arr);
    // cout << head->data;

    // traversing the entire linkedlist
    Node *temp = head;

    while (temp)
    {
        // run until temp is not equal to null
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << "Length of LL is : " << length_of_LL(head);
    cout << check_in_LL(head, 9);

    return 0;
}