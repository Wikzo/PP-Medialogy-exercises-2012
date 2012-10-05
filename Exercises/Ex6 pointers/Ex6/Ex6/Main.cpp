#include <string>
#include <iostream>

using namespace std;

struct Product
{
	int year;
	string name;
};

// Global fields
int myChoice = 1;
int test = 3;
int* testPointer = &test;
char *pointerInput1, *pointerInput2;

// Exercise functions
void Ex1();
void Ex2(char* a, char* b);
void Ex3(int numberOfStrings);
void ChooseExercise(int choice);
void TestDebug(int* a);
string ExerciseDescriptions();
string StringToUppercase(string& s);

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
			char a, b;
			cout << "Give me a number (single digit): ";
			cin >> a;
			cout << "\nGive me another number (single digit): " ;
			cin >> b;
			pointerInput1 = &a;
			pointerInput2 = &b;
			Ex2(pointerInput1, pointerInput2);
			break;

		case 3:
			int number;
			cout << "How many strings do you want: ";
			cin >> number;
			Ex3(number);
			break;


		case -1:
			TestDebug(testPointer);
			break;

		default:
			cout << "ERROR - Exercise not found!";
			break;
	}
}

string ExerciseDescriptions()
{
	string description;
	description.append("1 - Program containing each variable type with a pointer to each. Use pointer to manipulate variables.\n\n");
	description.append("2 - Function that takes two char as input and swaps their values\n\n");
	description.append("3 - Program that allows the user to:\n\t\ta - enter a number of strings that he wishes to type\n\t\tb - type the strings and store them in an array\n\t\tc - change all letters in the strings to uppercase and print them on the screen\n\n");

	return description;
}

void TestDebug(int* a)
{
	cout << "a: " << a << endl;
	cout << "&a: " << &a << endl;
	cout << "*a: " << *a << endl;
}

void Ex1()
{
	int aInt = 5;
	int* aPointer = &aInt;

	char bChar = 'b';
	char* bPointer = &bChar;

	string cString = "hejsa";
	string* cPointer = &cString;

	Product dProduct;
	dProduct.name = "Thomas";
	dProduct.year = 17;
	Product* dPointer = &dProduct;

	cout << "First we show all the values/pointers normally: --------------\n\n";
	// int variable and pointer
	cout << "aInt: " << aInt << " - &aInt: " << &aInt << endl;
	cout << "aPointer: " << aPointer << " - &aPointer: " << &aPointer << " - *aPointer: " << *aPointer << endl;

	// char variable and pointer
	cout << "bChar: " << bChar << " - &bChar: " << &bChar << endl;
	cout << "bPointer: " << bPointer << " - &bPointer: " << &bPointer << " - *bPointer: " << *bPointer << endl;

	// string variable and pointer
	cout << "cString: " << cString << " - &cString: " << &cString << endl;
	cout << "cPointer: " << cPointer << " - &cPointer: " << &cPointer << " - *cPointer: " << *cPointer << endl;

	// Product variable and pointer
	cout << "dProduct.name: " << dProduct.name << " - &dProduct.name: " << &dProduct.name << endl;
	cout << "dPointer->name: " << dPointer->name << " - &dPointer->name: " << &dPointer->name << endl;

	// Change
	cout << "\nNow we change the values of the pointer -----------------" << endl;
	
	dPointer->name = "Bob";
	cout << "dPointer->name = \"Bob\": " << dPointer->name << endl;
	cout << "(*dPointer).name: " << (*dPointer).name << endl;

}

void Ex2(char* a, char* b)
{
	cout << "a = " << *a << endl;
	cout << "b = " << *b << endl;

	cout << "\nNow we swap ------\n";

	int temp = *a;
    *a = *b;
    *b = temp;

	cout << "a = " << *a << endl;
	cout << "b = " << *b << endl;
}

void Ex3(int numberOfStrings)
{
	if (numberOfStrings <= 0)
	{
		cout << "ERROR - you need to specify a positive amount of strings!";
		return;
	}

	numberOfStrings -= 1; // make zero-based

	string* arrayOfStrings = new string[numberOfStrings];

	// Input
	int i = 0;
	for (; i < numberOfStrings; i++)
	{
		cout << "Give me string " << (i+1) << ": ";
		cin >> arrayOfStrings[i];
		arrayOfStrings[i] = StringToUppercase(arrayOfStrings[i]);
	}
	i = 0;

	cout << "\n\n--------------------Here are the strings converted to UPPERCASE:\n";
	// Show all the strings (now in uppercase)
	for (; i < numberOfStrings; i++)
	{
		cout << arrayOfStrings[i] << endl;
	}
	
}

string StringToUppercase(string& s)
{
	/*cout << "Before conversion:\n";
	cout << s << endl;*/

	std::string::iterator i = s.begin();
	std::string::iterator end = s.end();

	while (i != end)
	{
		*i = toupper((unsigned char)*i); 
		i++;
	}

	/*cout << "After conversion:\n";
	cout << s << endl;*/
	return s;
}


