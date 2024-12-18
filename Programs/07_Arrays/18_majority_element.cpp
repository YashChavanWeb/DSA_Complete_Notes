#include <bits/stdc++.h>
using namespace std;

/*
    // Find the majority element in the array
    - the element that appears more than n/2 times in the array

1. Brute force approach
- keep a counter
- count the no of same elements in the array and increase the counter
- if counter is greater than n/2 then we can return it as it is the majority element

- Time complexity -> O(n^2)
- Space complexity -> O(1)


2. Better Approach
- it is counting and finding the max occurrence so we can use hashing
- here we will use a hashmap where we will store the element and its count
- then iterate through the map and see whose count is > n/2 and return that element
Note: to store the count in hash -> hash[arr]++;

- Time complexity -> store in map O(nlogm) + O(n) traverse map -> O(nlogm + n)
- Space complexity -> O(n) for unique elements




3. Optimal Approach
- Apply Moore's Voting Algorithm
    -- increment the count if we get the same element
    -- decrement the count if we don't get the same element
    -- if count turns zero which means the element is not in that part of the subarray
    -- consider new element and follow same process with the count
    -- at the end we will get a element that may be a majority element
- verify if the element we got is majority or not
    -- iterate and check how many times element occurs it should be more than > n/2
Note: verification step only done if array may or may not have a majority element not sure


- Time complexity -> O(n) + if there is no surety of the majority O(n)
- Space complexity -> O(1)



*/

int majority_brute(vector<int> arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        int cnt = 0;

        for (int j = 0; j < n; j++)
        {
            if (arr[i] == arr[j])
                cnt++;
        }

        if (cnt > n / 2)
            return arr[i];
    }

    return -1;
}

int majority_better(vector<int> arr, int n)
{
    unordered_map<int, int> mpp;

    // store the element, occurrence in the hashmap
    for (int i = 0; i < n; i++)
    {
        mpp[arr[i]]++;
    }

    for (auto it : mpp)
    {
        if (it.second > n / 2)
        {
            // <key,value> -> <element, count> -> <first, second>

            return it.first;
        }
    }

    return -1;
}

int majority_optimal(vector<int> arr, int n)
{

    int cnt = 0;
    int element;
    for (int i = 0; i < n; i++)
    {

        // if condition for first element or any new element
        if (cnt == 0)
        {
            cnt = 1;
            element = arr[i];
        }

        // if the element that we have is still ongoing
        else if (element == arr[i])
        {
            cnt++;
        }

        // here if the element is not found what we are looking for
        else
        {
            cnt--;
        }
    }

    // see if the element that we got is actually the majority element

    int ctr = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == element)
            ctr++;
    }

    if (ctr > n / 2)
        return element;
    return -1;
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

    // int result = majority_brute(arr, n);
    // int result = majority_better(arr, n);
    int result = majority_brute(arr, n);

    if (result == -1)
        cout << "There is no majority element";
    else
        cout << "The majority element is : " << result;

    return 0;
}