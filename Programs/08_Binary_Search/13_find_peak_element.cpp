#include <bits/stdc++.h>
using namespace std;

/*

// Find the Peak element

- if arr[i] is the element then,    arr[i-1] < arr[i] > arr[i+1]

- the array can have multiple peaks - so we can return any one of them index

Eg:
1 2 3 4 5 -> consider -infinity on both the sides, so in this case, 5 is the peak

5 4 3 2 1 -> here as well 5 is the peak as it is greater than -infinity and 4




1. Brute force solution
- we are standing at a element, so we will check for the left and the right
- and when we find it is greater than both, then we can say that the element is the peak element

- we will not check on left for the first element and not check for right for the last element

- Time complexity -> O(n)
- Space complexity -> O(1)






2. Optimal Solution

- we find that there is a sorting pattern in the array
- so we use binary search here
- so for that we know that if we calculate the mid, the peak will be on the left, right or on the mid itself

- if mid is pointing to a increasing curve, then the peak is on the right of the mid (eliminate left) -> e1 < mid < e2

- if mid is pointing to a decreasing curve, then the peak is on the left of the mid (eliminate right) -> e1 > mid > e2

- But what if the first and last element is the peak
- write separate test cases for it

- so the binary search will always start from index 1 and n-2


// The above will work for one peak
- for the multiple peaks also it will work, with a small change

- if the case is 1 5 1 2 1 - then it will fall into an infinite case
- when the element is not at the peak, increasing or decreasing curve, it is on the bottom

\    /
 \  /
  \/  -> here is the element then it will go for infinite loop

- so just we write an else and say that go to the right or left so that it does not get into a infinite loop


- Time complexity -> O(log2n)
- Space complexity -> O(1)






*/

int peak_element_brute(vector<int> arr)
{
    int n = arr.size();

    if (n == 1)
        return 0;

    for (int i = 0; i < n; i++)
    {
        if ((i == 0 || arr[i - 1] < arr[i]) && (i == n - 1 || arr[i] > arr[i + 1]))
        {

            // (i == 0 || arr[i - 1] < arr[i])
            // here if we get either of the condition true then we will move to the next
            // suppose that it is the first element

            // (i == n - 1 || arr[i] > arr[i + 1])
            // then here the arr[i]>arr[i+1] condition needs to be true then only it will return i

            return i;
        }
    }

    return -1;
}

int peak_element_optimal(vector<int> arr)
{
    int n = arr.size();

    // first base case for the single element array
    if (n == 1)
        return 0;

    // case when there is first and last element
    if (arr[0] > arr[1])
        return 0;

    // If the last element is greater than the second-to-last element, it's a peak
    if (arr[n - 2] < arr[n - 1])
        return n - 1;

    // writing for the rest of the array elements
    int low = 1, high = n - 2; // Start the binary search from the second element to the second-to-last element
    while (low <= high)
    {

        int mid = (low + high) / 2;

        if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
            return mid;

        // Check if arr[mid] is greater than the next element
        else if (arr[mid] > arr[mid + 1])
        {
            // this means that the mid is in the decreasing curve
            // and also the peak element is on the left
            // so eliminate right side
            high = mid - 1;
        }
        else if (arr[mid - 1] < arr[mid])
        {
            // this means that the mid is in the increasing curve
            // and also the peak element is on the right
            // so eliminate left side
            low = mid + 1;
        }

        else
        {
            low = mid + 1;
            // or we can also say high = mid - 1;
        }
    }

    // If no peak is found, return -1 (this should never happen in a valid array)
    return -1;
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int peak = peak_element_brute(arr);

    cout << "The peak element index is : " << peak;

    return 0;
}