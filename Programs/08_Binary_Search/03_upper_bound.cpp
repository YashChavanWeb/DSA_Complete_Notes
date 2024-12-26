#include <bits/stdc++.h>
using namespace std;

/*

// Upper bound

- smallest index that is greater than that of the given element

*/

int upper_bound_binary(vector<int> arr, int n, int target)
{
    int ans = n;
    int low = 0, high = n - 1;

    while (low <= high)
    {

        int mid = (low + high) / 2;

        if (arr[mid] > target)
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

    int idx = upper_bound_binary(arr, n, target);
    cout << "The lower bound of the array is at the index " << idx;

    return 0;
}