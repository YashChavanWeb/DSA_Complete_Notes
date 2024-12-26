#include <bits/stdc++.h>
using namespace std;

/*

// lower bound of array

- return the smallest index such that, the element at that index is greater than the given number
- arr[index] >= given_number



1. Brute force
- apply linear search

2. Better
- use binary search

- we know that if there is no index in the array, then we will return the size of the array as the index

3. Coding Round

- use predefined function
- idx = lower_bound(arr.begin(), arr.end(), x);

idx will be the iterator pointing to that index
so to get that index just subtract arr.begin()

-idx = lower_bound(arr.begin(), arr.end(), x) - arr.begin();

Note:
if we are asked to find the lower bound in a specific portion of the index
Eg: index 2 to 7
- idx = lower_bound(arr.begin() + 2, arr.end(), x) - arr.begin();


Time complexity -> O(log2n)


*/

int lower_bound_binary(vector<int> arr, int n, int target)
{
    int ans = arr.size();
    int low = 0, high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] >= target) // satisfied and it can be the answer
        {
            ans = mid;

            // look for the smaller index on left
            high = mid - 1;
        }
        else
        {
            // look for the right
            low = mid + 1;
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

    int target;
    cin >> target;

    int idx = lower_bound_binary(arr, n, target);
    cout << "The lower bound of the array is at the index " << idx;

    return 0;
}