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