#include <bits/stdc++.h>
using namespace std;

/*

// Check if the two given strings are anagram

- in the two given strings the second string is formed by re-arranging the first string then it is called as anagram
- so we have to tell whether the given two strings follow the above rule
Eg: silent -> listen




1. Brute Force Approach
- first we will sort both the strings
- and then after sorting we can check one to one whether all the characters are matching
- if yes then return true or else return false

- Time complexity -> O(nlogn + nlogn + n) -> sort s1, sort s2, check and map
- Space complexity -> O(alphabet_size)





2. Better approach
- we will use a frequency array to count the frequency of each character in the first string and the second string
- and then if the count count matches then we can return true or false on the basis of that

- Time complexity -> O(n+n) -> O(n)
- Space complexity -> O(alphabet_size)




3. Optimal Approach

- push the characters into a single hash, unordered map
- then from the other string we will just decrement the count
- if the last count is zero then we will return true
- else return false

- Time complexity -> O(n)
- Space complexity -> O(n)


*/

bool strings_anagrams_brute(string s1, string s2)
{
    // edge case
    if (s1.length() != s2.length())
        return false;

    // sort both the strings
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());

    // then we have to compare both the string characters with each other
    for (int i = 0; i < s1.length(); i++)
    {
        if (s1[i] != s2[i])
        {
            return false;
        }
    }
    return true;
}

bool strings_anagrams_better(string s1, string s2)
{
    // edge case
    if (s1.length() != s2.length())
        return false;

    // create two hashs
    unordered_map<char, int> hash1, hash2;

    // store the instances of all the characters into the hashes for string1 and string2
    for (int i = 0; i < s1.length(); i++)
    {
        hash1[s1[i]]++;
    }
    for (int i = 0; i < s2.length(); i++)
    {
        hash2[s2[i]]++;
    }

    // compare both the hashes
    for (auto it = hash1.begin(); it != hash1.end(); it++)
    {
        if (hash1[it->first] != hash2[it->first])
            return false;
    }
    return true;
}

bool strings_anagrams_optimal(string s1, string s2)
{
    // edge case
    if (s1.length() != s2.length())
        return false;

    // create a single hash and store the instance count of string 1 only
    unordered_map<char, int> hash;

    for (int i = 0; i < s1.length(); i++)
    {
        hash[s1[i]]++;
    }

    // decrement the count of the index, where we find anything from string 2

    for (int i = 0; i < s2.length(); i++)
    {
        if (hash.find(s2[i]) != hash.end())
        {
            hash[s2[i]]--;
        }
        else
        {
            // if we find any character from string 2 which is not present in string 1
            return false;
        }
    }

    // now there can be multiple characters as well in the same string
    // but at the end count should be zero

    for (auto it : hash)
    {
        // that means if any occurrence was not zero then it means that string is not anagram
        if (it.second != 0)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;

    // bool result = strings_anagrams_brute(s1, s2);
    // bool result = strings_anagrams_better(s1, s2);
    bool result = strings_anagrams_optimal(s1, s2);

    if (result)
    {
        cout << "Yes, are anagrams" << endl;
    }
    else
    {
        cout << "No, are not anagrams" << endl;
    }

    return 0;
}