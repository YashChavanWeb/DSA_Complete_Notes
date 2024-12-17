#include <bits/stdc++.h>
using namespace std;

/*
// Intersection of two sorted arrays
- elements present in both arrays
- repetition of elements is allowed

1. Brute force approach
- create a visited array and all indexes marked as 0
- keep pointer in the first array and check for that element in the second array
- if we find an element then we will add it into the new array and also the visited array we will mark the index of that taken 2 as '1'
- once the iteration is over then the ans array will be ready, no need to look into the second array

- Time complexity -> O(n1xn2)
- Space Complexity -> O(n2)  // the smaller visited array

2. Optimal Approach
- we can use a two pointer approach
- we will keep two pointers i and j at the starting of the arrays
- compare first with the second
- if does not match then move i++
- if they match then move both i++, j++ and also add the element into the array
- Time complexity -> O(n1 + n2) - in the worst case
- Space Complexity -> O(1) - we are not using any extra spaces

 
*/

vector<int> intersection_brute(vector<int> a, vector<int> b)
{
    int n1 = a.size();
    int n2 = b.size();

    vector<int> visited(n2, 0); // create visited array of all values of zero of size of second array
    vector<int> intersection;

    for (int i = 0; i < n1; i++)
    {

        for (int j = 0; j < n2; j++)
        {

            // check if the array element is same and also it is not visited
            // then add it and break as we will look out for the next element
            if (a[i] == b[j] && visited[j] == 0)
            {
                intersection.push_back(a[i]);
                visited[j] = 1; // mark the index as visited
                break;
            }

            // also if while finding the element 1 becomes smaller we can always break as the array is sorted
            if (b[j] > a[i])
                break;
        }
    }

    return intersection;
}

vector<int> intersection_optimal(vector<int> a, vector<int> b)
{
    int n1 = a.size(), n2 = b.size();
    int i = 0, j = 0;
    vector<int> intersection;

    while (i < n1 && j < n2)
    {
        if (a[i] < b[j])
        {
            i++;
        }
        else if (b[j] < a[i])
        {
            j++;
        }
        else
        {
            intersection.push_back(a[i]);
            i++;
            j++;
        }
    }

    return intersection;
}

int main()
{

    int n1;
    cin >> n1;

    vector<int> a;
    for (int i = 0; i < n1; i++)
    {
        int x;
        cin >> x;
        a.push_back(x);
    }

    int c2;
    cin >> c2;

    vector<int> b;
    for (int i = 0; i < c2; i++)
    {
        int x;
        cin >> x;
        b.push_back(x);
    }

    // vector<int> result = intersection_brute(a, b);
    vector<int> result = intersection_optimal(a, b);

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }

    return 0;
}