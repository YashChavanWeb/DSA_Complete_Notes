// ##### Hashing ######

// if we want to check for how much time a element appears in the array then brute force approach:
// -- iterate through the entire array and then keep a counter
// -- display the counter value by comparing the arr each element with number given
// -- Complexity is O(Qxn) where Q is the numbers given to check, n is the no of iterations / size of array

// ##### What is hashing #####
// hashing is prestore something and then fetching it

// Technique:
// so first we have to see what is the max element in array (1 to 9 or 1 to 12 or else)
// then after we get the max, hash array is created with that much size with all the initial values as 0 (if 12 is max in array then hash array is of size 12)
// ----- then precalculation takes place -----
// - sees 1 in original array store 1 at index 1
// -  sees 1 again in the original array so store 2 at index 1
// - this process goes on
// now if we get question how many times 1 appears we can just do hash[1] and it will give how many times as we have done the pre calculation

#include <bits/stdc++.h>
using namespace std;

int main()
{

    // The values to take
    /*
        1. array size
        2. array elements
        3. query size
        4. query elements
    */

    //    array size
    int n;
    cout << "Enter the size of array : ";
    cin >> n;

    // array
    int arr[n];
    cout << "Enter the elements in the array : ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // pre-computation
    int hash[13] = {0}; // here we assume that the max value in array is 12
    // if it is given 10^5 then we can write hash[100001]

    // now we will write logic for the increment of the value of the array
    for (int i = 0; i < n; i++)
    {
        // this is done when we the query element is same as the array element
        hash[arr[i]] += 1;
    }

    // query
    int q;
    cout << "Enter the value of q:";
    cin >> q;
    cout << "Enter values to search count: ";
    while (q--)
    {

        // here we are taking the number / element with which we want to compare
        int number;
        cin >> number;

        // fetch
        cout << hash[number] << endl;
        // here if we do hash[2] then it will give how many times 2 appeared in the array
    }

    // But........
    // The maximum size array you can declare is 10^6 - integer array - inside main
    // But if we declare globally then we can declare 10^7 array - integers
    // boolean - main 10^7 and global 10^8

    // Note:
    /*
        - if we declare anything in main and don't give value then it is initialized by garbage value
        - if we declare globally then everything initialized to 0
    */

    return 0;
}