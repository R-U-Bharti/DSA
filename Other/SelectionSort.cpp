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
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(vector<int> arr)
{
    int size = arr.size();
    int min_idx = 0;

    for (int i = 0; i < size; i++)
    {
        min_idx = i;

        for (int j = 0; j < size; j++)
        {
            if (arr[j] > arr[min_idx])
                min_idx = j;
        }
        swap(&arr[min_idx], &arr[i]);
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
    cout << "Selection Sort: " << endl;
    selectionSort(arr);
}