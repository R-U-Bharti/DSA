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