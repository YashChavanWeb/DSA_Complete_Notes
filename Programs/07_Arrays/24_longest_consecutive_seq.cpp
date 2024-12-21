#include <bits/stdc++.h>
using namespace std;

/*

// Longest consecutive sequence
- we will be given an array, and we have to find the max no. of consecutive elements in it
- and then return its length

- Eg: {3, 100, 2, 1 , 102} -> here longest consecutive seq is 1 2 3 so return length = 3



1. Brute force solution

- so first we will take a variable longest as 1 and also a counter =1
- then we will select each element in array and then iterate through the entire array (i==j) then continue
- and check if we have element + 1 in the array
- if not then we will move to the next element
- if we find a element + 1 in the array then we will increment the counter, update the element
- then again we will follow the same process and then if we don't find the next element in the sequence
- then we will update the longest variable with the counter and then move to the next element

- Time complexity -> (n^2)
- Space complexity -> O(1)






2. Better solution

- the first step is the sort the array
- consider the longest = 1
- we will be keeping the track of the last smallest element we have seen initially it is INT_MIN
- at every iteration we check whether the last smallest is one lesser than the element or not
- if it is not then we will start fresh and replace the last smallest by the element
- but if last smallest is one lesser than the element then we will update the counter and the length

- so the catch is if the last smaller is not one lesser to the element then just start fresh if it is greater and if it is equal then don't change anything just move ahead

- Time complexity -> O(nlogn + n) (sorting and then performing)
- Space complexity -> O(1) (no extra space used sorted the same array)





3. Optimal Solution
- here we will first store all the elements in an unordered set
- here the duplicate elements will not come
- then we will check if the element - 1 is present in the set
- if yes then that element is not the starting one, we want the starting element of a sequence
- and if we not get element - 1 in the set then we will make it our first element and then find the x+1 element in the set to increase the counter if the sequence is there

- Time complexity: O(n) for storing in set , logic for finding the first element by while O(2n)
- Space complexity: O(n) for storing in set

- Time complexity -> O(n+2n) = O(3n)
- Space complexity -> O(n)

*/

bool linear_search(vector<int> &arr, int target)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == target)
        {
            return true;
        }
    }

    return false;
}

int longest_brute(vector<int> arr, int n)
{
    int longest = 1;

    for (int i = 0; i < n; i++)
    {
        int x = arr[i];  // take the current element
        int counter = 1; // initialize counter to 1 which is the current element

        // find the next consecutive elements x+1, x+2 and so on
        while (linear_search(arr, x + 1))
        {
            counter++; // increment the counter for each found consecutive element

            x = x + 1; // update x to the next consecutive element
        }

        // Update the longest sequence length if needed
        longest = max(longest, counter);
    }

    return longest;
}

int longest_better(vector<int> arr, int n)
{

    // first sort the array
    sort(arr.begin(), arr.end());

    int longest = 1, counter = 1;
    int last_smallest = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        // if equal to one lesser then update counter and last smallest
        if (arr[i] - 1 == last_smallest)
        {
            counter += 1;
            last_smallest = arr[i];
        }

        // if equal to the last smallest then do nothing
        else if (arr[i] == last_smallest)
        {
            continue;
        }

        // if not equal to the last smallest then start from fresh by re-initializing the counter
        else if (arr[i] != last_smallest)
        {
            counter = 1;
            last_smallest = arr[i];
        }

        longest = max(longest, counter);
    }

    return longest;
}

int longest_optimal(vector<int> arr, int n)
{

    int longest = 1, counter;

    if (n == 0)
        return 0; // there is no longest element if no size

    // create a unordered set for storing the array elements
    unordered_set<int> st;
    for (int i = 0; i < n; i++)
    {
        st.insert(arr[i]);
    }

    // iterating into the set
    for (auto it : st)
    {
        if (st.find(it - 1) == st.end())
        {
            // this means that we have no previous element for this element in the set
            // so we can start a new sequence from this element
            int x = it;
            counter = 1;

            // now search for the element after this
            while (st.find(x + 1) != st.end())
            {
                // if we are in the loop it means that we have got the element that is one greater than it

                // so we will increment the element as well and search for x + 1 and so on
                x = x + 1;
                // so we can increment the counter
                counter++;
            }

            // after we complete this loop we will get the counter value whether ii is unchanged as there was no next element for it or it will be changed due to the conditions

            // so we will just update the longest value
            longest = max(longest, counter);
        }
    }

    return longest;
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

    // int longest = longest_brute(arr, n);
    // int longest = longest_better(arr, n);
    int longest = longest_optimal(arr, n);
    cout << "Longest sequence is of length " << longest;

    return 0;
}