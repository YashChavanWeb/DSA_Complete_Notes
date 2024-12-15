// ### Insertion Sort

/*
    // In insertion sort, takes an element and places it at its correct position

    // see is the element sorted in the sorted array
    // sorted array starts from size 1 and goes till size n
    // if the element is not sorted then we go on swapping with the left element till it will not be swapped
    // which means until it is at the correct position

*/

#include <bits/stdc++.h>
using namespace std;

void insertion_sort(int arr[], int n)
{

    // this will go from 0 to n-1 as the sorted array goes on increasing

    for (int i = 0; i <= n - 1; i++)
    {
        // within the sorted array we have to perform the greater and less than checking and then swapping
        // first we declare the index j as = i (which is the size of the sorted array for iteration)
        // then in the while condition, j should not compare with before 0 element when we do j-1 so for that we have used j>0
        // the other is the normal sorting check
        // also as it is a while loop so don't forget to do j--

        int j = i;
        while (j > 0 && arr[j - 1] > arr[j])
        {
            int temp = arr[j - 1];
            arr[j - 1] = arr[j];
            arr[j] = temp;

            j--;
        }
    }
}

// ## Complexity
// Time Complexity: O(n^2) -> for the worst and average case
// as we are everytime checking if the array is sorted so the best complexity is -> O(n)
// as the swaps will not happen if the array is already sorted

int main()
{

    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    insertion_sort(arr, n);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}
