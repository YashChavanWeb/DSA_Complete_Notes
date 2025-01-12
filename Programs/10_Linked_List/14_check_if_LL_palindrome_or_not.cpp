#include <bits/stdc++.h>
using namespace std;

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

/*

// Check if a linked list is palindrome or not


1. Brute force approach

- use a stack data structure
- push all the values so they will be added in stack in reverse order
- then compare the top wth the linked list and if the reverse is also the same then it is a palindrome

- Time complexity -> O(N + N) -> O(2N)
- Space complexity -> O(N) - as we are storing every element in the stack




2. Optimal Approach

- we have to do the comparison within the given linked list
- so for that we need to compare the nodes from start and end and so on
- but it is not a doubly linked list but we first may have to reverse those links
- but for that we need to locate the middle of the linked list
- for that we have to tortoise and the hair algorithm


- in this we need to stand at the middle 1 (in case of even) so for that fast node should be on the second last node and not on the last
- so by doing this we have recognized the second half

- then we will reverse the second half of the linked list
- for the odd length linked list how will it work, so we will stop at the last node (which is what we do)



// 3 steps
- find the middle
- reverse the second half
- check for palindrome
- reverse again to original

- Time complexity -> O(N/2 + N/2 + N/2 + N/2) -> O(2N)
- Space complexity -> O(1) - as we are not using any extra space



*/

bool find_palindrome_brute(Node *head)
{
    // edge case
    if (head == NULL || head->next == NULL)
    {
        return true; // as it will always be a palindrome
    }

    // use stack to push all the elements
    stack<int> st;
    Node *temp = head;
    while (temp)
    {
        st.push(temp->data);
        temp = temp->next;
    }

    // then we have to compare the elements will the elements in reverse from the stack
    temp = head;
    while (temp)
    {
        if (temp->data != st.top())
        {
            return false;
        }
        st.pop();
        temp = temp->next;
    }

    return true;
}

Node *reverse_LL_optimal(Node *head)
{

    // we will write the base condition
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    // when we get a linked list head through recursion
    // we will call the function for the rest of the linked list and then add the head to
    Node *newHead = reverse_LL_optimal(head->next);
    // after we have the new head we will also get the front
    Node *front = head->next;
    // then we can replace the front next and head next
    front->next = head;
    head->next = NULL;

    return newHead;
}

bool find_palindrome_optimal(Node *head)
{

    // edge case
    if (head == NULL || head->next == NULL)
    {
        return true;
    }

    // first step is to find the before middle to identify second half
    Node *fast = head, *slow = head;
    while (fast->next != NULL && fast->next->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    // here the slow will be pointing to the before mid node so we know the second half now

    // next we have to reverse so that we can traverse and compare
    Node *newHead = reverse_LL_optimal(slow->next);

    // now we will take two pointers and just compare
    Node *first = head, *second = newHead;

    while (second)
    {
        if (first->data != second->data)
        {
            reverse_LL_optimal(newHead);
            return false;
        }

        first = first->next;
        second = second->next;
    }

    // or else return true
    reverse_LL_optimal(newHead);
    return true;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 2, 1};
    Node *head = convert_array_to_LL(arr);

    // if(find_palindrome_brute(head)) {
    if (find_palindrome_optimal(head))
    {
        cout << "The linked list is a palindorme.";
    }
    else
    {
        cout << "The linked list is not a palindrome";
    }

    return 0;
}