#include<iostream>
using namespace std;

class Node {

private:
	Node* head;
	Node* temp;
	Node* next;
	Node* tail;
	int data;

public:
	//Constructor
	Node() 
	{
		data = 0;
	}

	void Head(int a) {
		cout << "head" << endl;

		for (int i = 0; i < a; i++) {
			temp = new Node();
			temp->data = i;
			temp->next = head;
			head = temp;
		}


	}
	void Tail(int a) {
		cout << "Tail" << endl;
		head = new Node();
		tail = head;
		
		for (int i = 0; i < a;i++) {
			temp = new Node();
			temp->data = i;
			temp->next = NULL;
			tail->next = temp;
			tail = temp;
			
		}
	}

	void printList() {

		while (head != NULL) {
			cout << head->data << endl;
			head = head->next;
		}
	}

};


int main() {

	int a;
	Node obj;
	
	int i;
	cout << "1.head" << endl;
	cout << "2.tail" << endl;
	cin >> i;
	cout << endl;
	system("cls");
	cout << "Enter Number : " << endl;
	cin >> a;

	if (i == 1)
	{
		obj.Head(a);
		obj.printList();
	}
	else if(i==2)
	{
		obj.Tail(a);
		obj.printList();
	}
	
	return 0;	
}
