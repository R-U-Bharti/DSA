/*
Chocolate Distribution
Time Complexity: O(nlogn)

Description:
Given an array of N integers where each value represents the number of chocolates in a packet. 
Each packet can have a variable number of chocolates. 
There are m students, the task is to distribute chocolate packets such that:
# Each student gets one packet.
# The difference between the number of chocolates in the packet with maximum chocolates and 
    the packet with minimum chocolates given to the students is minimum.

Example:
Input : arr[] = {7, 3, 2, 4, 9, 12, 56} , m = 3
Output: Minimum Difference is 2
Explanation:
We have seven packets of chocolates and we need to pick three packets for 3 students
If we pick 2, 3 and 4, we get the minimum difference between maximum and minimum packet sizes.

Input : arr[] = {3, 4, 1, 9, 56, 7, 9, 12} , m = 5
Output: Minimum Difference is 6

https://www.geeksforgeeks.org/chocolate-distribution-problem/
*/

#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
using namespace std;

void printArray(vector<int> A)
{
    for (int i = 0; i < A.size(); i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

int getMinDiff(vector<int> arr, int m)
{
    int size = arr.size();

    if (m == 0 || size == 0)
    {
        return 0;
    }

    if (m > size)
    {
        return -1;
    }

    int min_diff = INT_MAX;

    sort(arr.begin(), arr.end());
    cout << "Sorted Array: " << endl;
    printArray(arr);

    for (int i = 0; i + m - 1 < size; i++)
    {
        int temp = arr[i + m - 1] - arr[i];
        if (temp < min_diff)
        {
            min_diff = temp;
        }
    }

    return min_diff;
}

int main()
{

    vector<int> arr = {7, 3, 2, 4, 9, 12, 56};
    int m = 3;

    cout << "Minimum Difference: " << getMinDiff(arr, m);

    return 0;
}