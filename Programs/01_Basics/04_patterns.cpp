// ------------------------- Steps to Print Patterns -------------------------

// 1. for outer loop count number of lines
// 2. for inner loop focus on the columns and connect them somehow to the rows
// 3. printing print them inside the inner for loop
// 4. Observe symmetry  (optional)

#include <bits/stdc++.h>
using namespace std;

void pattern1(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

void pattern2(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

void pattern3(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

void pattern4(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}

void pattern5(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++) // or  i is 1 to n  ->   j = 0; j < n-i+1 ; j++
        {
            cout << "* ";
        }
        cout << endl;
    }
}

void pattern6(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= n - i; j++)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

void pattern7(int n)
{
    for (int i = 1; i <= n; i++)
    {
        // loop for spaces
        for (int j = 1; j <= n - i; j++)
        {
            cout << " ";
        }

        // loop for stars
        for (int k = 1; k <= (2 * i - 1); k++)
        {
            cout << "*";
        }
        cout << endl;
    }
}

void pattern8(int n)
{
    for (int i = n; i >= 1; i--)
    {

        for (int j = 1; j <= n - i; j++)
        {
            cout << " ";
        }

        for (int k = 1; k <= (2 * i - 1); k++)
        {
            cout << "*";
        }
        cout << endl;
    }
}

void pattern9(int n)
{
    for (int i = 1; i <= n; i++)
    {
        // loop for spaces
        for (int j = 1; j <= n - i; j++)
        {
            cout << " ";
        }

        // loop for stars
        for (int k = 1; k <= (2 * i - 1); k++)
        {
            cout << "*";
        }
        cout << endl;
    }

    for (int i = n; i >= 1; i--)
    {

        for (int j = 1; j <= n - i; j++)
        {
            cout << " ";
        }

        for (int k = 1; k <= (2 * i - 1); k++)
        {
            cout << "*";
        }
        cout << endl;
    }
}

void pattern10(int n)
{
    for (int i = 1; i <= 2 * n - 1; i++)
    {
        int stars = i;

        if (i > n)
            stars = 2 * n - i;

        for (int j = 1; j <= stars; j++)
        {
            cout << "*";
        }
        cout << endl;
    }

    // Better Complexity

    //  for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= i; j++)
    //     {
    //         cout << "*";
    //     }
    //     cout << endl;
    // }

    // for (int i = n - 1; i >= 1; i--)
    // {
    //     for (int j = 1; j <= i; j++)
    //     {
    //         cout << "*";
    //     }
    //     cout << endl;
    // }
}

void pattern11(int n)
{
    int start;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            start = 1;
        }
        else
        {
            start = 0;
        }

        for (int j = 0; j <= i; j++)
        {
            cout << start;
            start = 1 - start;
        }
        cout << endl;
    }
}

void pattern12(int n)
{
    int spaces = 2 * (n - 1);
    for (int i = 1; i <= n; i++)
    {

        // Numbers
        for (int j = 1; j <= i; j++)
        {
            cout << j;
        }

        // Spaces
        for (int j = 1; j <= spaces; j++)
        {
            cout << " ";
        }

        // Numbers
        for (int j = i; j >= 1; j--)
        {
            cout << j;
        }
        cout << endl;
        spaces = spaces - 2;
    }
}

void pattern13(int n)
{
    int num = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << num << " ";
            num++;
        }
        cout << endl;
    }
}

void pattern14(int n)
{
    for (int i = 1; i <= n; i++)
    {
        char c = 'A';
        for (int j = 1; j <= i; j++)
        {
            cout << c << " ";
            c++;
        }
        cout << endl;
    }
}

void pattern15(int n)
{
    for (int i = n; i >= 1; i--)
    {
        char c = 'A';
        for (int j = 1; j <= i; j++)
        {
            cout << c << " ";
            c++;
        }
        cout << endl;
    }
}

void pattern16(int n)
{
    char c = 'A';
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << c;
        }
        cout << endl;
        c++;
    }
}

void pattern17(int n)
{
    for (int i = 0; i < n; i++)
    {
        // loop for spaces
        for (int j = 0; j < n - i; j++)
        {
            cout << " ";
        }

        // loop for characters
        char ch = 'A';
        int breakPoint = (2 * i + 1) / 2;

        for (int k = 1; k <= (2 * i + 1); k++)
        {
            cout << ch;
            if (k <= breakPoint)
            {
                ch++;
            }
            else
            {
                ch--;
            }
        }
        cout << endl;
    }
}

void pattern18(int n)
{

    for (int i = 0; i < n; i++)
    {
        for (char c = 'E' - i; c <= 'E'; c++)
        {
            cout << c << " ";
        }
        cout << endl;
    }
}

void pattern19(int n)
{
    int spaces = 0;
    for (int i = 1; i <= n; i++)
    {
        // stars
        for (int j = n; j >= i; j--)
        {
            cout << "*";
        }

        // spaces
        for (int j = 1; j <= spaces; j++)
        {
            cout << " ";
        }

        // stars
        for (int j = n; j >= i; j--)
        {
            cout << "*";
        }
        cout << endl;
        spaces += 2;
    }

    spaces -= 2;
    for (int i = 1; i <= n; i++)
    {
        // stars
        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }

        // spaces
        for (int j = 1; j <= spaces; j++)
        {
            cout << " ";
        }

        // stars
        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }
        cout << endl;
        spaces -= 2;
    }
}

void pattern20(int n)
{
    // int spaces = 2 * (n-1);
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= i; j++)
    //     {
    //         cout << "*";
    //     }

    //     for (int j = 1; j <= spaces; j++)
    //     {
    //         cout << " ";
    //     }

    //     for (int j = 1; j <= i; j++)
    //     {
    //         cout << "*";
    //     }

    //     cout << endl;
    //     spaces -= 2;
    // }

    // spaces += 4;
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = n-1; j >= i; j--)
    //     {
    //         cout << "*";
    //     }

    //     for (int j = 1; j <= spaces; j++)
    //     {
    //         cout << " ";
    //     }

    //     for (int j = n-1; j >= i; j--)
    //     {
    //         cout << "*";
    //     }

    //     cout << endl;
    //     spaces += 2;
    // }

    int spaces = 2 * n - 2;
    for (int i = 1; i <= 2 * n - 1; i++)
    {
        int stars = i;
        if (i > n)
            stars = 2 * n - i;

        for (int j = 1; j <= stars; j++)
        {
            cout << "*";
        }

        for (int j = 1; j <= spaces; j++)
        {
            cout << " ";
        }

        for (int j = 1; j <= stars; j++)
        {
            cout << "*";
        }
        cout << endl;
        if (i < n)
            spaces -= 2;
        else
            spaces += 2;
    }
}

void pattern21(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 || j == 0 || i == n - 1 || j == n - 1)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }
}

void pattern22(int n)
{
    for (int i = 0; i < 2 * n - 1; i++)
    {
        for (int j = 0; j < 2 * n - 1; j++)
        {
            int top = i;
            int left = j;
            int right = (2 * n - 2) - j;
            int bottom = (2 * n - 2) - i;

            cout << (n - min(min(top, bottom), min(left, right))) << " ";
        }
        cout << endl;
    }
}

int main()
{

    int n;
    cin >> n;

    pattern1(n);
    pattern2(n);
    pattern3(n);
    pattern4(n);
    pattern5(n);
    pattern6(n);
    pattern7(n);
    pattern8(n);
    pattern9(n);
    pattern10(n);
    pattern11(n);
    pattern12(n);
    pattern13(n);
    pattern14(n);
    pattern15(n);
    pattern16(n);
    pattern17(n);
    pattern18(n);
    pattern19(n);
    pattern20(n);
    pattern21(n);
    pattern22(n);

    return 0;
}
