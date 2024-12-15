#include <bits/stdc++.h>
using namespace std;

/*
// Check if the array is sorted

*/

bool check_sorted(vector<int> arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        if (arr[i] >= arr[i - 1])
        {
            continue;
        }
        else
        {
            return false;
        }
    }

    return true;
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

    if (check_sorted(arr, n))
        cout << "The array is sorted ";
    else
        cout << "The array is not sorted";

    return 0;
}