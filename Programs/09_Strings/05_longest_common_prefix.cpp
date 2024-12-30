#include <bits/stdc++.h>
using namespace std;

/*

// Find the longest common prefix

- we are given an array of strings
- and we have to find the longest common prefix of the string
- prefix - any letter/word that starts from beginning
(towards the end then it is suffix)

- find the prefix that exists in all the strings and also has longest length





1. Brute force Approach

- we keep a pointer on the first string
- then we will check whether that letter is present in all the strings
- if yes then we will add it to the ans
- if no then we will break

- Time complexity -> O(n^2)
- Space complexity -> O(1)






2. Optimal Approach
- first sort the entire array
- so the strings will be on the indexes alphabetical wise
- now we just have to compare the first and the last element characters
- as the characters before the last will be same matching as array is sorted
- so just by comparing the first and the last we can figure out the longest prefix

- Time complexity - O(nlog2n + n) -> sorting + traversing first
- Space complexity - O(1)


*/

string longest_prefix_brute(vector<string> &arr)
{
    // if the list of strings is empty, return an empty string
    if (arr.empty())
    {
        return "";
    }

    // The result string which will store the longest common prefix
    string prefix = "";

    // Iterate through the characters of the first string
    for (int i = 0; i < arr[0].size(); i++)
    {
        // Check if this character exists at the same position in all the strings
        for (int j = 0; j < arr.size(); j++)
        {
            // If the character is out of bounds for any string, or characters don't match
            if (i >= arr[j].size() || arr[j][i] != arr[0][i])
            {

                // arr[j][i] means - i is the position here and j is the string that is in the array - arr[j] - yash -> arr[j][i] - a

                return prefix; // Return the current longest common prefix
            }
        }
        // If the character is found in all strings, add it to the prefix
        prefix += arr[0][i];
    }

    return prefix;
}

string longest_prefix_optimal(vector<string> arr)
{
    string ans = "";

    // sort the string using predefined function
    sort(arr.begin(), arr.end());

    int i = 0;

    // here we will run a while loop and check for 2 conditions not to exceed
    // - the length of the first element should not exceed
    // - the elements need to be equal

    while (i < arr[0].length() and arr[0][i] == arr[arr.size() - 1][i])
    {
        ans += arr[0][i];
        i++;
    }

    return ans;
}

int main()
{
    int n;
    cin >> n;

    vector<string> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // string s = longest_prefix_brute(arr);
    string s = longest_prefix_optimal(arr);
    cout << "The longest prefix in the array of strings is : " << s;

    return 0;
}