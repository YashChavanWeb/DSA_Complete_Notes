// #### Selection sort
/*
    Selection sort - selecting the minimum elements from the array and swap

    - select the minimum element
    - replace it with the first element (swapping)
    - so the array at the position 0 is sorted

    - so now find minimum from index 1 to n as 0 is already sorted
    - then replace it the with the first element of the unsorted array that is index 1


    // Algorithm
    - assume min index as the first element of the unsorted array - min index is index with minimum array element
    - then traverse the remaining array and find minimum element by comparing with arr[min_index]
    - if we get anything less than arr[min_index], then update min index with that index (index of j)
    - then finally swap the two elements arr[i] and arr[min_index] that is updated

    // Complexity
    the inner loop runs for n+n-1+n-2....+ 3+2+1 = Sum of n natural numbers - n(n+1)/2
    So the complexity is O(n^2) - the best, worst and avg complexity is the same O(n^2)



*/

#include <bits/stdc++.h>
using namespace std;

void selection_sort(int arr[], int n)
{
    // selection sort logic
    for (int i = 0; i <= n - 2; i++)
    {
        // we have taken n-1 as we are not considering the last element and the size is n

        int mindex = i;
        for (int j = i; j <= n - 1; j++)
        {
            if (arr[j] < arr[mindex])
            {
                mindex = j;
            }
        }

        // swap after we get the final min index
        int temp = arr[i];
        arr[i] = arr[mindex];
        arr[mindex] = temp;
    }
}

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    selection_sort(arr, n);

    // printing array
    for (int k = 0; k < n; k++)
        cout << arr[k] << " ";

    return 0;
}
