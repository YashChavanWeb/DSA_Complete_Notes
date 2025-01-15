#include <bits/stdc++.h>
using namespace std;

/*

// Find the starting point of the loop in the linked list

- detecting a loop in a linked list
- and then find its starting point


1. Brute force Approach

- at any moment I see a node twice, we can say that that is the starting node of the loop
- so for that we have to remember the loop
- so we can use hashing here
- we will store the nodes and not values, as the values can repeat

- Time complexity - O(N * 2*logN)
- Space complexity - O(N) - we are using map data structure






2. Optimal Approach

- here we will be using tortoise and the hair algorithm
- so with this when they collide, then we have detected that there is a loop in the LL
- next step is to find the starting point
- fast starts at the collision point, slow starts from the head
- and both move by one step
- they collide again, and where they collide will be the starting point of the loop

Intuition
- How are we so sure that they will collide?
- How do we know that the colliding is the starting point?

After 3 steps:
- head to starting point distance is lets say L1
- and distance between starting point to the fast pointer is also L1

- the distance between fast and slow pointer is d
- distance d is getting reduced as fast is moving towards slow by d-1

- so the length of the loop is L1 + d

- total distance fast covered until collision is 2d
- total distance slow covered until collision is d

- so we can say that, from the starting point till the collision point, the distance slow traveled is d
- so from the collision to the starting point, the distance will be L1

- so from head to starting point, and from collision point to starting point, the distance is same
- and so we get the collision again

- Time complexity -> O(N/2 * N/2)
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

Node *find_starting_point_brute(Node *head)
{

    // first consider the map
    map<Node *, int> mpp;
    Node *temp = head;

    while (temp)
    {

        if (mpp.find(temp) != mpp.end())
        {
            // this means that we got the node in the map
            return temp;

            // with this we will get the starting point of the loop
        }

        // if not then we can add that in the map
        mpp[temp] = 1;

        temp = temp->next;
    }

    // if we don't get anything then it means it is linear LL
    return NULL;
}

Node *find_starting_point_optimal(Node *head)
{
    Node *slow = head, *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        // now here if we find that they both are colliding then we have to perform the step 2
        if (slow == fast)
        {

            // move slow to the head
            slow = head;

            // run the loop until they again collide
            while (slow != fast)
            {
                // both will move by 1 place
                slow = slow->next;
                fast = fast->next;
            }

            // this means that yes they collided again
            return slow;
        }
    }

    // if not returned then it means that there is no starting point/no loop
    return NULL;
}

int main()
{

    vector<int> arr = {1, 2, 3, 15, 4, 13, 6, 7, 8, 9};
    Node *head = convert_array_to_LL(arr);

    // traverseLL(head);

    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = head->next->next->next;

    // Node *result = find_starting_point_brute(head);
    Node *result = find_starting_point_optimal(head);

    if (result)
    {
        cout << "The starting point of the loop is " << result->data;
    }
    else
    {
        cout << "Linked list has no loop";
    }

    return 0;
}