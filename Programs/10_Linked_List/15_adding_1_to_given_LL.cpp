#include <bits/stdc++.h>
using namespace std;

/*

// Adding 1 to a given LL

- we will be given a LL where every node is representing a digit
Eg: 1->5->9 = 159 and we have to add 159 + 1 that is 160
which we have to return as 1-> 6-> 0



1. Brute force approach

- we need to do a backward traversal
- but it is a singly linked list so we cannot do that
- so at first we will be reversing the linked list
- the initial value that we need to add is 1 so let's take it as a carry
- we will add the temp->data to carry
- and when carry is 0 we will break as no need to traverse ahead
- reverse the linked list again

- what if the number of digits are different
- if temp goes to null and still there is carry, then we have to create a new node
- for that we will reverse the list again and then create the newNode, point it to the head and return the newHead

Note: Note we are adding 1 so the carry cannot be more than 1


- Time complexity -> O(N + N + N) -> O(3N) -> reverse + traverse + reverse
- Space Complexity -> O(1)






2. Optimal Approach

- we want to do this without reversing as it is taking time
- so we can use recursion, as we can traverse back with its help (backtracking)

- we will call the recursion until we reach null -> it will be the base case

- Time complexity -> O(N)
- Space Complexity -> O(N)






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

Node *reverseLL(Node *head)
{
  if (head == NULL || head->next == NULL)
  {
    return head;
  }

  Node *newHead = reverseLL(head->next);

  // then swap the links between front and head
  Node *front = head->next;
  front->next = head;
  head->next = NULL;

  return newHead;
}

Node *add_1_brute(Node *head)
{
  // first in order to traverse from the end reverse the LL
  head = reverseLL(head);

  // after that traverse the Linked list and add carry
  Node *temp = head;

  int carry = 1;
  while (temp)
  {
    temp->data += carry;

    if (temp->data < 10)
    {
      carry = 0;
      break;
    }
    else
    {
      carry = 1;
      temp->data = 0;
    }

    temp = temp->next;
  }

  if (carry)
  {
    // if still carry is 1 then we need to add a new Node before the start
    Node *newNode = new Node(carry);
    reverseLL(head);
    newNode->next = head;

    return newNode;
  }

  head = reverseLL(head);
  return head;
}

int helper_func(Node *temp)
{
  // this function will be helping to perform all the operations

  // so first of all as it is a recursive function so the base case
  if (temp == NULL)
  {
    // if temp is null then it means we can start from the reverse and so we return carry 1
    return 1;
  }

  // after we return then we can get it using the carry
  int carry = helper_func(temp->next);

  // once we get the carry we do the addition and the carrying process
  temp->data += carry;

  if (temp->data < 10)
  {
    // if less than 10 means no carry so return 0
    return 0;
  }

  // this means that the carry is > 10 so we have to return 1
  temp->data = 0;
  return 1;
}

Node *add_1_optimal(Node *head)
{

  // this is the ending part where we call the helper function to get the final carry
  int carry = helper_func(head);

  // if there is still carry then it means that we have to add a new Node
  if (carry)
  {
    Node *newNode = new Node(carry);
    newNode->next = head;

    // and then simply we will return this new node
    return newNode;
  }

  // if carry is not there then we can directly return the head
  return head;
}

int main()
{

  vector<int> arr = {3, 5, 2};

  Node *head = convert_array_to_LL(arr);
  // head = add_1_brute(head);
  head = add_1_optimal(head);
  traverseLL(head);

  return 0;
}