#include <bits/stdc++.h>
using namespace std;

/*

// Maximum sum Subarray
- array of +ves and -ves given, find subarray that has the maximum sum


1. Brute force solution
- finding all the subarrays
- counter i stays on an element, j gives the next index where we are going and then k finally adds the sum

- so basically i and j will decide the two locations of the subarrays start and end and then k will iterate between them


- Time complexity -> O(n^3)
- Space complexity -> O(1)





2. Better Approach
- here we will only use the i and the j pointer
- here when we have the sum then no need to calculate the entire sum again using the k pointer
- sum at that point we already have just add the next element with it

- Time complexity -> O(n^2)
- Space complexity -> O(1)





3. Optimal Approach
- we will be using the Kadane's Algorithm
- so there will be two variables sum and maxi
- the sum will be initially 0 and will be added with the elements
- maxi will be given the sum value
- but here if the sum is < 0 then we will not carry that element in the sum and so we will make sum = 0 after maxi takes the value of sum

Steps:
add the element to the sum
compare and replace the sum with the maxi
if sum < 0 then don't carry the sum, make sum =0 and carry on ahead

- finally if it is a empty sub array (max is less than 0) then we will reinitialize by 0 and then return it

- Time complexity -> O(n)
- Space complexity -> O(1)


// Follow up question
- print the sub-arrays giving the maximum sum



*/

int max_sum_brute(vector<int> arr, int n)
{
    int maxi = INT_MIN;

    // iterate the loop for the i pointer
    for (int i = 0; i < n; i++)
    {
        // iterate the loop for the j pointer
        for (int j = i; j < n; j++)
        {
            int sum = 0;
            // iterate the loop for the k pointer
            for (int k = i; k <= j; k++)
            {
                sum += arr[k];
            }
            maxi = max(maxi, sum);
        }
    }

    return maxi;
}

int max_sum_better(vector<int> arr, int n)
{
    int maxi = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            maxi = max(sum, maxi);
        }
    }

    return maxi;
}

int max_sum_optimal(vector<int> arr, int n)
{

    int sum = 0;
    int maxi = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];

        if (sum > maxi)
            maxi = sum;

        if (sum < 0)
            sum = 0;
    }

    // for the empty sub array logic
    if (maxi < 0)
    {
        maxi = 0;
    }

    return maxi;
}

vector<int> max_sum_optimal_subarray(vector<int> arr, int n)
{

    int sum = 0;
    int maxi = INT_MIN;

    int start = 0;

    int ansStart = -1, ansEnd = -1;

    for (int i = 0; i < n; i++)
    {

        // for setting up the start of the subarray
        // if the sum is zero, then it is a start of the new subarray

        if (sum == 0)
        {
            start = i;
        }

        sum += arr[i];

        if (sum > maxi)
        {
            maxi = sum;

            // so here we will write logic if the sum is greater which means we have got array that has sum greater than max so we are storing the sum into the maxi

            ansStart = start, ansEnd = i;
        }

        if (sum < 0)
            sum = 0;
    }

    // for the empty sub array logic
    if (maxi < 0)
    {
        maxi = 0;
    }

    return {ansStart, ansEnd};
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

    // cout << "The maximum subarray sum in the array is : " << max_sum_brute(arr, n);
    // cout << "The maximum subarray sum in the array is : " << max_sum_better(arr, n);
    // cout << "The maximum subarray sum in the array is : " << max_sum_optimal(arr, n);

    vector<int> result = max_sum_optimal_subarray(arr, n);
    cout << "the maximum subarray is : ";

    for (int i = result[0]; i <= result[1]; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}