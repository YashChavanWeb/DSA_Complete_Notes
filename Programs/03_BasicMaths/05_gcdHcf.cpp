#include <bits/stdc++.h>
using namespace std;

int main()
{

    // GCD - Greatest Common Divisor
    // HCF - Highest Common Factor

    // Cases:
    // 1. GCD(11, 13) -> 1 - there will always be a gcd as 1 divides every no
    // 2. GCD(20, 40) -> 20 - one of the numbers can also be a gcd

    // Logic
    // Brute force - GCD(9,12) - run the loop till n2 which is 12
    // Optimized - GCD(12,9) - run the code till the min of the both bcos then the next no will divide just the greater no and not both (so can't be divisor)
    // Best - GCD(12, 9) - and we start from reverse and not from 1 and just run once and then we will get the max gcd
    //  ---- but still the complexity will remain the same O(min(n1, n2))

    // Note: break will break from the outer loop (if added inside a if then outside it is for so break out of that loop)

    // Method 1 : Brute Force Method
    int n, m, gcd = 1;
    cin >> n >> m;

    for (int i = 1; i <= min(n, m); i++)
    {
        if (n % i == 0 && m % i == 0)
        {
            gcd = i;
        }
    }
    cout << "The gcd of " << n << " and " << m << " is " << gcd << endl;
    // Complexity is O(min(n,m))

    /*




    */

    // Method 2 : Euclidean Algorithm
    // gcd(a,b) == gcd(a - b, b) -> where a > b ;     -> we go on doing this until a - b == 0 and other is zero

    // Euclidean Algorithm
    // gcd(20,15) = gcd(5, 15)
    // gcd(5,15) = gcd(10,5)
    // gcd(10,5) = gcd(5, 5)
    // gcd(5,5) = gcd(0, 5)
    // One of them becomes zero so the other parameter is the gcd of 20, 15 that is 5
    // Note: but this can take a quite more complexity for larger difference (52,10)

    // A better way is, gcd(a,b) -- where a > b == gcd(a % b, b);
    // greater % smaller and if one of them is zero then other is the gcd
    // Time Complexity - O(log phi min(a,b)) -> log bcos there is division happening -> phi (we don't know with what it is dividing)

    int a = n, b = m;
    while (a > 0 && b > 0)
    {
        if (a > b)
            a = a % b;
        else
            b = b % a;
    }
    if (a == 0)
        cout << "The gcd is " << b;
    else
        cout << "The gcd is " << a;

    return 0;
}