#include <iostream>

using namespace std;

void FillArray(int a[], int size, int& numbersUsed);
void BubbleSort(int a[], int size, int& numbersUsed);

int main()
{
	int arraySize = 0;
	int numbersUsed = 0;
	cout << "How many numbers do you want in the array: ";
	cin >> arraySize;

	while (arraySize < 0)
	{
		cout << "Please specify an array size greater than 0!" << endl;
		cin >> arraySize;
	}
	
	int* myArray = new int[arraySize];
	FillArray(myArray, arraySize, numbersUsed);
	BubbleSort(myArray, arraySize, numbersUsed);

	cin.clear();
	cin.sync();
	cin.ignore();
	cin.get();

	return 0;
}

void FillArray(int a[], int size, int& numbersUsed)
{
	for (int i = 0; i < size; i++) // maybe -1?
		a[i] = 0;

	int next = 0;
	int index = 0;

	cout << "Give me some numbers. Use any negative number (e.g. -1) to stop\n\n";

	do
	{
		cout << "Give me a number to put in element " << index << ": ";
		cin >> next;
		a[index] = next;
		index++;
	} while ((next > 0) && (index < size));

	numbersUsed = index;
}

void BubbleSort(int a[], int size, int& numbersUsed)
{

	cout << "Before the bubblesort:" << endl;
	for (int i = 0; i < size; i++)
		cout << a[i] << endl;

	// Bubble list
	int index = 0;
	bool swapped = true;

	while (swapped)
	{
		swapped = false;
		for (int i = 1; i < size; i++)
		{
			if (a[i-1] > a[i])
			{
				// Sort numbers
				int temp = a[i-1];
				a[i-1] = a[i];
                a[i] = temp;

                swapped = true;
			}
		}
	}

		cout << "\n\nAfter the bubblesort:" << endl;
		for (int i = 0; i < size; i++)
			cout << a[i] << endl;
}