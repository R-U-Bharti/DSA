/*
Repeated and Missing Array
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

void printArray(vector<int> arr)
{

    if (arr.size() == 0)
    {
        cout << "Not Found!!!";
    }

    for (int el : arr)
        cout << el << " ";
}

void repeatedMissingElement(vector<int> array)
{
    printArray(array);
    cout << endl;

    unordered_map<int, int> freq; // initialize unordered map with "<key, value> name"
    vector<int> me, re; // initialize two array to store
    vector<int> arr = array; // argument array

    int size = arr.size(); // initialize size

    for (int nums : arr) // count freq. of each element
    {
        freq[nums]++; // Example freq[12]: 1 , if repeated it will update to freq[12]: 2
    }

    for (int i = 1; i <= size; i++) // iterate array
    {
        if (freq.find(i) == freq.end()) // if i value is not found then it will return freq.end()
        {
            me.push_back(i); // add to missing element array
        }
        if (freq[i] > 1) // if freq. of the element is greater than 1, it means repeated
        {
            re.push_back(i); // add to repeated element array
        }
    }

    // Using algorithm library
    // ========================================
    // for (size_t i = 0; i < size - 1; i++)
    // {
    //     for (size_t j = i + 1; j < size; j++)
    //     {
    //         if (arr[i] == arr[j])
    //         {
    //             re.push_back(arr[j]);
    //         }
    //     }
    // }

    // sort(arr.begin(), arr.end());
    // arr.erase(unique(arr.begin(), arr.end()), arr.end()); // removed duplicate element
    // printArray(arr);

    // int temp = 1;
    // for (int i = 0; i < arr.size();)
    // {
    //     if (temp < arr[i])
    //     {
    //         me.push_back(temp);
    //         temp++;
    //     }
    //     if (temp == arr[i])
    //     {
    //         i++;
    //         temp++;
    //     }
    // }

    cout << endl;
    cout << "Repeated elements are: " << endl;
    printArray(re);
    cout << endl;
    cout << endl;

    cout << "Missing Elements are: " << endl;
    printArray(me);
    cout << endl;
}

int main()
{
    vector<int> arr = {7, 3, 2, 5, 5, 6, 7, 3, 9, 11, 13, 1};
    repeatedMissingElement(arr);

    return 0;
}