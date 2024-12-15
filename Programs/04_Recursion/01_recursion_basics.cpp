// Recursion
// - recursion is calling a function within itself until a specific condition is met

// when a function call itself, it is waiting in the stack memory (functions keep on getting pushed)
// so when there is infinite recursion then it is called as stack overflow & we get a segmentation fault

// Condition that we use to stop recursive calling of the function is called as - Base condition
// there can be a single or even multiple base conditions
// stack space - where incomplete functions are stored

// Example Code
#include <bits/stdc++.h>
using namespace std;

int cnt = 0;

void call()
{

    if (cnt == 3)
        return;

    cout << cnt << endl;
    cnt++;
    call();
}

int main()
{
    call();

    return 0;
}

// Recursion tree - explaining the recursive function on paper
