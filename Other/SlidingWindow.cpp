#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
using namespace std;

void slidingWindow(vector<int> arr, int key)
{
    int n = arr.size();
    int curr_sum = 0;
    int glob_sum = 0;
    int step = 0;

    while (key <= n)
    {
        curr_sum = 0;

        for (int i = step; i < key; i++)
            curr_sum += arr[i];

        step++;
        key++;

        glob_sum = max(curr_sum, glob_sum);
    }

    cout << "Sliding Window sum with key of " << key << " is: " << glob_sum;
}

int main()
{
    // vector<int> arr = {1, 1, 1, 1, 2, 2, 2, 2, 3, 4, 5};
    vector<int> arr = {1, 9, -1, -2, 7, 3, -1, 2};
    int key = 4;
    slidingWindow(arr, key);
}