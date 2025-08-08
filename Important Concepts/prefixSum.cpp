#include <bits/stdc++.h>
using namespace std;

int noOfSubarrays(vector<int> arr, int k)
{

    map<int, int> hash; // <prefixSum, count>
    int prefixSum = 0;
    int count = 0;

    // base case where sum = target
    hash[0] = 1;

    for (int i = 0; i < arr.size(); ++i)
    {

        prefixSum += arr[i];
        int rem = prefixSum - k;

        if (hash.find(rem) != hash.end())
        {
            count += hash[rem];
        }

        hash[prefixSum]++;
    }

    return count;
}

int longestSubarray(vector<int> arr, int k)
{

    map<int, int> hash; // prefixSum , index
    int prefixSum = 0;
    int maxLen = 0;

    for (int i = 0; i < arr.size(); ++i)
    {
        prefixSum += arr[i];

        if (prefixSum == k)
        {
            maxLen = max(maxLen, i + 1);
        }

        int rem = prefixSum - k;

        if (hash.find(rem) != hash.end())
        {
            maxLen = max(maxLen, i - hash[rem]);
        }

        // but we have to look as left as possible
        if (hash.find(prefixSum) == hash.end())
        {
            hash[prefixSum] = i;
        }
    }

    return maxLen;
}

int main()
{

    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    int k;
    cin >> k;

    // Find the no of subarrays that sum up to given target
    cout << "No of Sub-arrays with target " << k << " : " << noOfSubarrays(arr, k) << endl;

    cout << "Longest Sub-array length with target " << k << " : " << longestSubarray(arr, k) << endl;

    return 0;
}