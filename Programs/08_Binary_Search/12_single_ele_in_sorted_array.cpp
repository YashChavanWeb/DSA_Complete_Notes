#include <bits/stdc++.h>
using namespace std;

/*

// Single element in sorted array
- array given, all of the numbers will be appearing twice, and only one number will be appearing once
- it is guaranteed that there will be a single elements and all others will be twice only




1. Brute Force Approach
- if standing at a index, if the index + 1 and index - 1, either of the two match the element of index then it is repeated
- if both does not match then it means that the element is unique

- also with this there is a chance of overflow during the runtime so we have to write separate conditions for the first and the last element


- Time Complexity: O(n)
- Space Complexity: O(1)





2. Optimal Solution
- for this we will use Binary Search
- so as we have twice repetition of each element, we have a observation

-- For the same element (1,1)
- (even, odd) -> we are on the left half and the element is on the right half
- (odd, even) -> we aer on the right half and the element is on the left half

- we will start from the index 1 and index n-1 so that we will not consider the first and the last element
- with this it will reduce lot of our work for writing lots of edge cases

- so check for the first last element separately
- then for the rest, we will use elimination
- we will calculate the mid, and check the mid index
    -- if it is odd index and the previous element is same,then it means that we have element on the right half and so eliminate on the left hal
    -- if it is even index and the element after it is same, then it means that we are on the right side nad the element is on the left side so eliminate the right side

- Time complexity -> O(logn)
- Space Complexity -> O(1)


*/

int single_element_brute(vector<int> arr)
{
    int n = arr.size();

    // what if the array contains just a single element
    if (n == 1)
    {
        return arr[0];
    }

    // write separate conditions for the first and the last element
    if (arr[0] != arr[1])
        return arr[0];
    if (arr[n - 1] != arr[n - 2])
        return arr[n - 1];

    for (int i = 1; i < n - 1; i++)
    {
        if (arr[i] != arr[i - 1] && arr[i] != arr[i + 1])
        {
            return arr[i];
        }
    }

    return -1;
}

int single_element_optimal(vector<int> arr)
{
    int n = arr.size();

    // first step is to trim down the search for writing less cases
    int low = 1, high = n - 2;

    // what if the array contains only a single element
    if (n == 1)
        return arr[0];

    // what if the element is in the first or last position
    if (arr[0] != arr[1])
        return arr[0];

    if (arr[n - 1] != arr[n - 2])
        return arr[n - 1];

    // start with the while loop
    while (low <= high)
    {
        int mid = (low + high) / 2;

        // check if the mid is pointing to the single element

        if (arr[mid] != arr[mid - 1] && arr[mid] != arr[mid + 1])
            return arr[mid];

        // what if the element is in either of the halfs

        // first check for the left half
        if (((mid % 2 == 1) && arr[mid - 1] == arr[mid]) || ((mid % 2 == 0) && arr[mid] == arr[mid + 1]))
        {

            // we have checked for both if mid comes on even or odd index
            // if this is the case, as we are on the left the element will be on the right so eliminate left

            low = mid + 1;
        }
        else
        {

            // here we come that means we are on the right side and the element will be on the left side
            // so we will eliminate the right half

            high = mid - 1;
        }
    }

    return -1;
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

    int single_element = single_element_brute(arr);
    // int single_element = single_element_optimal(arr);
    cout << "The single element in the array is : " << single_element;

    return 0;
}