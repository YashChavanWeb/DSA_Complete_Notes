#include <bits/stdc++.h>
using namespace std;

/*
// Find the missing number in the array
- we will be given n and n-1 numbers
- the array will be containing numbers between 1 to n
- we have to tell the number that is not there from 1 to n

1. Brute force approach
- we know n and also know that the numbers are from 1 to n
- so using linear search we will check whether the element is present or not in the array
- and if it is not then we can return that element
- so we will require two loops to do this

- Time complexity -> o(n^2)
- Space complexity -> o(1)



2. Better Approach
- we can use hashing
- so if the elements are from 1 to 5, so we will have to create a hash of size 6 with all values as zero
- then iterate and make all the values of hash 1 where the element match with the index
- then see where there is 0 still in the hash from 1 to n and then return that index

- Time complexity -> O(n) + O(n) -. O(2n)
- Space complexity -> O(n) - as we are using a extra hash

3. Optimal Approach

Sum
- we know that the numbers are upto n -> so we can do n(n+1)/2
- then we will also sum the elements in the array
- and then we can do s1 - s2 and the diff will be the remaining number
- Time complexity -> O(n)
- Space complexity -> O(1)

XOR
- XOR of two same numbers is 0
- 0 xor with any number is the number itself

- so we can use here two for loops for xor 1 and xor 2 and then do
xor1 xor xor2 and we get the number that is missing
- but the time complexity will be O(2n) due to 2 loops
- so in order to fix that we can use logic of xor1 xor (i+1) and then at the end XOR1 xor n
- and with this there will be only 1 for loop

- Time complexity -> O(n)
- Space complexity -> O(1)

*/

int missing_brute(vector<int> arr, int n)
{
    for (int i = 1; i <= n; i++)
    {
        bool flag = 0;
        for (int j = 0; j < n; j++)
        {
            if (i == arr[j])
            {
                flag = 1;
                break;
            }
        }

        if (flag == 0)
        {
            return i;
        }
    }

    return -1;
}

int missing_better(vector<int> arr, int n)
{
    int hash[n + 1] = {0}; // hash with all values as 0

    for (int i = 0; i < n - 1; i++)
    {
        hash[arr[i]] = 1;
    }

    for (int i = 1; i < n; i++)
    {
        if (hash[i] == 0)
        {
            return i;
        }
    }
}

int missing_optimal_sum(vector<int> arr, int n)
{
    int s1 = (n * (n + 1)) / 2;

    int s2 = 0;
    for (int i = 0; i < n - 1; i++)
    {
        // we are doing n-1 here as the number of elements in the array are n-1 and 1 element is missing

        s2 += arr[i];
    }

    return s1 - s2;
}

int missing_optimal_xor(vector<int> arr, int n)
{
    int xor1 = 0;

    // we can remove this for loop
    // for (int i = 0; i < n; i++)
    // {
    //     xor1 = xor1 ^ i;
    // }

    int xor2 = 0;
    for (int i = 0; i < n - 1; i++)
    {
        xor2 = xor2 ^ arr[i];

        // here we can write the logic for xor1
        xor1 = xor1 ^ (i + 1);
    }
    xor1 = xor1 ^ n;

    return xor1 ^ xor2;
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

    // int result = missing_brute(arr, n);
    // int result = missing_better(arr, n);
    // int result = missing_optimal_sum(arr, n);
    int result = missing_optimal_xor(arr, n);
    cout << "The missing number in array is : " << result;

    return 0;
}