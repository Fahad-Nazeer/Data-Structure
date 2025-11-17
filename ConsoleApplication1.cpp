/*
    Name   : Fahad Nazeer
    Roll No: 241372
    Class  : BSAI-F-24-A
*/

#include <iostream>
using namespace std;

int main()
{
    int number;
    long long factorial = 1;

    cout << "Enter a positive integer:" << endl;
    cin >> number;

    if (number < 0)
    {
        cout << "No factorial for negative numbers" << endl;
    }
    else
    {
        for (int i = 1; i <= number; i++)
        {
            factorial *= i;
        }

        cout << "Factorial of " << number << " is: " << factorial << endl;
    }

    return 0;
}
