#include <bits/stdc++.h>
using namespace std;

/*
    // Two sum problem

    Variety 1: given a target we have to find two elements whose sum matches with the target -> give yes or no possible or not

    Variety 2: It is sure that there are 2 elements in the array that add up with the target so tell the element indexes


1. Brute force approach
- take the first element, then add it and check with all other elements
- i==j just continue as we don't want same elements
- also it can be optimized if we start j from i+1 as if we check 2,5 then no need to check 5,2

- Time complexity -> O(n^2)
- Space complexity -> O(1)





2. Better Approach
- we will be using hashing- hashmap
- first we will check how much is the diff in the target and the element
- then check whether the result is there in the hashmap
- if yes then simply return both the indexes
- if not then store that array element in the hashmap and then move ahead

- Time complexity -> O(n*nlogm)
- Space Complexity -> O(N) as we are using a extra hashmap




3. Optimal Solution
- we are not allowed to use the hashmap
- we will be using a two pointer approach
- first we will sort the array in ascending order
- so here we will follow the greedy approach
- two pointers, left and right
- if the sum of left and right is more than the target, then reduce so right pointer --
- if the sum is not till the target, so increase so left pointer ++


- Time complexity -> O(n) + O(nlogn) for sorting
- Space Complexity -> O(1)



*/

vector<int> two_sum_brute(vector<int> arr, int target)
{
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if ((arr[i] + arr[j]) == target)
            {
                return {i, j};
            }
        }
    }

    return {};
}

string two_sum_better(vector<int> arr, int target)
{

    unordered_map<int, int> mpp;

    for (int i = 0; i < arr.size(); i++)
    {
        // first calculate the remaining to check that element in the hashmap
        int remaining = target - arr[i];

        // if we find that 2nd element in the hashmap then directly return
        if (mpp.find(remaining) != mpp.end())
        {
            return "Yes";

            // return {mpp[remaining], i}
        }

        // if we don't find the element then we will store that element with its index in a hashmap
        mpp[arr[i]] = i;
    }

    return "No";

    // return {}
}

string two_sum_optimal(vector<int> arr, int target)
{
    int left = 0, right = arr.size() - 1; // as we want the indexes of the arr

    // sort it
    sort(arr.begin(), arr.end());

    // after it is sorted then we will use the greedy approach

    while (left < right)
    {
        int sum = arr[left] + arr[right];

        if (sum == target)
        {
            return "YES";
        }
        else if (sum < target)
        {
            left++;
        }
        else if (sum > target)
        {
            right--;
        }
    }

    return "NO";
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

    int target;
    cin >> target;

    // vector<int> result = two_sum_brute(arr, target);
    // if (result.size() == 2)
    // {
    //     cout << "Target value " << target << " is found at indexes " << result[0] << " and " << result[1] << " of the array.\n";
    // }
    // else
    // {
    //     cout << "No two numbers in the array sum up to " << target << ".\n";
    // }

    // cout << two_sum_better(arr, target);
    cout << two_sum_optimal(arr, target);

    return 0;
}