/*
Kth Largest Element

🚀With sorting
sort in descending coz' need to find largest else ascending
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

void printArray(vector<int> arr)
{
    for (int nums : arr)
        cout << nums << " ";
}

int kthLargestElement(vector<int> nums, int k)
{

    // 🚀 With Sorting
    // sort(nums.begin(), nums.end());
    // reverse(nums.begin(), nums.end());

    // return nums[k-1];

    // 🚀Without Sorting
    vector<int> arr = nums;
    unordered_map<int, int> freq;

    // store element freq.
    for (int el : arr)
        freq[el]++;

    // print element freq.
    cout << endl;
    for (auto const i : freq)
        cout << i.first << "-->" << i.second << endl;

    // find greatest number
    int max_number = 0;
    for (int n : arr)
        max_number = max(max_number, n);

    int cap = 0;
    int target = k;
    for (int i = 0; i < arr.size(); i++)
    {
        if (max_number > arr[i] && cap <= arr[i])
        {
            cap = arr[i];
        }
        else
        {
            target -= freq[arr[i]];
            max_number = arr[i];
        }
    }

    if (target == 1 || target == 0)
    {
        return max_number;
    }

    return max_number;
}

int main()
{
    vector<int> arr = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    int k = 2;

    cout << k << "::element of array is: " << kthLargestElement(arr, k);
}