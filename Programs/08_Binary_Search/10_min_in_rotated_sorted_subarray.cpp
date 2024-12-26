#include <bits/stdc++.h>
using namespace std;

/*

// Find the minimum element in the rotated sorted array

- first step is to sort the array
- then find the minimum element in the sorted array
- the minimum element in the sorted array will be the low of that array
- then once we update the minimum then we can eliminate that half and move to the next half


## Optimizing the solution
- if the array between low and high is already sorted entirely
- this happens when we cross the pivot / point of rotation
- so we can directly return the low instead of perfroming binary search

- Time complexity -> O(log2n)


*/

int min_in_rotated(vector<int> arr)
{
    int low = 0, high = arr.size() - 1;
    int ans = INT_MAX;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        // if the search space is already sorted
        if (arr[low] <= arr[high])
        {

            // this means that the entire array is sorted

            ans = min(ans, arr[low]);
            break;
        }

        if (arr[low] <= arr[mid])
        {
            // this means that the left half is sorted

            ans = min(ans, arr[low]);
            low = mid + 1;
        }
        else
        {

            // this means that the right half is sorted

            ans = min(ans, arr[mid]);
            high = mid - 1;
        }
    }

    return ans;
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
    cout << "The minimum element in the array is : " << min_in_rotated(arr);

    return 0;
}