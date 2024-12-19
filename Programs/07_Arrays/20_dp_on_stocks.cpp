#include <bits/stdc++.h>
using namespace std;

/*
// Dp and Stocks problem

Q. Best time to buy and sell stock

- array is given with the prices of the stock of each day (n elements)
- you have n days and you have to decide a day to buy the stock and also sell the stock
- maximize the profit
- buying should be done before selling and transaction can be only done once

- so what we have to do is, for every element we will keep a track of the minimal on the left
- because if I sell a stock at x rs then i should buy it at the most minimal possible which will be on the left


- Time Complexity -> O(n)
- Space Complexity -> O(1)

Note: Dynamic Programming - remembering the past (we are remembering the minimum)


*/

int best_time(vector<int> stock_prices, int n)
{
    // lets consider the first element of the array to be minimum
    int mini = stock_prices[0];
    int profit = 0;
    for (int i = 1; i < n; i++)
    {
        int cost = stock_prices[i] - mini;
        profit = max(profit, cost);
        mini = min(mini, stock_prices[i]);
    }

    return profit;
}

int main()
{

    int n;
    cin >> n;

    vector<int> stock_prices(n);

    for (int i = 0; i < n; i++)
    {
        cin >> stock_prices[i];
    }

    int maxProfit = best_time(stock_prices, n);

    cout << "The max profit is " << maxProfit;

    return 0;
}