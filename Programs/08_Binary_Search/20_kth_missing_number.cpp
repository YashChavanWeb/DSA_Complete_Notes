#include <bits/stdc++.h>
using namespace std;

/*

// Find the kth missing number
- the numbers will be given in the increasing order
- and we have to find the kth missing number
- Eg: [2 3 4 7 11] , k = 5
- if we write the sequence - [1,2,3,4,5,6,7,8,9,10,11]
- the missing numbers are - 1 5 6 8 9 10 - so here 5th missing number is 9
- this is what we have to find



1. Brute force Approach
- the numbers that are lesser than k will take its place
- and then we when any element exceeds then we will return the answer

- Time complexity -> O(n)
- Space complexity -> O(1)




2. Optimal Approach

- if we figure out, between which 2 indexes our answer will lie, then it will be easy to find it
- if we can find how many elements are missing on that index then we can also find the position of the kth missing number

Eg: arr = 2 3 4 7 11
missing = 1 1 1 3 6
k = 5 so it will lie between 3 and 6

- formula to find missing nos till that index is arr[idx] - (idx + 1)

- arr[high] + more is what we have to find
- what is more -> k - missing
- so we can substitute more -> arr[high] + k - missing
- also substitute missing which is arr[idx] - idx - 1
    - so we have -> arr[high] + k - (arr[high] - high - 1)
    - so we have -> arr[high] + k - arr[high] + high + 1
    - so we have -> high + 1 + k
- as low is one place ahead of high so low is high + 1 so we can also write -> low + k

- Time complexity -> O(log2n)
- Space complexity -> O(1)



*/

int missing_no_brute(vector<int> arr, int k)
{
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= k)
            k++;
        else
            break;
    }

    return k;
}

int missing_no_optimal(vector<int> arr, int k)
{
    int n = arr.size();
    int low = 0, high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        // eg: if we have 3 4 7 then mid is 4 and missing number is 4 - 1 + 1 = 4 - so here we will have 4th missing number that is 5
        int missing_index = arr[mid] - (mid + 1);

        if (missing_index < k)
        {
            // we have to find the index equal to k not less so
            low = mid + 1;
        }
        else
        {
            // we have to find the index less than k so we have to go to left half
            high = mid - 1;
        }
    }

    // at the end the high crosses low and so we have to return the answer

    // so we can either return in terms of high
    return high + 1 + k;

    // or we can return in terms of low (which is high + 1)
    // return low + k;
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int k;
    cin >> k;

    // int number = missing_no_brute(arr, k);
    int number = missing_no_optimal(arr, k);

    cout << "The " << k << " th missing number is : " << number;

    return 0;
}