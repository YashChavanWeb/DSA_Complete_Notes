#include <bits/stdc++.h>
using namespace std;

/*
// left rotate the array by just one place without using a new array
Eg: 1 2 3 4 5 ->  2 3 4 5 1

1. Optimal Approach
- we have to store the first element in a temp variable
- then from 2nd till last element move to left by 1 place
- and then at the last index add the temp variable element

// Time complexity
- Time complexity is -> O(n)
- Space complexity is -> O(1) - the space that we are using extra

*/

void left_rotate(vector<int> &arr, int n)
{
    int temp = arr[0];

    for (int i = 1; i < n; i++)
    {
        arr[i - 1] = arr[i];
    }

    arr[n - 1] = temp;
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

    left_rotate(arr, n);

    cout << "The left rotated array is : ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}