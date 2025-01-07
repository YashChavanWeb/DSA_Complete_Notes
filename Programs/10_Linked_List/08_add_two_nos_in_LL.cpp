#include <bits/stdc++.h>
using namespace std;

/*

// Add two numbers in a linked list

- we will be given L1 and L2
L1 is the number to you given in reverse order - every digit is the node of the LL
L2 is the second reversed number

- so we have to add both the nos and put the ans in a linked list in reverse order

L1 - 2 -> 4 -> 6
L2 - 3 -> 8 -> 7
Ans -> 1 -> 4 -> 2 -> 5  (642 + 783)







1. Dummy Node Approach

- we consider a dummy node with initial data as -1 -> and it has a curr to traverse
- take temp1 and temp2 to traverse on the linked lists
- also we take a variable carry initially = 0

- temp1 + temp2 + carry -> put in the sum list
- current's next should point to this node
- then move the current to next
- also move t1 and t2 to the next

- if 2 digit output, then it means there is carry, so update the carry variable
- then current -> next should be the output node
- move current, t1 and t2

- once both t1 and t2 are pointing to the null, then we add the carry into the new node
- and then end


- What is the use of the dummy node? Can't we start directly?
- the code will get a lot messier
- whenever we want to create a new list, we have to use dummy node concept

- Time complexity -> O(max(n1,n2))
- Space complexity -> O(max(n1,n2))


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

Node *return_sum_list(Node *head1, Node *head2)
{

    // take 2 pointers temp1 and temp2 for pointing the two linked lists
    Node *temp1 = head1;
    Node *temp2 = head2;

    // take dummy node
    Node *dummyNode = new Node(-1);
    // current initially points to dummy node
    Node *current = dummyNode;

    // initialize carry variable to be 0 initially
    int carry = 0;

    // run the loop until both the lists become null
    while (temp1 != NULL || temp2 != NULL)
    {

        // first declare the sum with the carry
        int sum = carry;

        // then if the linked lists are not null then add their value to sum
        if (temp1)
            sum += temp1->data;
        if (temp2)
            sum += temp2->data;

        // then create the new node for adding into the sum list and don't add the first digit as it is carry so it is %
        Node *newNode = new Node(sum % 10);
        // also modify the carry by doing /10
        carry = sum / 10;
        // point the current to this node
        current->next = newNode;
        // move the current to the next
        current = current->next;

        // also move both the pointers of the linked lists ahead, if they are not null
        if (temp1)
            temp1 = temp1->next;
        if (temp2)
            temp2 = temp2->next;
    }

    // after the while loop is complete check whether the carry is still there
    if (carry)
    {
        // add the carry by creating the new node
        Node *newNode = new Node(carry);
        // point the current to this node
        current->next = newNode;
    }

    // now we return the head, which is the next of dummy Node
    return dummyNode->next;
}

int main()
{
    vector<int> arr1 = {3, 5};
    vector<int> arr2 = {4, 5, 9, 9};
    Node *head1 = convert_arr_to_LL(arr1);
    Node *head2 = convert_arr_to_LL(arr2);

    traverse_LL(head1);
    cout << endl;
    traverse_LL(head2);
    cout << endl;
    Node *sumList = return_sum_list(head1, head2);
    traverse_LL(sumList);

    return 0;
}