#include <bits/stdc++.h>
using namespace std;

/*

// Remove outermost Parentheses

- we will be given a string of parentheses
Eg: (())(()())
- so we find the decompositions - groups of the valid parenthesis
Eg: 1 - (()) , 2 - (()()) -> so here there are 2 decompositions
- and finally then we have to remove the outer parentheses of these decompositions
Eg: Output will be () ()()






1. Approach 1: Stack based approach

- if the stack is empty & opening parentheses -> push into stack
- if the stack is not empty & opening parentheses -> push into stack and also add it to the ans

- if all opening are over and we have the closing parentheses, then pop from the array and after that check if array is empty
    - if not then add the closing to the ans
    - if yes then don't add closing to the ans

- Time complexity -> O(n)
- Space complexity -> O(n) - as we are using a extra stack




2. Approach 2: Maintaining the counter

- initially the counter will be counter = 0, this means that we are either starting or ending the string
- for every opening parentheses we will do counter + 1 and closing parentheses we will do counter--
- and whenever the counter is != 0 we will add it to the ans

- whenever opening parentheses comes, then before it we have to check whether counter = 0 or not
- whenever closing parentheses comes, then after it we have to check whether counter = 0 or not

- Time complexity -> O(n)
- Space complexity -> O(1)

*/

string remove_outermost_brute(string s)
{
    string ans = "";
    stack<char> st;

    for (int i = 0; i < s.length(); i++)
    {
        // if stack is empty then push into the stack
        if (st.empty())
        {
            st.push(s[i]);
        }
        else
        {
            // if not empty then check for opening or closing
            if (s[i] == '(')
            {
                // if opening then push it in stack and also ans
                st.push(s[i]);
                ans += s[i];
            }
            else if (s[i] == ')')
            {
                // if closing then pop from stack and check for empty
                st.pop();

                // if empty after popping then it was last so don't add
                if (st.empty() == false)
                {
                    // if not empty after popping so it is not last so add
                    ans += s[i];
                }
            }
        }
    }

    return ans;
}

string remove_outermost_optimal(string s)
{

    int counter = 0;
    string ans = "";

    for (int i = 0; i < s.length(); i++)
    {
        // if (s[i] == '(')
        //     counter++;
        if (s[i] == ')')
            counter--;

        // but for the first iteration counter will be already incremented and so the first parentheses will get added which we don't want

        // so we will add the ( condition after the checking
        if (counter != 0)
        {
            ans += s[i];
        }

        // in this way it will start from second opening (
        if (s[i] == '(')
            counter++;
    }

    return ans;
}

int main()
{
    string parentheses;
    cin >> parentheses;

    // string ans = remove_outermost_brute(parentheses);
    string ans = remove_outermost_optimal(parentheses);
    cout << ans << endl;

    return 0;
}