/*
Kth Largest Element

🚀With sorting
sort in descending coz' need to find largest else ascending
*/

#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
using namespace std;

void printArray(vector<int>arr){
    for(int nums: arr)
        cout<<nums<<" ";
}

int kthLargestElement(vector<int>nums, int k){

    // 🚀 With Sorting
    // sort(nums.begin(), nums.end());
    // reverse(nums.begin(), nums.end());

    // return nums[k-1];

    // 🚀Without Sorting
    int array = nums;


    return array[k-1];
}

int main(){
    vector<int> arr = { 3,2,3,1,2,4,5,5,6 };
    int k = 2;

    cout<<k<<"th element of array is: "<<kthLargestElement(arr, key);
}