/*
    Name   : Fahad Nazeer
    Roll No: 241372
    Class  : BSAI-F-24-A
*/
#include <iostream> 
using namespace std;

int* sortedArray(int* arr, int size)
{
    int* newArray = new int[size];
    for (int i = 0; i < size; i++)
    {
        newArray[i] = arr[i];
    }

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (newArray[j] < newArray[i])
            {
                swap(newArray[i], newArray[j]);
            }
        }
    }
    return newArray;
}

int main()
{
    int size = 5;
    int* array = new int[size];

    cout << "Enter the elements in array:" << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> array[i];
    }

    cout << "Original array elements:" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }

    int* array2 = sortedArray(array, size);

    cout << endl << "Duplicated + sorted array elements:" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << array2[i] << " ";
    }

    delete[] array;
    delete[] array2;

    return 0;
}
