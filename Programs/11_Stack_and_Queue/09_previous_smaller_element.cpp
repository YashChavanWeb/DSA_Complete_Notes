#include <bits/stdc++.h>
using namespace std;

/*

// Previous Smaller element





1. Brute Force approach
- we will be using 2 loops
- first loop to traverse the array
- inner loop to traverse to the left of the array for finding the nearest smallest
- and then we can add it in the result array

- Time complexity -> O(N^2)
- Space complexity -> O(1)








2. Optimal Approach

- we will be using a stack based approach again
- start traversing from the left
- keep popping the stack elements until it is empty or is smaller than the element

- Time complexity -> O(N + N) -> O(2N)
- Space complexity -> O(N + N) -> O(2N)


*/

vector<int> previous_smaller_ele_brute(vector<int> arr)
{
    vector<int> result(arr.size(), -1);

    for (int i = 0; i < arr.size(); i++)
    {

        for (int j = i - 1; j >= 0; j--)
        {

            // check if we have any smaller element on the left
            if (arr[j] < arr[i])
            {
                result[i] = arr[j];
                break;
            }
        }
    }

    return result;
}

vector<int> previous_smaller_ele_optimal(vector<int> arr)
{
    stack<int> st;
    vector<int> result(arr.size(), -1);

    for (int i = 0; i < arr.size(); i++)
    {

        // run while until we have someone greater
        while (!st.empty() && st.top() >= arr[i])
        {
            st.pop();
        }

        // if in stack there is smaller then update result array
        result[i] = st.empty() ? -1 : st.top();

        // push the element in the stack as well
        st.push(arr[i]);
    }

    return result;
}

int main()
{

    vector<int> arr = {4, 5, 2, 10, 8};

    // vector<int> result = previous_smaller_ele_brute(arr);
    vector<int> result = previous_smaller_ele_optimal(arr);

    for (int i = 0; i < arr.size(); i++)
    {
        cout << result[i] << " ";
    }

    return 0;
}