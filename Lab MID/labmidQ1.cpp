#include<iostream>
using namespace std;
class Node {
public:
	int data;
	Node* next;


};


class LinkedList
{
private:
	Node* head;
	int arr[10];
	int i = 0;
public:

	void insert(int data)
	{
		Node* temp = new Node;
		temp->data = data;

		head = temp;
	}

	int circular()
	{
		Node* curr = head;
		Node* temp;
			temp = curr;
		//head = curr;
		do
		{
			
			do
			{
				if (temp->data == curr->data)
				{
					arr[i]=temp->data;
					cout<<arr[i];
			     	++i;

				}
				temp = temp->next;
			} while (temp != head);
			curr = curr->next;
		} while (curr != head);
	}

	void check()
	{
		Node* temp;
		temp = head;
		while (temp->next != head)
		{
			if (temp == NULL)
			{
				cout << "Not Circular Linked list" << endl;
			}
			else
			{
				cout << "Circular Linked List" << endl;
				break;
			}
			temp = temp->next;


		}
	}


};
int main()
{
	LinkedList l;
	l.insert(3);
	l.insert(4);
	l.insert(5);
	l.insert(2);
	l.insert(2);
	l.insert(4);
	l.circular();
	l.check();

}
