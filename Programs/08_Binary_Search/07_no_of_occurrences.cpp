#include <bits/stdc++.h>
using namespace std;

/*

// Count the number of occurrences in the array

- to find the number of occurrences in the array
- so we can directly do this using the index
- last occurrence - first occurrence + 1

- Time complexity -> O(2*logn)
- Space complexity -> O(1)


*/

pair<int, int> first_last_occurrence_optimal(vector<int> arr, int n, int x)
{
    pair<int, int> result = {-1, -1};

    // for the first occurrence
    int low = 0, high = n - 1;
    result.first = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == x)
        {
            // we have got the occurrence so mark it as first
            result.first = mid;

            // but we can get even lower index so move to the left
            high = mid - 1;
        }
        else if (arr[mid] > x)
        {
            high = mid - 1;
        }
        else
        {
            // here we have arr[mid] < x so we have not got the element
            // so go on the right
            low = mid + 1;
        }
    }

    if (result.first == -1)
    {
        // there is no first occurrence which means the element does not exist in the array
        return result;

        // don't wait for the second occurrence
    }

    // for the last occurrence
    low = 0, high = n - 1;
    result.second = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == x)
        {
            result.second = mid;
            low = mid + 1;
        }
        else if (arr[mid] > x)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return result;
}

int no_of_occurrences_optimal(vector<int> arr, int x)
{
    pair<int, int> result = first_last_occurrence_optimal(arr, arr.size(), x);

    if (result.first == -1)
        return -1;

    int occurrences = result.second - result.first + 1;
    return occurrences;
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

    int occurrences = no_of_occurrences_optimal(arr, x);
    cout << "The number of occurrences of " << x << " are " << occurrences;

    return 0;
}