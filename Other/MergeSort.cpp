/*
MERGE SORT
*/

#include <iostream>
#include <vector>
using namespace std;

void printArray(vector<int> &arr)
{
    for (int nums : arr)
        cout << nums << " ";
}

void conquer(vector<int> &arr, int si, int mid, int ei)
{
    vector<int> merge(ei - si + 1); // init new array to store temperory of maximum size

    int idx1 = si;      // first index of left part
    int idx2 = mid + 1; // second index of right part
    int x = 0;          // initial point

    while (idx1 <= mid && idx2 <= ei) // iterate parallely both parts
    {
        if (arr[idx1] < arr[idx2]) // comparing both index
        {
            merge[x] = arr[idx1]; // store in new array
            idx1++;
        }
        else
        {
            merge[x] = arr[idx2];
            idx2++;
        }
        x++; // increase the index point of new array
    }

    // while only one condition is true it means some elements are left to store in new array
    while (idx1 <= mid) // for left part
    {
        merge[x] = arr[idx1];
        x++;
        idx1++;
    }

    while (idx2 <= ei) // for right part
    {
        merge[x] = arr[idx2];
        x++;
        idx2++;
    }

    // update the original array with stored new array
    for (int i = 0, j = si; i < merge.size(); i++, j++)
        arr[j] = merge[i];
}

void mergeSort(vector<int> &arr, int si, int ei)
{
    // check si and ei is valid or not
    if (si >= ei)
        return;

    int mid = (si + ei) / 2; // take out the mid index

    mergeSort(arr, si, mid);     // recursion with left part to divide
    mergeSort(arr, mid + 1, ei); // recursion with right part to divide

    conquer(arr, si, mid, ei); // calling function to conquer the parts one by one while divided
}

int main()
{
    vector<int> arr = {23, 9, 134, 2, 0, 50};

    cout << "Your array: " << endl;
    printArray(arr);

    cout << "\n\nMerge Sort: \n";
    mergeSort(arr, 0, arr.size() - 1); // call the funtion with start index (si) and end index (ei)

    printArray(arr);
    cout << endl;

    return 0;
}