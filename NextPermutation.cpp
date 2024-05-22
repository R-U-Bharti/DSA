/*
Next Permutation

Description:
A permutation of an array of integers is an arrangement of its members into a sequence or linear order.

# For example, for arr = [1,2,3], the following are all the permutations of arr:
[1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].

The next permutation of an array of integers is the next lexicographically greater permutation of
its integer. More formally, if all the permutations of the array are sorted in one container according
to their lexicographical order, then the next permutation of that array is the permutation that follows
it in the sorted container. If such arrangement is not possible, the array must be rearranged as the lowest
possible order (i.e., sorted in ascending order).

# For example, the next permutation of arr = [1,2,3] is [1,3,2].
# Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
# While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical larger rearrangement.

Example 1:
Input: nums = [1,2,3]
Output: [1,3,2]

Example 2:
Input: nums = [3,2,1]
Output: [1,2,3]

Example 3:
Input: nums = [1,1,5]
Output: [1,5,1]
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

void printArray(vector<int> &arr)
{
    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
}

void nextPermutation(vector<int> &arr)
{
    if (arr.size() == 1)
    {
        return;
    }

    int idx = INT_MIN;
    for (int i = arr.size() - 2; i >= 0; i--)
    {
        if (arr[i] < arr[i + 1])
        {
            idx = i;
            break;
        }
    }

    if (idx < 0)
    {
        reverse(arr.begin(), arr.end());
    }
    else
    {
        int idx2 = 0;
        for (int i = arr.size() - 1; i >= 0; i--)
        {
            if (arr[i] > arr[idx])
            {
                idx2 = i;
                break;
            }
        }
        swap(arr[idx], arr[idx2]);
        reverse(arr.begin() + idx + 1, arr.end());
    }

}

int main()
{

    vector<int> arr = {1, 2, 3};
    // vector<int> arr = {3, 2, 1};

    cout << "Your array: ";
    printArray(arr);

    cout << "Next Permutation: ";
    nextPermutation(arr);
    printArray(arr);

    return 0;
}