/*
Search in Rotated Sorted Array
Time Complexity: O(logn)

Description:
There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) 
such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). 
For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target 
if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.

Example 1:
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4

Example 2:
Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1

Example 3:
Input: nums = [1], target = 0
Output: -1
*/

#include <iostream>
#include <vector>
using namespace std;

void printArray(vector<int> A)
{
    for (int i = 0; i < A.size(); i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

int searchInRotatedArray(vector<int> arr, int target, int left, int right)
{
    if(left > right){
        return -1;
    }

    int mid = (left+right)/2;

    if(arr[mid] == target){
        return mid;
    }

    if(arr[left]<=arr[mid]){
        if(target <= arr[mid] && target >= arr[left]){
            return searchInRotatedArray(arr, target, left, mid-1);
        }
        return searchInRotatedArray(arr, target, mid+1, right);
    }

    if(target >= arr[mid] && target <= arr[right]){
        return searchInRotatedArray(arr, target, mid+1, right);
    }

    return searchInRotatedArray(arr, target, left, mid-1);
}

int main()
{
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2};
    int n = arr.size();
    int target = 0;

    cout << "Your array: ";
    printArray(arr);

    cout << "Index of your element is: " << searchInRotatedArray(arr, target, 0, n-1);

    return 0;
}