#include <bits/stdc++.h>
using namespace std;

/*

// Number of sub arrays with given sum k

// #### Refer the subarray question for the notes

1. Brute - 3 loops
2. Better - 2 loops

3. Best - prefixsum
- the number of s-k will be the number of k in the array





--- Dry Run

### Initial Values:
- `arr = [2, 1, 3, 4, 5]`
- `target = 3`
- `n = 5`
- `mpp = {0: 1}` (initially, we assume we have seen a prefix sum of 0 once)
- `prefix_sum = 0`
- `cnt = 0`

---

### Iteration 1 (i = 0):

- **i**: 0
- **prefix_sum**: `0 + 2 = 2`
- **remove**: `prefix_sum - target = 2 - 3 = -1`
- **cnt**: `cnt + mpp[-1] = 0 + 0 = 0` (mpp[-1] doesn't exist)
- **mpp**: `{0: 1, 2: 1}` (add prefix sum 2)

---

### Iteration 2 (i = 1):

- **i**: 1
- **prefix_sum**: `2 + 1 = 3`
- **remove**: `prefix_sum - target = 3 - 3 = 0`
- **cnt**: `cnt + mpp[0] = 0 + 1 = 1` (mpp[0] exists with value 1)
- **mpp**: `{0: 1, 2: 1, 3: 1}` (add prefix sum 3)

---

### Iteration 3 (i = 2):

- **i**: 2
- **prefix_sum**: `3 + 3 = 6`
- **remove**: `prefix_sum - target = 6 - 3 = 3`
- **cnt**: `cnt + mpp[3] = 1 + 1 = 2` (mpp[3] exists with value 1)
- **mpp**: `{0: 1, 2: 1, 3: 1, 6: 1}` (add prefix sum 6)

---

### Iteration 4 (i = 3):

- **i**: 3
- **prefix_sum**: `6 + 4 = 10`
- **remove**: `prefix_sum - target = 10 - 3 = 7`
- **cnt**: `cnt + mpp[7] = 2 + 0 = 2` (mpp[7] does not exist)
- **mpp**: `{0: 1, 2: 1, 3: 1, 6: 1, 10: 1}` (add prefix sum 10)

---

### Iteration 5 (i = 4):

- **i**: 4
- **prefix_sum**: `10 + 5 = 15`
- **remove**: `prefix_sum - target = 15 - 3 = 12`
- **cnt**: `cnt + mpp[12] = 2 + 0 = 2` (mpp[12] does not exist)
- **mpp**: `{0: 1, 2: 1, 3: 1, 6: 1, 10: 1, 15: 1}` (add prefix sum 15)

---

### Final Values:

- **cnt** = 2 (The number of subarrays whose sum is equal to 3)





*/

int no_of_subarray_brute(vector<int> arr, int n, int target)
{

    int cntr = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int sum = 0;
            for (int k = i; k <= j; k++)
            {
                sum += arr[k];
            }

            if (sum == target)
            {
                cntr++;
            }
        }
    }

    return cntr;
}

int no_of_subarray_better(vector<int> arr, int n, int target)
{

    int cntr = 0;

    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[i];
            if (sum == target)
            {
                cntr++;
            }
        }
    }

    return cntr;
}

int no_of_subarray_optimal(vector<int> arr, int n, int target)
{

    map<int, int> mpp;
    mpp[0] = 1; // this has significance

    // store a prefix sum as 0
    int prefix_sum = 0;
    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        prefix_sum += arr[i];
        int remove = prefix_sum - target;
        cnt += mpp[remove];

        mpp[prefix_sum] = 1;
    }

    return cnt;
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

    int target;
    cin >> target;

    // int result = no_of_subarray_brute(arr, n, target);
    int result = no_of_subarray_better(arr, n, target);
    cout << "The no. of subarrays with sum " << target << " is " << result;

    return 0;
}