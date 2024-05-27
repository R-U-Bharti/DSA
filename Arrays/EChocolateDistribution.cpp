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

APPROACH
------------------
# Initially sort the given array. And declare a variable to store the minimum difference, and initialize it to INT_MAX. 
Let the variable be min_diff.
# Find the subarray of size m such that the difference between the last (maximum in case of sorted) and 
first (minimum in case of sorted) elements of the subarray is minimum.
# We will run a loop from 0 to (n-m), where n is the size of the given array and m is the size of the subarray.
# We will calculate the maximum difference with the subarray and store it in diff = arr[highest index] – arr[lowest index]
# Whenever we get a diff less than the min_diff, we will update the min_diff with diff.

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

int minDiff(vector<int> arr, int m)
{

    int size = arr.size(); // intialize size

    if (m == 0 || size == 0) // if member = 0 or size of array = 0; return 0;
    {
        return 0;
    }

    if (m > size)
    {
        return -1;
    }

    sort(arr.begin(), arr.end()); // sorted the array

    int final_min = INT_MAX; // initialize fina min;
    int curr_min = 0;        // initialize current min;

    for (int i = 0; i < size - m - 1; i++) // iterate array
    {
        curr_min = arr[i + m - 1] - arr[i]; // set current min
        if (curr_min < final_min)           // checks the current min is less than final min
        {
            final_min = curr_min; // set final min
        }
    }

    return final_min;
}

int main()
{

    vector<int> arr = {7, 3, 2, 4, 9, 12, 56};
    int m = 3; // suppose members are 3

    cout << "Minimum Difference: " << minDiff(arr, m);

    return 0;
}