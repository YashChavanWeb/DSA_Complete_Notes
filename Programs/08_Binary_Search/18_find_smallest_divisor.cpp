#include <bits/stdc++.h>
using namespace std;

/*

// Find the smallest divisor, given a threshold
- eg: 1 2 5 9 is the array given and 6 is the threshold given
- if we divide all the array elements by a number and then add the ceil of the answer,
- ans should be <= the given threshold





1. Brute force solution

- we will divide the array elements by all the numbers
- and then sum it up and compare with the threshold
- if it is <= then we will return that value which is the min divisor
- the range in which the answer will be is 1 to the max_element in array
- as the max value of threshold can not be more than n

- Time complexity -> O(max_element * n)
- Space complexity -> O(1)





2. Binary Search (Optimal) Approach

- Time complexity -> O(log2(max_element) * n)


Note: 
The minimum sum that we can have is n -> size of array
- you can add a small condition at the very top for this as well










*/

int smallest_divisor_brute(vector<int> arr, int threshold)
{
    int n = arr.size();

    int max_element_array = *max_element(arr.begin(), arr.end());

    // divisor loop
    for (int d = 1; d <= max_element_array; d++)
    {
        int sum = 0;

        // i loop for iterating through the array
        for (int i = 0; i < n; i++)
        {
            sum += ceil((double)arr[i] / (double)(d));
        }

        // If the sum is less than or equal to the threshold, return the divisor
        if (sum <= threshold)
        {
            return d;
        }
    }

    // If no divisor satisfies the condition, return -1
    return -1;
}

int find_sum(vector<int> arr, int divisor)
{
    int sum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        sum += ceil((double)arr[i] / (double)(divisor));
    }
    return sum;
}

int smallest_divisor_optimal(vector<int> arr, int threshold)
{

    int low = 1, high = *max(arr.begin(), arr.end());
    int ans = -1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (find_sum(arr, mid) <= threshold)
        {
            high = mid - 1;
            ans = mid;
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

    int threshold;
    cin >> threshold;

    // int divisor = smallest_divisor_brute(arr, threshold);
    int divisor = smallest_divisor_optimal(arr, threshold);
    cout << "The minimum divisor is : " << divisor;

    return 0;
}