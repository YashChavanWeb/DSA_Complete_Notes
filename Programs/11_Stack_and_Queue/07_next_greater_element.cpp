#include <bits/stdc++.h>
using namespace std;

/*

// Next Greater Element (Monotonic Stacks)

- when we use stack to store elements in a specific order, then we call it as Monotonic stack
- we are given a array, and for every element in the array, we have to tell the next greater element towards the right
- if there is no greater number then just keep it -1




1. Brute force Approach

- we first use two for loops for looking onto the right and getting the next greater element
- and it is simply by using nested for Loops

- Time complexity -> O(N^2)
- Space complexity -> O(N)







2. Optimal Approach

- we should be knowing the right elements, if we don't want to traverse
- so we can traverse from the back, so that we will remember and know what are the elements on the right
- we will take a stack, and it will store elements in a specific order

- we can think the elements like light poles
- so when we encounter an element, and if stack is empty then push element into the stack
- if we encounter other element, and then pop off elements in the stack until you get the greater
- we are not worried about the popped elements, as the next greater will be the one we pushed, and not the ones we removed (the pole cannot see beside the taller one)

- Time complexity -> O(N + N) = O(2N) - traverse + pushing n elements
- Space complexity -> O(N + N)


*/

vector<int> next_greater_element_brute(vector<int> arr, int n)
{
    // first consider the result array
    vector<int> result(n, -1);

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {

            // if we get greater than arr[i] element in j then break
            if (arr[j] > arr[i])
            {

                // update the result array
                result[i] = arr[j];
                break;
            }
        }
    }
    return result;
}

vector<int> next_greater_element_optimal(vector<int> arr, int n)
{
    // create the stack
    stack<int> st;

    // create result array
    vector<int> result(n, -1);

    // start traversing the array in reverse order
    for (int i = n - 1; i >= 0; i--)
    {

        // keep popping the elements until we get a element greater than the current element
        while (!st.empty() && st.top() <= arr[i])
        {

            // keep popping the elements
            st.pop();
        }

        // now here we are so it means that either stack is empty, or we got greater element in the stack
        if (!st.empty())
        {
            result[i] = st.top();

            // if we got greater element, then update result array
        }
        // and also push the current element in the stack
        st.push(arr[i]);
    }

    return result;
}

int main()
{

    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // vector<int> result = next_greater_element_brute(arr, n);
    vector<int> result = next_greater_element_optimal(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << result[i] << " ";
    }

    return 0;
}