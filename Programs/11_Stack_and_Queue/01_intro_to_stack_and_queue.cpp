#include <bits/stdc++.h>
using namespace std;

/*

// Introduction to stack and queues

1. Stack
- follows LIFO - Last In First Out
- functions: push, pop, top, size

2. Queue
- follows FIFO - First In First Out
- functions: push, pop, top, size







# Implementing stack using Arrays

- consider a fixed size array (it cannot be dynamic)
- initially the top will be -1
- size of the stack will be top + 1

- Time complexity -> all operations are done in O(1)
- Space complexity -> O(n) ~ somewhat not exactly







# Implementing queue using Arrays

- consider two variables, start and end, both will initially point to -1
- also keep a current size variable to count the remaining size
- if start and end are both -1, then it means that we are entering first element
- move the start and end to the first index i.e. 0
- when we enter the next element, the start will not move, only the end will move
- the top most element will be arr[start] (only if stack is not pointing to -1)
- if we want to pop an element, then just move the stack to the next element
- if the end exceeds, then we have to place it at the front again
- as we can add more elements to the queue (use modular operation for this)
- if we pop the last element of the queue, then after that we will place the start and end at the -1 again

- Time complexity -> all operations are done in O(1)
- Space complexity -> O(n) ~ somewhat not exactly



*/
class stack_impl
{
private:
    static const int size = 5; // Maximum size of the stack
    int st[size];
    int top = -1; // Indicates an empty stack initially

public:
    // Push function to add an element to the stack
    void push(int x)
    {
        if (top < size - 1)
        {
            top++;
            st[top] = x;
            cout << "Pushed " << x << " to stack." << endl;
        }
        else
        {
            cout << "The stack is full, cannot push " << x << endl;
        }
    }

    // Pop function to remove the top element from the stack
    void pop()
    {
        if (top != -1)
        {
            cout << "Popped " << st[top] << " from stack." << endl;
            top--;
        }
        else
        {
            cout << "The stack is empty, cannot pop." << endl;
        }
    }

    // Function to return the top element of the stack
    void st_top()
    {
        if (top != -1)
        {
            cout << "Top element: " << st[top] << endl;
        }
        else
        {
            cout << "The stack is empty." << endl;
        }
    }

    // Function to return the size of the stack
    void st_size()
    {
        cout << "Current stack size: " << top + 1 << endl;
    }
};

class queue_impl
{
private:
    int start, end;
    static const int size = 5;
    int qu[size];
    int curr_size;

public:
    queue_impl()
    {
        start = end = -1;
        curr_size = 0;
    }

    void push(int x)
    {
        if (curr_size == size)
        {
            cout << "The queue is full." << endl;
        }
        else
        {
            if (curr_size == 0)
            {
                start = end = 0; // as we are entering the first element
            }
            else
            {
                end = (end + 1) % size;
            }

            qu[end] = x;
            curr_size++;
            cout << x << endl;
        }
    }

    void pop()
    {
        if (curr_size == 0)
        {
            cout << "The queue is empty" << endl;
        }
        else
        {
            int el = qu[start];
            cout << el << endl;

            if (curr_size == 1)
            {
                // If there's only one element, reset the queue
                start = end = -1;
            }
            else
            {
                start = (start + 1) % size;
            }

            curr_size--;
        }
    }

    void top()
    {
        if (curr_size == 0)
        {
            cout << "The queue is empty." << endl;
        }
        else
        {
            cout << "Front element: " << qu[start] << endl;
        }
    }

    void qu_size()
    {
        cout << "Current queue size: " << curr_size << endl;
    }
};

int main()
{
    // Stack Operations
    stack_impl stack1;
    stack1.push(2);
    stack1.push(5);
    stack1.push(5);
    stack1.push(6);
    stack1.push(1);
    stack1.push(2);
    stack1.st_top();
    stack1.pop();
    stack1.st_top();
    stack1.st_size();

    // Queue Operations
    queue_impl queue1;
    queue1.push(5);
    queue1.push(3);
    queue1.push(8);
    queue1.top();
    queue1.pop();
    queue1.pop();
    queue1.top();
    queue1.qu_size();
    queue1.pop();
    queue1.pop();
    queue1.pop();
    queue1.pop();

    return 0;
}
