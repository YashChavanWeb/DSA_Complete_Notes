#include <bits/stdc++.h>
using namespace std;

/*
// Second largest element in the array without sorting

1. Brute force
- sort the array and check the n-2 index
- cannot directly tell that it is second largest as there can be same elements as well so it will become the largest
- so when we have n-2 index check if it is same as the previous index
- if yes then compare with the next index
- so the loop will go from n-2 to 0 and if arr[i] != largest then we can say that arr[i] is the second largest
- Here the complexity will be O(Nlog2N)

2. Better Approach
- find the largest element as we have done previously
- then after that add a for loop and consider max_element as -1
- then compare if (arr[i] > max_element && arr[i] != largest)
- if yes then update max_element with arr[i]
- so with this we will get the second largest element
- so the time complexity will be O(2N)


3. Optimal Approach
- we will consider the largest as a[0] and the second_largest as -1
- now if the element is larger than largest then second_largest = largest and largest = element
- but if the element is smaller than largest but it is greater than second_largest then second_largest = element
- so the time complexity will be O(N) as we are doing just one pass

*/

int second_largest(vector<int> arr, int n)
{
    int largest = arr[0], sLargest = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > largest)
        {
            sLargest = largest;
            largest = arr[i];
        }
        else if (arr[i] < largest && arr[i] > sLargest)
        {
            sLargest = arr[i];
        }
    }

    return sLargest;
}

int second_smallest(vector<int> arr, int n)
{
    int smallest = arr[0], sSmallest = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] < smallest)
        {
            sSmallest = smallest;
            smallest = arr[i];
        }
        else if (arr[i] > smallest && arr[i] < sSmallest)
        {
            sSmallest = arr[i];
        }
    }

    return sSmallest;
}

vector<int> getSecondOrderElements(vector<int> arr, int n)
{
    int secondLargest = second_largest(arr, n);
    int secondSmallest = second_smallest(arr, n);

    return {secondLargest, secondSmallest};
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

    vector<int> result = getSecondOrderElements(arr, n);
    // Print the result
    cout << "Second largest: " << result[0] << endl;
    cout << "Second smallest: " << result[1] << endl;

    return 0;
}