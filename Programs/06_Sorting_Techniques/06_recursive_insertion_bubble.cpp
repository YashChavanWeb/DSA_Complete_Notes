// ### Recursive bubble sort
// ### Recursive insertion sort

#include <bits/stdc++.h>
using namespace std;

void recursive_bubble_sort(int arr[], int n)
{

    // base case
    if (n == 1)
        return;

    for (int i = 0; i <= n - 2; i++)

    // here we go till n-2 because we are comparing with i+1 so it should not exceed the array

    {
        if (arr[i] > arr[i + 1])
        {
            swap(arr[i], arr[i + 1]);
        }
    }

    recursive_bubble_sort(arr, n - 1);
}

void recursive_insertion_sort(int arr[], int i, int n)
{
    if (i == n)
        return;

    int j = i; // this keep on shrinking the unsorted array
    while (j > 0 && arr[j - 1] > arr[j])
    {
        swap(arr[j], arr[j - 1]);
        j--;
    }

    recursive_insertion_sort(arr, i + 1, n);
}

int main()
{

    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // recursive_bubble_sort(arr, n);
    recursive_insertion_sort(arr, 0, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}