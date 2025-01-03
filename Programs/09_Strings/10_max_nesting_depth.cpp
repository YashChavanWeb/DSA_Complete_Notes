#include <bits/stdc++.h>
using namespace std;

/*

// Maximum nesting depth of the parentheses

- Valid parentheses string (VPS)
A
""
AB -> concatenating two VPS
(A)
(())

- invalid parentheses string
"("
")"

- our task is to find the maximum depth of the string
- (A) -> depth is 1
- (()()) -> depth is 2
- if we get 2 depths then we have to get the maximum depth


- Eg: (1+(2+3)+((8)/4))+1 -> Max depth is 3






1. Brute force solution

- when we see the parentheses, we have to think about the stack
- when we see a opening bracket, we add it to the stack and then update the max size of the stack
- when we see a closing bracket, we remove the parentheses for balancing it

- Time complexity -> O(n)
- Space complexity -> O(n/2)





2. Optimal Approach

- we solve this without using stack
- we will keep two variables, open bracket and result
- whenever we see open bracket, do +1 to open bracket variable and when we see closing then do -1
- and everytime we do any change update the result by the max

- Time complexity -> O(n)
- Space complexity -> O(1)


*/

int max_nesting_depth_brute(string s)
{
    int max_depth = 0;

    // first we consider a stack
    stack<char> st;

    // then we iterate the string and apply the push and pop logic

    for (auto &ch : s)
    {

        if (ch == '(')
        {
            st.push(ch);
        }
        else if (ch == ')')
        {
            st.pop();
        }

        // max_depth = max(max_depth, st.size());
        max_depth = max(max_depth, (int)st.size());

        // st.size() is of not integer type size_t
        // so we need to convert overall to int
    }

    return max_depth;
}

int max_nesting_depth_optimal(string s)
{

    // just define a variable to store the counter
    int open_bracket_count = 0;

    // maximum depth storing variable
    int max_depth = 0;

    for (auto &ch : s)
    {
        if (ch == '(')
        {
            open_bracket_count++;
        }
        else if (ch == ')')
        {
            open_bracket_count--;
        }

        // update the value of the max depth
        max_depth = max(max_depth, open_bracket_count);
    }

    return max_depth;
}

int main()
{
    string s;
    cin >> s;

    // int result = max_nesting_depth_brute(s);
    int result = max_nesting_depth_optimal(s);

    cout << "The max nesting depth is : " << result;

    return 0;
}