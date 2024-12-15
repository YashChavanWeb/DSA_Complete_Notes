// Multiple recursion calls into a single functions
// n queens has multiple recursion calls

// Example: Fibonacci Series
// 0 1 1 2 3 5 8 13 21

// Question: Give the nth fibonacci number from the series

#include <bits/stdc++.h>
using namespace std;

int fibonacci(int n)
{

    if (n <= 1)
        return n;

    int slast = fibonacci(n - 1);
    int last = fibonacci(n - 2);
    return slast + last;
}

int main()
{

    // Normal standard for loop approach
    int n = 5;
    if (n == 0)
    {
        cout << "The Fibonacci Series up to " << n << "th term:" << endl;
        cout << 0;
    }
    else
    {
        int secondLast = 0; // for (i-2)th term
        int last = 1;       // for (i-1)th term
        cout << "The Fibonacci Series up to " << n << "th term:" << endl;
        cout << secondLast << " " << last << " ";
        int cur; // for ith term
        for (int i = 2; i <= n; i++)
        {
            cur = last + secondLast;
            secondLast = last;
            last = cur;
            cout << cur << " ";
        }
    }

    cout << endl
         << fibonacci(3);

    // Time complexity
    // O(2^n) - everyone is calling twice - it is exponential in nature

    return 0;
}