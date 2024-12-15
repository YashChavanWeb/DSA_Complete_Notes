#include <bits/stdc++.h>
using namespace std;

int main()
{

    /* Q.2. Reverse a number - breathing zeros are not considered */

    int a, lst, revnum = 0;
    cin >> a;
    int a1 = a; // storing the copy of the actual number as it changes due to /10
    while (a > 0)
    {
        lst = a % 10;
        revnum = (revnum * 10) + lst;
        a = a / 10;
    }
    cout << "Reverse number is : " << revnum << endl;
    /*




    */
    /* Q.3. Check if pallindrome or not - 121 (reverse is also the same) */

    if (revnum == a1)
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
    cout << endl;
    /*




    */

    /* Q.4. Check if armstrong number or not */
    // armstrong : 371 - 3^3 + 7^3 + 1^3 = 371  -> same number back so it is armstrong no.

    int n1, lastdig1, sum = 0, n2;
    cin >> n1;
    n2 = n1;
    while (n1 > 0)
    {
        lastdig1 = n1 % 10;
        sum += pow(lastdig1, 3);
        n1 = n1 / 10;
    }
    if (sum == n2)
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
    cout << endl;

    return 0;
}
