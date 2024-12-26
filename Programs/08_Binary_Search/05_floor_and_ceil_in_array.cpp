#include <bits/stdc++.h>
using namespace std;

/*

// Floor and ceil in sorted array

- floor -> largest element in array <= target
- ceil -> smallest element in array >= target

- if we have the number itself in the array, then that itself will be both the floor and the ceil

Approach

- the ceil is the lower bound in the array
- for the floor we can use the similar kind of logic

Note:
- At expert level, we don't need to store the ans in a variable
- we can always return low or high (depends) as the answer

*/

pair<int, int> getFloorAndCeil(vector<int> &arr, int n, int x)
{
    int low = 0, high = n - 1;
    pair<int, int> ans = {-1, -1};

    // for ceil
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] >= x)
        {
            ans.first = arr[mid]; // ceil
            high = mid - 1;       // Move left to find smaller ceil
        }
        else
        {
            low = mid + 1; // Move right to find larger elements
        }
    }

    low = 0, high = n - 1; // Re-initialize for floor search
    // for floor
    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] <= x)
        {
            ans.second = arr[mid]; // floor
            low = mid + 1;         // Move right to find larger floor (we want the largest element <= x)
        }
        else
        {
            high = mid - 1; // Move left to find smaller elements
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

    int x;
    cin >> x;

    pair<int, int> floor_ceil = getFloorAndCeil(arr, n, x);
    cout << "Floor is : " << floor_ceil.second << endl
         << "Ceil is : " << floor_ceil.first;

    return 0;
}