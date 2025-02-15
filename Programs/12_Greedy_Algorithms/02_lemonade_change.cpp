#include <bits/stdc++.h>
using namespace std;

/*

// lemonade change

- we are having lemonades that we can give with 0 money
- the currency is 5, 10 and 20
- customers will give money and we have to sell them lemonade - price = 5rs
- if customer gives 20 rs then we have to give then 1 lemonade and 15rs back
- but we can only do it if we have money, or else we will not be able to sell the lemonade
- so we have to return true or false based on whether we can serve all the customers or not




Approach

- we will keep 3 variables - 5, 10, 20
- if we get a 5 - +5
- if we get a 10 - +10 and then -5
- if we get a 20 - + 20 -10 -5     or    +20 -5 -5 -5

- Time complexity -> O(N)
- Space complexity -> O(1)




*/

bool lemonade_change(vector<int> arr)
{

    // maintain two variables 5 and 10
    int five = 0, ten = 0;

    for (int i = 0; i < arr.size(); i++)
    {

        if (arr[i] == 5)
            five += 1;
        else if (arr[i] == 10)
        {

            // then we have to check if we have a 5
            if (five)
            {
                five -= 1;
                ten += 1;
            }
            else
            {

                // if we don't have a 5 we can have anything so
                return false;
            }
        }
        else
        {

            // first check if we  have a 10 and a 5
            if (ten && five)
            {
                ten -= 1;
                five -= 1;

                // no need to store 20 variable as we are not returning anything
            }
            else if (five >= 3)
            {
                five -= 3;
            }
            else
            {
                return false;
            }
        }
    }

    return true;
}

int main()
{
    vector<int> arr = {5, 5, 5, 10, 20};

    if (lemonade_change(arr))
    {
        cout << "Served all customers";
    }
    else
    {
        cout << "Did not serve all the customers";
    }

    return 0;
}