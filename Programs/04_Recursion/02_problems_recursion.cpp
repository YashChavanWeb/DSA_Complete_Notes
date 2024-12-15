

#include <bits/stdc++.h>
using namespace std;

// Brute force - global variables
int cnt = 1;
void printName1(string name)
{
    if (cnt > 5)
        return;
    cout << name << endl;
    cnt++;
    printName1(name);
}

// Changing parameters
void printName2(int i, int n)
{
    if (i > n)
        return;

    cout << "Yash" << endl;
    printName2(i + 1, n);
}

// Brute force
int dup = 1;
void print_1ton1(int n)
{
    if (dup > n)
        return;
    cout << dup << endl;
    dup++;
    print_1ton1(n);
}

// Optimized
void print_1ton2(int i, int n)
{
    if (i > n)
        return;
    cout << i << endl;
    print_1ton2(i + 1, n);
}

// Brute force
void print_reverse(int n)
{
    if (n == 0)
        return;

    cout << n << endl;
    print_reverse(n - 1);
}

// backtracking optimized approach
void back_track(int i, int n)
{

    if (i < 1)
        return;

    back_track(i - 1, n);
    cout << i << endl;
}

// backtrack for n to 1
void back_reverse(int i, int n)
{
    if (i > n)
        return;

    back_reverse(i + 1, n);
    cout << i << endl;
}

int main()
{

    // Q.1. Print name n times
    // printName1("Yash");  // Brute force
    // printName2(1, 5); // changing parameters
    // Complexity - O(n) - calling n functions

    // Q.2. Print linearly from 1 to n
    // print_1ton1(5);
    // print_1ton2(1, 5);

    // Q.3. Print in reverse order from n to 1
    // print_reverse(5);

    // Q.4. Print from 1 to n using backtracking - don't use +1
    // this is basically writing the print line after the function call
    // back_track(5, 5);
    // The last thing will get executed at the first

    // Q.5. Print from n to 1 using backtracking - don't use -1
    back_reverse(1, 5);

    return 0;
}