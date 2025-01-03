#include <bits/stdc++.h>
using namespace std;

/*

// Convert integer number to its equivalent roman number and vice versa

Eg: 58 - LVIII , 1994 - MCMXCIV

Given Mapping:
I - 1
V - 5
X - 10
L - 50
C - 100
D - 500
M - 1000

IV - 4
IX - 9
XL - 40
XC - 90
CD - 400
CM - 900

Store this in the given vector

1. Integer to Roman Approach

- we will start iterating in the val vector and then find the value that is just smaller than or equal to the input
- then we will take the times - which is num/val[i] which will give how many times we have to add symbol[i] in the string

- then to go the the next number, we will do num%val[i] so if 1994 then we will go to 994

- Time complexity -> O(n)
- Space complexity -> O(1)

Note: if we want variables to initialize only once and they are not going to change then we can use static.














2. Roman to Integer Approach

- we will start iterating in the result from the first character
- then we will go on comparing i value with i+1 value
- initially result will be stored with the last value

- two conditions:
- if i < i+1 then we will subtract from the result
- else we will add to the result

Eg: VIII
start with result as 0
then we move from the left:
add - 5
add - 1 (now 6)
add - 1 (now 7)
add - 1 (now 8)

if it is less than the next, only then we subtract

- Time complexity -> O(n)
- Space complexity -> O(1)

*/

static vector<pair<int, string>> roman_map = {
    {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}};

;

static map<char, int> reverse_roman_map = {
    {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

// Integer to Roman conversion
string int_to_roman(int num)
{
    // initialize the ans variable
    string ans = "";

    // iterate through the map
    for (auto &pair : roman_map)
    {
        // edge case - if number becomes zero then it means it is done
        if (num == 0)
        {
            break;
        }

        // check how many times the symbol will come by dividing by the value
        int no_of_times = num / pair.first;

        // add the symbol into the string number of times it has appeared
        while (no_of_times--)
        {
            ans += pair.second;
        }

        // as the left side is done so we will reduce the number by modulo
        num %= pair.first;
    }

    return ans;
}

// Roman to Integer conversion
int roman_to_int(string s)
{
    // result where we will store the consecutive answers
    int result = 0;

    // Iterate through the string
    for (int i = 0; i < s.length(); i++)
    {
        // now check if the value of s[i] is < than s[i+1], current < next
        if (reverse_roman_map[s[i]] < reverse_roman_map[s[i + 1]])
        {
            // if yes, then subtract the value of s[i] from result
            result -= reverse_roman_map[s[i]];
        }
        else
        {
            // otherwise, simply add the value of s[i] to result
            result += reverse_roman_map[s[i]];
        }
    }

    return result;
}

int main()
{
    int n;
    cin >> n;

    string s;
    cin >> s;

    string result = int_to_roman(n);
    int res = roman_to_int(s);

    cout << "The Roman numeral is: " << result << endl;
    cout << "The Integer is: " << res << endl;

    return 0;
}
