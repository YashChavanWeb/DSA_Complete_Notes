#include <bits/stdc++.h>
using namespace std;

/*

// Aesteroid Collision

- asteroids if +ve then moving in right and if -ve then moving in left direction
- if 10 and 2 collide then 2 will be destroyed
- if 10 and 10 collide then 10 will be destroyed
- we have to return the final state of the asteroids



Approach

- we will maintain a stack
- we will keep on first pushing the positive elements
- and use the negative elements to compare

- Time complexity -> O(N + N)
- Space complexity -> O(N)

*/

vector<int> asteroid_collisions(vector<int> arr)
{

    // create a list
    vector<int> st;

    // start traversing the array
    for (int i = 0; i < arr.size(); i++)
    {

        // if stack is empty then push the element in stack
        if (arr[i] > 0)
        {
            st.push_back(arr[i]);
        }
        else
        {

            // if the stack is not empty then we have to do

            while (!st.empty() && st.back() > 0 && st.back() < abs(arr[i]))
            {
                st.pop_back();
            }

            // when we come out first check if both elements are equal, if yes then both get destroyed
            if (!st.empty() && st.back() == abs(arr[i]))
            {
                st.pop_back();
            }

            // if stack is empty or not equal then we have to do

            // if stack empty then add in stack
            else if (st.empty() || st.back() < 0)
            {

                // this is basically storing the negative element
                st.push_back(arr[i]);
            }
        }
    }
    return st;
}

int main()
{
    vector<int> arr = {4, 7, 1, 1, 2, -3, -7, 17, 15, -18, -19};

    vector<int> result = asteroid_collisions(arr);

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }

    return 0;
}