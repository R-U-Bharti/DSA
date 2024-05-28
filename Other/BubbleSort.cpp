/*
BUBBLE SORT
======================================

Description:
Suppose we are trying to sort the elements in ascending order.

1. First Iteration (Compare and Swap)
-------------------------------------------
i. Starting from the first index, compare the first and the second elements.
ii. If the first element is greater than the second element, they are swapped.
iii. Now, compare the second and the third elements. Swap them if they are not in order.
iv. The above process goes on until the last element.

2. Remaining Iteration
--------------------------------------------
# The same process goes on for the remaining iterations.
# After each iteration, the largest element among the unsorted elements is placed at the end.
# In each iteration, the comparison takes place up to the last unsorted element.
# The array is sorted when all the unsorted elements are placed at their correct positions.

Description for "swapped" variable:
--------------------------------------------
Added extra variable "swapped", the value of swapped is set true if there occurs swapping of elements. Otherwise, it is set false.
After an iteration, if there is no swapping, the value of swapped will be false. This means elements are already sorted and 
there is no need to perform further iterations.
This will reduce the execution time and helps to optimize the bubble sort.

*/

#include <iostream>
#include <vector>
using namespace std;

void printArray(vector<int> arr)
{
    for (int nums : arr)
        cout << nums << " ";
}

void bubbleSort(vector<int> arr)
{
    int size = arr.size(); // init size
    int temp = 0;          // init temp
    int swapped = 0;       // init swap

    for (int i = 0; i < size; i++) // iterate array
    {
        swapped = 0;
        for (int j = 0; j < size - i - 1; j++) // iterate element to size-i coz' it becomes sorted from end
        {
            if (arr[j] > arr[j + 1]) // compare ">" for ascending to next element
            {
                // swap the element
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1; // update that it swapped
            }
        }

        if (swapped == 0) // if not swapped means that sorted then break the loop
            break;
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
    cout << "Bubble Sort: " << endl;
    bubbleSort(arr);
}