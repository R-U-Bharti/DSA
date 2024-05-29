/*
SELECTION SORT
=============================

Description:
1. Set the first element as minimum.
2. Compare minimum with the second element. If the second element is smaller than minimum, assign the second element as minimum.
   Compare minimum with the third element. Again, if the third element is smaller, then assign minimum to the third element
   otherwise do nothing. The process goes on until the last element.
   Compare minimum with the remaining elements
3. After each iteration, minimum is placed in the front of the unsorted list.
4. For each iteration, indexing starts from the first unsorted element. Step 1 to 3 are repeated until all the elements
   are placed at their correct positions.

*/

#include <iostream>
#include <vector>
using namespace std;

void printArray(vector<int> arr)
{
    for (int nums : arr)
        cout << nums << " ";
}

// function to swap two elements, argument is pointer
void swap(int *a, int *b)
{
    cout << " | " << *b << "->" << *a << endl;
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(vector<int> arr)
{
    cout << "Sorting Process: " << endl;

    int size = arr.size(); // init size
    int min_idx = 0; // init minimum index to swap the element

    for (int step = 0; step < size - 1; step++) // array iterate step wise
    {
        int min_idx = step; // update minimum index to initial step
        for (int j = step + 1; j < size; j++) // iterate array from step + 1 to compare
        {
            if (arr[j] < arr[min_idx]) // check throughout iteration to find the minimum index to swap
            {
                min_idx = j; // update minimum index
            }
        }
        cout << "Before: ";
        printArray(arr);
        cout << endl;
        cout << step << "->" << min_idx;
        swap(&arr[min_idx], &arr[step]); // Swap the found index to current step
        cout << "After: ";
        printArray(arr);
        cout << endl;
        cout << endl;
    }

    cout << "Final Sorted Array by Selection Sort: ";
    printArray(arr);
}

int main()
{
    vector<int> arr = {23, 9, 134, 2, 0, 50};

    cout << "Your array: ";
    printArray(arr);

    cout << endl;
    cout << endl;
    selectionSort(arr);
}