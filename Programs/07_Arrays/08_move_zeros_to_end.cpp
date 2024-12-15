#include <bits/stdc++.h>
using namespace std;

/*
// Moving 0s to the end of the array


1. Brute force Approach
- first we will iterate and store all the non-zero numbers into a temp array
- then we will place all these elements into the main array at the front
- and then at the end we will just add zeros
- so here we will need 3 loops for doing
- Time complexity: first the storing into temp arr O(n), then storing back into the main array O(x) where x is the size of temp, and then adding zeros O(n-x)
- Time complexity -> O(n+x+n-x)  -> O(2n)
- Space Complexity -> Extra space used -> O(n)
        --  worst case when the entire array is stored as there are no zeros


2. Optimal Solution
- we can use a two pointer approach
- we can first find the first 0 in the array and assign j to it
- then we can start array from j+1 and if i is a non-zero number then just swap it with j and do j++
- i will go on moving forward in a for loop
- Time complexity will be for first iteration O(x) and the second loop O(n-x)
- Time complexity -> O(x + n-x) -> O(n)
- Space Complexity -O(1)

*/

void move_zeros_brute(vector<int> &arr, int n)
{
    vector<int> temp;

    // Step 1
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 0)
        {
            temp.push_back(arr[i]);
        }
    }

    int non_zero_terms = temp.size();

    // Step 2
    for (int i = 0; i < non_zero_terms; i++)
    {
        arr[i] = temp[i];
    }

    // Step 3
    for (int i = non_zero_terms; i < n; i++)
    {
        arr[i] = 0;
    }
}

void move_zeros_optimal(vector<int> &arr, int n)
{
    // Step 1
    int j = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            j = i;
            break;
        }
    }

    // Step 2
    for (int i = j + 1; i < n; i++)
    {
        if (arr[i] != 0)
        {
            swap(arr[i], arr[j]);
            j++;
        }
    }
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

    // move_zeros_brute(arr, n);
    move_zeros_optimal(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}