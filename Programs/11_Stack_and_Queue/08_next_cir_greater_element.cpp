#include <bits/stdc++.h>
using namespace std;

/*

// Next greater element - II

- in this case, we not only look for the greater element on the right, if we don't get then we look in the circular direction of the array





1. Brute force approach

- we will traverse the array from the outer loop
- the inner loop will run from i+1 to i+N - 1 (as it is a circular array)
- and the index for getting the value will be j%N - so that we get index within 0 to 5
- if the index value is greater than arr[i] then we can have the index element as greater and break

- Time complexity -> O(N^2)
- Space complexity -> O(N)





2. Optimal Approach

- we will use the monotonic stack concept
- we will double the array hypothetically
- we will be just using hte modular to get the next greater element

- Time complexity -> O(2N + 2N) - traversing the doubled array + pushing elements in stack
- Space complexity -> O(2N)


*/

vector<int> next_cir_greater_element_brute(vector<int> arr, int n)
{

    // make the result array
    vector<int> result(n, -1);

    // start traversing
    for (int i = 0; i < n; i++)
    {

        // now here we will traverse in circular manner
        for (int j = i + 1; j < i + n - 1; j++)
        {

            // first get the index
            int idx = j % n;

            // then compare the index element with the actual array element
            if (arr[idx] > arr[i])
            {
                result[i] = arr[idx];

                // break out
                break;
            }
        }
    }

    return result;
}

vector<int> next_cir_greater_element_optimal(vector<int> arr, int n)
{

    // first create a stack
    stack<int> st;

    // then we will create the result array
    vector<int> result(n, -1);

    // start traversing backwards from the doubled array
    for (int i = 2 * n - 1; i >= 0; i--)
    {

        // then when we get the element, we will compare it with the stack top
        // and we will keep popping until empty or we find greater

        while (!st.empty() && st.top() <= arr[i % n])
        {
            st.pop();
        }

        // now here it either means the stack is empty
        // so don't do anything

        // if stack is not empty then first modify result and then push the current into the stack
        if (i < n)
        {
            result[i] = st.empty() ? -1 : st.top();
        }

        st.push(arr[i % n]);
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

    // vector<int> result = next_cir_greater_element_brute(arr, n);
    vector<int> result = next_cir_greater_element_optimal(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << result[i] << " ";
    }

    return 0;
}