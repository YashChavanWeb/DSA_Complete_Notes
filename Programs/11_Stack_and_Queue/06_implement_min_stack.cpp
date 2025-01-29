#include <bits/stdc++.h>
using namespace std;

/*

// Implement min Stack

- we have to return the minimum of the stack as in when required



1. Brute force Approach

- we will not use the traversing approach as it is O(N) which is very much time taking
- we will store a pair into the stack
- the element and also the minimum seen until now

- Time complexity -> O(1)
- Space complexity -> O(2*N) - stack + pairs




2. Optimal Approach

- we cannot store two elements in the stack
- we need to optimize the space complexity
- we can keep a min variable which will update the min value when we push the elements
- but when we pop the elements, then we cannot get the previous minimum as the history cannot be saved
- so instead of pushing the element directly in the stack, we will store -
    2 * val_given - prev_min = new_val
Eg: if we want to push 10 and we have 12 as the prev min the by the formula we will store 2*10 - 12 = 8
- the min variable will not be changed it will be modified as it was getting earlier

- now when we pop, then we need to update the min variable as well
    prev_min = 2*val - new_val -> 2*10 - 8 - where 8 is min and 10 is value popped

- if you modify, then the top of the stack will be the min value
- how do we know this, it is because - the min value is always greater than the modified pushed value
- so we always take the min of stack top and min and return it

- Time complexity -> O(1)
- Space complexity -> O(N)




*/

class min_stack
{

    stack<pair<int, int>> st;

public:
    void push(int x)
    {

        // if the stack is empty so no min element so we will directly push into the stack
        if (st.empty())
        {
            st.push({x, x});
        }

        // if not empty then we have to get the min uptil now
        else
        {

            st.push({x, min(x, st.top().second)});
        }
    }

    void getMin()
    {
        cout << st.top().second << endl;
    }

    void top()
    {
        cout << st.top().first << endl;
    }

    void pop()
    {

        st.pop();
    }

    void size()
    {
        cout << st.size() << endl;
    }
};

class minStack
{

    stack<int> st;
    int mini = INT_MAX;

    void push(int x)
    {

        // if stack is empty then push directly
        if (st.empty())
        {
            st.push(x);

            // update mini to x
            mini = x;
        }

        // if not empty then we have to check if it is greater than mini or lesser
        else
        {

            if (x > mini)
            {

                // then no change just push as the mini will not update
                st.push(x);
            }
            else
            {
                // if it is lesser then first a modified value will be pushed in the stack
                st.push(2 * x - mini);

                // and then also update the mini with the actual mini value
                mini = x;
            }
        }
    }

    void pop()
    {

        // first write edge case for stack empty
        if (st.empty())
        {
            return;
        }

        // first pop out the top and then compare so that we will know what to return
        int x = st.top();
        st.pop();

        // now if it is lesser than mini then we know that it was a modified value
        // and so we have to first update the min with the previous minimum
        mini = 2 * mini - x;

        // and if it is greater then no issues just pop as the min will not hamper by that
    }

    int top()
    {
        if (st.empty())
        {
            return -1;
        }

        int x = st.top();

        // this top we got can be a modified value (lesser than mini), if yes then we have to return the min as our top
        if (x < mini)
        {
            return mini;
        }

        // and if it is greater then no change with the mini so actual top we have got so return that only
        else
        {
            return x;
        }
    }

    int get_min()
    {
        return mini;
    }
};

int main()
{
    min_stack st;

    st.push(3);
    st.push(32);
    st.push(13);
    st.push(1);
    st.push(5);

    st.getMin();
    st.top();

    st.pop();
    st.pop();

    st.getMin();

    return 0;
}