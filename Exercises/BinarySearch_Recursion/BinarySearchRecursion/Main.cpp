#include <iostream>
using namespace std;

const int ARRAY_SIZE = 10000;

void search(const int a[], int first, int last,
			int key, bool& found, int& location);
// Precondition: a[first] through a[last] are sorted in increasing order
// Postcondition: if key is not one of the values a[first] through a[last],
// then found == false; otherwise a[location] == key and found == true

void search_simple(const int a[], int size, int key, bool& found, int& location);

int main()
{
	int a[ARRAY_SIZE];
	const int final_index = ARRAY_SIZE-1;

	// Fill/sort the array
	for (int i = 0; i < ARRAY_SIZE; i++)
		a[i] = i*2;

	int key, location;
	bool found = false;
	cout << "Enter a number to be located: ";
	cin >> key;
	
	// Using smart search
	cout << "First we use the smart search...\n";
	search(a, 0, final_index, key, found, location);

	if (found == true)
		cout << key << " is in index location " << location << endl;
	else
		cout << key << " is not in the array" << endl;

	// Using primitive search
	cout << "\nAnd here comes the simple search...\n";
	cout << "Enter a number to be located: ";
	cin >> key;
	found = false;
	search_simple(a, ARRAY_SIZE, key, found, location);
	if (found == true)
		cout << key << " is in index location " << location << endl;
	else
		cout << key << " is not in the array" << endl;

	cin.ignore();
	cin.clear();
	cin.sync();
	int temp;
	cin >> temp;
	return 0;
}

void search(const int a[], int first, int last, int key, bool& found, int& location)
{
	int mid;
	if (first > last) // stopping case
		found = false;
	else
	{
		mid = (first + last) / 2;

		if (key == a[mid]) // stopping case
		{
			found = true;
			location = mid;
		}
		else if (key < a[mid])
			search(a, first, mid-1, key, found, location);
		else if (key > a[mid])
			search(a, mid+1, last, key, found, location);
	}
}

void search_simple(const int a[], int size, int key, bool& found, int& location)
{
	found = false;
	for (int i = 0; i < size; i++)
		{
			if (a[i] == key)
			{
				found = true;
				location = i;
			}
		}
}