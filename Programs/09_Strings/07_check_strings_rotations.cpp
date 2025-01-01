#include <bits/stdc++.h>
using namespace std;

/*

// check whether one string is a rotation of another
- both strings are of same length

- eg:
s1 - abc
s2 - cab
Rotated strings

s1 - abcd
s2 - cbda
Not rotated strings






1. Brute force approach
- a string can be rotated n times where n is the length of the string
- we will everytime rotate the string by one character and then compare with the other string
- if it matches then we will return true or else false


### Rotating the string by one shift ###

1. STL function in c++ -> rotate(s.begin() , s.begin() + K , s.end())
-> in the middle we have to tell which position will become the starting position after rotation


- Time complexity -> O(n^2)
- Space Complexity -> O(1)






2. Optimal Approach

- if you concatenate a string with itself, it will contain all rotations as a substring in it
- abcabc  -> will contain all the rotations of abc in it

- Time complexity -> O(n)
- Space Complexity -> O(2*n) -> as we are concatenating


 */

void rotate_string(string &s, int no_of_times)
{
    int n = s.length();

    // do the same process till the given no of times
    for (int i = 0; i < no_of_times; i++)
    {
        // perform substr operation
        // extracts eve
        string temp = s.substr(1, n - 1) + s.substr(0, 1);
        s = temp;
    }
}

bool strings_rotate_brute(string s, string goal)
{

    // run n times as a string can at max rotate n times where n is the length of the string
    for (int i = 0; i < s.length(); i++)
    {
        // rotate the string
        string rotated = s;

        // the rotation is done on a temporary string
        // rotate(rotated.begin(), rotated.begin() + i, rotated.end());

        // writing a predefined function to rotate the string
        rotate_string(rotated, i);

        // at every iteration we will check whether the string matches with the goal
        if (rotated == goal)
        {
            return true;
        }
    }

    return false;
}

bool strings_rotate_optimal(string s, string goal)
{
    if ((s + s).find(goal) != string::npos)
    {
        // npos is no position that means we don't get the position that is equal with the position of the goal in the entire stirng

        // .find() searches and returns the index of the first occurrence

        return true;
    }

    return false;
}

int main()
{
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);

    // bool result = strings_rotate_brute(s1, s2);
    bool result = strings_rotate_optimal(s1, s2);

    if (result)
    {
        cout << "Strings are rotations of each other" << endl;
    }
    else
    {
        cout << "Strings are not rotations of each other" << endl;
    }
}