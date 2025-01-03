#include <bits/stdc++.h>
using namespace std;

/*

// Sort the characters of the string in the increasing order of the frequency

- so a string will be given
- we have to sort the string in the increasing order of frequency or the no of times letters occur
- also if the frequencies are same then the same characters must be together

Eg:
tree
eert or eetr -> so here e has max frequency so it is first and remaining are after it (e=2, r=1, t=1)

Aabb
bbaA -> same here

cccaaa
aaaccc or aaaccc -> allowed | aacacc -> not allowed

Note: relative order of characters of same frequency is not important






1. Brute solution

- we can just sort the hash instead of sorting the entire string

- we will have a hash storing the character and its frequency
- there are total 126 chars so hash can be that big
- we will sort the hash based on the frequency
        A-Z-> 65-90
        a-z-> 97-122
- then we will print the sorted hash
- loop for printing the character until its frequency

- Time complexity -> O(klogk + n) -> sorting + traversing
- Space complexity -> O(k)








2. Optimal Approach
- here we can use the bucket sort
- as we have to optimize the sorting complexity, but we also have to use sorting

- we will store all the characters with the same frequency in the same bucket
- and then print the string according to the frequency

- Time complexity -> O(n+k)
- Space complexity -> O(n)

*/

// comparator function
bool compare_by_frequency(const pair<char, int> &a, const pair<char, int> &b)
{
    // here we are getting the char1 and its frequency as parameter 1 and same for char2 as parameter 2
    return a.second > b.second;
}

string sort_by_freq_brute(string s1)
{

    // steps:

    // create hash
    // copy hash in vector for sorting
    // sort the vector
    // loop for printing the character until its frequency

    // first step is to store frequency into hash
    unordered_map<char, int> freq;
    for (char c : s1)
    {
        freq[c]++;
    }

    // then we will sort the string based on the frequencies

    // we cannot sort the hash so we need a vector to store the hash
    vector<pair<char, int>> v;
    for (auto it = freq.begin(); it != freq.end(); it++)
    {
        v.push_back(*it);
    }

    // then we will sort the hash based on the highest frequency
    sort(v.begin(), v.end(), compare_by_frequency);

    // then we will finally store the string in the result
    string res = "";
    for (auto it = v.begin(); it != v.end(); it++)
    {
        res += string(it->second, it->first);
        // Repeat the character `it->second` times
    }

    return res;
}

string sort_by_freq_optimal(string s1)
{
    // Count frequencies of each character
    unordered_map<char, int> freq;
    for (char c : s1)
    {
        freq[c]++;
    }

    // Create a bucket array where index i will hold characters with frequency i
    int n = s1.length();
    vector<vector<char>> buckets(n + 1); // Bucket for frequencies from 0 to n

    for (auto &p : freq)
    {
        int count = p.second;
        char character = p.first;
        buckets[count].push_back(character);
    }

    // Build the result string by going through the bucket array from high to low frequency
    string result = "";
    for (int i = n; i >= 1; i--)
    {
        // if that bucket index is not empty then perform this operation
        // there are characters occurring i times
        if (!buckets[i].empty())
        {
            // this loop iterates over the characters stored in each bucket
            for (char c : buckets[i])
            {
                result += string(i, c); // Repeat the character i times
            }
        }
    }

    return result;
}

int main()
{

    string s1;
    cin >> s1;

    // string ans = sort_by_freq_brute(s1);
    string ans = sort_by_freq_optimal(s1);
    cout << "Frequency sorted string: " << ans;

    return 0;
}