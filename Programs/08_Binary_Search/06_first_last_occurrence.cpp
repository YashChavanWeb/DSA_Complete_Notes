#include <bits/stdc++.h>
using namespace std;

/*
// Find the first and last occurrence of the given element in the array

Eg: if the element repeats {1,2}
    if the element does not repeat {3,3}
    if the element is not present {-1,-1}


1. Brute force approach
- just apply a linear search and store the index where the element occurs
- for the first time if the first = -1 then only store
- and last time goes on updating as at the end we will get the last occurrence index as the array is already sorted












2. Better Approach
- so here we will use the upper bound and the lower bound occurrence
- so if we do upper bound of the target then we will get the element > target so we can just do a -1 for the index
- so upper bound is helpful for the last index

- and for the first occurrence we can use the lower bound as we have >= target
- so we will get the first occurrence, but there are 2 cases
    - first is that if the element that we get is not the target element then we will return -1
    - second that if we return hypothetical index then there will be no element to compare with

- Time complexity -> O(2*(log2n)) -> to find upper bound + lower bound
- Space complexity -> O(1)








3. Optimal Approach

- here we will calculate the first and the last occurrence separately
- we will be using the binary search 3 steps

- Time complexity -> O(2* logn)
- Space complexity -> O(1)


*/

pair<int, int> first_last_occurrence_brutal(vector<int> arr, int n, int x)
{

    pair<int, int> result = {-1, -1};

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
        {
            if (result.first == -1)
                result.first = i;
            result.second = i;
        }
    }

    return result;
}

pair<int, int> first_last_occurrence_better(vector<int> arr, int n, int x)
{

    pair<int, int> result;

    int lb = lower_bound(arr.begin(), arr.end(), x) - arr.begin();

    // check for the upper bound index and the upper bound element
    if (lb == n || arr[lb] != x)
    {
        result.first = result.second = -1;
    }
    else
    {
        result.first = lb;
        result.second = upper_bound(arr.begin(), arr.end(), x) - arr.begin() - 1;
    }

    return result;
}

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

    // pair<int, int> result = first_last_occurrence_brutal(arr, n, x);
    // pair<int, int> result = first_last_occurrence_better(arr, n, x);
    pair<int, int> result = first_last_occurrence_optimal(arr, n, x);

    cout << "The first occurrence of " << x << " : " << result.first << endl;
    cout << "The second occurrence of " << x << " : " << result.second;

    return 0;
}