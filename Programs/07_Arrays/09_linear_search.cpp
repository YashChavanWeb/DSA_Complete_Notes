#include <bits/stdc++.h>
using namespace std;

/*
// Linear search
- find the first occurrence of the number given

1. Approach
- we will iterate through the array and compare every element
- if the element matches then return that index

Note: If we want the last occurrence then we can start the iteration from the last
If we want all the occurrences, then we can start the iteration and store the occurrence indexes in a list


*/

int linear_search(vector<int> &arr, int n, int num)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == num)
        {
            return i;
        }
    }

    return -1;
}

int main()
{

    int n;
    cin >> n;

    int num;
    cin >> num;

    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }

    int result = linear_search(arr, n, num);

    if (result == -1)
    {
        cout << "Element is not found in the array";
    }
    else
    {
        cout << "Element is found at index " << result;
    }

    return 0;
}