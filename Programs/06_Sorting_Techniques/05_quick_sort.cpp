// ### Quick Sort
/*

// Why quick sort when we have merge sort?
- this is because we need extra temp array for storing divided arrays in merge sorts
- in quick sort we don't need those so the Space complexity is O(1)
- this is a divide and conquer algorithm


// Algorithm steps
- pick a pivot - any element in the array (we are taking the first element)
- place the pivot element in the correct position of the sorted array
- smaller on the left and larger on the right
- the elements smaller than pivot should be to its left and the elements greater than the pivot should be to its right
- repeat these steps on the left portion and the right portion again

- so we will keep two pointers and use the logic as
    - take i as low and j as high
    - if ith element is greater than pivot and jth element is smaller than pivot
    - swap both the elements
    - if ith is smaller and jth is bigger then they are in correct position so just increment i++ or j++
    - so in this process, if we stop both the pointers, where j is greater than i then we just swap j with the pivot
    - this is because if j crosses i then we have already divided both correctly

    - once the pivot is placed at its correct position then we can call it as a partition index where we will divide the two arrays left and right
    - so after we have the two arrays left and right then perform the quick sort on them again


    // Time complexity
    // - here also we are dividing the array into two so the complexity will be the same
    // Time complexity -> O(nlog2n)


    // Space complexity
    // - we are not using any extra space for creating new arrays like the merge sort
    Space complexity -> O(1)




*/

#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[low];
    int i = low;
    int j = high;

    // we will go until i is less than j if both cross or are equal then we will stop
    while (i < j)
    {
        // if the element is smaller than the pivot then i++
        while (arr[i] <= pivot && i <= high - 1)
        {

            // here we have to take care so that when we do i++ it should not exceed the high and so we do only till high - 1

            i++;
        }

        // same we will perform for the j
        while (arr[j] > pivot && j >= low + 1)
        {
            // here we have done arr[j] > pivot and not >=
            // because if we have same element then we cannot place it both on left and on right so for that we have kept <= on the left side and on > on the right side

            j--;
        }

        // the while loop exits that means we have got two elements that are, arr[i] > pivot and arr[j] < pivot
        // so we will swap them

        // but we can swap them only if i < j because if they have crossed (j > i) then we will do something else
        if (i < j)
            swap(arr[i], arr[j]);
    }

    // finally after ending the while loop here we will be having a condition where j has exceeded i
    // so in that case we will just swap the pivot with the i
    swap(arr[low], arr[j]);

    // then we will finally return the j index which is where the pivot has come which is the partitioning index
    return j;
}

void quick_sort(vector<int> &arr, int low, int high)
{

    // we can also write this as if low >= high then return like the merge condition

    if (low < high)
    {
        // first calculate the partition index which will be helpful for dividing the arrays
        int partition_index = partition(arr, low, high);

        // divide the array and perform quick sort
        quick_sort(arr, low, partition_index - 1);
        quick_sort(arr, partition_index + 1, high);
    }
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

    quick_sort(arr, 0, n - 1);

    for (auto it : arr)
    {
        cout << it << " ";
    }

    return 0;
}