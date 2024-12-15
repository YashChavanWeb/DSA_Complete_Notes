#include <bits/stdc++.h>
using namespace std;

int main()
{

    /* Q.4. Print all divisions */

    // Met 1 :
    int n3, count = 0;
    cin >> n3;
    cout << "The divisions of " << n3 << " are ";
    for (int i = 1; i <= n3; i++)
    {
        if (n3 % i == 0)
        {
            cout << i << " ";
        }
        else
        {
            continue;
        }
    }
    cout << endl;
    // Complexity is O(n)
    /*





    */
    // Met 2 :
    cout << "The divisions of " << n3 << " are ";
    vector<int> ls;

    for (int i = 1; i <= sqrt(n3); i++)
    // instead of sqrt(n) we can write i*i <=n
    {
        if (n3 % i == 0)
        {
            ls.push_back(i);
            if (n3 / i != i)
            {
                ls.push_back(n3 / i);
            }
        }
        else
        {
            continue;
        }
    }
    sort(ls.begin(), ls.end());
    for (auto it : ls)
    {
        cout << it << " ";
    }
    cout << endl;

    // Complexity:
    // for (int i = 1; i <= sqrt(n3); i++) - O(sqrt(n))
    // sort(ls.begin(), ls.end()); -> m  is the no. of factors - O(nlogn)
    // for (auto it : ls) - O(m) -> m is no of factors
    // Overall complexity -> O(sqrt(n) + mlogm + m )

    return 0;
}
