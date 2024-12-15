// ---------------------- Basic Structure of Program ----------------------

// #include<iostream>   - consists of input and output libraries

#include <bits/stdc++.h> // consists of all the libraries
using namespace std;

int main()
{

    // ---------------------- Input & Output ----------------------

    // Input
    int a;
    cin >> a;

    // Outputs
    cout << "The value of a is " << a << "\n";

    // ---------------------- Data Types ----------------------

    // for greater range of numbers
    long x;
    long long x;

    // decimal numbers
    float x = 4.5;
    double y = 1.233232; // an integer can also be stored in a float or double

    // strings  - getline
    string s1, s2;
    cin >> s1 >> s2; // approach to get string with spaces
    cout << s1 << " " << s2;

    string name;
    etline(cin, name) g; // this is used to get the entire string with spaces
    cout << name;        // string is stored only till the line break, after pressing enter it stops

    // character - char
    char ch = 'a'; // string double quotes , char single quotes

    // Note : integer: -10^9 to 10^9   , long: -10^12 to 10^12  ,  long long: -10^18 to 10^18

    // ---------------------- If else statements ----------------------

    // only if conditions - check all the condition
    // else if conditions - even if one is true it does not check the other one
    // nested if else conditons - same criteria with an addition then we use this

    int age;
    cin >> age;

    // Arrpoach one
    if (age < 18)
    {
        cout << "Not Eligible";
    }
    else if (age >= 18 && age <= 44)
    {
        cout << "Eligible for Job";
    }

    // Arrpoach two
    if (age <= 18)
    {
        cout << "Not Eligible";
    }
    else if (age <= 44)
    { // here we no need to check as the first condition is false
        cout << "Eligible for Job";
    }

    // Nested if else example
    if (age <= 18)
    {
        cout << "Not Eligible";
    }
    else if (age <= 60)
    {
        cout << "You are eligible ";
        if (age >= 55)
        {                                              // because the condition was 18 to 55 print eligible
            cout << ", you can also have retirements"; // and 55 to 60 print same with retirement statement

            // so instead of using 2 if we used nested if else s
        }
    }

    // ---------------------- switch statement ----------------------

    int day;
    cin >> day;

    switch (day)
    {
    case 1:
        cout << "Monday";
        break; // this is important or else all cases after the true once will execute

    case 2:
        cout << "Tuesday";
        break;

    default:
        cout << "Invalid";
    }

    // ---------------------- Arrays ----------------------

    // Array is stored in a consecutive memory location , but the 0th index can be stored anywhere

    // 1D array
    int arr[3];

    // 2D array
    int arr2[2][3]; // rows x columns  -. acts like a matrix

    // ---------------------- Strings ----------------------

    string s = "yash"; // string is also an array of characters
    cout << s[3];      // output will be h

    // to find the length of the string
    int len = s.size();
    cout << s[len - 1]; // by this we will get the last index

    // to change any value from the string
    s[2] = 'm'; // since it is a character we have to using single quotes

    // ---------------------- Loops ----------------------

    // for loop  - scope of i is limited only till for loop
    // while loop
    // do while loop

    return 0;
}
