#include <string>
#include <iostream>

using namespace std;

// Global fields
int myChoice = 1;

// Exercise functions
void Ex1();
void Ex2();
void Ex3();
void ChooseExercise(int choice);
void TestDebug();
string ExerciseDescriptions();

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
	description.append("1 - Define int pointer p and create dynamic array with 5 cells. Write a loop to fill the array with values 3, 7, 11, 15, 19. Write a loop to print the values in p. Then free the dynamic memory allocated to p.\n\n");
	description.append("2 - Simple question (no program)\n\n");
	description.append("3 - Write program that uses pointers to set each element in an array to 0.\n\n");
	
	return description;
}

void TestDebug()
{
}

void Ex1()
{
	int pointerSize = 5;
	int* p = new int[pointerSize];
	p[0] = 3;
	p[1] = 7;
	p[2] = 11;
	p[3] = 15;
	p[4] = 19;

	for (int i = 0; i < pointerSize; i++)
		cout << p[i] << endl;

	delete [] p;
}

void Ex2()
{
	cout << "-------------\nConsider the following:" << endl;
	cout << "int *p; \nint i; \nint k; \ni = 42; \nk = i; \np = &i;" << endl;

	int *p;
	int i;
	int k;
	i = 42;
	k = i;
	p = &i;

	cout << "\nWhich statement changes the value of i to 75?" << endl;
	cout << "A. k = 75;" << endl;
	cout << "B. *k = 75;" << endl;
	cout << "p = 75;" << endl;
	cout << "D. *p = 75;" << endl;

	cout << "\nGive me an answer (A-D): ";
	char input;
	cin >> input;

	switch (input)
	{
		case 'A':
			k = 75;
			cout << "i is now: " << i << endl;
			break;

		case 'B':
			//*k = 75;
			cout << "ERROR - k is not a pointer!" << endl;
			break;

		case 'C':
			//p = 75;
			cout << "ERROR - p is not an int!" << endl;
			break;

		case 'D':
			*p = 75;
			cout << "i is now: " << i << endl;
			cout << "YAY ... correct answer!" << endl;
			break;

		default:
			cout << "ERROR (remember to use capital letters)" << endl;
	}
}

void Ex3()
{
	int myArray[10];

	int* p = myArray;

	for (int i = 0; i < 10; i++)
	{
		p[i] = 0;
		cout << myArray[i] << endl;
	}

	
}


