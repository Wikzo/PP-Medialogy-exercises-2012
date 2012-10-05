#include <iostream>

using namespace std;

int main()
{
    for (int i = 1; i <= 100; i++)
    {
        if (i % 3 == 0 && i % 5 == 0)
            cout << i << ": FizzBuzz" << endl;
        else if (i % 5 == 0)
            cout << i << ": Buzz" << endl;
        else if (i % 3 == 0)
            cout << i << ": Fizz" << endl;
        else
            cout << i << endl;
    }

    cin.get();
    return 0;
}
