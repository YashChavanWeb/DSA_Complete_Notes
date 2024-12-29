#include <bits/stdc++.h>
using namespace std;

/*

// Koka Eating Bananas

- We have given piles (indexes) having bananas (elements)
- also h is given which is no. of hours

- Task is to return minimum integer k such that Koko can eat all bananas in given h hours
- k is no. of bananas she will eat per hour



1. Brute force solution
- we will first start with 1 banana/hr
- then we will calculate the total no of hours required for eating all the bananas
- if it exceeds then we will increase the i
- and if it is same or less then we will stop there
- and return the i as the answer

- The maximum possible answer is the maximum no. of bananas in a pile, that you can eat per hour
- ans will always lie between 1 and max_in_array

- Time complexity -> O(max(arr) * n) - time limit exceeded







2. Optimal Approach

- we can apply binary search on answers
- we will find the mid, which will the no of bananas koka can eat per hour
- we will calculate the total no of hours required for eating all the bananas
- if it exceeds then we will bring low = mid + 1
- if it is same or less then we will bring high = mid - 1 as we want the minimum

Observation:
- when we start the low from the not possible ans, and high from the possible ans
- then when we end the binary search, low will be to the possible and high will be to the not possible
- so we can always return low as the answer


- Time complexity -> O( n* log(max_element)) -> n for finding total hrs
- Space complexity -> O(1)




*/

int total_hours_calc(vector<int> arr, int bananas_per_hour)
{

    int n = arr.size();

    // check the time required for all the array elements per hour and then sum it up

    int total_hours = 0;
    for (int i = 0; i < n; i++)
    {
        // type cast the array into double for proper calculation
        total_hours += ceil(double(arr[i]) / bananas_per_hour);
        // here i is the no of bananas koka can eat per hour

        // so if arr[i] = 3 which means 3 bananas and i = 1, then
        // total time to eat bananas in that pile is 3/1 = 3 hours
    }

    return total_hours;
}

int koka_eating_bananas_brute(vector<int> arr, int h)
{
    int n = arr.size();

    // predefined function to find maximum in array
    int max_in_array = *max_element(arr.begin(), arr.end());

    // the first step is to run the loop in the range
    // here i will be the no. of bananas koka has to eat

    for (int i = 1; i <= max_in_array; i++)
    {

        // we need to get the total hours, for i where i is total no. of bananas koka is eating

        int total_hours = total_hours_calc(arr, i);

        // once we get the total hours check if it is less than or equal to given hours
        // if it is then we will return the i as the answer
        if (total_hours <= h)
        {
            return i;
        }

        // else it is exceeding the hours so we will increase the no of bananas per hour koka is eating
    }

    return -1;
}

int max_ele(vector<int> arr)
{
    int maxi = INT_MIN;

    for (int i = 0; i < arr.size(); i++)
    {
        maxi = max(maxi, arr[i]);
    }

    return maxi;
}

int koka_eating_bananas_optimal(vector<int> arr, int h)
{
    int n = arr.size();

    int low = 1, high = max_ele(arr);
    int ans;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int total_hours = total_hours_calc(arr, mid);

        if (total_hours <= h)
        {
            // this can possibly be the answer, but I want minimum so I will move to the left
            ans = mid;
            high = mid - 1;
        }
        else
        {
            // this is not the answer, so I will move to the right
            low = mid + 1;
        }
    }

    // return low;
    return ans;
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

    int h;
    cin >> h;

    // int k = koka_eating_bananas_brute(arr, h);
    int k = koka_eating_bananas_optimal(arr, h);
    cout << "The minimum bananas koka can eat per hour is : " << k;

    return 0;
}