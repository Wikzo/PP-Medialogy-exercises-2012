#include <iostream>
using namespace std;

int discs = 20;
double stepsUsed = 0;

void SolveTower(double count, char source, char destination, char spare)
{
	if (count == 1)
	{
		stepsUsed++;
		//cout << "Move disc from pole " << source << " to pole " << destination << endl;
	}

	else
	{
		SolveTower(count-1, source, spare, destination);
		SolveTower(1, source, destination, spare);
		SolveTower(count-1, spare, destination, source);
	}

}

void CountdownRecursion(int count)
{
	cout << count << "..." << endl;
	
	if (count > 0)
		CountdownRecursion(count-1);
}

void BackwardsStringRecursion(char c[], int size)
{
	if (size-1 >= 0)
	{
		cout << c[size-1];
		BackwardsStringRecursion(c, size-1);
	}
}

int main()
{
	//CountdownRecursion(10);
	//cout << "\n------------------\n";

	//char c[] = { 'H', 'E', 'J', 'S', 'A' };
	//BackwardsStringRecursion(c, 5);
	//cout << "\n------------------\n";

	SolveTower(discs, 'A', 'B', 'C');
	cout << "The Tower of Hanoi with " << discs << " discs has been solved using " << stepsUsed << " steps.";
	cin.ignore();
	return 0;
}