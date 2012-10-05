#include <string>
#include <iostream>

// Gustav Dahl Medialogy
// gdahl11@student.aau.dk

using namespace std;

struct Node
{
	int value;
	Node* pLeft;
	Node* pRight;

	Node(int number) // Constructor - everything is per default NULL
	{
		pLeft = NULL;
		pRight = NULL;
		value = number;
	}
};

// Global fields
int myChoice = 1;

// Others
void InsertNode(Node *&root, int newItem);
void PrintNodes(Node *&root);
int getRandomNumber(int max);


//Node RecursiveFindNodeLeft(Node node, int counter);
// void CreateNode(Node *&root, int number);
void CreateLeftNode(int number, int limitCounter, Node &parentNode);
void CreateRightNode(int number, int limitCounter, Node &parentNode);

// Exercise functions
void Ex1(int a[], int size);
void Ex2(int a[], int size);
void ChooseExercise(int choice);
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
			{
				// Bubble sort
				// Get some random values and store them in an array
				int numbers[5000];
				for (int i = 0; i < 5000; i++)
					numbers[i] = getRandomNumber(500);

				cout << endl << endl;

				Ex1(numbers, 5000);
				break;
			}

		case 2:
			{
				// Binary tree sort
				// Get some random values and store them in an array
				int numbers[5000];
				for (int i = 0; i < 5000; i++)
					numbers[i] = getRandomNumber(500);

				cout << endl << endl;
				Ex2(numbers, 5000);
				break;
			}
		default:
			cout << "ERROR - Exercise not found!";
			break;
	}
}

string ExerciseDescriptions()
{
	string description;
	description.append("1 - Implement a bubble sort algorithm that works on an array of integers.\n\n");
	description.append("2 - Use a binary tree to implement a binary tree sorting algorithhm for integers.\n\n");
	
	return description;
}

void Ex1(int a[], int size)
{
	bool hasSwapped = true;

	// Before sorting
	cout << "\nHere are the values before sorting:" << endl;
	for (int i = 0; i < size; i++)
		cout << a[i] << endl;

	while (hasSwapped)
	{
		hasSwapped = false;
		for (int i = 1; i < size; i++)
		{
			// Check if the next value is smaller than the previous
			if (a[i] < a[i-1])
			{
				int temp = a[i-1];

				// Swap the values
				a[i-1] = a[i];
				a[i] = temp;

				hasSwapped = true;
			}
		}
	}

	// After sorting
	cout << "\nHere are the values after sorting:" << endl;
	for (int i = 0; i < size; i++)
		cout << a[i] << endl;
}

void Ex2(int a[], int size)
{
	/* Compare to current node

	If SMALLER than or equal to the current node:
		If the left branch is empty --> Insert to left
		Else insert using the left node as a new root
	If GREATER than the current node
		If the right branch is empty --> Insert to right
		Else insert using the right node as new root
		*/

	Node* root;
	root = NULL;

	int index = 1;
	int counter = size;

	for (int i = 0; i < size; i++)
	{
		InsertNode(root, a[i]);
	}

	PrintNodes(root);

	/*while (index < size)
	{

		// Value LESS than root --> go left
		if (a[index] <= root->value)
		{
			CreateLeftNode(a[index], 0, *root);
		}
		// Value GREATER than root --> go right
		else if (a[index] > root->value)
		{
			CreateRightNode(a[index], 0, *root);
		}


		index++;
	}*/

	cout << "\n\nWe are now back in main..." << endl;
}

// A solution I found on the Internet - didn't get it to work 100%
/*void CreateNode(Node *&root, int number)
{
	if (root == NULL)
	{
		root = new Node(number);
		return;
	}
	else if (number < root->value)
		return CreateNode(root->pLeft, number);
	else 
		return CreateNode(root->pRight, number);

		cout << "\nERROR - CreateNode didn't work as expected! Value was: " << number;

}*/

// Beginning to retrieve the data - not done yet
/*

// child->getChild(); ... recursion something


void LookAtNodes(Node *&root)
{
	/* 
	// Retrieve data in recursive order
	Retrive left subtree if it exists
	Get the contents of this node
	Retrieve right subtree if it exits
	

	// Go down left
	if (root->pLeft != NULL)
		return LookAtNodes(root->pLeft);
	else
	{
		cout << root->value << endl;
	}

	// Go right
	if (root->pRight != NULL)
		return LookAtNodes(root->pRight);
	else
	{
		cout << root->value << endl;
	}

}*/


void InsertNode(Node *&root, int newItem)
{
	if (root == NULL)
	{
		root = new Node( newItem );
		return;
	}
	else if ( newItem < root->value ) {
		InsertNode( root->pLeft, newItem );
	}
	else {
		InsertNode( root->pRight, newItem );
	}
}

void PrintNodes(Node *&root)
{

	if (root->pLeft != NULL)
	{
		PrintNodes(root->pLeft);
		//cout << "l: " << root->value << endl;
	}

	cout << root->value << endl;
	
	if (root->pRight != NULL)
	{
		PrintNodes(root->pRight);
		//cout << "r: " << root->value << endl;
	}

}

int getRandomNumber(int max)
{
    int result;
    do {
        result = rand()%(max+1);
    } while (result == 0);

    return result;
}


void CreateLeftNode(int number, int limitCounter, Node *&parentNode)
{
	int counter = limitCounter;
	counter++;

	// Just to avoid infinite loop
	if (counter > 100)
	{
		cout << "\n" <<"ERROR - I have tried " << counter << " times, but cannot find left node";
		return;
	}

	if (parentNode == NULL)
	{
		parentNode = new Node(number);
		return;
	}

	// The left child is empty
	if (parentNode->pLeft == NULL)
	{
		Node leftNode(number); // Make new node (storing the current value)

		parentNode->pLeft = &leftNode; // Make link between parent and child
	}
	else
	{   // -------------------------------------------------------------------------  !!!!!!!!!!!!!!!!
		// I THINK MY PROBLEM IS HERE
		// Need to speak to the child of the child of the root and then make a new node
		// It should be like this: [root] --> [left_child] --> [child_of_left_child]
		//-------------------------------------------------------------------------  !!!!!!!!!!!!!!!!
		//Node* temp = parentNode.pLeft->pLeft; // <--- does not work

		return CreateLeftNode(number, counter, parentNode->pLeft); // <--- does not work
	}
}

void CreateRightNode(int number, int limitCounter, Node *&parentNode)
{
	int counter = limitCounter;
	counter++;

	// Just to avoid infinite loop
	if (counter > 100)
	{
		cout << "\n" <<"ERROR - I have tried " << counter << " times, but cannot find right node";
		return;
	}

	// The right child is empty
	if (parentNode->pRight == NULL)
	{
		Node rightNode(number); // Make new node (storing the current value)

		parentNode->pRight = &rightNode; // Make link between parent and child
	}
	else
	{
		// -------------------------------------------------------------------------  !!!!!!!!!!!!!!!!
		// I THINK MY PROBLEM IS HERE
		// Need to speak to the child of the child of the root and then make a new node
		// It should be like this: [root] --> [left_child] --> [child_of_left_child]
		//-------------------------------------------------------------------------  !!!!!!!!!!!!!!!!
		//Node* temp = parentNode.pRight->pRight; // <--- does not work

		return CreateRightNode(number, counter, parentNode->pRight); // <--- does not work
	}
}

