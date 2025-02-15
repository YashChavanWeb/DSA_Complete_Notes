#include <bits/stdc++.h>
using namespace std;

/*

// Assign Cookies

- there is a parent who has children which have a greed factor from 1 to 5
greed = [1, 5, 3, 3, 4]
- the parent have cookies as well for the children which have size
- the child will only be satisfied if it is greater or equal to the greed of the child
- one cookie can be given to only one child
- and we have to return the number of children that we were able to satisfy






Approach:

- we will take the size array and then sort it
- then we will also sort the greed factor
- then we will take two pointers for greed and size arrays

- Time complexity -> O(nlogn + mlogm + M) -> sort + sort + while loop
- Space complexity -> O(1)


*/

int assign_cookies(vector<int> greed, vector<int> cookie_size)
{

    // get the sizes for running the loop
    int gs = greed.size();
    int cs = cookie_size.size();

    // sort both the arrays
    sort(greed.begin(), greed.end());
    sort(cookie_size.begin(), cookie_size.end());

    // take two pointers pointing to the two arrays starting
    int gptr = 0, sptr = 0;

    while (gptr < gs && sptr < cs)
    {
        // now first check if the greed is satisfied
        if (cookie_size[sptr] >= greed[gptr])
        {
            gptr++;
        }

        sptr++;
    }

    return gptr;
}

int main()
{

    vector<int> greed = {1, 5, 3, 3, 4};
    vector<int> cookie_size = {4, 2, 5, 2, 1, 3};

    int satisfied = assign_cookies(greed, cookie_size);
    cout << "No of children satisfied are : " << satisfied;
 
    return 0;
}