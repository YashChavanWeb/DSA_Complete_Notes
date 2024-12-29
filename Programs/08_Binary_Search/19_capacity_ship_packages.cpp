#include <bits/stdc++.h>
using namespace std;

/*

// Find the least capacity to ship packages within D days
- we have 1 ship and n products with us
- each of these products will have a weight
- no of days is also given
- the ship will run only once per day
- we have to make sure that all of the products are shipped within 5 days
- so we have to find what is the least weight of products that we can load into the ship such that we can do it in 5 days




1. Brute force approach
- whatever is the maximum weight, minimum the ship has to be of that capacity
- otherwise we cannot ship each and every product
- the capacity of the ship will always be between the max element and the summation of the array

- so we will run a loop from the max_element till the summation
- in that we will check the days required to fit all the elements
- if the days required <= the given days then we will return those days

- for writing the days req function, we have the array and the capacity per day of the ship
- so we will take days = 1 and load = 0
- now we will iterate through the elements in the array (that are weights) and then go on adding them to the load.
- if the load exceeds the capacity then change the day and start new load
- or else add the weight to the load


- Time complexity -> O( (sum - max + 1) * n ) -> O(n^2) approximately






*/

int find_days(vector<int> weight, int capacity)
{

    // set initial values of days and load
    int days = 1, load = 0;

    for (int i = 0; i < weight.size(); i++)
    {
        if ((load + weight[i]) > capacity)
        {
            // if exceeds the capacity then, increase day and start new load
            days++;
            load = weight[i];
        }
        else
        {
            // else add the weight to the load
            load += weight[i];
        }
    }

    return days;
}

int capacity_ship_brute(vector<int> arr, int days_limit)
{
    // we will run loop from max in array till sum in array
    int maxi = *max_element(arr.begin(), arr.end());
    int sum = accumulate(arr.begin(), arr.end(), 0); // here 0 is the initial value

    for (int capacity = maxi; capacity <= sum; capacity++)
    {
        int req_days = find_days(arr, capacity); // find the no. of days with this capacity

        if (req_days <= days_limit)
        {
            return capacity;
        }
    }

    return -1;
}

int capacity_ship_optimal(vector<int> arr, int days_limit)
{

    int low = *max(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);

    while (low <= high)
    {
        int mid = (low + high) / 2;

        int no_of_days = find_days(arr, mid); // here we are sending the mid as the capacity

        if (no_of_days <= days_limit)
        {
            // this can possibly be my answer but I want lower
            high = mid - 1;
        }
        else
        {
            // I don't get answer so i move the low
            low = mid + 1;
        }
    }

    // the low will end up at a possible answer so we can return the low
    return low;
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int days;
    cin >> days;

    // int least_capacity = capacity_ship_brute(arr, days);
    int least_capacity = capacity_ship_optimal(arr, days);
    cout << "The ship can ship packages with capacity of " << least_capacity << " kg per day";

    return 0;
}