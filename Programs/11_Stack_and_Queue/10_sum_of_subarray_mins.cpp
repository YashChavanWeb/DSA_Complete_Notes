#include <bits/stdc++.h>
using namespace std;

/*

// Sum of Subarray minimum

- we are given an array
- we have to take all the sub arrays of the array
- and then find the minimum of each subarray
- then we have to sum up the minimums to a value and return it





1. Brute force Approach
- find all the possible subarrays
- find their mini and its sum

- Time complexity -> O(N^2)
- Space complexity -> O(1)





2. Optimal Approach

- instead of finding all the sub arrays
- we can find individual contributions of a element, and then sum it up
- find the next smaller element on left (index)
- find the next smaller element on the right (indices)
- and then subtract it with the index of the element
- then multiply them so that we get the number of subarrays
- and then we multiply it with the ans so that we get no. of occurrences of that element
- and then add it to the sum

- for avoiding the duplicates -> eg: 2 1 3 4 2
- so here for 2 there will be same subarrays and so the count may hamper
- so for that for left consider both two and for right consider only 1 two
- with this the problem will get solved

- Time complexity -> O(2N + 2N + N) - NSR + NSL + traverse array
- Space complexity -> O(N + N)


*/

vector<int> get_nsl(vector<int> arr, int n)
{
    stack<int> st;
    vector<int> result(n);

    // start traversing from the reverse
    for (int i = 0; i < n; i++)
    {

        // if stack emtpy then directly add -1
        if (st.empty())
        {
            result[i] = -1;
        }
        else
        {

            // keep popping until the stack has element smaller than the given
            // we are storing indexes in the stack
            while (!st.empty() && arr[st.top()] >= arr[i])
            {
                st.pop();
            }

            // here the stack is empty or we have found the smaller element
            result[i] = st.empty() ? -1 : st.top();
        }

        //  and at the end we are pushing the current element (index) in the stack
        st.push(i);
    }

    return result;
}
vector<int> get_nsr(vector<int> arr, int n)
{
    stack<int> st;
    vector<int> result(n);

    // start traversing the array from the front as we want the right
    for (int i = n - 1; i >= 0; i--)
    {

        // if stack is empty then we have to add the max that is size n
        if (st.empty())
        {
            result[i] = n;
        }
        else
        {

            // now here the same condition of getting the smaller until that we keep popping
            // but here we will be using >= as we also want to avoid the duplicates
            while (!st.empty() && arr[st.top()] >= arr[i])
            {
                st.pop();
            }

            // here again the stack may be empty or having the smaller element
            result[i] = st.empty() ? n : st.top();
        }

        // at the end push the index of element in the stack
        st.push(i);
    }

    // return the result array
    return result;
}

long long sum_of_subarray_mins_optimal(vector<int> arr)
{
    int n = arr.size();
    long long sum = 0;
    int M = 1e9 + 7;

    // first find the two arrays of next smaller to right and next smaller to left
    vector<int> nsl = get_nsl(arr, n);
    vector<int> nsr = get_nsr(arr, n);

    // start traversing the given input
    for (int i = 0; i < n; i++)
    {

        // first get the no of elements on left and right
        long long left = i - nsl[i];
        long long right = nsr[i] - i;

        // no of subarrays possible
        long long total_ways = left * right;

        // now once we get the total ways we will just multiply it with the element
        long long total_Sum = total_ways * arr[i];

        // now add it to the final sum
        sum += total_Sum;
    }

    return sum;
}

int sum_of_subarray_min_brute(vector<int> arr)
{

    int sum = 0;

    // start iterating the array
    for (int i = 0; i < arr.size(); i++)
    {
        // the first element is itself a min as no subarray so we are doing this
        int mini = arr[i];

        // from i to n we will be finding all the sub arrays
        for (int j = i; j < arr.size(); j++)
        {

            // find the min with respect to each subarray
            mini = min(arr[j], mini);

            // also update the sum everytime
            sum += mini;
        }
    }

    return sum;
}

int main()
{
    vector<int> arr = {3, 1, 2, 4};

    // int sum = sum_of_subarray_min_brute(arr);
    long long sum = sum_of_subarray_mins_optimal(arr);
    cout << "The sum is " << sum;

    return 0;
}