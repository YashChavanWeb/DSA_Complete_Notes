#include <bits/stdc++.h>
using namespace std;

/*
    // Remove the duplicates from the given array
    - find the unique elements
    - place them starting from 0th index
    - the remaining elements give any value to them
    - then tell the count of how many unique elements are there

1. Brute force Approach
- unique elements so set data structure
- put all the elements into the set (it stores in ascending order)
- it will just take the unique elements
- then after that you can put the elements from the set into the array
- the indexes that is remaining are of no use so we can just simply return that index which will be the no. of unique elements
- Complexity: Set takes logn to insert and we are doing this n times, also to put it back into the array is n
- Time Complexity -> O(nlogn + n)

2. Optimal Solution
- We can use here two pointer approach
- keep pointer i considering its element to be unique
- take pointer j and check which element is not same as j and then just replace it with i+1 and also do i++
- follow the same process
- finally the no of unique elements will be i+1
- Time Complexity -> O(n)

*/

int find_duplicates(vector<int> &arr, int n)
{
    int i = 0;
    for (int j = 1; j < n; j++)
    {
        if (arr[j] != arr[i])
        {
            arr[i + 1] = arr[j];
            i++;
        }
    }
    return i;
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

    cout << "The number of unique elements are " << find_duplicates(arr, n);

    return 0;
}