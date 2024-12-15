#include <bits/stdc++.h>
using namespace std;

// parameterized approach
void print_sum(int i, int sum)
{

    if (i < 1)
    {
        cout << sum << endl;
        return;
    }

    print_sum(i - 1, sum + i);
}

// functional recursion approach
int func_sum(int n)
{
    if (n == 0)
        return 0;

    return n + func_sum(n - 1);
}

// factorial using functional execution
int factorial(int n)
{
    if (n < 1)
    {
        return 1;
    }

    return n * (n - 1);
}

int main()
{

    // Parameterized functions
    // print_sum(3, 0);
    // here the parameters of the function will change

    // Functional Recursion
    // cout << func_sum(3);
    // here the function will return a value that will be then added with the return of recursive function
    // Eg: return 2 + f(1) -> 1 + f(0) = 1+ 0 -> 2 + 1 = 3

    // task - factorial of n
    // The basic logic here is n*(n-1) and if n is 1 or less then return 1
    cout << "The factorial of 5 is " << factorial(5);

    return 0;
}