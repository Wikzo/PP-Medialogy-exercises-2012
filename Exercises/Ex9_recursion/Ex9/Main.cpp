#include <string>
#include <iostream>

using namespace std;

// Global fields
int myChoice = 1;

// Others
double Power(int number, int exponent);

// Exercise functions
void Ex1();
void Ex2();
void Ex3();
void Ex4();
void ChooseExercise(int choice);
void TestDebug();
string ExerciseDescriptions();

// sadasd

int main()
{
	
	do
	{
		cout << ExerciseDescriptions() << endl << endl;
		cout << "Type exercise number (0 to exit): ";
		cin >> myChoice;
		ChooseExercise(myChoice);
		cout << "\n---------------------------------------------\n";
	} while (myChoice != 0);

	cin.get();
	cin.sync();
	cin.ignore();
	return 0;
}

void ChooseExercise(int choice)
{
	system("cls");
	cout << "Exercise " << choice << endl;
	switch (choice)
	{
		case 0:
			myChoice = 0;
			cout << "Bye...";
			break;
		case 1:
			Ex1();
			break;

		case 2:
			Ex2();
			break;

		case 3:
			Ex3();
			break;


		case 4:
			Ex4();
			break;

		case -1:
			TestDebug();
			break;

		default:
			cout << "ERROR - Exercise not found!";
			break;
	}
}

string ExerciseDescriptions()
{
	string description;
	description.append("1 - Implement a recursive and non-recursive version of the factorial function.\n\n");
	description.append("2 - Create a recursive solution to the problem in lec5 ex3 about bills and coins.\n\n");
	description.append("3 - Design and implement a binary tree where all operations on the tree are defined recursiveley, eg. tree contents, get size of tree, and add node.\n\n");
	
	return description;
}

void TestDebug()
{
}

void Ex1()
{
	int number = 3;
	int exponentMax = 100;

	for (int i = 0; i < exponentMax; i++)
	{
		cout << number << " to the power of " << i << " is " << Power(number, i) << endl;
	}
}

double Power(int number, int exponent)
{
	if (exponent < 0)
	{
		cout << "ERROR - exponent cannot be less than zero!" << endl;
		return -1;
	}

	if (exponent == 0)
	{
		return 1;
	}
	else
	{
		return (Power(number, exponent-1) * number);

	}
}

void Ex2()
{
	// Blabla
}

void Ex3()
{

}

void Ex4()
{
}


