#include <bits/stdc++.h>
using namespace std;
/*
// Longest subarray with the given sum (positives)
- subarray is the contiguous part of the main array

1. Brute force approach
- we will find all the subarrays using 3 loops
- first loop starting from i to n
- inside that j will run from i to n where we will be finding all the subarrays
- the next loop will be inside j which will find the sum of all the sub-arrays - where it will go from k=i to k=j
- in the third loop everytime the max will be taken for the length

int len = 0
int given_sum = x;

for(int i=0; i<n; i++) {

    sum = 0

    for(int j=i; j<n; j++) {

        for(int k=i; k<j; i++)
            sum += a[k]

            if(sum==given_sum) {
                len = max(len, j-i+1)
            }
    }
}

- Time complexity -> O(n^3)
- Space Complexity -> O(1)


- the brute force can be optimized where we dont need a third loop
- just one new element is coming in the new sum array
- so we can just add it to the previous array


int len = 0
int given_sum = x;

for(int i=0; i<n; i++) {

    sum = 0

    for(int j=i; j<n; j++) {

            sum += a[k]

            if(sum==given_sum) {
                len = max(len, j-i+1)
            }
}
- Time complexity -> O(n^2)
- Space Complexity -> O(1)






2. Better approach

// the better one for the +ves and 0s is the optimal for +ves -ves and 0s

- we can use hashing
- so we will declare a hash map
- we will be using prefix sum approach - sum till this point
- to compute the prefix, everytime we don't need to calculate sum till that point
- we can simply do prefix[i] = prefix [i-1] + a[i]
- so we will find the prefix sum of each term and then store it into the hashmap
- so we can say that, whatever is the current sum, if we subtract it from the given sum and if the ans is present in the hashmap, then we can say that we have found the subarray

Time Complexity:
Ordered Map -> O(n*nlogm)
Unordered Map -> O(n*n) for worst case -> O(n^2)


Main Steps:
= find the sum till i by sum += i
- check if sum = k
    - if yes then find the max of (maxLen, i+1)
    - if not then we move ahead
- calculate the remaining which is sum - k
- check if remaining is there in the hashmap
    - if yes then the len will be i - map[remaining]
    - and then find the max of the maxLength and len
- then we have to add the sum with the index into the map
    - if the sum is already there then we will not add
    - if sum is not present in the map then add sum with its index i

Note: to check if element is there in map or not
    mpp.find(3) != mpp.end()
    // if this is true then it means 3 is there in the map
    // if this is false then it means that pointer is at the end and the element is not present in the map






3. Optimal Approach
- first I will  keep two pointers
- one pointer j will go on increasing until the sum is equal to k
- if it exceeds then we will increase i by 1 so that the sum is less than or equal to the given k

- everytime j moves then add it to sum, compare also it with the given sum
- then if it is equal then we will store in the length as j-i+1
- when j exceeds so we move i by 1 pointer and also reduce the sum, everytime before moving j we have to see to the sum
- and follow this process

Basic steps
check for greater - reduce sum and then increment left (while loop)
check for equal - update the max length (just if)
check for smaller - increment right and update sum (with if condition)

- Time complexity -> O(2n)
even though there are two for loops
the outer while runs for n and the inner while runs for n (not everytime)
so it will be O(n+n)

- Space Complexity -> O(1)


*/

int subarray_better(vector<int> arr, long long k)
{

    // map to store the prefix sum with the index
    map<long long, int> preSumMap;

    // variable that stores the prefix sum
    long long sum = 0;

    // variable that stores the length
    int maxLength = 0;

    // traverse through the entire array
    for (int i = 0; i < arr.size(); i++)
    {

        // here we are calculating the sum of the each subarray
        sum += arr[i];

        // if at any point sum is equal to the given sum then just replace it with index + 1
        if (sum == k)
        {
            // even if we don't write max then its fine because i will be max everytime that the maxLength
            maxLength = max(maxLength, i + 1);
        }

        // now if the condition does not satisfy then we have the sum and we want to find the remaining
        long long remaining = sum - k;

        // now according to the logic, if the map has the remaining at the end then it is the length of the subarray
        if (preSumMap.find(remaining) != preSumMap.end())
        {

            // so we calculate the length of the subarray as
            int len = i - preSumMap[remaining];
            maxLength = max(maxLength, len);
        }

        // now at the end we will just make the preSumMap of the sum as the index i
        // preSumMap[sum] = i;

        // Edge case
        /*
        - if the array also has 0s then there will be a slight change in the logic
        - so we will have to always look for the left most element when we are calculating the sum and finding (x - k)
        - that is why, if a previously does exist, then we should not update in the map
        */

        // this condition means that it has gone till the end and it is not there in the map so we are adding it

        if (preSumMap.find(sum) == preSumMap.end())
        {
            preSumMap[sum] = i;
        }
    }

    return maxLength;
}

int subarray_optimal(vector<int> arr, long long k)
{
    int left = 0, right = 0;
    int n = arr.size();

    int sum = arr[0];
    int maxLength = 0;

    while (right < n)
    {

        // but if the sum exceeds then until it becomes smaller or equal we have to run the while loop
        // and while this process, the left should also not exceed the right
        while (left <= right && sum > k)
        {
            // so we will subtract the sum and then  move the left pointer
            sum -= arr[left];
            left++;
        }

        // if the sum is equal to k then just we have to update the length
        if (sum == k)
        {
            maxLength = max(maxLength, right - left + 1);
        }

        // if the sum is not greater not equal but it is less then we have to follow this

        // first increment the right pointer and then add it to the sum
        right++;

        // but we may be at the last and then try to add so we should always be in the boundary
        if (right < n)
        {
            sum += arr[right];
        }
    }

    return maxLength;
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }

    long long k;
    cin >> k;

    // cout << "Longest sub-array with sum " << k << " is of length " << subarray_better(arr, k);
    cout << "Longest sub-array with sum " << k << " is of length " << subarray_optimal(arr, k);

    return 0;
}