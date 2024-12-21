#include <bits/stdc++.h>
using namespace std;

/*
    // Leaders in array
    - everything on the right must be smaller

Q. Find the elements in the array that are leaders (have everything smaller than than on the right)

- task is to collect the leaders from the array
- so then we can return them in any fashion - sorted, same order, etc


1. Brute force solution
- we will select each element and see to its right
- we will maintain a leader flag and if at the end it is still true then we can push back that element in the result array

- Time complexity -> O(n^2)
- Space Complexity -> O(n)





2. Optimal Solution
- here we have to just compare 2 elements
- we will select the element and then find the max on the right
- if the element is greater than the max on the right, then it means that it will be greater than all the elements on the right
- so we can push it in the result array

- so here we will be doing a back iteration and then store the last element in the max
- then we will go on comparing to the right and if we find someone greater than max then we will update the max and also add that element into the leader

- so the answer is stored from the back
- if we want from the front then we will just reverse this ans
- if we want it sorted then we will just sort this


- Time complexity - O(n) and if sorted then O(n + nlogn)
- Space Complexity -> O(n)

*/
#include <vector>
using namespace std;

vector<int> leaders_brute(vector<int> arr, int n)
{
    vector<int> result;

    // Traverse from left to right
    for (int i = 0; i < n; i++)
    {
        bool leader = true;

        // Check if arr[i] is greater than all elements to its right
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] <= arr[j])
            {
                leader = false;
                break;
            }
        }

        // If it's a leader, add it to the result
        if (leader)
        {
            result.push_back(arr[i]);
        }
    }

    return result;
}

vector<int> leaders_optimal(vector<int> arr, int n)
{

    vector<int> result;

    int maxi = INT_MIN;

    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[i] > maxi)
        {
            result.push_back(arr[i]);
        }

        // keep track of the right max
        maxi = max(maxi, arr[i]);
    }

    sort(result.begin(), result.end());

    return result;
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

    // vector<int> result = leaders_brute(arr, n);
    vector<int> result = leaders_optimal(arr, n);

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }

    return 0;
}