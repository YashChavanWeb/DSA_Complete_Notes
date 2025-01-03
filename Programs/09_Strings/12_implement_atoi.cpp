#include <bits/stdc++.h>
using namespace std;

/*

// Implement the Atoi Function

- implement the atoi function that is already there in cpp
- atoi function converts the integer convertable string to the integer
- Eg: "123" - 123 , "12a" - -1 , "-121" - -121






1. Approach
- so first we take a flag variable to consider it the number is -ve or +ve
- iterate over the entire string
- and then we will have the each string character between 48 and 57 which is the ASCII value for '0' and '9'
- and for going to the next number we will do ans*10 and then add that string character to the ans

- Time complexity -> O(n)
- Space Complexity -> O(1)


*/

int implement_atoi(string s)
{

  // declare ans variable and i for negative sign
  int ans = 0;
  int flag = 0;
  int i = 0;

  // check for negative sign
  if (s[0] == '-')
  {
    flag = 1;

    // to start from the next index
    i = 1;
  }

  // loop
  for (; i < s.length(); i++)
  {

    // check if it is in range of 0 to 9 -> 0 - 48 and 9 - 57
    if (s[i] >= 48 && s[i] <= 57)
    {
      ans = ans * 10 + (s[i] - 48);
    }
    else
    {
      // not in range
      return -1;
    }
  }

  // if negative number then flag must be 1
  if (flag)
  {
    return -ans;
  }

  return ans;
}

int main()
{
  string s;
  cin >> s;

  cout << "The number is : " << implement_atoi(s);
}
