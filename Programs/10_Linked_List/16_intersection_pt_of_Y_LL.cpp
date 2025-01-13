#include <bits/stdc++.h>
using namespace std;

/*

// To find the intersection point of the Y linked list

- we will be given two linked list
- so we will have to return the first common node between them if it is a Y linked list
- what if the linked list never collide and don't have Y so we will return the null


1. Brute force approach
- we are looking for a node which is in LL 1 as well as LL 2
- so we will traverse 1 LL and then memorize all the nodes in a hash
- and then compare with 2nd LL, if the node matches then return the first node

- we will consider a hash map with the node and its occurrence
- we don't store the value as LL can have multiple same values

- Time complexity -> O(N1 + N2) - first traversal + second traversal
- Space complexity -> O(N1)





2. Better Approach
- we are using a extra space so we need to do it during the traversal
- if we want to do it during the traversal itself, then we need to start comparing as if the LL are equal
- but the LL will be unequal, so we find their length and make the pointer of the longer LL same as that of the shorter
- so that the comparison will be easier

- Time complexity -> O(N1) + O(N2) + O(N2 - N1) + O(N1) = O(N1 + 2N2)
- Space complexity -> O(1)





3. Optimal Approach

- we start the traversing of both the LL simultaneously by one place
- if temp1 is about to reach null, it will go to the head of LL2 and same if temp2 is about to reach null, it will go to the head of LL1
- and after a point they will align
- and once they meet at the same point, then we can say that the node they are at is the common node


- Edge cases:
- if they are of the of hte same length, then they will collide in the first go so no need to do anything
- if the LL are not colliding so how we will figure out that
- if both of them are at the last node, then it means that they have started together yet not collided so return null


- Time complexity -> O(N1 + N2)
- Space complexity ->O(1)




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

Node *intersecting_Node_brute(Node *head1, Node *head2)
{
    // first we will store the LL1 in a hashmap
    map<Node *, int> mpp;

    // Traverse the first linked list and store the addresses of its nodes in the map
    Node *temp = head1;
    while (temp)
    {
        mpp[temp] = 1;
        temp = temp->next;
    }

    // now we have to compare whether we have the common node in the LL1 from LL2
    temp = head2;
    while (temp)
    {
        if (mpp.find(temp) != mpp.end())
        {
            // this means that we have found the node  in the map
            return temp;
        }

        temp = temp->next;
    }

    return NULL;
}

Node *find_intersection(Node *smallerLL, Node *greaterLL, int d)
{
    // int d is the difference till which we will first traverse the greaterLLL

    while (d)
    {
        d--;
        greaterLL = greaterLL->next;
    }

    // now we can equally start and compare
    Node *temp1 = smallerLL;
    Node *temp2 = greaterLL;

    while (temp1 != temp2)
    {
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    // now here we will be either out when we get a same node or else it is null
    return temp1;
}

Node *intersecting_Node_better(Node *head1, Node *head2)
{
    // first we will find the length of the linked lists
    Node *t1 = head1;
    int len1 = 0;
    while (t1)
    {
        len1++;
        t1 = t1->next;
    }
    Node *t2 = head2;
    int len2 = 0;
    while (t2)
    {
        len2++;
        t2 = t2->next;
    }

    // once we get the lengths we will call a function that returns us the node
    Node *newNode;
    if (len1 < len2)
    {
        // this means that LL2 is bigger
        newNode = find_intersection(head1, head2, len2 - len1);
        // function(smaller, greater, distance to travel for greater)
    }
    else
    {
        newNode = find_intersection(head2, head1, len1 - len2);
    }

    return newNode;
}

Node *intersecting_Node_optimal(Node *head1, Node *head2)
{

    // base case if LL is empty
    if (head1 == NULL || head2 == NULL)
        return NULL;

    // now lets start traversing
    Node *temp1 = head1, *temp2 = head2;
    while (temp1 != temp2)
    {

        // we will move both by 1 place simultaneously
        temp1 = temp1->next;
        temp2 = temp2->next;

        // now if they are equal then we got the intersecting node
        // this will even work if they both reach null so no need to worry it in the while
        if (temp1 == temp2)
            return temp1;

        // if not equal, then any one of them will reach null so simply move it to the other LL head
        if (temp1 == NULL)
            temp1 = head2;
        if (temp2 == NULL)
            temp2 = head1;
    }

    return temp1;
}

int main()
{
    vector<int> arr1 = {3, 1, 4, 6, 2};
    vector<int> arr2 = {1, 2, 4, 5, 4, 6, 2};

    Node *head1 = convert_array_to_LL(arr1);
    Node *head2 = convert_array_to_LL(arr2);

    // making the Y LL
    head2->next->next->next->next = head1->next->next;
    // traverseLL(head2);

    // Node *intersectingNode = intersecting_Node_brute(head1, head2);
    // Node *intersectingNode = intersecting_Node_better(head1, head2);
    Node *intersectingNode = intersecting_Node_optimal(head1, head2);

    if (intersectingNode)
    {
        cout << "The intersecting Node is : " << intersectingNode->data << " -> null ";
    }
    else
    {
        cout << "There is no intersecting Node ";
    }

    return 0;
}