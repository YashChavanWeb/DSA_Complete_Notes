// Hashing in Characters
/*
- here we have to do the same thing as the integer
- just we have to map the integer with the corresponding letter - so there will be 26 letters
- so here we can use ASCII values for writing it programmatically - to know that 5 is f
*/

// Example:
int x = 'a'; // this will not give error it will store the ascii value of the character - 97

// to map the index to the alphabets, we have to apply the logic as
// 'f' - 'a'  = 5  -> which is the index of f
// so just subtract a from the character and we will get its index in the array
// Formula: character - 'a'

#include <bits/stdc++.h>
using namespace std;

int main()
{

    string s;
    cout << "Input string : ";
    cin >> s;

    // hash
    int hash[26] = {0}; // this is if all the string chars are of small letters
    // if string is mixture of all then we have to take hash[256] and no need to do -'a' as it will now go to the right index Eg:  a goes to index 97 and so on

    // prefetch
    for (int i = 0; i < s.size(); i++)
    {
        hash[s[i] - 'a'] += 1;
        // hash inside its brackets needs integer so it will convert to its ascii value
    }

    int q;
    cout << "Input query number : ";
    cin >> q;

    while (q--)
    {

        char c;
        cin >> c;

        cout << hash[c - 'a'] << endl; // hash of that index
    }

    return 0;
}