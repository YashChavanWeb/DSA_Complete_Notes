#include <bits/stdc++.h>
using namespace std;

/*

// Search in rotated sorted array

- Binary Search eliminates one half
- in the question through observation we know that one of the half is sorted, as the array is rotated

- so our first step will be to identify which half is sorted (low <= mid) and (high>=mid)
- then in the sorted half check whether we have the target element or not
- and then if it is not then we perform binary search on the remaining half

- Time complexity -> O(n)
- Space complexity -> O(1)

*/

int rotated_search(vector<int> arr, int target)
{
    int low = 0, high = arr.size() - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == target)
            return mid;

        // find out if the array is sorted or not

        // check if the left half is sorted
        else if (arr[low] <= arr[mid])
        {

            // here we come means the left half is sorted

            // here we check if the target lies between the low and the mid which is the left sorted parts
            if (arr[low] <= target && target <= arr[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        else
        {
            // here we know that the right half will be sorted

            // so here we check if the target lies between the right sorted part
            if (arr[mid] <= target && target <= arr[high])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
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

    int target;
    cin >> target;

    cout << "The Element is found at the index " << rotated_search(arr, target);

    return 0;
}