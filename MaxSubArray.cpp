/*
Maximum SubArray
Time Complexity: O(n)

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.
Example 2:

Input: nums = [1]
Output: 1
Explanation: The subarray [1] has the largest sum 1.
Example 3:

Input: nums = [5,4,-1,7,8]
Output: 23
Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.

"vector" is used for dynamic array and "algorithm" used for "max(value1, value2)" to get maximum value of these two arguments.
"size_t" used for ignore negative integer.
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int maxSubArray(vector<int>arr, int size)
{
    int max_current = arr[0];
    int max_global = arr[0];

    for(size_t i=0; i<size-1; i++){
        max_current = max(arr[i], max_current + arr[i]);
        max_global = max(max_global, max_current);
    }
    cout<<endl;
    return max_global;
}

int main(){

    vector<int>arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int size = arr.size();

    cout<<"Max sub-array: "<<maxSubArray(arr, size);

    return 0;
}