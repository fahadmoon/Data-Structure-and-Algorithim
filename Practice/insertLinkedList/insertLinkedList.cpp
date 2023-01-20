#include <iostream>
using namespace std;
class node {
	public:
	int data;
	node* next;
};
class singlyList
{
private:
	node* head;
	node* tail;
public:
	singlyList()
	{
		head = NULL;
		tail = NULL;
	}
	void createdNode(int value)
	{
		node* temp = new node;
		temp->data = value;
		temp->next = NULL;

		if (head == NULL)
		{
			head = temp;
			tail = temp;
		}
		else
		{
			tail->next = temp;
			tail = temp;
		}

	}
	//Display Function
		void display()
		{
			node* curr;
			curr = head;//again start first node
			while (curr != NULL)
			{
				cout << curr->data << endl;
				curr=curr->next;
			}

		}
	
		//insert Function
		void inserthead(int value)
		{
			node* temp = new node();
			temp->data = value;
			temp->next = head;
			head = temp;
		}

		//Last Insert

		void insertLast(int value)
		{
			node* temp = new node();
			temp->data = value;
			tail->next = temp;
			tail = temp;

		}
	

};

	int main()
	{
		singlyList s;
		s.createdNode(6);
		s.createdNode(87);
		
		cout << "Insert" << endl;
		s.inserthead(56);
		s.insertLast(99);
		s.display();
		return 0;
	}