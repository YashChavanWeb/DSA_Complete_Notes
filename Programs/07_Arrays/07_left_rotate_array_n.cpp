#include <bits/stdc++.h>
using namespace std;

/*
    Rotating the array by d spaces
    here d can be anything

    - if we rotate the array by n spaces (where n is the no of elements in the array),then the array will come to its original state
    - if the array is of n size and we want to make rotation by n+3 places, it means that n keeps the array same and just we have to left rotate it by 3 places
    - 15 can be 7+7+1 where 7 is the size of array so we have to just perform 1 rotation


    - So the number of rotations that we have to perform is d % n
    where d is no. of places and n is no. of elements


1. Brute force approach
- first store the d elements into a temp array

- then start a for loop from d till n and then we are going to shift the elements towards the left
- so we can write a[i-d] = a[i] so that the elements will be shifted properly to the left

- after this is done then we finally just need to add the elements to the end of the array
- so start for loop from n-d till n, and just do a[i] = temp[i-(n-d)]

- Time complexity can be O(d + n-d + d) - putting d elements into temp, then moving to left, then again from temp to the array
- So Time complexity is -> O(n+d)
- Space complexity is -> O(d)


2. Optimal Solution
- there are two parts of the array
- 0 to d,  d to n
- so we have to just perform 3 steps

- reverse(a, a+d) -> logically arr of 0 to arr d -1
- reverse(a+d, a+n) -> logically from arr d to arr n-1
- reverse(a, a+n) -> logically from arr to arr n-1


// Time complexity -> O(d + n-d + n ) -> O(2n)
// Space Complexity -> O(1) no extra space is used


Note: if the question is asked to rotate the array from the left then we can do the same
first reverse from a+d to n
then reverse from a to a+d
then reverse from a to a+n


*/

void rotate_brute(vector<int> &arr, int n, int d)
{

    vector<int> temp;
    // push the rotating elements into a temporary array
    for (int i = 0; i < d; i++)
    {
        temp.push_back(arr[i]);
    }

    // then shift the elements to the left
    for (int i = d; i < n; i++)
    {
        arr[i - d] = arr[i];
    }

    // then again put the rotating elements to the end of array
    for (int i = n - d; i < n; i++)
    {
        arr[i] = temp[i - (n - d)];

        // or we can also consider a j variable and do j++
        // arr[i] = temp[j];
    }
}

void rotate_optimal(vector<int> &arr, int n, int d)
{
    reverse(arr.begin(), arr.begin() + d);
    reverse(arr.begin() + d, arr.end());
    reverse(arr.begin(), arr.end());
}

// Manual reverse function
void Reverse(vector<int> arr, int start, int end)
{
    while (start <= end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        start++;
        end--;
    }
}

int main()
{

    int n;
    cin >> n;

    int d;
    cin >> d;

    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }

    // rotate_brute(arr, n, d);
    rotate_optimal(arr, n, d);

    cout << "Array after " << d << " rotations is ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}