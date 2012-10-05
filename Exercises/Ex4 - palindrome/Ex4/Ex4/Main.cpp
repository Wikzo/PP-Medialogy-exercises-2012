#include <string>
#include <iostream>

using namespace std;

struct Movie
{
	string Title;
	int Year;
};

struct Color
{
	int r;
	int g;
	int b;
};

string reverse(string src);
void TestDebug();
void ChooseExercise(int choice);
void Ex1();
void Ex2();
void Ex3();
void Ex3b();
void Ex4();
void Ex5();

int main()
{
	/*Movie myMovie;
	myMovie.Title = "Harry Potter";
	myMovie.Year = 2000;
	cout << myMovie.Title << endl;*/

	int myChoice = 1;
	
	do
	{
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
	cout << "Exercise " << choice << endl;
	switch (choice)
	{
		case 1:
			Ex1();
			break;

		case 2:
			Ex2();
			break;

		case 3:
			//Ex3();
			Ex3b();
			break;

		case 4:
			Ex4();
			break;
		
		case 5:
			Ex5();
			break;

		case -1:
			TestDebug();
			break;
	}
}

void Ex1()
{
			const int arrayLimit = 63;
			int numberArray[arrayLimit];

			for (int i = 0; i < arrayLimit; i++)
			{
				numberArray[i] = i+1;
				cout << numberArray[i] << endl;
			}
}

void Ex2()
{
	Movie myMovie;
	myMovie.Title = "Harry Potter";
	myMovie.Year = 2001;
	cout << myMovie.Title << " " << myMovie.Year << endl;
}

void Ex3()
{
	int numbers[10];

	// Get input
	for (int i = 0; i < 10; i++)
	{
		cout << "Give me number " << (i+1) << ": ";
		cin >> numbers[i];
		//cout << numbers[i];
	}

	// Find smallest and biggest number in array
	int smallest, biggest;
	smallest = numbers[0];
	biggest = numbers[0];
	for (int i = 0; i < 10; i++)
	{
		if (numbers[i] < smallest)
			smallest = numbers[i];
		else if (numbers[i] > biggest)
			biggest = numbers[i];
	}

	cout << "\n\n";
	cout << "Smallest: " << smallest << endl;
	cout << "Biggest: " << biggest << endl;
	cout << "But now we swap the two values... ---------------------- \n";

	int temp = smallest;
	numbers[smallest] = biggest;
	numbers[biggest] = temp;

	cout << "(original smallest, but now big): " << numbers[smallest] << endl;
	cout << "(original biggest, but now small): " << numbers[biggest] << endl;
}

void Ex3b()
{
	// Now check for palindrome (staves forfra og bagfra)

	cin.ignore();
	cin.clear();
	cin.sync();

	string input = "";
	cout << "Give me a word: ";
	getline(cin, input);
	string output = input;
	int length = input.size(); // is NOT zero-based
	int i, j;
	bool isPalindrome = true;

	for (i = 0, j = length - 1; i <= (length/2); i++, j--)
	{
		if (input[i] != input[j])
		{
			isPalindrome = false;
		}
	}

	cout << endl << input << " is a palindrome: " << isPalindrome << endl;
	cout << "Backwards: " << output << endl;
	output = reverse(input);
	cout << "Backwards: " << output << endl;
}

string reverse(string src)
{
	return string(src.rbegin(), src.rend());
}

void Ex4()
{
	cin.ignore();

	string original = "A";
	//cout << (int)original[0]; // prints "32" (space)    A=65

	cout << "Give me a string: " ;
	getline(cin, original);
	int length = original.size();
	char code[100]; // can be changed to store more


	//cout << "WITH spaces: " << original << endl;
	// Remove all spaces
	for (int i = length-1; i > 0; i--)
	{
		if (original[i] == ' ')
			original.erase(i, 1);
	}
	length = original.size();
	//cout << "WITHOUT spaces: " << original;

	// string to char
	for (int i = 0; i < length; i++)
	{
		code[i] = original[i];
	}

	for (int i = 0; i < length; i++)
	{
		// UPPER-CASE LETTERS
		// Between A-M
		if ((int)code[i] >= 64 && (int)code[i] < 78)
			code[i] = (int)code[i] + 13;
		// Between N-Z
		else if ((int)code[i] >= 78 && (int)code[i] < 91)
			code[i] = (int)code[i] - 13;

		// LOWER-CASE LETTERS
		// Between a-m
		else if ((int)code[i] >= 97 && (int)code[i] < 110)
			code[i] = (int)code[i] + 13;
		// Between n-z
		else if ((int)code[i] >= 110 && (int)code[i] < 123)
			code[i] = (int)code[i] - 13;

	}

	cout << endl << original << "<---- Original message\n\n";
	for (int i = 0; i < length; i++)
	{
		if (code[i] != ' ')
			cout << code[i];
	}
	cout << "<---- ROT13 message" << endl;



	// ROT13 algorithm
	// A-M --> + 13
	// N-Z --> -13

	// http://www.cdrummond.qc.ca/cegep/informat/professeurs/alain/images/ASCII1.GIF
	// A (char) = 0x465 (dec)
    // a (char) = 0x97; (dec)
	// space (char) = 20 (dec)
	// N (char) = 78 (dec)
	// Z (char) = 90 (dec)

	// A + 13 = N
	// B = O
	// C = P, etc.
	// M = Z
	// N = A
}

void Ex5()
{
	Color Pic[600][800];
	Pic[0][0].b = 0;
	Pic[1][1].r = 10;
}

void TestDebug()
{
	cin.ignore();
	string txt;
	getline(cin, txt);
	cout << txt;
}
