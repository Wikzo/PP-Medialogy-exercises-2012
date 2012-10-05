#include <iostream>
using namespace std;

struct Node
{
	int value;
	Node* next;
};

struct List
{
	Node* head; // the first item (root)
};

void list_initialize(List* list)
{
	if (list == NULL)
		return;

	list->head = NULL;
}


void list_push(List* list, int val)
{
	if (list == NULL)
		return;

	// List is empty
	if (list->head == NULL)
	{
		list->head = new Node();
		list->head->next = NULL;
		list->head->value = val;
	}
	else // Go to last element in list and then append a new Node
	{
		Node* curr = list->head; // Root Node
		
		// Iterate until the end of the list
		while (curr->next != NULL)
		{
			curr = curr->next;
		}
		// Make the new Node and assign the value
		curr->next = new Node();
		curr->next->value = val;
		curr->next->next = NULL;
	}
}

void list_cleanUp(List* list)
{
	if (list == NULL)
		return;

	Node* curr = list->head;


	while (curr != NULL)
	{
		Node* copyOfNext = curr->next; // copy - the value of next is a Node pointer which is an address
		delete curr; // removes whatever the pointer is pointing to
		curr = copyOfNext;
	}
}
void list_print(List* list) // The pointer needs an address to point to
{
	if (list == NULL)
		return;

	for (Node* next = list->head; next != NULL; next = next->next) // or (*next).next which is de-reference
	{
		cout << next->value << endl;
	}

}

int main()
{
	List list;
	list_initialize(&list); // The pointer needs an address to point to, therefore "&list" is used and NOT "*list"
	list_push(&list, 1);
	list_push(&list, 5);
	list_push(&list, 8);
	list_push(&list, 13);

	list_print(&list);
	list_cleanUp(&list);

	cin.clear();
	cin.sync();
	cin.ignore();

	return 0;
}