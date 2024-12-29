#include <bits/stdc++.h>
using namespace std;

/*

// To find the nth root of the given integer
- 3rd root of 27 is -> 3
- 4th root of 68 is -> -1 (as there is no root)




1. Brute force approach
- we will do a linear search
- we will calculate i^n and then if it is equal to m, then we return i
- if i^n exceeds m then break as we will not get the element
- return -1

- Time complexity -> O(m*log2n) -> here m is the element and log2n is time for finding power





2. Optimal Approach

- use binary search

- Time complexity -> O(log2m * log2n) -> one for binary and other for power

Edge cases:

- what if m is 10^9 then if we do power of 10^9 ^n then it will be very much larger
- the function that finds m^n might overflow, so we have to fix it

- while multiplying, if the ans crosses m then we stop
- because then it will not overflow


*/
int nth_root_brute(int n, int m)
{

    // n is the number we multiply
    // m is the number we get

    for (int i = 1; i <= m; i++)
    {
        if (pow(i, n) == m)
        {
            return i;
        }
        else if (pow(i, n) > m)
        {
            break;
        }
    }
    return -1;
}

// function for handling the overflow condition of power
// return 1 if == m
// return 0 if < m
// return 2 if > m

int func(int mid, int n, int m)
{
    long long ans = 1;
    for (int i = 1; i <= n; i++)
    {
        ans = ans * mid;
        if (ans > m)
            return 2;
    }

    if (ans == m)
        return 1;
    return 0;
}

int nth_root_optimal(int n, int m)
{
    int low = 1, high = m;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        int midN = func(mid, n, m);

        // if func(mid, n, m) == 1, we found the nth root
        if (midN == 1)
            return mid;

        // if func(mid, n, m) == 0, mid^n is less than m, so move to the right half
        else if (midN == 0)
            low = mid + 1;

        // if func(mid, n, m) == 2, mid^n is greater than m, so move to the left half
        else
            high = mid - 1;
    }

    return -1;
}

int main()
{
    int n, m;
    cin >> n >> m;

    int nth_root = nth_root_brute(n, m);
    // int nth_root = nth_root_optimal(n, m);
    cout << "The " << n << " th root of " << m << " is " << nth_root;

    return 0;
}