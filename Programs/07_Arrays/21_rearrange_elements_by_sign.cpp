#include <bits/stdc++.h>
using namespace std;

/*
// Rearrange the array elements by sign

- given an array with equal +ve and -ve elements (n/2)
- n will always be even number

- rearrange means +ve -ve +ve -ve and so on
- order is maintained like 3 1 2 will still stay 3 1 2 even if it is alternate
- all the +ve elements are at the even indexes and all the -ve elements are at the odd indexes



1. Brute force approach
- create two lists, one for positive and other for negative elements
- append the elements in appropriate order into the appropriate arrays
- after that on all the even indexes replace the +ve array elements and on all the odd indexes replace the -ve array elements

- Time complexity -> O(n) + (O(n/2) + O(n/2)) -two arrays
- Space complexity -> O(n) - two arrays






2. Optimal Approach

- all the positive elements will be at the even indexes
- so we can use a new array where we will store all the +ves on the even index and the -ves on the odd index
- we will do this only in a single pass

- Time complexity -> O(n)
- Space complexity -> O(n)





Variety 2
- The number of +ves and -ves are not mentioned as equal so they can be unequal as well
- the elements that remain should be added at the end of the array
- for this we will fall back to the brute force solution of the variety 1
- because the optimal solution was valid only if the +ves and -ves were equal

- Time complexity -> O(n) + O(min(pos, neg)) + O(leftovers) -> O(n) + O(n) -> O(2n)
- Space complexity -> O(n)



*/

void rearrange_brute(vector<int> &arr, int n)
{

    // two lists for storing the elements of size n/2
    vector<int> pos;
    vector<int> neg;

    // first for loop to store the elements in the list
    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= 0)
        {
            pos.push_back(arr[i]);
        }
        else if (arr[i] < 0)
        {
            neg.push_back(arr[i]);
        }
    }

    // second for loop to replace the elements in the array
    for (int i = 0; i < n / 2; i++)
    {
        arr[2 * i] = pos[i];
        arr[2 * i + 1] = neg[i];
    }
}

void rearrange_optimal(vector<int> &arr, int n)
{
    // starting pointers of the array
    int pos = 0;
    int neg = 1;

    // new array to store the result
    vector<int> new_array(n);

    for (int i = 0; i < n; i++)
    {
        // logic for positive and negative elements
        if (arr[i] > 0)
        {
            new_array[pos] = arr[i];
            pos += 2;
        }
        else if (arr[i] < 0)
        {
            new_array[neg] = arr[i];
            neg += 2;
        }
    }

    // final loop for copying the new array into the main array
    for (int i = 0; i < n; i++)
    {
        arr[i] = new_array[i];
    }
}

void rearrange_variety2_brute(vector<int> &arr, int n)
{

    vector<int> pos, neg;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0)
        {
            pos.push_back(arr[i]);
        }
        else
        {
            neg.push_back(arr[i]);
        }
    }

    if (pos.size() > neg.size())
    {
        // for loop for first adding equal values (end at smaller size)
        for (int i = 0; i < neg.size(); i++)
        {
            arr[2 * i] = pos[i];
            arr[2 * i + 1] = neg[i];
        }

        // for loop for the remaining elements of the positive array
        int index = neg.size() * 2;
        for (int i = neg.size(); i < pos.size(); i++)
        {
            arr[index] = pos[i];
            index++;
        }
    }
    else
    {
        // for loop for first adding equal values (end at smaller size)
        for (int i = 0; i < pos.size(); i++)
        {
            arr[2 * i] = pos[i];
            arr[2 * i + 1] = neg[i];
        }

        // for loop for the remaining elements of the negative array
        int index = pos.size() * 2;
        for (int i = pos.size(); i < neg.size(); i++)
        {
            arr[index] = neg[i];
            index++;
        }
    }
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

    // rearrange_brute(arr, n);
    // rearrange_optimal(arr, n);
    rearrange_variety2_brute(arr, n);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}