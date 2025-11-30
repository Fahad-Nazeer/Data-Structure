/*
    Name   : Fahad Nazeer
    Roll No: 241372
    Class  : BSAI-F-24-A
*/
#include <iostream>
#include <vector>
using namespace std;

int bruteGCD(int a, int b)
{
    int gcdValue = 1;
    int small;

    if (a < b)
    {
        small = a;
    }
    else
    {
        small = b;
    }

    for (int x = 1; x <= small; x++)
    {
        if (a % x == 0 && b % x == 0)
        {
            gcdValue = x;
        }
    }

    return gcdValue;
}

int fastGCD(int a, int b)
{
    while (b != 0)
    {
        int remainder = a % b;
        a = b;
        b = remainder;
    }

    return a;
}

int main()
{
    while (true)
    {
        int num1 = rand() % 100 + 1;
        int num2 = rand() % 100 + 1;

        cout << "Numbers: " << num1 << " and " << num2 << endl;

        int slowResult = bruteGCD(num1, num2);
        int quickResult = fastGCD(num1, num2);

        cout << "Brute GCD: " << slowResult << endl;
        cout << "Fast GCD : " << quickResult << endl;

        if (slowResult != quickResult)
        {
            cout << "Mismatch detected!" << endl;
            break;
        }
        else
        {
            cout << "Correct" << endl;
        }

        cout << endl;
    }

    return 0;
}
