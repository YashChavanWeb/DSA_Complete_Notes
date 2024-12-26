#include <bits/stdc++.h>
using namespace std;

/*

// Binary Search

- searching algorithm in a limited search space
- binary search is applicable when we are performing a search on a sorted array only

1. Real life example
- instead of searching page by page in a dictionary
- we can split it in half and just iterate in the half where the word letter is there
- and we go on doing this, until we find the first word



2. Coding problem example
- we have to find the given target in the array
- so we have to perform binary search

- low = 0 and high = n-1
- calculate mid and then compare the target with the mid
- if high crosses low then it means that the target is not present in the array



3. Iterative code
// using while loop



4. Recursive code



5. Time complexity

- Time complexity -> O(log2n)

Eg: if 32 size array then log2 2^5 -> log 5
 - so we will have approx 5 steps to divide array till single
  32 - 16 - 8 - 4 - 2 - 1 - approx 5 steps



6. Overflow case

- if we are performing binary search on the last element, then
mid = INT_MAX + INT_MAX/2 -> so it will overflow

- to overcome this we can use long long data type
- or we can use mid = low + (high - low)/2


*/

int binary_search_iterative(vector<int> arr, int target)
{
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == target)
            return mid;

        if (arr[mid] < target)
            low = mid + 1;

        if (arr[mid] > target)
            high = mid - 1;
    }

    return -1;
}

int binary_search_recursive(vector<int> arr, int low, int high, int target)
{

    if (low > high)
        return -1;

    int mid = (low + high) / 2;

    if (arr[mid] == target)
        return mid;

    else if (arr[mid] > target)
        return binary_search_recursive(arr, low, mid - 1, target);
    else
        return binary_search_recursive(arr, mid + 1, high, target);
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

    int target;
    cin >> target;

    int idx = binary_search_iterative(arr, target);
    // int idx = binary_search_recursive(arr, 0, arr.size() - 1, target);
    cout << "The target is found at index " << idx;

    return 0;
}