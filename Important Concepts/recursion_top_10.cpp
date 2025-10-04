#include <vector>
#include <string>
using namespace std;

// 1. Factorial of a Number
int factorial(int n)
{
    if (n == 0)
        return 1;
    return n * factorial(n - 1);
}

// 2. Fibonacci Series
int fibonacci(int n)
{
    if (n <= 1)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// 3. Sum of Natural Numbers
int sumNaturalNumbers(int n)
{
    if (n <= 0)
        return 0;
    return n + sumNaturalNumbers(n - 1);
}

// 4. Tower of Hanoi
void towerOfHanoi(int n, char source, char auxiliary, char destination)
{
    if (n == 1)
    {
        // Move disk 1 from source to destination
        return;
    }
    towerOfHanoi(n - 1, source, destination, auxiliary);
    // Move disk n from source to destination
    towerOfHanoi(n - 1, auxiliary, source, destination);
}

// 5. Reverse a String
void reverseString(string &str, int start, int end)
{
    if (start >= end)
        return;
    swap(str[start], str[end]);
    reverseString(str, start + 1, end - 1);
}

// 6. Find GCD of Two Numbers
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// 7. Generate All Subsets of a Set
void generateSubsets(string &str, int index, string &current, vector<string> &result)
{
    if (index == str.size())
    {
        result.push_back(current);
        return;
    }
    generateSubsets(str, index + 1, current, result); // Exclude current character
    current.push_back(str[index]);                    // Include current character
    generateSubsets(str, index + 1, current, result);
    current.pop_back(); // Backtrack
}

// 8. Palindrome Check
bool isPalindrome(string &str, int start, int end)
{
    if (start >= end)
        return true;
    if (str[start] != str[end])
        return false;
    return isPalindrome(str, start + 1, end - 1);
}

// 9. Print All Permutations of a String
void permute(string &str, int left, int right, vector<string> &result)
{
    if (left == right)
    {
        result.push_back(str);
        return;
    }
    for (int i = left; i <= right; ++i)
    {
        swap(str[left], str[i]);
        permute(str, left + 1, right, result);
        swap(str[left], str[i]); // Backtrack
    }
}

// 10. Count Number of Ways to Climb Stairs
int countWays(int n)
{
    if (n <= 1)
        return 1;
    return countWays(n - 1) + countWays(n - 2);
}
