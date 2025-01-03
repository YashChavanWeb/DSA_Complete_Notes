#include <bits/stdc++.h>
using namespace std;

/*

// Longest Palindromic Substring

1. Brute force approach

- find all the substring using o(n^2)
- check for the reverse if it is a palindrome
- and then take the max of the result everytime

- Time complexity -> O(n*n^2) -> O(n^2)
- Space complexity -> O(n)







2. Optimal Approach

- how do we check whether a string is palindrome
- we start from the end and then go to the middle and if i crosses j then palindrome
- we can do this by starting from the middle as well and then going to the end

- but this will work for odd palindromes
- for even palindromes there is a edge case


- Time complexity -> O(n^2)
- Space complexity -> O(n)

*/

string longest_palindrome_optimal(string s)
{
    string res = "";
    int resLen = 0;

    // iterate till the length of the string
    for (int i = 0; i < s.length(); i++)
    {

        // we will initialize the left and right pointers that will be moving from the center
        int left = i, right = i;

        // ##### Odd length palindromes

        // we will run a loop for moving then until both of them are in the bound of the string length, and also both have same value (palindrome)
        while (left >= 0 and right < s.length() and s[left] == s[right])
        {
            // here we know that the string is the palindrome
            // so we will update the result if the length of the current palindrome is greater than the result
            if (right - left + 1 > resLen)
            {
                // updating the length
                resLen = right - left + 1;

                // also we will update the substring to our result string
                res = s.substr(left, right - left + 1);
            }

            // move the left and the right pointers
            left--;
            right++;
        }

        // ##### Even length palindromes
        // we will initialize the left and right pointers that will be moving from the center
        left = i;
        right = i + 1;

        // same code again
        while (left >= 0 and right < s.length() and s[left] == s[right])
        {
            // here we know that the string is the palindrome
            // so we will update the result if the length of the current palindrome is greater than the result
            if (right - left + 1 > resLen)
            {
                // updating the length
                resLen = right - left + 1;

                // also we will update the substring to our result string
                res = s.substr(left, right - left + 1);
            }

            // move the left and the right pointers
            left--;
            right++;
        }
    }

    return res;
}

int main()
{

    string s;
    cin >> s;

    cout << "The longest palindrome string is : " << longest_palindrome_optimal(s);

    return 0;
}