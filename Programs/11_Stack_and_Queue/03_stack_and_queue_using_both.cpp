#include <bits/stdc++.h>
using namespace std;

/*

# Implementing Stack using queue

- for pushing an element, after we push the element, the elements before that element will come after that
Eg; 2 9  if we push 5 -> 2 9 5 then we have to bring 2 and 9 after it 5 2 9
- this is done so that the stack like elements are maintained in the queue
- as the queue is re-arranged as the stack, we can then directly apply the pop and top operation
- as there will be no change

- Time complexity -> Except for push which takes O(n) rest all operations take O(1)
- Space complexity -> O(1)






# Implementing Queue using stack

Approach 1 - If your problem needs faster top and pop operations

- as stack only has the top element, we have to use two stacks
- first we will move everything from s1 to s2 before inserting the element
- insert element in s1
- then insert everything from s2 to s1 back again
- with this, we can insert the element from the front and then pop it from the back

- Time complexity -> The push operation only will take O(2N) and rest all operations will take O(1)
- Space complexity -> O(2N)


Approach 2 - if your problem needs faster push operation

- we will keep on pushing all the elements on s1 initially
- if we are asked for top, then we have to move all elements to s2 (so that they will be reversed)
- and then we can return the top of s2 which will be correct
- for popping we just have to check if there is something in s2, if yes then directly pop from there or else move s1 to s2 and then pop
- for pushing we can use s1 but for accessing and popping we use s2

- Time complexity -> Top and Pop operations are taking O(N)
- Space Complexity -> O(2*N)




*/

class stack_q
{

    queue<int> que;

public:
    void push(int x)
    {
        // first push the element
        que.push(x);

        // then consider the size for running the loop
        int size = que.size();

        // run the for loop till before the entered element
        for (int i = 0; i < size - 1; i++)
        {
            // push the front element of the queue in it from the back
            // and then pop that front element
            // follow the same process again

            que.push(que.front());
            que.pop();
        }

        cout << que.front() << endl;
    }

    void pop()
    {
        // here as the queue is changed so normal operation
        cout << que.front() << endl;
        que.pop();
    }

    void top()
    {
        cout << que.front() << endl;
    }

    void size()
    {
        cout << que.size() << endl;
    }
};

class queue_s_one
{

    stack<int> s1, s2;

public:
    void push(int x)
    {

        // first we will move everything from s1 to s2 before inserting
        while (s1.size())
        {
            s2.push(s1.top());
            s1.pop();
        }

        // then we will push the element in s1 which is blank currently
        s1.push(x);

        // then again push back everything from s2 to s1
        while (s2.size())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }

    void pop()
    {
        s1.pop();
    }

    void top()
    {
        cout << s1.top() << endl;
    }

    void size()
    {
        cout << s1.size() << endl;
    }
};

class queue_s_two
{
    stack<int> s1, s2;

public:
    void push(int x)
    {
        s1.push(x);
    }

    void pop()
    {
        if (!s2.empty())
        {
            // if s2 is not empty then we can pop from there directly
            s2.pop();
        }
        else
        {
            while (s1.size())
            {
                s2.push(s1.top());
                s1.pop();
            }

            s2.pop();
        }
    }

    void top()
    {

        if (!s2.empty())
        {
            cout << s2.top() << endl;
        }
        else
        {
            while (s1.size())
            {
                s2.push(s1.top());
                s1.pop();
            }

            cout << s2.top();
        }
    }
};

int main()
{
    stack_q stack1;

    // stack1.push(3);
    // stack1.push(14);
    // stack1.push(31);
    // stack1.top();
    // stack1.pop();
    // stack1.pop();
    // stack1.top();
    // stack1.size();

    // queue_s_one queue1;
    queue_s_two queue1;

    queue1.push(12);
    queue1.push(40);
    queue1.push(34);
    queue1.pop();
    queue1.top();
    queue1.pop();
    queue1.top();
    // queue1.size();

    return 0;
}