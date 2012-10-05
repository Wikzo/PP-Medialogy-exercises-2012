#include <iostream>

using namespace std;

void IsPrime(int testNum);
int inputNumber;
int numberToCheck;
int totalNumberOfPrimes = 0;
bool isPrime = true;

int main()
{
    // PP_E3 - 3
    // Print out prime numbers (can only be divided by 1 and itself)

    // Some prime numbers 2, 3, 5, 7, 11, 13, 17, 19

    cout << "Type a number n to list all prime numbers from 1 to n: ";
    cin >> inputNumber;
    cout << endl;

    // Go from numberToCheck to 1
    for (numberToCheck = inputNumber; numberToCheck > 0; numberToCheck--)
    {
        isPrime = t0rue;

        // Check numberToCheck against currentIndex (1 to numberToCheck)
        for (int currentIndex = 1; currentIndex < numberToCheck +1; currentIndex++)
        {
            if (numberToCheck == 1) // 1 is not a prime
                isPrime = false;
            else if (numberToCheck % currentIndex == 0 // something else than 1 or itself is integer divisor
                     && numberToCheck != currentIndex // divided by itself
                     && currentIndex != 1) // divided by 1
                isPrime = false;
        }
        if (isPrime == false)
            cout << numberToCheck << ": no" << endl;
        else
        {
            cout << numberToCheck << ": yes" << endl;
            totalNumberOfPrimes++;
        }
    }

    cout << "\n---------------\nTotal number of primes [1; " << inputNumber << "]: " << totalNumberOfPrimes << endl;

    return 0;
}

void IsPrime(int testNum)
{
        isPrime = true;
        for (int i = 1; i < testNum +1; i++)
        {
            if (testNum == 1)
                isPrime = false;
            else if (testNum % i == 0 && testNum != i && i != 1)
                isPrime = false;
        }
        cout << testNum << " is: " << isPrime << endl;
}
