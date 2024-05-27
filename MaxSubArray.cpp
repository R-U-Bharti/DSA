/*
Maximum SubArray (or Contiguous array)
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

----------------------
| KADANE'S ALGORITHM |
----------------------
The idea of Kadane’s algorithm is to maintain a variable max_ending_here that stores the maximum sum contiguous subarray
 ending at current index and a variable max_so_far stores the maximum sum of contiguous subarray found so far,
 Everytime there is a positive-sum value in max_ending_here compare it with max_so_far and update max_so_far
 if it is greater than max_so_far.

Pseudocode of Kadane’s algorithm:
-----------------------------------
Initialize:
    max_so_far = INT_MIN
    max_ending_here = 0

Loop for each element of the array

  (a) max_ending_here = max_ending_here + a[i]
  (b) if(max_so_far < max_ending_here)
            max_so_far = max_ending_here
  (c) if(max_ending_here < 0)
            max_ending_here = 0
return max_so_far
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
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

int maxSubArraySum(vector<int>arr, int size){
    int max_sum = INT_MIN; // initialize max_sum
    int curr_sum = 0; // current sum of sub-array

    for(int i =0; i< size; i++){ // iterate array
        curr_sum = max(curr_sum, 0); // set curr_sum to zero if negative
        curr_sum += arr[i]; // add next element to curr_sum
        max_sum = max(max_sum, curr_sum); // set max_sum
    }

    return max_sum;
}

int main(){

    // vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    vector<int> arr = {-2, -3, 4, -1, -2, 1, 5, -3};
    int size = arr.size();

    // cout << "Max sub-array: " << maxSubArray(arr, size);
    cout << "Max sub-array or contiguous array: " << maxSubArraySum(arr, size);

    return 0;
}