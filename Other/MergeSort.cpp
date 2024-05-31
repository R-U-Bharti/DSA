#include <iostream>
#include <vector>
using namespace std;

void printArray(vector<int>& arr)
{
    for (int nums : arr)
        cout << nums << " ";
}

void conquer(vector<int>& arr, int si, int mid, int ei)
{
    vector<int> merge(ei - si + 1);

    int idx1 = si;
    int idx2 = mid + 1;
    int x = 0;

    while (idx1 <= mid && idx2 <= ei)
    {
        if (arr[idx1] < arr[idx2])
        {
            merge[x] = arr[idx1];
            idx1++;
        }
        else
        {
            merge[x] = arr[idx2];
            idx2++;
        }
        x++;
    }

    while (idx1 <= mid)
    {
        merge[x] = arr[idx1];
        x++;
        idx1++;
    }

    while (idx2 <= ei)
    {
        merge[x] = arr[idx2];
        x++;
        idx2++;
    }

    for (int i = 0, j = si; i < merge.size(); i++, j++)
        arr[j] = merge[i];
}

void divide(vector<int>& arr, int si, int ei)
{
    if (si >= ei)
        return;

    int mid = (si + ei) / 2;

    divide(arr, si, mid);
    divide(arr, mid + 1, ei);

    conquer(arr, si, mid, ei);
}

int main()
{
    vector<int> arr = {23, 9, 134, 2, 0, 50};

    cout << "Your array: " << endl;
    printArray(arr);

    cout << endl << endl;
    cout << "Merge Sort: " << endl;
    divide(arr, 0, arr.size() - 1);

    printArray(arr);
    cout << endl;

    return 0;
}
