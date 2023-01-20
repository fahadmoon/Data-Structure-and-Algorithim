#include<iostream>
using namespace std;

class node
{
public:
	int data;
	node* next;
	node* prev;

};

class DoublyList {
private:
	node* head;
public:
	DoublyList()
	{
		head = NULL;
	}

	void CreatNode(int val)
	{
		node* temp = new node();
		temp->data = val;
		temp->next = NULL;
		if (head == NULL)
		{
			temp->prev = NULL;
			head = temp;
		}
		else {
			node* curr;
			curr = head;
			while (curr->next != NULL)
			{
				curr = curr->next;
			}
			curr->next = temp;
			temp->prev = curr;
		}
	}


	//Insert Node
	void InsertFirst(int val)
	{
		node* temp = new node;
		temp->prev = NULL;
		temp->data = val;
		temp->next = head;
		head->prev = temp;
		head = temp;
	}


	void EndInsert(int val)
	{
		node* temp = new node;
		temp->data = val;
		node* curr;

		curr = head;
		while (curr->next != NULL)
		{
			curr = curr->next;
		}
		curr->next = temp; //current and temp node connection
		temp->next = NULL;
		temp->prev = curr;
	}

	//Insert Position
	void InsertPosition(int pos, int val)
	{
		node* temp, * curr;
		curr = head;
		
		for (int i = 0; i < pos; i++)
		{
			curr = curr->next;
		}
		temp = new node;
		temp->data = val;
	    /*if (curr->next != NULL)
		{
			curr->next = temp;
			temp->next = NULL;
			temp->prev = curr;
		}
		else
		{*/
			temp->next = curr->next;
			temp->next->prev = temp;
			curr->next = temp;
			temp->prev = curr;
	//	}


	}

	//Display

	void Display()
	{
		node* curr = head;
		while (curr!= NULL)
		{
			cout << curr->data << endl;
			curr = curr->next;
		}
	}

};

int main()
{
	DoublyList d;


	//Create Node
	d.CreatNode(5);
	d.CreatNode(2);
	//d.EndInsert(23);
	//d.InsertFirst(3);
	d.Display();

	cout << "-----------" << endl;
	d.InsertPosition(1, 4);
	
	d.Display();
}