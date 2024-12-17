#include <bits/stdc++.h>
using namespace std;

/*
// Find the number that appears once and the others are twice
- array will be given where there will be numbers repeating twice and just one number repeating once
- we have to find that number


1. Brute force approach
- consider a number arr[i] and then linear search the entire array
- if the number is found once again then it means that the number is repeated
- if we don't get any then the number is not repeated so return it

- Time complexity -> O(n^2)
- Space complexity -> O(1)


2. Better 1 Approach
- here first we will find the max element in the array
- then we will create a hash of max + 1 to fit all the elements
- then iterate for all the values in the array and do hash[arr[i]]++
- and in the third loop just where the hash[arr[i]] is 1 that is the element that appeared once

- Time complexity -> O(N + N + N) -> O(3N)
- Space complexity -> O(N)  (depends on the input)

Note: Can we use the hash everytime ?
- we cannot use it if the array elements are negative, elements too large 10^7 - 10^12
- so we have to use the map data-structure

3. Better 2 Approach
- we can use a map data structure
- the ordered map has O(nlogm) and unordered map has O(n)
- so first we will iterate and then increment values like mpp[arr[i]]++
- then we will check which value in the map is 1 and then return that
- the values that will get stored into the map will be N/2 as each element is occurring twice


- Time complexity -> O(NlogM) + O(N/2 + 1) - where M is the size of the map
- Space complexity -> O(N/2+1)


4. Optimal Approach
- we can simply xor all the numbers
- the number that remains is the one that not cancelled itself
- which means it has appeared once

- Time Complexity -> O(n)'
- Space Complexity -> O(1)



*/

int appearing_brute(vector<int> arr, int n)
{
    for (int i = 0; i < n; i++)
    {

        int cnt = 0;
        int val = arr[i];

        for (int j = 0; j < n; j++)
        {
            if (arr[j] == val)
            {
                cnt++;
            }
        }

        if (cnt == 1)
            return val;
    }
}

int appearing_better1(vector<int> arr, int n)
{

    // find the max element in the array
    int maximum;
    for (int i = 0; i < n; i++)
    {
        maximum = max(arr[i], maximum);
    }

    // create hash and add values
    int hash[maximum] = {0};
    for (int i = 0; i < n; i++)
    {
        hash[arr[i]]++;
    }

    // then find which index has the value 1
    for (int i = 0; i < n; i++)
    {
        if (hash[arr[i]] == 1)
        {
            return arr[i];
        }
    }
}

int appearing_better2(vector<int> arr, int n)
{

    map<int, int> mpp;

    // first add the occurrences into the map
    for (int i = 0; i < n; i++)
    {
        mpp[arr[i]]++;
    }

    // then we will check which value of the map is 1 and return that
    for (auto it : mpp)
    {
        if (it.second == 1)
        {
            return it.first;
        }
    }
}

int appearing_optimal(vector<int> arr, int n)
{
    int xor1 = 0;
    for (int i = 0; i < n; i++)
    {
        xor1 = xor1 ^ arr[i];
    }

    return xor1;
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }

    // cout << "The number appearing once is : " << appearing_brute(arr, n);
    // cout << "The number appearing once is : " << appearing_better1(arr, n);
    // cout << "The number appearing once is : " << appearing_better2(arr, n);
    cout << "The number appearing once is : " << appearing_optimal(arr, n);

    return 0;
}