#include <bits/stdc++.h>
using namespace std;

/*

// Rotated sorted array, but the elements can have duplicates
- the question is that we have to tell whether the element exists or not



- so here the steps that we will use is:
- trim down the conditions
- the problem that we have is:
    arr[low] = arr[mid] = arr[high], due to which we cannot identify the sorted half
- so if the above condition is true, then we will simply shrink the search space


- the other conditions have no problem, just identifying which half is sorted and then eliminating the half is the main problem
- which can be solved by modifying the code slightly


- Time complexity -> O(log2n) -> average , O(n/2) -> in the worst case

Note:
when we have duplicates, first try on the unique adn then fit the test case on the duplicate ones


*/

bool rotated_duplicates(vector<int> arr, int target)
{

    int low = 0, high = arr.size() - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == target)
            return true;

        if (arr[low] == arr[mid] && arr[mid] == arr[high])
        {
            // shrink the search space

            low = low + 1;
            high = high - 1;

            // continue until this condition is false
            continue;
        }

        if (arr[low] <= arr[mid])
        {

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

    return false;
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

    if (rotated_duplicates(arr, target))
    {
        cout << "Element found in the array" << endl;
    }
    else
    {
        cout << "Element not found in the array" << endl;
    }

    return 0;
}