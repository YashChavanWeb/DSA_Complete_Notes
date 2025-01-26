#include <bits/stdc++.h>
using namespace std;

/*

# Balanced Parentheses

- every opening bracket should have a same closing bracket
- every closing bracket should have same opening bracket
- the order of the brackets should be same

Approach
- when we encounter a closing, we look for the last opening encountered
- so preserve all the opening brackets
- and we should be able to see the last one

- Time complexity -> O(N)
- Space complexity -> O(N)



*/

bool check_parentheses(string s)
{

    stack<char> st;

    int n = s.size();

    for (int i = 0; i < n; i++)
    {

        // if it is opening then push in stack
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            st.push(s[i]);
        }
        else
        {

            // it means it is a closing bracket

            // now check if the stack is empty or not
            if (st.empty())
            {

                // if stack empty then not valid parentheses so return
                return false;
            }
            else
            {

                // now take out the opening bracket from stack to compare
                char ch = st.top();
                st.pop();

                // then compare it with the closing bracket
                if (s[i] == ')' && ch == '(' || s[i] == ']' && ch == '[' || s[i] == '}' && ch == '{')
                {
                    continue;
                }
                else
                {
                    // if non of the above case is true then return false

                    return false;
                }
            }
        }
    }

    // at the end return stack is empty or not if we found everything is cancelled
    return st.empty();
}

int main()
{
    string s = "([]{()})";

    if (check_parentheses(s))
    {
        cout << "Valid";
    }
    else
    {
        cout << "Invalid";
    }

    return 0;
}