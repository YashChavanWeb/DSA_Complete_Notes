#include <bits/stdc++.h>
using namespace std;

/*

// Find minimum no. of days to make m number of bouquets

- we will be given an array of bloom_day
- which will day on which the flower will bloom
- m is the no. of bouquets we have to create
- k is the adjacent flowers required
- we have to find minimum no. of days to create m number of bouquets

Note: if there is a requirement of 3 bouquets but we can create at max only 2 then we have to return -1


1. Brute force approach

- first we will figure out when will the requirement exceed what we have
if the total no. of flowers (n) is size of array
and m (no. of bouquets) and k(adjacent req.) on multiplying m*k is
  m*k > n -> this is not possible as all flowers are bloomed and still cannot fulfill
- apart form this all the cases are possible

- maximum value in array is the ans
- minimum value is array is the minimum possible ans
- so we figure out the range ans [min, max]

- Time complexity O ( ( max - mini + 1 ) * n ) -> n for possibility






2. Optimal Approach
- as we have a range given, we can apply binary search

- Time complexity -> O(n * log2n) -> possible * binary search



*/

bool possible(vector<int> arr, int no_of_days, int req_bouquets, int no_of_adjacent)
{

    int n = arr.size();

    int counter = 0;
    int no_of_bouquets = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= no_of_days)
        {
            counter++;
        }
        else
        {
            no_of_bouquets += counter / no_of_adjacent;

            // not possible so we turn counter to 0
            counter = 0;
        }
    }

    // also if we complete iteration and count is there so we will have to divide that as well
    no_of_bouquets += counter / no_of_adjacent;

    // and at the end we will finally check whether our requirement is fulfilled or not
    if (no_of_bouquets >= req_bouquets)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int min_days_brute(vector<int> arr, int m, int k)
{

    int mini = *min(arr.begin(), arr.end());
    int maxi = *max(arr.begin(), arr.end());

    for (int i = mini; i <= maxi; i++)
    {
        if (possible(arr, i, m, k))
        {
            return i;
        }
    }

    return -1;
}

int min_days_optimal(vector<int> arr, int m, int k)
{
    int low = *min(arr.begin(), arr.end());
    int high = *max(arr.begin(), arr.end());

    int ans;

    // the overflow condition
    if (m * k > arr.size())
        return -1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (possible(arr, mid, m, k))
        {
            ans = mid;
            high = mid - 1; // as I want smaller
        }
        else
            low = mid + 1; // as it is not possible
    }

    return ans;
}

int main()
{

    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int m, k;
    cin >> m >> k;

    // int min_days = min_days_brute(arr, m, k);
    int min_days = min_days_optimal(arr, m, k);
    cout << "minimum no. of days to make " << m << " bouquets are " << min_days;

    return 0;
}