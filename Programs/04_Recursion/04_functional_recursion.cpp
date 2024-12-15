#include <bits/stdc++.h>
using namespace std;

int demo[] = {4, 10, 1, 4};

// reverse an array using recursion - Brute force
void reverse(int l, int r)
{
    if (l >= r)
        return;

    swap(demo[l], demo[r]);
    reverse(l + 1, r - 1);
}

// reverse an array - optimized approach
//  we just use single variable to swap the array - swap i with n - i - 1
// also when i will cross n/2 then there is no need to swap and it will be the base condition
int demo_size = sizeof(demo) / sizeof(demo[0]);
void reverse_o(int i)
{

    if (i >= demo_size / 2)
        return;

    swap(demo[i], demo[demo_size - i - 1]);
    reverse_o(i + 1);
}

// Check whether string is palindrome or not
// same as the reverse logic, here we have to compare and not actually swap
bool check_palindrome(int i, string &name)
{
    // if crossed then it means all are same
    if (i >= name.size() / 2)
        return true; // this is the actual returning value of the function

    // does not match so return false or call function again and what it returns is the final value
    if (name[i] != name[name.size() - i - 1])
        return false; // this is the actual returning value of the function

    return check_palindrome(i + 1, name); // the return value will come here which will be returned by the main function
}

int main()
{
    int arr[5] = {2, 3, 1, 4, 2}; // Array to reverse
    int n = sizeof(arr) / sizeof(arr[0]);

    // Display the original array
    cout << "The array before : ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    // Reverse array using a for loop
    for (int i = 0, j = n - 1; j >= i; i++, j--)
    {
        swap(arr[i], arr[j]);
    }

    // Display the reversed array after using the for loop
    cout << "\nThe array after : ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    // Reverse array using recursion on demo array
    // reverse(0, 3);
    // cout << "\nThe demo array after recursion: ";
    // for (int i = 0; i < 4; i++)
    // {
    //     cout << demo[i] << " ";
    // }

    // Reverse array with just one variable - optimized
    // reverse_o(0);
    // for (int i = 0; i < demo_size; i++)
    // {
    //     cout << endl
    //          << demo[i] << " ";
    // }

    // Check if a given string is palindrome or not
    string name;
    cin >> name;
    if (check_palindrome(0, name))
    {
        cout << "It is a palindrome string";
    }
    else
    {
        cout << "Not a palindrome ";
    }

    return 0;
}
