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
    if (arr.size() <= 1) // check array size, must be greater that 1
    {
        return;
    }

    int idx = INT_MIN; // initali first index to get the minimum value
    for (int i = arr.size() - 2; i >= 0; i--) // iterate array from ignore last one element to inital element
    {
        if (arr[i] < arr[i + 1]) // check if previous element is less than next element
        {
            idx = i; // store first index
            break;
        }
    }

    if (idx < 0) // if not found first index
    {
        reverse(arr.begin(), arr.end()); // reverse the array because it is the last permutation
    }
    else
    {
        int idx2 = 0; // Otherwise initialse second index to swap
        for (int i = arr.size() - 1; i >= 0; i--) // iterate array to end because it can swap to end of the element too
        {
            if (arr[i] > arr[idx]) // check the element is just greater than the found element
            {
                idx2 = i; // store the second index
                break;
            }
        }
        swap(arr[idx], arr[idx2]); // swap the elements
        reverse(arr.begin() + idx + 1, arr.end()); // reverse the array from the swapped element, so that it becomes the minumum next permutation
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