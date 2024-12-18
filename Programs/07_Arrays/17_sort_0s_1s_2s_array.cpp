#include <bits/stdc++.h>
using namespace std;

/*
// Sort an array of 0s, 1s and 2s

1. Brute force
- sort the array using the quick or merge sort

- Time complexity -> O(nlogn)




2. Better Approach
- keep 3 counters counter0 , 1 and 2
- and increment the counter by 1 if we see any of the integer of that count
- after we have count of all 3 values, we can run the loop till the counter-1 for index and then override the values in the array with the 0's 1's and 2's

- Time complexity -> O(n) for counter O(n) for overriding -> O(2n)
- Space complexity -> O(1)





3. Optimal Approach
- Here we will be using the "Dutch National Flag algorithm"

- The 3 rules that we will be following are
    -- 0 to low - 1 -> all 0s are sorted (extreme left)
    -- low to mid - 1 -> all 1s are sorted
    -- high + 1 to n - 1 -> all 2s are sorted (extreme right)

    Note: the middle chunk of mid to high will be of unsorted elements

- we will be performing all the iterations considering the arr[mid] to be our comparing element
- Here also there are 3 cases
    -- arr[mid] == 0  -> then we can swap( arr[mid], arr[low])
        --- so now low is on 0 and mid is on 1 and both are sorted so we can do low++ and mid++
    -- arr[mid] == 1 -> then it is already sorted as it is coming after mid-1
        --- so no need to change just do mid++
    -- arr[mid] == 2 -> then we can swap(arr[mid], arr[high] )
        --- so now high has 2 and mid has high element, so we just have to shrink high so we do just high--

- If the mid crosses high then, we can say that we can stop and the array becomes sorted

- Time Complexity -> o(n)
- Space Complexity -> O(1)

*/

void sort_array_better(vector<int> &arr, int n)
{

    int counter0 = 0, counter1 = 0, counter2 = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
            counter0++;
        if (arr[i] == 1)
            counter1++;
        if (arr[i] == 2)
            counter2++;
    }

    for (int i = 0; i < counter0; i++)
    {
        arr[i] = 0;
    }
    for (int i = counter0; i < counter0 + counter1; i++)
    {
        arr[i] = 1;
    }
    for (int i = counter0 + counter1; i < n; i++)
    {
        arr[i] = 2;
    }
}

void sort_array_optimal(vector<int> &arr, int n)
{
    int low = 0, mid = 0, high = n - 1;

    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
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

    // sort_array_better(arr, n);
    sort_array_optimal(arr, n);

    cout << "The sorted array is : ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}