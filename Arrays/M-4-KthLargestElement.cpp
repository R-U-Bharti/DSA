/*
Kth Largest Element

🚀With sorting
sort in descending coz' need to find largest else ascending
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include<limits.h>
using namespace std;

void printArray(vector<int> arr)
{
    for (int nums : arr)
        cout << nums << " ";
}

// APPROACH 1
int getMaxNumber(vector<int> &arr, vector<int> &max_array)
{
    int max_number = INT_MIN;

    for (int i = 0; i < arr.size(); i++)
    {

        auto check = find(max_array.begin(), max_array.end(), arr[i]);

        if (check == max_array.end())
        {
            max_number = max(max_number, arr[i]);
        }
    }

    return max_number;
}

int kthLargestElement(vector<int> arr, int k)
{

    // 🚀 With Sorting
    // sort(nums.begin(), nums.end());
    // reverse(nums.begin(), nums.end());

    // return nums[k-1];

    // 🚀Without Sorting
    vector<int> max_array;
    int max_number = 0;
    unordered_map<int, int> freq;
    int idx = k;
    int res = arr[0];

    // store element freq.
    for (int el : arr)
        freq[el]++;

    // print element freq.
    cout << endl;
    for (auto const i : freq)
        cout << i.first << "-->" << i.second << endl;

    for (int i = 0; i < arr.size(); i++)
    {
        cout << "\nmax array: ";
        printArray(max_array);

        cout << "\nIterate element:" << arr[i] << endl;

        cout << "Checking max_number \n";
        max_number = getMaxNumber(arr, max_array);

        max_array.push_back(max_number);
        cout << "Pushed max number: " << max_number << " and freq. is: " << freq[max_number] << endl;

        cout << "Current idx: " << idx << " and now changed to " << idx - freq[max_number] << endl;
        idx = idx - freq[max_number];

        if (idx <= 0)
        {
            res = max_number;
            break;
        }
    }

    return res;
}

// APPROACH 2
// int kthLargestElement(vector<int>arr, int k){
//     return -1;
// }

int main()
{
    // vector<int> arr = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    // int k = 3;

    // vector<int> arr = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    // int k = 9;

    vector<int> arr = {-1, 2, 0};
    int k = 3;

    cout << k << "::element of array is: ";
    cout << kthLargestElement(arr, k);
}