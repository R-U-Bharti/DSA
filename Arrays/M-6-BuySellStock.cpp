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

int getMaxProfit(vector<int> arr)
{
    if (arr.size() <= 1)
    {
        return 0;
    }

    int max_profit = 0;
    int buy = arr[0];

    // Brute Force approach
    // for (int i = 0; i <= arr.size() - 1; i++) // iterate array to select element
    // {
    //     for (int j = i + 1; j < arr.size(); j++) // iterate again to loop over the array
    //     {
    //         int temp = arr[j] - arr[i]; // store temperory difference
    //         if (max_profit < temp) // check temp is max or not
    //         {
    //             max_profit = temp; // update max_profit
    //         }
    //     }
    // }

    // conditionally return max_profit
    // if (max_profit <= 0)
    // {
    //     return 0;
    // }
    // else
    // {
    //     return max_profit;
    // }

// Kandane's Algo
    for (int i = 1; i < arr.size(); i++) // iterate array
    {
        max_profit = max(max_profit, arr[i] - buy); // fetch the maximum element
        buy = min(arr[i], buy); // update the buy
    }

    return max_profit;
}

int main()
{
    vector<int> prices0 = {1, 2};
    vector<int> prices1 = {2, 4, 1};
    vector<int> prices2 = {7, 6, 4, 3, 1};
    vector<int> prices3 = {7, 1, 5, 3, 6, 4};
    vector<int> prices4 = {7, 1, 5, 3, 0, 2};
    vector<int> prices5 = {3, 2, 6, 5, 0, 3};

    cout << "Maximum profit: " << getMaxProfit(prices0) << endl;
    cout << "Maximum profit: " << getMaxProfit(prices1) << endl;
    cout << "Maximum profit: " << getMaxProfit(prices2) << endl;
    cout << "Maximum profit: " << getMaxProfit(prices3) << endl;
    cout << "Maximum profit: " << getMaxProfit(prices4) << endl;
    cout << "Maximum profit: " << getMaxProfit(prices5) << endl;

    return 0;
}