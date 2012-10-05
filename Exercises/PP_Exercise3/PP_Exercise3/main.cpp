#include <iostream>

using namespace std;

int main()
{

    // PP_Exercise 3 - 2
    // Print even integers between 2 inputs..

    int numA, numB;

    cout << "Give me two numbers, and I'll show you the even numbers in-between\n\n";
    cout << "Input number 1: ";
    cin >> numA;
    cout << "\nInput number 2: ";
    cin >> numB;

    // NumB should be the biggest number
    if (numB < numA)
    {
       int temp = numB;
       numB = numA;
       numA = temp;
    }

    for (int i = numB; i > numA; i--)
    {
        if (i % 2 == 0)
            cout << i << endl;
    }
    return 0;
}
