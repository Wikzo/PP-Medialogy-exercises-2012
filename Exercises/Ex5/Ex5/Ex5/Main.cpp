#include <string>
#include <cstdlib> 
#include <ctime> 
#include <iostream>
#include <cmath>

using namespace std;

// Money types
struct Money
{
	int _1000, _500, _200, _100, _50, _20, _10, _5, _2, _1, _05;
	unsigned int _total;
};

Money myMoney;

string ExerciseDescriptions();
void TestDebug();
void ChooseExercise(int choice);
float Ex1(float a, float b);
void Ex2();
Money Ex3();
void Ex4();

int myChoice = 1;

int main()
{
	srand((unsigned)time(0)); // used to seed the random
	
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
			cout << "Average of 20.5 and 10.32: " << Ex1(20.5, 10.32) << endl;
			break;

		case 2:
			Ex2();
			break;

		case 3:
			myMoney = Ex3();
			cout << "\nTotal: " << myMoney._total << endl << endl;
			cout << "1000's: " << myMoney._1000 << endl;
			cout << "500's: " << myMoney._500 << endl;
			cout << "200's: " << myMoney._200 << endl;
			cout << "100's: " << myMoney._100 << endl;
			cout << "50's: " << myMoney._50 << endl;
			cout << "20's: " << myMoney._20 << endl;
			cout << "10's: " << myMoney._10 << endl;
			cout << "5's: " << myMoney._5 << endl;
			cout << "2's: " << myMoney._2 << endl;
			cout << "1's: " << myMoney._1 << endl;
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
	description.append("1 - Implement a function that, given two floating point numbers, computes the average of the two numbers and prints it to the screen\n\n");
	description.append("2 - Function that given two ints returns the one closest to zero\n\n");
	description.append("3 - Given a payable amount of DKK, produces the smallest combination of bills and coins to pay that amount\n\n");
	description.append("4 - Game where player has to guess a random number between 0-100, by getting smaller than/greater than hints fafter each guess\n");
	
	return description;
}

void TestDebug()
{
}

float Ex1(float a, float b)
{
	return (a + b) / 2;
}

void Ex2()
{
	int a, b;
	cout << "Give me two integer values: " << endl;
	cout << "Value1: ";
	cin >> a;
	cout << endl << "Value2: ";
	cin >> b;

	if (abs(a) < abs(b))
		cout << a << " is closer to zero than " << b;
	else
		cout << b << " is closer to zero than " << a;
}

Money Ex3()
{
	unsigned int inputMoney = 0;
	int moneyLeft = 0;
	Money myMoney;

	do
	{
		cout << "Give me an amount of money I need to give you: ";
		cin >> inputMoney;
		
		// Check if legal ... DOES NOT WORK
		if (inputMoney > 429496729)
			inputMoney = 0;
	} while (inputMoney == 0);

	myMoney._total = inputMoney;

	// Test combinations
	myMoney._1000 = inputMoney / 1000;
	moneyLeft = inputMoney % 1000;

	myMoney._500 = moneyLeft / 500;
	moneyLeft = moneyLeft % 500;

	myMoney._200 = moneyLeft / 200;
	moneyLeft = moneyLeft % 200;

	myMoney._100 = moneyLeft / 100;
	moneyLeft = moneyLeft % 100;

	myMoney._50 = moneyLeft / 50;
	moneyLeft = moneyLeft % 50;

	myMoney._20 = moneyLeft / 20;
	moneyLeft = moneyLeft % 20;

	myMoney._10 = moneyLeft / 10;
	moneyLeft = moneyLeft % 10;

	myMoney._5 = moneyLeft / 5;
	moneyLeft = moneyLeft % 5;

	myMoney._2 = moneyLeft / 2;
	moneyLeft = moneyLeft % 2;

	myMoney._1 = moneyLeft / 1;
	moneyLeft = moneyLeft % 1;

	// 0.5
	/*myMoney._0.5 = inputMoney / 0.5;
	moneyLeft = inputMoney % 0.5;*/

	return myMoney;

}

void Ex4()
{
	int tries = 0;
	int guess = 0;
	int numberToGuess = (rand() % 100); // gives random number between 0-100
	
	cout << "You have to guess a number between 0 and 100." << endl;

	do
	{
		cout << "Your guess: ";
		cin >> guess;

		if (guess == numberToGuess)
		{
			cout << "\nHOORAY - You guessed the number " << numberToGuess << " using " << tries << " tries. Nice";
		}
		else if (guess > numberToGuess)
		{
			tries++;
			cout << "\nYour guess was too high" << endl;
		}
		else if (guess < numberToGuess)
		{
			tries++;
			cout << "\nYour guess was too low" << endl;
		}

	} while (guess != numberToGuess);

}


