#include <bits/stdc++.h>
using namespace std;

/*
// Union of two sorted arrays
- sorted arrays part will help us to find the most optimal solution
- the arrays can also have duplicates


1. Brute force approach
- we can put the first and the second array into the set
- the set will only contain unique elements and also in the sorted order

Time Complexity can be: first array adding into the set O(n1logn), second array putting into the set O(n2logn), putting set back into a third array O(n1+n2) - assuming worst case that all elements are unique

- Time complexity -> O(n1logn + n2logn + n1+n2)

Space Complexity can be: first space of the set to store 2 arrays O(n1+n2), then a third union array to return the answer O(n1+n2)

- Space Complexity -> O(2(n1+n2))


2. Optimal Approach
- here we can use the two pointer approach
- where we can put the smaller element into the union array from the a[i] and b[j]
- but before adding the element we will also check what is the previous element in the union array
- if it is same as that of the element we are going to push, then we don't push
- also the pointer will go ahead irrespective of whether we add the element or not as we are comparing the elements in the array

- Time complexity -> O(n1+n2) - worst case
- Space Complexity -> O(n1+n2) for returning the answer not any extra in the algorithm -> worst case as there can be all the elements unique


*/

vector<int> union_array_brute(vector<int> a, vector<int> b)
{
    int n1 = a.size();
    int n2 = b.size();

    set<int> st;

    // insert elements of the first array
    for (int i = 0; i < n1; i++)
    {
        st.insert(a[i]);
    }

    // insert elements of the second array
    for (int i = 0; i < n2; i++)
    {
        st.insert(b[i]);
    }

    vector<int> arr_union;
    for (auto it : st)
    {
        arr_union.push_back(it);
    }

    return arr_union;
}

vector<int> union_array_optimal(vector<int> a, vector<int> b)
{
    int n1 = a.size();
    int n2 = b.size();

    int i = 0, j = 0;
    vector<int> union_array;

    // iterate till one of the array gets exhausted
    while (i < n1 && j < n2)
    {

        // first check which one is the smaller
        if (a[i] <= b[j])
        {

            // then check here if the array element is equal to the previous element in the union
            // also we will check if it is the first element in the union then too we will add the element

            if (union_array.back() != a[i] || union_array.size() == 0)
            {
                union_array.push_back(a[i]);
            }
            // irrespective of whether you add the element or not we have to increment the pointer
            i++;
        }
        else
        {
            if (union_array.back() != a[i] || union_array.size() == 0)
            {
                union_array.push_back(b[j]);
            }
            j++;
        }
    }

    // after the while loop here we can have any one of the array to get exhausted and there can be another array remaining
    while (i < n1)
    {
        if (union_array.back() != a[i] || union_array.size() == 0)
        {
            union_array.push_back(a[i]);
        }
        i++;
    }
    while (j < n2)
    {
        if (union_array.back() != b[j] || union_array.size() == 0)
        {
            union_array.push_back(b[j]);
        }
        j++;
    }
}

int main()
{
    int n1;
    cin >> n1;

    vector<int> a, b;
    for (int i = 0; i < n1; i++)
    {
        int x;
        cin >> x;
        a.push_back(x);
    }

    int n2;
    cin >> n2;

    for (int i = 0; i < n2; i++)
    {
        int x;
        cin >> x;
        b.push_back(x);
    }

    vector<int> result = union_array_brute(a, b);

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }

    return 0;
}