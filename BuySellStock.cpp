/*
🚀Buy and Sell Stock🚀

Description:
You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day
in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

Example 1:
Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

Example 2:
Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

int getMaxProfit(vector<int> &arr, int idx)
{
    int max_profit = 0;
    int buy_index = 0;
    int sell_index = 0;

    int max_index = idx;
    for (int i = idx + 1; i < arr.size() - 1; i++)
    {
        if (arr[max_index] < arr[i + 1])
        {
            max_index = i + 1;
        }
    }
cout<<endl;
cout << "idx -->" << idx << endl;
cout << "max_index -->" << max_index << endl;

for (int i = idx + 1; i <= max_index; i++)
{
    int temp = INT_MAX;
    if (arr[i] < temp)
    {
        buy_index = i;
        temp = arr[i];
    }
    }

    max_profit = arr[max_index] - arr[buy_index];

    if (max_profit == 0)
    {
        if (max_index == arr.size() - 1)
        {
            return max_profit;
        }
        else
        {
            return getMaxProfit(arr, max_index);
        }
    }

    cout << "max" << max_index << " " << "min index" << buy_index << "===>";
    return max_profit;
}

// int maxProfitDay(vector<int> &arr)
// {
//     int max_profit = 0;
//     int buy_index = 0;
//     int sell_index = 0;

//     int max_profit_index = 0;
//     for (int i = 0; i < arr.size() - 1; i++)
//     {
//         if (arr[max_profit_index] < arr[i + 1])
//         {
//             max_profit_index = i+1;
//         }
//     }

//     for (int i = 0; i < max_profit_index; i++)
//     {
//         if (arr[i] < arr[i + 1])
//         {
//             buy_index = i;
//         }
//     }

//     max_profit = arr[max_profit_index] - arr[buy_index];

//     if(max_profit == 0){
//         if(max_profit_index == arr.size()-1){
//             return max_profit;
//         } else {
//             return getMaxProfit(arr, max_profit_index);
//         }
//     }

//     return max_profit;
// }

int main()
{
    // vector<int> prices = {2, 4, 1};
    // vector<int> prices = {7, 6, 4, 3, 1};
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    // vector<int> prices = {3, 2, 6, 5, 0, 3};

    cout << "Maximum profit: " << getMaxProfit(prices, -1);

    return 0;
}