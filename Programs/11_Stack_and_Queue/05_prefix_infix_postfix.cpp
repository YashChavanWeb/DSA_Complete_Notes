#include <bits/stdc++.h>
using namespace std;

/*

// Prefix, Infix and Postfix Conversion

What is an operator?
^, *, /, + and -

What is an operand?
A to Z, a to z and 0 to 9

Priority Order
^    -> 3
* /  -> 2
+ -  -> 1

Infix - all the operators are in between the operands
Most of the programming languages used

Prefix - all the operators are before the operands
Used in tree datastructures


Postfix - all the operators are after the operands
Used in stack based calculators



#1 Infix to Postfix

- take i pointer and start iterating
-- if it is a operand, just add it to the ans
-- if opening bracket then just push into the stack
-- if it is a operator then we will check
    - if stack is empty, put it into the stack
    - if not empty, then check for the operator
        -- if operator in stack is having less priority then push the current operator into the stack
        -- if the operator in stack is having more priority then pop it and add it to ans - and then again check and until it is less then push the current element in stack
-- if we get a closing bracket, until we get opening bracket, add everything to the answer
- done with the iteration, then pop everything and add to the ans

- Time complexity -> O(N) + O(N) -> traverse + remaining
- Space complexity -> O(N) + O(N) - stack + ans






#2 Infix to Prefix

- reverse the given infix (with one conditional change)
    - make the opening bracket a closing bracket and a closing bracket the opening bracket
- perform infix to postfix (under the controlled condition)
    - if the operator is anything else than ^ then we will straight away push it into the stack
- reverse the ans of the postfix

- Time complexity -> O(N/2) + O(N/2) + O(N + N) - reverse + reverse + traverse + remaining
- Space complexity -> O(N + N)








#3 Postfix to Infix

- if we get an operand, we push it into the stack
- if we get an operator, we take the t1 and t2 element there and then put the operand between them -> t2 operand t1
- and then wrap the ans in (brackets) and push the combined into the stack again
- at the end of the stack we will have just one element, which will be our infix expression

- Time complexity -> O(N) + O(N) - loop + string addition
- Space complexity -> O(N) + O(N)






#4 Prefix to Infix

- we will be iterating from the back
- and when we get an operand then we will push it into the stack
- when we get an operator, we follow the same process, take the top 2 elements - put operator in between - wrap between brackets and push back
- but here the operator should be t1 operator t2
- whatever is at the top of the stack, that is the infix expression

- Time complexity -> O(N) + O(N) - iteration + string operations
- Space complexity -> O(N)






#5 Postfix to Prefix

- we will normally iterate
- when we get an operand we just push it into the stack
- if we get an operator then we will just add the top 1 and top 2 to the operator
eg: + t2 t1
- and then push it into the stack without any brackets
- after the end of the iteration, the top of the stack will be the prefix expression

- Time complexity -> O(N) + O(N) - iteration + string operation
- Space Complexity -> O(N)






#6 Prefix to Postfix

- we will start from the back as we want to convert to postfix
- and then if it is an operand then push into the stack
- if we get an operator then we take t1 + t2 + operator and then push it into the stack

- Time complexity -> O(2N)
- Space complexity -> O(N)



*/

// writing the priority function
int priority(char a)
{

    if (a == '^')
    {
        return 3;
    }
    else if (a == '*' || a == '/')
    {
        return 2;
    }
    else if (a == '+' || a == '-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

string infix_to_postfix(string s)
{

    // declare the ans string
    string ans;

    // temporary stack to store the operators
    stack<char> st;

    // take the string size first
    int n = s.size();

    // we will iterate the entire string
    int i = 0;
    while (i < n)
    {
        // first check whether it is a operand

        // there is also a predefined way to check
        // if (isalnum(s[i]))

        if (s[i] >= 'A' && s[i] <= 'Z' || s[i] >= 'a' && s[i] <= 'z' || s[i] >= '0' && s[i] <= '9')
        {

            // if operand then directly add it to the ans
            ans += s[i];
        }

        // if it is a opening bracket
        else if (s[i] == '(')
        {
            st.push(s[i]);
        }

        // if it is a closing bracket
        else if (s[i] == ')')
        {

            // then we will add all characters between the (brackets) to the ans

            while (!st.empty() && st.top() != '(')
            {
                ans += st.top();
                st.pop();
            }

            // at the end also pop the opening bracket
            st.pop();
        }

        // if it is a operator
        else
        {

            // for the operator we will check the priority first

            while (!st.empty() && priority(s[i]) <= priority(st.top()))
            {

                // if the priority of s[i] is less than the element in the stack then we have to keep popping and adding it to the ans

                ans += st.top();
                st.pop();
            }
            // if the priority is greater than the top of stack then we can simply push

            st.push(s[i]);
        }
        i++;
    }

    // now after iterating if the stack is still having any elements then we have to just add them to the ans

    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }

    return ans;
}

void rev_infix(string &s)
{
    for (int i = 0, j = s.size() - 1; i <= j; i++, j--)
    {

        if (s[i] == '(')
            s[i] = ')';
        else if (s[i] == ')')
            s[i] = '(';

        else if (s[j] == '(')
            s[j] = ')';
        else if (s[j] == ')')
            s[j] = '(';

        // we will keep swapping the last and the first element
        swap(s[i], s[j]);
    }
}

string infix_to_prefix(string s)
{

    // create the stack
    stack<char> st;

    // answer string
    string ans;

    int n = s.size();

    // first step is to reverse the given infix string
    rev_infix(s);

    // then we will apply the infix operation
    int i = 0;
    while (i < n)
    {
        if (isalnum(s[i]))
        {
            ans += s[i];
        }
        else if (s[i] == '(')
        {
            st.push(s[i]);
        }
        else if (s[i] == ')')
        {

            // if closing then push to ans

            while (!st.empty() && st.top() != '(')
            {
                ans += st.top();
                st.pop();
            }

            st.pop();
        }
        else
        {

            // it will be a operator

            // if it is a power then only perform this
            if (s[i] == '^')
            {

                while (!st.empty() && priority(s[i]) <= priority(st.top()))
                {
                    ans += st.top();
                    st.pop();

                    // if there is a power in the stack then we have to pop it and add to ans
                }
            }
            else
            {

                // if any other operator then apply the same normal logic just if it is equal then pop

                while (!st.empty() && priority(s[i]) < priority(st.top()))
                {

                    ans += st.top();
                    st.pop();
                }
            }

            // and then after doing all this we can push the operator in the stack
            st.push(s[i]);
        }

        i++;
    }

    // here just if there are any extra elements remaining in the stack
    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }

    // reverse the postfix ans that we get
    reverse(ans.begin(), ans.end());

    return ans;
}

string postfix_to_infix(string s)
{
    // Create a stack to store operands and partial expressions
    stack<string> st;

    int n = s.size();

    // Iterate through the string
    int i = 0;
    while (i < n)
    {
        // Check if the current character is an operand
        if (isalnum(s[i]))
        {
            // If it's an operand, push it to the stack
            st.push(string(1, s[i]));
        }
        else
        {
            // Otherwise, it must be an operator
            string t1 = st.top(); // Top operand
            st.pop();             // Pop it

            string t2 = st.top(); // Second operand
            st.pop();             // Pop it

            // Form the expression with parentheses
            string ans = "(" + t2 + s[i] + t1 + ")";

            // Push the resulting expression back onto the stack
            st.push(ans);
        }
        i++;
    }

    // The final expression is at the top of the stack
    return st.top();
}

string prefix_to_infix(string s)
{
    // first consider a stack for storing string
    stack<string> st;

    int i = s.size() - 1; // as we are iterating from the back

    // start iterating
    while (i >= 0)
    {
        // if it is an operand then push into the stack
        if (isalnum(s[i]))
        {
            st.push(string(1, s[i]));
        }

        // if it is not an operand (i.e., it is an operator)
        else
        {
            // first take the operands from the top of the stack
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();

            // form the infix expression by adding parentheses and operator between operands
            string ans = '(' + t1 + s[i] + t2 + ')';

            // push the formed infix expression back into the stack
            st.push(ans);
        }

        i--;
    }

    return st.top();
}

string postfix_to_prefix(string s)
{

    // first take the stack
    stack<string> st;

    int n = s.size();

    // start iterating
    int i = 0;
    while (i < n)
    {

        // if operand then push in the stack
        if (isalnum(s[i]))
        {
            st.push(string(1, s[i]));
        }

        // not not then it  is an operator
        else
        {

            // first take the top 1 and top 2 out
            string t1 = st.top();
            st.pop();

            string t2 = st.top();
            st.pop();

            // combine the string operator + t2 + t1
            string ans = s[i] + t2 + t1;

            st.push(ans);
        }

        i++;
    }

    return st.top();
}

string prefix_to_postfix(string s)
{

    // stack
    stack<string> st;

    int i = s.size() - 1;

    while (i >= 0)
    {

        if (isalnum(s[i]))
        {
            st.push(string(1, s[i]));
        }

        else
        {

            // if it is operator
            string t1 = st.top();
            st.pop();

            string t2 = st.top();
            st.pop();

            string ans = t1 + t2 + s[i];
            st.push(ans);
        }

        i--;
    }

    return st.top();
}

int main()
{

    // string exp = "2+3*(4/2)-3"; // infix exp
    // string exp = "AB-DE+F*/"; // postfix exp
    // string exp = "*+PQ-MN"; // prefix exp
    string exp = "/-AB*+DEF"; // prefix exp

    // cout << infix_to_postfix(exp);
    // cout << infix_to_prefix(exp);
    // cout << postfix_to_infix(exp);
    // cout << prefix_to_infix(exp);
    // cout << postfix_to_prefix(exp);
    cout << prefix_to_postfix(exp);

    return 0;
}