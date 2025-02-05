#include <bits/stdc++.h>
using namespace std;

/*

// Largest rectangle in Histogram

- we are given a histogram with bars
- and we have to find the largest rectangle that can be formed





1. Brute force Approach
- when we are starting at an element, we cannot continue if the element on right or left is smaller
- it means that in every block, we can go till the smallest element is encountered
- so we need previous smaller and next smaller element for every block
- for pse - assign -1 if not there, for nse - assign n if not there

- and then we can iterate and just find the max of the area
- the area will be width - nse[i] - pse[i] - 1 and height - arr[i]

- Time complexity -> O(2*(2N)) + O(N) - O(5N) - pse + nse + traversal
- Space complexity -> O(N + N + N + N) - stack + stack + list of nse + list of pse

- This is a two pass solution








2. Optimal Approach

- traversing is the main issue due to which we are doing it in two pass
- so we are traversing just once, but still pse can be computed as it is done by traversing itself from start to end

- we will maintain a stack
- when we are pushing element in the stack, we will only push if in it is the smaller once (we maintain the increasing stack)
- when we want to pop the element, then we will compute the area for it
    for it the pse is the top of the stack now
    for it the nse will be element that we are pushing after that as it is smaller one

- if there are elements still left in the stack, then it means that there is no NSE or PSE for those elements
- we will do individual computations by taking pse as -1 and nse as n wherever required


- Time complexity -> O(N + N) - for + stack traversal
- Space complexity -> O(N) - stack


*/

vector<int> get_pse(vector<int> arr, int n)
{

    vector<int> result(n);
    stack<int> st;

    for (int i = 0; i < n; i++)
    {

        if (st.empty())
        {
            result[i] = -1;
            st.push(i);
        }
        else
        {

            while (!st.empty() && arr[st.top()] > arr[i])
            {
                st.pop();
            }

            // when we are here stack can be empty as well
            result[i] = st.empty() ? -1 : st.top();
        }

        st.push(i);
    }

    return result;
}
vector<int> get_nse(vector<int> arr, int n)
{

    vector<int> result(n);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--)
    {

        if (st.empty())
        {
            result[i] = n;
            st.push(i);
        }
        else
        {

            while (!st.empty() && arr[st.top()] > arr[i])
            {
                st.pop();
            }

            // when we are here stack can be empty as well
            result[i] = st.empty() ? n : st.top();
        }

        st.push(i);
    }

    return result;
}

int largest_rect_brute(vector<int> &arr)
{

    int n = arr.size();
    int maxi = -1;

    // first get the previous and next smaller elements
    // the list is containing the indexes of them and not the elements
    vector<int> pse = get_pse(arr, n);
    vector<int> nse = get_nse(arr, n);

    // now iterate
    for (int i = 0; i < n; i++)
    {

        int area = (nse[i] - pse[i] - 1) * arr[i];
        maxi = max(maxi, area);
    }

    return maxi;
}

int largest_rect_optimal(vector<int> &arr)
{

    // basic declarations
    stack<int> st;
    int maxArea = -1;
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {

        // first we will keep popping the stack for greater elements
        while (!st.empty() && arr[st.top()] > arr[i])
        {

            // if this is the case then we got out element
            int element = st.top();
            st.pop();

            // compute the pse and nse
            int nse = i;
            int pse = st.empty() ? -1 : st.top();

            // now compute the area
            int area = arr[element] * (nse - pse - 1);
            maxArea = max(area, maxArea);
        }

        // and then after all this we will push the index of element in stack
        st.push(i);
    }

    // if there are still elements remaining in the stack
    while (!st.empty())
    {
        int element = st.top();
        st.pop();

        // compute the pse and nse
        int nse = n;
        int pse = st.empty() ? -1 : st.top();

        // compute area
        int area = arr[element] * (nse - pse - 1);
        maxArea = max(area, maxArea);
    }

    return maxArea;
}

int main()
{
    vector<int> arr = {3, 2, 10, 11, 5, 10, 6, 3};

    // int area = largest_rect_brute(arr);
    int area = largest_rect_optimal(arr);
    cout << area;

    return 0;
}