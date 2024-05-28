#include <iostream>
#include <vector>
using namespace std;

void printArray(vector<int> arr)
{
    for (int nums : arr)
        cout << nums << " ";
}

void swap (int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(vector<int> arr)
{
    int size = arr.size();
    int temp = 0;
    int swapped = 0;

    for (int i = 0; i < size; i++)
    {
        swapped = 0;
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j+1]);
                swapped = 1;
            }
        }

        if (swapped == 0)
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
    cout << "Selection Sort: " << endl;
    selectionSort(arr);
}