#include <iostream>

using namespace std;

const int MAX_NUMBER_SCORES = 10;

void FillArray(int a[], int size, int& numbersUsed);
double ComputeAverage(const int a[], int numbersUsed);
void ShowDifference(const int a[], int numbersUsed);


int main()
{
	int score[MAX_NUMBER_SCORES], number_used;

	cout << "This program reads golf scores and shows how much each differs from the average.\n";

	cout << "Enter golf scores:\n";
	FillArray(score, MAX_NUMBER_SCORES, number_used);
	ShowDifference(score, number_used);

	cin.clear();
	cin.sync();
	cin.get();

	return 0;
}

void FillArray(int a[], int size, int& numbersUsed)
{
	cout << "Enter up to " << size << " non-negative whole numbers." << endl;
	cout << "Mark the end of the list using a negative number (e.g. -1)" << endl;

	int next, index = 0;

	cin >> next;

	while ((next >= 0) && (index < size))
	{
		a[index] = next;
		index++;
		cin >> next;
	}

	numbersUsed = index;
}

double ComputeAverage(const int a[], int numbersUsed)
{
	double total = 0;

	for (int index = 0; index < numbersUsed; index++)
		total += a[index];

	if (numbersUsed > 0)
		return (total/numbersUsed);
	else
	{
		cout << "ERROR - number of elements is 0!" << endl;
		return 0;
	}
}

void ShowDifference(const int a[], int numbersUsed)
{
	double average = ComputeAverage(a, numbersUsed);

	cout << "\n\nAverage of the " << numbersUsed << " scores: " << average << endl;

	for (int i = 0; i < numbersUsed; i++)
	{
		cout << a[i] << " differs from the average by "
			<< (a[i] - average) << endl;
	}
}
