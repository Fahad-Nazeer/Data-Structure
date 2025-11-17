/*
    Name   : Fahad Nazeer
    Roll No: 241372
    Class  : BSAI-F-24-A
*/
#include <iostream>
using namespace std;

int* duplicateArray(int* arr, int size)
{
    int* newArray = new int[size];
    for (int i = 0; i < size; i++)
    {
        newArray[i] = arr[i];
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


    int* array2 = duplicateArray(array, size);

    cout << endl << "Duplicated array elements:" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << array2[i] << " ";
    }

    delete[] array;
    delete[] array2;

    return 0;
}
