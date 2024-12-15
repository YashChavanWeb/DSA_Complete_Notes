// ### Merge Sort

// the algorithm means divide and merge

/*
// How the algorithm will work

- first we will consider a low and a high
- low is the starting pointer of the array and high is the ending point of that array
- we are dividing the array on the basis of the mid which can be calculated as mid = (low+high)/2
- so in short the divided array will be from low to mid and then mid+1 to high
- then after dividing there is the sorting logic
- then after both the parts are sorted then we can merge both the divided arrays into a single sorted array
- now to write the base condition, we can say that when the low and high will be the same then there will be a single element and so we will stop


// Merging part

- here also we have two pointers, one at low and other at mid+1
- compare both the elements, and the element that is smaller is added to the array and then that pointer is incremented
- this is done till the end
- if still there are elements in one array remaining, then simply add them to the sorted array directly
- but we are pushing these elements into a temporary array, so copy it into the main array from low to high
- to store from temp to the arr in correct order we have to do temp[low-i] so that indexing starts from 0


// Time Complexity of merge sort
// here division is occurring by 2 so it will be log based - log2n for the dividing
// and we are also performing the merge after the division so it will be n times merging for comparing both the array elements

// Time complexity -> O(nlog2n) -> it is the best, avg and worst case

// Space complexity
- there are only indexes used on the same array so nothing about them
- but everytime a new array is created we are using a temp array
- n times there will formation of new array

// Space complexity -> O(n)

*/

#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int low, int mid, int high)
{

    // pointer for first array
    int left = low;

    // pointer for second array
    int right = mid + 1;

    // temporary array for storing
    vector<int> temp;

    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }

    // if one side array is done but other side still has elements then directly add then to the temp array

    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }

    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    // finally copying the temp array into the main array
    for (int i = low; i <= high; i++)
    {
        // so due to i-low we don't have to maintain the index of the temp
        arr[i] = temp[i - low];
    }
}

void merge_sort(vector<int> &arr, int low, int high)
{

    // base condition - if low == high (it means single element)
    if (low >= high)
        return;

    // calculate the mid for dividing the array
    int mid = (low + high) / 2;

    merge_sort(arr, low, mid);      // first
    merge_sort(arr, mid + 1, high); // second
    merge(arr, low, mid, high);     // merging logic
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

    merge_sort(arr, 0, n - 1);

    for (auto it : arr)
    {
        cout << it << " ";
    }

    return 0;
}
