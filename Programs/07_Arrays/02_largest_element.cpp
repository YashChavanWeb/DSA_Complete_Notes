#include <bits/stdc++.h>
using namespace std;

/*
Q. to find the largest element in the array

1. Brute force
- we can sort the array and then return the element at the last index of the array

2. Optimal
- we can consider a max element and then compare it with all the elements
- if any of them is greater then max = that element

*/

int largest_element(vector<int> arr, int n)
{
    int max_element = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max_element)
        {
            max_element = arr[i];
        }
    }

    return max_element;
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

    int largest = largest_element(arr, n);

    cout << "The largest element in the array is : " << largest;

    return 0;
}