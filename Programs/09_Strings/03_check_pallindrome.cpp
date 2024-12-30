#include <bits/stdc++.h>
using namespace std;

/*

// Check if the string is palindrome or not

1. Brute force Approach
- first we will reverse the string
- the compare both the string and its reverse
- if equal

- Time complexity -> O(n)
- Space complexity -> O(n)



2. Optimal Approach
- we will compare the string from both the end
- if the characters are equal then we will move towards the center of the string
- if the characters are not equal then we will return false

- Time complexity -> O(n)
- Space complexity -> O(1)



*/

void str_reverse(string &rev)
{
    for (int i = 0; i < rev.length() / 2; i++)
    {

        // go on swapping the first and the last
        char temp = rev[i];
        rev[i] = rev[rev.length() - 1 - i];
        rev[rev.length() - 1 - i] = temp;

        // predefined way to swap
        // swap(rev[i], rev[rev.length() - i - 1]);
    }
}

bool check_palindrome_brute(string s)
{
    string rev = s;

    // predefined way to reverse a string
    // reverse(rev.begin(), rev.end());

    // writing function to reverse the string
    str_reverse(rev);

    // after swapping just add a if condition
    if (s == rev)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool check_palindrome_optimal(string s)
{

    // we will go till length/2 because we have to just check half the string with the remaining half
    for (int i = 0; i <= s.length() / 2; i++)
    {
        // if at any point we get that end characters are not the same then w will return false

        if (s[i] != s[s.length() - i - 1])
        {
            return false;
        }
        else
        {
            return true;
        }
    }
}

int main()
{
    string s;
    cin >> s;

    // if (check_palindrome_brute(s))
    if (check_palindrome_optimal(s))
    {
        cout << "The string is palindrome" << endl;
    }
    else
    {
        cout << "The string is not palindrome" << endl;
    }

    return 0;
}