#include <bits/stdc++.h>
using namespace std;

/*

// Remove k digits

- we are given a string of numbers (0 to 9) and a value of k
- so we have to remove k digits from this string, such that the remaining string is the smallest number possible





Approach

- we will be using a stack
- if initially the stack is empty, then push the element
- for the next element, if there is smaller/same element at top then simply push the element
- for the next element, if there is larger element at the top then pop it and place the element in the stack (reduce k as well)
- do this until we remove k no of elements from the string
- then pop all the values from the stack and also reverse them


Edge Cases:
- k<= N - if k == N then we will be removing everything from string
- 00100 - if the number is not a valid number so we have to trim out -the initial zeros
- after the entire traversal, if we are not able to k values, then it means that it is a increasing number
- so just trim the k digits from the end

- Time complexity -> O(3N + K) - stack + stack + traversal + no of removals
- Space complexity -> O(N+N)






*/

string remove_k_digits(string str, int k)
{

    // declare a stack
    stack<char> st;

    // start iterating
    for (int i = 0; i < str.length(); i++)
    {

        // keep on popping from the stack until top > s[i]
        while (!st.empty() && k > 0 && (st.top() - '0' > str[i] - '0'))
        {
            st.pop();
            k--;
        }

        // when we come here that means any one of the condition is false
        st.push(str[i]);
    }

    // now after the iteration if there is k values left, then remove the elements froms stack
    while (k > 0)
    {
        st.pop();
        k--;
    }

    // what if after this the stack is empty - it means that we have removed all
    if (st.empty())
    {
        return "0";
    }

    // now the stack will have the final answer elements that we want to return
    string res = "";
    while (!st.empty())
    {
        res += st.top();
        st.pop();
    }

    // edge case: what if there are zeros at the front (which means as reverse so at the end of res)
    while (res.back() == '0' && res.length() != 0)
    {

        // removing the zeros
        res.pop_back();
    }

    // now at the end also reverse the result
    reverse(res.begin(), res.end());

    // and now at the end also check if the result is empty
    if (res.empty())
    {
        return "0";
    }

    return res;
}

int main()
{

    string input = "1432219";
    int k = 3;

    string res = remove_k_digits(input, k);
    cout << res;

    return 0;
}