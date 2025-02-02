#include <bits/stdc++.h>
using namespace std;

/*

// Sum of Subarray ranges

- we have to find the all possible subarrays from a list
- then we have to find the diff of max - min for each sub array
- calculate the sum of the answers and then return it





1. Brute force approach

- we will go on traversing with i and j where we find all the subarrays
- and also we notice that the element itself is not contributing to the ans as difference is 0
- so we will find the subarrays, and then their differences using the brute method

- Time complexity -> O(N^2)
- Space complexity -> O(1)







2. Optimal Approach

- we just find the sub array minimum and sub array maximum
- and we just return their difference


- Time complexity -> O(N) (approximately)
- Space complexity -> O(N)









*/

int sum_of_subarray_ranges_brute(vector<int> arr)
{

    int sum = 0;

    for (int i = 0; i < arr.size(); i++)
    {

        // consider the smallest and the largest elements are arr[i] initially
        int maxi = arr[i];
        int mini = arr[i];

        for (int j = i + 1; j < arr.size(); j++)
        {

            // we are starting from i+1 as the element itself is a subarray but it is not contributing to the ans

            maxi = max(arr[j], maxi);
            mini = min(arr[j], mini);
            sum += (maxi - mini);
        }
    }

    return sum;
}

vector<int> get_nsl(vector<int> arr, int n)
{
    stack<int> st;
    vector<int> result(n);

    // start traversing from the reverse
    for (int i = 0; i < n; i++)
    {

        // if stack empty then directly add -1
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
        sum = (sum + total_Sum) % M; // adding modulo operation
    }

    return sum;
}

vector<int> get_nbl(vector<int> arr, int n)
{
    stack<int> st;
    vector<int> result(n);

    // start traversing from the reverse
    for (int i = 0; i < n; i++)
    {

        // if stack empty then directly add -1
        if (st.empty())
        {
            result[i] = -1;
        }
        else
        {

            // keep popping until the stack has element smaller than the given
            // we are storing indexes in the stack
            while (!st.empty() && arr[st.top()] <= arr[i])
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

vector<int> get_nbr(vector<int> arr, int n)
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
            while (!st.empty() && arr[st.top()] < arr[i])
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

long long sum_of_subarray_max_optimal(vector<int> arr)
{
    int n = arr.size();
    long long sum = 0;
    int M = 1e9 + 7;

    // first find the two arrays of next smaller to right and next smaller to left
    vector<int> nsl = get_nbl(arr, n);
    vector<int> nsr = get_nbr(arr, n);

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
        sum = (sum + total_Sum) % M; // adding modulo operation
    }

    return sum;
}

long long sum_of_subarray_ranges_optimal(vector<int> arr)
{
    return sum_of_subarray_max_optimal(arr) - sum_of_subarray_mins_optimal(arr);
}

int main()
{

    vector<int> arr = {1, 4, 3, 2};

    // int sum = sum_of_subarray_ranges_brute(arr);
    long long sum = sum_of_subarray_ranges_optimal(arr);
    cout << "The sum is : " << sum;

    return 0;
}
