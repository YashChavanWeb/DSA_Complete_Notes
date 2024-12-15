#include <bits/stdc++.h>
using namespace std;

// Pass by Value
void doSomething(int val)
{
    cout << (val + 5) << endl;
    cout << (val + 10) << endl; // value is 25 but only here not in main
}

// Pass by Reference
void doSome(int &val) // here we directly give the address so value on original location is changed
{
    cout << (val + 5) << endl;
    cout << (val + 10) << endl; // value is 25 updated on the address
}

// Pass by Reference - Array
void passArr(int arr[])
{ // array always goes with reference so value is updated on the address
}

int main()
{

    // ---------------------- Functions ----------------------

    // Note :
    // 1. Functions are set of codes that perform something for you.
    // 2. Functions are used to modularize codes
    // 3. Functions are used to increase readability
    // 4. Functions are used to use same code multiple times

    // Types of Functions :
    // 1. void -> does not return anything
    // 2. return -> returns a value
    // 3. pre-defined functions -> have been already declared in the library

    int num1, num2;
    cin >> num1 >> num2;
    int minimum = min(num1, num2);
    int maximum = max(num1, num2);
    cout << minimum;
    cout << maximum;
    // Note : if it is a return function & you dont return a value then it will return a garbage value

    // 4. Pass by Value

    int val = 10;
    cin >> val;
    doSomething(val); // a copy of val is sent, so the actual val is not changes
    cout << val;      // value is 10

    // 5. Pass by Reference
    int val = 10;
    cin >> val;
    doSome(val); // actual val is sent, so the actual val is changes
    cout << val;

    // ---------------------- Passing Arrays in Functions ----------------------
    int arr[3];
    passArr(arr);

    return 0;
}