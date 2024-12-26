#include <bits/stdc++.h>
using namespace std;

/*

// Find the square root of a integer number

- we have to return the floor of integer value of the square root

- modify the question - Find the maximum integer, which on squaring is <= n

Note: use binary search when there is a range given, and you know that the answer lies in that range (min, max, etc)



1. Brute force approach

- we will iterate from 1 to n as the sqrt will be max to max between 1 to n where n is the given number
- we will go on doing i*i and compare with n
- if we get it <= then we can replace the ans


2. Optimal Solution

- we will be using binary search
- elimination will be the key

*/

int find_sqrt_brute(int n)
{
    int ans = 1;
    for (int i = 1; i <= n; i++)
    {
        // we are going order wise so else will be executed just once at the end
        if (i * i <= n)
        {
            ans = i;
        }
        else
        {
            break;
        }
    }

    return ans;
}

int find_sqrt_optimal(int n)
{
    int low = 1, high = n;
    int ans = 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (mid * mid <= n)
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            // if mid is greater then eliminate all the further numbers
            high = mid - 1;
        }
    }

    return ans;
}

int main()
{
    int n;
    cin >> n;

    // int square_root = find_sqrt_brute(n);
    int square_root = find_sqrt_optimal(n);

    cout << "The square root of " << n << " is " << square_root;

    return 0;
}