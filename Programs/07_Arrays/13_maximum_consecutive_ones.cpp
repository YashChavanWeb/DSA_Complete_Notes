#include <bits/stdc++.h>
using namespace std;

/*
// Maximum number of consecutive 1's in an array

1. Optimal Approach
- we will keep a counter to keep consecutive 1's and also simultaneously update the max variable
- but if we get something else then we will start the counter again from 0
- Time complexity -> O(N) - as just one loop

*/

int return_ones(vector<int> nums, int n)
{
    int maximum = 0;
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (nums[i] == 1)
        {
            count++;

            // everytime the max will take the value which is greater between the count and the maximum
            maximum = max(count, maximum);
        }

        else
        {
            count = 0;
        }
    }

    return maximum;
}

int main()
{

    int n;
    cin >> n;

    vector<int> nums;

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        nums.push_back(temp);
    }

    cout << "The maximum consecutive 1's are " << return_ones(nums, n);

    return 0;
}