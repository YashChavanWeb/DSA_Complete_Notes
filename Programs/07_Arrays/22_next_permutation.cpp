#include <bits/stdc++.h>
using namespace std;

/*

// Next permutation problem

- What is permutation
-- ways in which we can arrange the elements
-- no of ways the numbers can be rearranged is -> n! for n numbers

- So the problem states that the combinations should be in the dictionary order (ascending order)
- so a combination will be given in the form of array [3,1,2] and we have to find the next possible combination in the ascending order
- which is in this case [3,2,1]

- Edge case -> if the array given is [3,2,1] which is the end of combinations, so in that case we will fallback to the first combination that was given so ans will be [1,2,3]



1. Brute force approach
- Generate all the possible combinations in sorted order
    -- we will be doing this using recursion (which has a long code)
- Do a linear search and find the given combination in the array
- the next index combination is the combination we will return

- Time complexity:
    -- O(n!) for the no of combinations and each combination is of length n so O(n!*n)
- Time complexity -> O(n*n!)



2. Better Approach
- there is a standard function in STL in c++ known as next_permutation()
- next_permutation(arr.begin(), arr.end())
    return arr;




3. Optimal Approach
- writing the code for this inbuild function of next_permutation()

- 1.  so here we have to figure out the breakpoint where there is a element on left which has larger elements than that on the right
    -- graph should have i || i+1  where || is the breaking point
    -- so we can find the longest_prefix_match -> a[i] < a[i+1]
    -- n-2 is the last index that can have a dip

- 2. now we have to find someone > 1 but the smallest one, to stay close

- 3. try to place the remaining in the sorted order (reverse the remaining)

Note: edge case: if(index == -1) then reverse the array


- Time complexity -> O(n) + O(n) + O(n) -> O(3n)
- Space Complexity -> O(n)

*/

vector<int> next_greatest_permutation(vector<int> &arr, int n)
{

    // first set the index to -1
    int indx = -1;

    // as the last digit that can have a dip is n-2 so start from there
    for (int i = n - 2; i >= 0; i--)
    {

        // if arr[i] < arr[i+1] then there is a dip and there is a break point so we will store that index and add break
        if (arr[i] < arr[i + 1])
        {
            indx = i;
            break;
        }
    }

    // if there is no break index then we know that it is increasing graph and so we can just reverse and return the array
    if (indx == -1)
    {
        reverse(arr.begin(), arr.end());
        return arr;
    }

    // now we are out of the first loop which means that we have got the break point and there are elements on the right of it
    // so we need to find the just greater than the breaking point element and the swap it
    // so the loop will run from back to the index
    for (int i = n - 1; i > indx; i--)
    {
        // if we find someone that is greater than the index then we will simply swap
        if (arr[i] > arr[indx])
        {
            swap(arr[i], arr[indx]);
            break;
        }
    }

    // now once we have done that, the remaining elements need to be as small as possible so we will reverse the remaining elements
    // reverse from index + 1 to the end
    reverse(arr.begin() + indx + 1, arr.end());
    return arr;
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<int> result = next_greatest_permutation(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << result[i] << " ";
    }

    return 0;
}