#include <bits/stdc++.h>
using namespace std;

/*

// Reverse the words in the given string

- eg string: "Hello yash chavan" -> "chavan yash Hello"
- also if there are any extra spaces in the start, end or middle then we have to remove them and give final output




1. Brute force approach

- reverse the entire string
- reverse the individual words in the string

- for reversing the entire string we can use reversal function or else a stack
- then to reverse the word, store a word variable where we get the word until we get a space
- and then reverse that word using the same function

// Process
- the pen
- nep eht
- nep -> pen -> " pen"
- eht -> the -> " pen the"
- return ans.substr(1) -> so that the first space does not come

- Time complexity -> O(n)
- Space complexity -> O(n)





2. Optimal Approach

- we start from the end of the string
- we go on till we encounter a space
- then we know that we have a word, so we will append that word into our ans string

- Time complexity -> O(n)
- Space complexity -> O(1) - as we are not using any extra space


*/

string reverse_words_brute(string s)
{
    string ans = "";

    // first reverse the entire string
    reverse(s.begin(), s.end());

    // for loop till the entire string
    for (int i = 0; i < s.length(); i++)
    {

        // while loop for each word
        string word;

        while (s[i] != ' ' && i < s.length())
        {

            // here we will start forming the word
            word += s[i];

            // move ahead
            i++;
        }

        // when we get the reverse word we will again reverse it
        reverse(word.begin(), word.end());

        // add the word to the answer string
        if (word.length() > 0)
        {
            // we will only add if there is some value in the word
            ans += word + " ";
        }
    }
    return ans;
}

string reverse_words_optimal(string s)
{

    int n = s.length();
    string ans;

    // start traversing from the end of the string

    for (int i = n - 1; i >= 0; i--)
    {

        // go on until we encounter a space
        if (s[i] == ' ')
        {
            // here we encounter a space which means one word we have

            // make the ending index (length of the word)
            int len = n - i;

            // now append the substring into the answer
            ans.append(s.substr(i + 1, len));

            // also append a space after the word
            ans += " ";

            // now we will also update the value of n as it will then start after the space as i is on the space
            n = i - 1;
        }
    }

    // now after we come after the loop
    // we did not encounter space but there is a word at the first which is not yet appended

    // append that word
    ans.append(s.substr(0, n + 1));

    return ans;
}

int main()
{
    string s;
    getline(cin, s);

    // string ans = reverse_words_brute(s);
    string ans = reverse_words_optimal(s);
    cout << "Before reverse- " << s << endl;
    cout << "After reverse- " << ans << endl;

    return 0;
}