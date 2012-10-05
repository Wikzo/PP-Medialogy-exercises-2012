#include <iostream>
#include <cstdlib>
using namespace std;

void write_vertical(int n)
{
	// Base/stopping case
	if (n < 10)
		cout << n << endl;
	else
	{
		write_vertical(n / 10); // the number n where the last digit is removed
		write_vertical(n % 10); // the last digit in n
	}
}

// This recursive way is more expensive in terms of memory use
int power(int x, int n)
{
	if (n < 0)
	{
		cout << "ERROR";
		exit(1);
	}

	if (n > 0)
		return (power(x, n - 1) * x);
	else // n == 0
		return 1;
}

// This iterate way is more cheap in terms of memory use
int power_simple(int x, int n)
{
	for (int i = 0; i < n; i++)
	{
		x *= x;
	}

	return x;
}
int main()
{
	write_vertical(123456789);


	cout << "\n\n------------------\n";
	// Recursive way
	cout << "\nRecursive way of power:\n";
	for (int i = 0; i < 10; i++)
	{
		cout << "3 to the power of " << i << " is " << power(3, i) << endl;
	}

	// My simple way
	cout << "\nMy simple way of power:\n";
	for (int i = 0; i < 10; i++)
	{
		cout << "3 to the power of " << i << " is " << power(3, i) << endl;
	}

	cin.ignore();
	return 0;
}