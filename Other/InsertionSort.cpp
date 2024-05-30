/*
INSERTION SORT
----------------------

Description:
1. The first element in the array is assumed to be sorted. Take the second element and store it separately in key.
    Compare key with the first element. If the first element is greater than key, then key is placed in front of the first element.

2. Now, the first two elements are sorted.
    Take the third element and compare it with the elements on the left of it. Placed it just behind
    the element smaller than it. If there is no element smaller than it, then place it at the beginning of the array.

3. Similarly, place every unsorted element at its correct position.

*/

#include <iostream>
#include <vector>
using namespace std;

void printArray(vector<int> arr)
{
    for (int nums : arr)
        cout << nums << " ";
}

void insertionSort(vector<int> arr)
{
    int n = arr.size(); // init size
    int leftPos = 0; // left position init for comparing

    for (int step = 1; step < n; step++) // iterate array
    {
        leftPos = step; // update left position to step
        while (leftPos > 0)
        {
            if (arr[leftPos] < arr[leftPos - 1]) // compare left position with that previous one
            {
                // Swap process
                int temp = arr[leftPos];
                arr[leftPos] = arr[leftPos - 1];
                arr[leftPos - 1] = temp;
            }
            
            leftPos--; // decreament left position
        }
    }

    printArray(arr);
}

int main()
{
    vector<int> arr = {23, 9, 134, 2, 0, 50};

    cout << "Your array: " << endl;
    printArray(arr);

    cout << endl;
    cout << endl;
    cout << "Insertion Sort: " << endl;
    insertionSort(arr);
}