#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s)
{
    int l = 0;
    int r = 0;
    int maxLen = 0;
    map<char, int> hash;

    while (r < s.length())
    {
        if (hash.find(s[r]) != hash.end() && hash[s[r]] >= l)
        {
            l = hash[s[r]] + 1;
        }
        else
        {
            maxLen = max(maxLen, r - l + 1);
        }

        hash[s[r]] = r;
        r++;
    }

    return maxLen;
}

int main()
{
    string s;
    cin >> s;

    cout << "Longest string with non-repeating characters is : " << lengthOfLongestSubstring(s) << endl;

    return 0;
}