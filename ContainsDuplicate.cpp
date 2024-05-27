/*
Contains Duplicate
Time Complexity: O(n^2)

Example 1:

Input: nums = [1,2,3,1]
Output: true
Example 2:

Input: nums = [1,2,3,4]
Output: false
Example 3:

Input: nums = [1,1,1,3,3,4,3,2,4,2]
Output: true

"vector" is used for dynamic array and "algorithm" used for "max(value1, value2)" to get maximum value of these two arguments.
"size_t" used for ignore negative integer.
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Brute force algorithm
bool checkDuplicate (vector<int>arr){
    bool flag = false;
    int size = arr.size();

    for(int i=0; i<size; i++){ // iterate array
        for(int j=i+1; j<size; j++){ // iterate again to check element to whole array
            if(arr[i] == arr[j]){ // check if it's equal
                flag = true; // set flag true
            }
        }
    }

    return flag;
}

int main()
{
    vector<int> arr = {1, 2, 3, 1};
    vector<int> arr2 = {1, 2, 3, 4};

    cout << "Array 1 contains duplicate: " << (checkDuplicate(arr) ? "true" : "false") << endl;
    cout << "Array 2 contains duplicate: " << (checkDuplicate(arr2) ? "true" : "false");

    return 0;
}
