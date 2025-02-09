#include <bits/stdc++.h>
using namespace std;

/*

// Stock and Span Problem

- we will be starting off with stock spanner calls - which means opening of stock market
- after that we will be having next function calls
- our task is to return a possible integer
    - this integer defines the maximum consecutive days for which the stock prize was less than or equal to the current day

Eg: 7 2 1 3 3 1 8
SO, next(7) - 1
SO, next(2) - 1
SO, next(1) - 1
SO, next(3) - 3
SO, next(3) - 4
SO, next(1) - 1
SO, next(8) - 7






1. Brute force

- initially we have a empty list
- first we add the value in the list and then start iterating from n - 2
- and then keep the counter from 1 and increment if we get any less

- Time complexity -> every next function call is taking O(no. of days till now)
                  -> O(total no of next calls till now)
- Space complexity -> O(N)





2. Optimal Approach

- we were adding the element and then traversing back which was taking time
- if we find the previous greater element, then the elements before that will be the no of days where the price was low
- so it means that if we do curr_index - prev_gre_index then we get the no of days
- so for finding the PGE, we will have to traverse from left to right and store the elements in the stack
- and then compare with the top and pop the elements until we have a greater element than the current

- Time complexity -> O(2N) - overall time complexity
- Space complexity -> O(N) - stack

*/

class StockSpanner
{
    // for brute
    vector<int> arr;

    // for optimal
    stack<pair<int, int>> st;
    int idx = -1;

public:
    // constructor
    StockSpanner()
    {
        // for brute
        arr = {};

        // for optimal
        idx = -1;

        while (!st.empty())
        {
            st.pop();
        }
    }

    int next_brute(int val)
    {

        int counter = 1;
        arr.push_back(val);

        for (int i = arr.size() - 2; i >= 0; i--)
        {
            if (arr[i] <= val)
            {
                counter++;
            }
            else
            {
                break;
            }
        }

        return counter;
    }

    int next_optimal(int val)
    {
        // incr the index
        idx++;

        while (!st.empty() && st.top().first <= val)
        {
            // then there is no use
            st.pop();
        }

        // so here we will have the element
        int ans = idx - (st.empty() ? -1 : st.top().second);

        // also push the current val in the stack
        st.push({val, idx});

        return ans;
    }
};

int main()
{
    StockSpanner s1 = StockSpanner();
    cout << s1.next_optimal(7) << endl;
    cout << s1.next_optimal(2) << endl;
    cout << s1.next_optimal(1) << endl;
    cout << s1.next_optimal(3) << endl;
    cout << s1.next_optimal(3) << endl;
    cout << s1.next_optimal(1) << endl;
    cout << s1.next_optimal(8) << endl;

    return 0;
}