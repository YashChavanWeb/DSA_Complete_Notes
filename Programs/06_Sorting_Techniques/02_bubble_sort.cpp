// ### Bubble Sort

/*

    The algorithm works with adjacent swapping
    - so we will everytime check the i and the i+1 element
    - see if i < i+1 element, and if not then swap both the elements
    - so after 1 iteration of this the max will be at the last
    - so we will do this n-1 times to get the array in sorted order
    - everytime we do we will keep on excluding the last elements that are already sorted

*/

#include <bits/stdc++.h>
using namespace std;

// Bubble sort
void bubble_sort(int arr[], int n)
{
    // we have to traverse 0 to n-1, 0 to n-2, 0 to n-3...0 to 1

    for (int i = n - 1; i >= 0; i--)
    {
        // don't go from n as 1 element is of no use

        // this part is done for the optimization
        int didswap = 0;

        for (int j = 0; j <= i - 1; j++)
        {
            // here j is going till i-1 because,
            // for the first iteration last element will have no comparison as we are doing j+1, so we write till 1 less

            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                // increase the value of the swap
                didswap = 1;
            }
        }

        if (didswap == 0)
        {
            break;
        }

        // run check
        // cout << "runs\n";
    }
}

// ### Time complexity
// it is same i.e. -> O(n^2) -> this is the worst and avg complexity
// best time complexity -> O(n)

// ### Optimization
// - if the array is already sorted, and if during the first iteration there were no swaps, then we can directly tell that the array is already sorted
// - so in the best case(no swaps array is sorted), the cod will run for o(n)

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    bubble_sort(arr, n);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}