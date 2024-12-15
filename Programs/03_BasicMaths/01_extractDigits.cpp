#include <bits/stdc++.h>
using namespace std;

int main()
{

    /* ------------- Extraction of Digits in reverse order ------------- */
    /*

    778 % 10 = 8
    778 / 10 = 77.8 = 77 (int)

    */

    int n, lastdig;
    cin >> n;
    while (n > 0)
    {
        lastdig = n % 10;
        cout << lastdig << " ";
        n = n / 10;
    }
    cout << endl;

    /* Q.1. Count the digits of a number */

    // Met 1 : easy - just put a counter before every extraction (n / 10) to count the digits
    // (no need for n%10)

    // Met 2 :
    int m;
    cin >> m;
    int cnt = (int)(log10(m) + 1);
    cout << "The count of digits is : " << cnt << endl;
    // Time complexity = O(log10(n))

    // if division is happening by 2 then complexity is O(log2(n))
    // Note: If the no of iterations is based on division, then complexity is logarithmic
    /*



    */
    /* Q.2. Reverse a number - breathing zeros are not considered */
    int a, lst, revnum = 0;
    cin >> a;
    // int a1 = a; // used later in Q.3.
    while (a > 0)
    {
        lst = a % 10;
        revnum = (revnum * 10) + lst;
        a = a / 10;
    }
    cout << "Reverse number is : " << revnum << endl;

    return 0;
}
