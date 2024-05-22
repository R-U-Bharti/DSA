/*
Maximum & Minimum Element in an Array
Time Complexity: O(n)
Auxiliary Space: O(1)
*/

#include <iostream>
#include <limits.h>
using namespace std;

void printArray(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

void getReversedArray(int A[], int start, int end)
{
    int len = end+1;

    while(start < end){
        int temp = A[start];
        A[start] = A[end];
        A[end] = temp;
        start++;
        end--;
    }

    printArray(A, len);

}

int main()
{

    int A[] = {3, 5, 4, 6, 20};
    int n = sizeof(A) / sizeof(A[0]);

    cout << "Given Array: ";
    printArray(A, n);

    cout << "Reversed Array: ";
    getReversedArray(A, 0 , n-1);

    return 0;
}