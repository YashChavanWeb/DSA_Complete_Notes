#include <bits/stdc++.h>
using namespace std;

/*

// Find the largest odd number in the string
- Eg: 3214 - so the largest odd number is 321


Note:
- as the numbers are in the string, so individually they are characters
- so to covert them to numbers we can do s[i] - '0' -> converted to integer
- this is because we are subtracting two ASCII values to get the actual integer





1. Optimal approach
- we know that any odd number ends with a odd digit at the end 1,3,5,7,9
- so if we start from the end, and when we encounter a odd number, simply we will return the string till that odd no
- which will indeed be the largest odd number


- Time complexity -> O(n) -> no complexity of substring as we are using it just once
- Space complexity -> O(1)


*/

string largest_odd_number(string s)
{
    for (int i = s.length() - 1; i >= 0; i--)
    {

        // first convert the character to the number
        int num = s[i] - '0';

        // checking if it is odd
        if (num % 2 != 0)
        {
            // this means that the num we got is odd
            // so we will return the string till this odd number

            return s.substr(0, i + 1);
            // here the 0 is the starting index and i+1 is the length of the string
        }
    }

    // if we don't get any odd number then we will return empty string
    return "";
}

int main()
{
    string s;
    cin >> s;

    cout << "The largest odd number in the string is : " << largest_odd_number(s);

    return 0;
}