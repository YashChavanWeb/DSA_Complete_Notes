#include <bits/stdc++.h>
using namespace std;

/*

// Find how many times the array is Rotated

3 4 5 1 2 -> this means that the array is rotated 3 times

// The logic is some kind of similar as finding the minimum in sorted array

- the index at which the minimum appears is actually the answer of how many times the array is rotated
- if we can keep the track of index while finding the minimum, that index will be the no. of times the array is rotated



// to modify the code we can write:

ans = min(ans, arr[low]) can be written as

if(arr[low] < ans) {
    ans = arr[low]
}


// if we have this then we can also update the index as well

if(arr[low] < ans) {
    index = low or mid as per the side on which we are working
    ans = arr[low]
}

*/

int no_of_times_rotated(vector<int> arr)
{
    int low = 0, high = arr.size() - 1;

    int ans = INT_MAX;
    int index = -1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[low] <= arr[mid])
        {
            // this means left half is sorted

            if (arr[low] < ans)
            {
                index = low;
                ans = arr[low];
            }
            low = mid + 1;
        }
        else
        {
            // this means right half is sorted

            if (arr[mid] < ans)
            {
                index = mid;
                ans = arr[mid];
            }
            high = mid - 1;
        }
    }
    return index;
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

    cout << "The number of times array is rotated is : " << no_of_times_rotated(arr);

    return 0;
}