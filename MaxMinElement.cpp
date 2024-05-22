/*
Maximum & Minimum Element in an Array
Time Complexity: O(n)
Auxiliary Space: O(1)
*/

#include <iostream>
#include <limits.h>
using namespace std;

int getMin(int A[], int n)
{
    int mini = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        if (A[i] < mini)
        {
            mini = A[i];
        }
    }

    return mini;
}

int getMax(int A[], int n)
{
    int max = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        if (A[i] > max)
        {
            max = A[i];
        }
    }

    return max;
}

int printArray(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
    return 0;
}

int main()
{

    int A[] = {3, 5, 4, 6, 20};
    int n = sizeof(A) / sizeof(A[0]);

    cout << "Given Array: ";
    printArray(A, n);

    cout << "Minimum Element: " << getMin(A, n) << endl;
    cout << "Maximum Element: " << getMax(A, n) << endl;

    return 0;
}