#include <bits/stdc++.h>
using namespace std;

/*

// Sum of beauty of all substrings

- so for all the substrings of the string, we will find the max and min frequency and then do
- max  - min -> and then go on adding the ans
- whatever is the sum of all the final ans is the result

Eg: aabcb
aab, aabc, aabcb, abcb, bcb
2-1 = 1
same for all so 1+1+1+1+1 = 5
output is 5



1. Brute force approach
- we will find all the substrings
- and then find the max and the min frequency
- then subtract them and store into the result

- Time complexity -> O(n^3) or O(n^2) as the letters loop is constant for 26 times
- Space complexity -> O(n^2) as we are storing all the substrings in a map




2. Optimal Approach

- we can use set as well for storing the frequencies of the characters
- as the set will be in sorted order, so we can get the highest and the lowest frequency

- Time complexity -> O(n* nlogm) as we are looping over the string and the set
- Space complexity -> O(m) as we are storing the frequencies of the characters in the set

*/

int sum_beauty_brute(string s)
{

    int ans = 0;
    int n = s.size();

    // iterate till the length of the string
    for (int i = 0; i < n; i++)
    {

        // hashmap to store the frequencies of all the characters
        map<char, int> freq;
        for (int j = i; j < n; j++)
        {
            freq[s[j]]++;

            // now to see the most frequent and the least frequent characters

            int most_f = 0, least_f = INT_MAX;
            for (auto mp : freq)
            {
                most_f = max(most_f, mp.second);
                least_f = min(least_f, mp.second);
            }
            ans += most_f - least_f;
        }
    }

    return ans;
}

int sum_beauty_optimal(string s)
{
    int ans = 0;
    int n = s.size();

    // Iterate over all starting points of the substring
    for (int i = 0; i < n; i++)
    {
        // To store frequencies of characters in the current window
        map<char, int> freq_map;
        multiset<int> freq_set;

        // Iterate over all substrings starting at i
        for (int j = i; j < n; j++)
        {
            char ch = s[j];

            // If this character is already present, update the frequency
            if (freq_map.find(ch) != freq_map.end())
            {
                // Remove the old frequency from the multiset
                freq_set.erase(freq_set.find(freq_map[ch]));
            }

            // Update frequency of the character
            freq_map[ch]++;

            // Insert the new frequency into the multiset
            freq_set.insert(freq_map[ch]);

            // Calculate the beauty of the current substring
            int max_freq = *freq_set.rbegin(); // maximum frequency
            int min_freq = *freq_set.begin();  // minimum frequency

            // Add the beauty of this substring to the answer
            ans += (max_freq - min_freq);
        }
    }

    return ans;
}

int main()
{
    string s;
    cin >> s;

    // int sum = sum_beauty_brute(s);
    int sum = sum_beauty_optimal(s);

    cout << "The sum is : " << sum;

    return 0;
}