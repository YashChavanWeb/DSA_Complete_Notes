#include <bits/stdc++.h>
using namespace std;

// Define the Node class for the linked list
class Node
{
public:
    int data;   // Data value
    Node *next; // Pointer to the next node

    // Constructor to initialize Node with data and next pointer
    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }

    // Constructor to initialize Node with data and default next pointer (nullptr)
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

// Function to convert an array to a linked list
Node *convert_array_to_LL(vector<int> arr)
{
    // Initialize the head with the first element
    Node *head = new Node(arr[0]);

    // Use a mover pointer to traverse and construct the linked list
    Node *mover = head;

    // Traverse from the second element to the end
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]); // Create a new node
        mover->next = temp;            // Link the current node to the new node
        mover = temp;                  // Move the pointer to the next position
    }

    return head; // Return the head of the linked list
}

// Function to traverse and print the linked list
void traverseLL(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "null" << endl;
}

/*
Approach to Reverse a Linked List

1. Brute Force Approach:
   - Use a stack to store all node data values.
   - Traverse the linked list and push all values onto the stack.
   - Then, traverse the linked list again and replace node data with values popped from the stack.
   - Time Complexity: O(N + N) = O(2N)
   - Space Complexity: O(N) due to the stack storage.















2. Iterative Approach (Better):
   - Use two pointers to reverse the links iteratively.
   - Maintain a 'prev' pointer initialized to NULL and a 'temp' pointer to traverse the list.
   - Reverse the 'next' pointers of nodes in place.
   - Time Complexity: O(N)
   - Space Complexity: O(1)















3. Recursive Approach (Optimal):
   - Reverse the list recursively by reducing the problem size.
   - Base case: If head is NULL or the last node is reached, return head.
   - Recursive case: Reverse the rest of the list and link the current node to its previous node.
   - Time Complexity: O(N)
   - Space Complexity: O(N) (due to recursive function call stack)



*/

// Brute Force Approach to reverse the linked list
Node *reverse_LL_brute(Node *head)
{
    stack<int> st; // Stack to store data
    Node *temp = head;

    // Push all node data onto the stack
    while (temp)
    {
        st.push(temp->data);
        temp = temp->next;
    }

    // Replace node data with values from the stack
    temp = head;
    while (temp)
    {
        temp->data = st.top();
        st.pop();
        temp = temp->next;
    }
    return head;
}

// Iterative Approach to reverse the linked list
Node *reverse_LL_better(Node *head)
{
    Node *temp = head; // Pointer to traverse the list
    Node *prev = NULL; // Pointer to store the previous node

    while (temp)
    {
        Node *front = temp->next; // Save the next node
        temp->next = prev;        // Reverse the 'next' pointer
        prev = temp;              // Move 'prev' to the current node
        temp = front;             // Move 'temp' to the next node
    }

    return prev; // Return the new head of the reversed list
}

// Recursive Approach to reverse the linked list
Node *reverse_LL_optimal(Node *head)
{
    // Base case: If the list is empty or has one node, return the head
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    // Reverse the rest of the list recursively
    Node *newHead = reverse_LL_optimal(head->next);

    // Link the current node to its previous node
    Node *front = head->next; // Get the next node
    front->next = head;       // Reverse the link
    head->next = NULL;        // Set the current node's 'next' to NULL

    return newHead;
}

int main()
{
    // Input array to convert to a linked list
    vector<int> arr = {1, 3, 5, 4, 1};
    Node *head = convert_array_to_LL(arr);

    // head = reverse_LL_brute(head);
    // head = reverse_LL_better(head);
    head = reverse_LL_optimal(head);

    traverseLL(head);

    return 0;
}
