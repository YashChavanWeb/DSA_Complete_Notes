#include <bits/stdc++.h>
using namespace std;

/*

// Search index position

- return the index where the element can be inserted or the element is present
eg: 1 2 4 7
-> for target 2 we will return index 1
-> for target 6 we will return index 3


- so it is same as returning the lower bound of the element
arr[mid]>=target then ans = mid

*/

int search_insert_position(vector<int> arr, int n, int target)
{
    int low = 0, high = n - 1;
    int ans = n; // hypothetical if the element is not in the array

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] >= target)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
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

    int idx = search_insert_position(arr, n, target);
    cout << "The element " << target << " can be inserted at the index " << idx << " in the array";

    return 0;
}