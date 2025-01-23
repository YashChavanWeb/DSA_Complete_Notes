#include <bits/stdc++.h>
using namespace std;

/*

// Implement Stack and Queue using Linked List

1. Stack
- create a node of the element and its next will be pointing to the top
- the top is initially pointing to null and then it will point to the new node
- same with the next node - point top top and move the top
- to pop the element just move the top by one and then delete the element which top was pointing to earlier


2. Queue
- we first consider the start and the end pointers
- then when we push, if it is first element then we point start and end both to the new node
- and if not then we just point end next to the new node (temp)
- and then move the end one step forward
- for popping element, we simply move the start pointer (just check if queue is null)
- for finding top as well we check if the queue is null


*/

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

class stack_LL
{

    Node *top;
    int size = 0;

public:
    void push(int x)
    {
        // No need to worry about the size

        Node *temp = new Node(x);
        temp->next = top;
        top = temp;
        size++;

        cout << temp->data << endl;
    }

    void pop()
    {

        Node *temp = top;
        top = top->next;
        cout << temp->data << endl;
        delete temp;

        size--;
    }

    void get_top()
    {
        cout << top->data << endl;
    }

    void get_size()
    {
        cout << size << endl;
    }
};

class queue_LL
{

    static const int size = 5;
    Node *start, *end;
    int curr_size = 0;

public:
    void push(int x)
    {

        Node *temp = new Node(x);

        if (start == NULL)
        {
            // we are pushing the first element
            start = end = temp;
        }
        else
        {
            end->next = temp;
            end = end->next;
        }

        cout << end->data << endl;

        curr_size++;
    }

    void pop()
    {
        if (start == NULL)
        {
            cout << "The queue is empty." << endl;
        }
        else
        {

            Node *temp = start;
            start = start->next;

            cout << temp->data << endl;
            delete temp;

            curr_size--;
        }
    }

    void top()
    {

        if (start == NULL)
        {
            cout << "Queue is empty." << endl;
        }
        else
        {

            cout << start->data << endl;
        }
    }

    void get_size()
    {
        cout << curr_size << endl;
    }
};

int main()
{
    // stack_LL stack1;
    // stack1.push(10);
    // stack1.push(3);
    // stack1.push(6);

    // stack1.get_top();
    // stack1.get_size();
    // stack1.pop();
    // stack1.get_top();
    // stack1.get_size();

    queue_LL queue1;
    queue1.push(100);
    queue1.push(4);
    queue1.push(12);

    queue1.pop();
    queue1.top();
    queue1.get_size();
    queue1.pop();
    queue1.push(3);
    queue1.top();

    return 0;
}