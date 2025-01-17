#include <bits/stdc++.h>
using namespace std;

/*

// Find pairs with given sum in a Doubly Linked List which is sorted

- we have given the head and a sum
- the linked list is also sorted



1. Brute force approach

- we will first consider temp1 and then temp2 will be moving
- we will check whether the addition is equal to the sum or not
- if it is less then move the temp2 and if it is more then stop as the linked list is sorted
- so we cannot find a number that will have less sum
- and if it is equal then store it in a data structure

- Time complexity -> O(N^2)
- Space Complexity -> O(1)





2. Optimal Approach

- we will take a pointer at the head and other pointer at the tail
- then add both, and if it is greater, then we try to reduce and so we move the tail pointer to the left
- if it is smaller, then we want to increase, so we move the head pointer to the right
- and if they are equal then just move both of them

- Time complexity -> O(N + N) - find tail and traverse
- Space complexity -> O(1)



*/

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int data1, Node *next1, Node *prev1)
    {
        data = data1;
        next = next1;
        prev = prev1;
    }
    Node(int data1)
    {
        data = data1;
        next = nullptr;
        prev = nullptr;
    }
};

Node *arraytoDLL(vector<int> arr)
{
    // initially head will be created
    Node *head = new Node(arr[0]);

    // also maintain a prev pointer pointing to the head
    Node *previous = head;

    for (int i = 1; i < arr.size(); i++)
    {
        // now first we will create Node
        Node *newNode = new Node(arr[i], nullptr, previous);

        // once the node is created, also the previous link needs to be established
        previous->next = newNode;

        // move the prev to the node
        previous = newNode;
    }

    return head;
}

void traverse_DLL(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "null";
}

vector<pair<int, int>> find_pairs_brute(Node *head, int sum)
{
    // take temp1
    Node *temp1 = head;

    // data structure to store the pairs
    vector<pair<int, int>> ans;

    while (temp1)
    {
        // now consider temp2 from next of temp1
        Node *temp2 = temp1->next;

        // traverse the temp2 by comparing with temp2
        // also keep in mind that it is sorted so don't traverse extra
        while (temp2 != NULL && temp2->data + temp1->data <= sum)
        {

            // check if equal to the sum
            if (temp1->data + temp2->data == sum)
            {
                ans.push_back({temp1->data, temp2->data});
            }

            // if not then we will just move the temp2
            temp2 = temp2->next;
        }

        // after one iteration of temp2 is done then move temp1
        temp1 = temp1->next;
    }

    // at the end then we can return the vector of all the pairs
    return ans;
}

Node *find_tail(Node *head)
{
    Node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    return temp;
}

vector<pair<int, int>> find_pairs_optimal(Node *head, int sum)
{
    // we are going to use two pointer approach so declare them
    Node *temp1 = head;
    Node *temp2 = find_tail(head);

    // data structure for storing the ans
    vector<pair<int, int>> ans;

    // as the list is sorted, traverse until we have temp1 < temp2 / until they cross each other
    while (temp1->data <= temp2->data)
    {

        // check if the sum is equal
        if (temp1->data + temp2->data == sum)
        {
            ans.push_back({temp1->data, temp2->data});

            temp1 = temp1->next;
            temp2 = temp2->prev;
        }
        else if (temp1->data + temp2->data < sum)
        {
            temp1 = temp1->next;
        }
        else
        {
            temp2 = temp2->prev;
        }
    }

    return ans;
}

int main()
{
    vector<int> arr = {1, 2, 4, 5, 9};
    int sum = 6;

    Node *head = arraytoDLL(arr);
    // traverse_DLL(head);

    // vector<pair<int, int>> ans = find_pairs_brute(head, sum);
    vector<pair<int, int>> ans = find_pairs_optimal(head, sum);

    for (auto it : ans)
    {
        cout << "{ " << it.first << ", " << it.second << "}" << endl;
    }

    return 0;
}