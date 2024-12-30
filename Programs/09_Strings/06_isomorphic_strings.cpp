#include <bits/stdc++.h>
using namespace std;

/*

// Isomorphic Strings

- two strings are isomorphic, if all occurrences of a character can be replaced by other character from string 2
- both strings are of same length




1. Brute force Approach
- brute force approach is to replace the string 2 with the string 1 characters
- and then check if the string 2 is same as string 1

- Time complexity -> O(n * 26 * 26) -> where n is length of string
- Space complexity : O(n)






2. Optimal Approach
- so we will consider a map
- we will keep the pointer on the first position of both the strings
- and if they are not present in the map then we will map it as <key,value> into the map
- in this way we can map all the characters and replace the first string with its mapped characters
- if the first strings turns out to be equal with the second then we can say that the strings are isomorphic

- but there is a small problem
b a d c -> b a b a
- so here d is not present in the map so it will map to b
- but b is already mapped to b before
- so we need one another map to check if second strings characters are already mapped with any other character or not

- so we will store s->t in map1 and t->s in map2

- Time complexity -> O(n)
- Space complexity -> O(256) - valid ASCII characters



*/

bool isomorphic_strings_optimal(string s1, string s2)
{

    // If lengths are different, immediately return false
    if (s1.length() != s2.length())
    {
        return false;
    }

    // first create two maps

    // one for storing the mapping s-> t
    unordered_map<char, char> mp1;
    // one for storing the mapping t-> s
    unordered_map<char, char> mp2;

    // then we will run the for loop for string length of any string
    for (int i = 0; i < s1.length(); i++)
    {

        // now here the first thing is to get ith character of both the strings
        char char1 = s1[i];
        char char2 = s2[i];

        // now we have to check whether there is any kind of mapping already in the map

        if (mp1.find(char1) != mp1.end() && mp1[char1] != char2)
        {
            // this means the character is found in the map1
            // and also the character1 is mapped to some different character not to character2
            return false;
        }

        // similarly check in map2 - we can also apply || in single if

        if (mp2.find(char2) != mp2.end() && mp2[char2] != char1)
        {
            return false;
        }

        // if mapping is not present then we can add the mapping into both the maps
        mp1[char1] = char2;
        mp2[char2] = char1;
    }

    // if false is not returned then it means that properly everything is mapped
    return true;
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;

    if (isomorphic_strings_optimal(s1, s2))
    {
        cout << "Yes are isomorphic" << endl;
    }
    else
    {
        cout << "No are not isomorphic" << endl;
    }

    return 0;
}