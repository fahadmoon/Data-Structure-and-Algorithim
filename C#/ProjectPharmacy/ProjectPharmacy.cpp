#include<iostream>
#include<string>
using namespace std;

class Node
{
public:
	string medicineName;
	double price;
	int medicineQuantity;
	int productID;
	string expiredDate;
	string issueDate;
	int orderNo;

	Node* next;
	Node* prev;
	/*Node()
	{
		next = NULL;
		prev = NULL;
	}*/
};


//Create class Menu

class Stock
{
private:
	Node* head;
public:
	Stock()
	{
		head = NULL;
	}
	//This Funiction is Add Stock
	void AddStock()
	{
		string medicineName;
		while (true)
		{
			cout << "Enter Medcine Name: " << endl;
			cin >> medicineName;
			int i = 0;
			Node* c = head;
			while (c != NULL)
			{
				if (medicineName == c->medicineName)
				{
					i++;
					break;
				}
				c = c->next;
			}
			//If found same name medicine 

			if (i == 1)
			{
				cout << "Already Medicine create......" << endl << endl;
				/*cout << "1. Go Menu" << endl;
				cout << "2. Continue" << endl;
				int s;
				cin >> s;
				if (s == 1)
				{
					menu();
				}
				else if (s == 2)
				{
					continue;
				}*/
			}
			else
			{
				break;
			}
		}

		//
		double price;
		while (true)
		{
			cout << "Enter Price: " << endl;
			cin >> price;
			if (price > 0)
			{
				break;
			}
		}

		//Product ID
		int productId;
		while (true)
		{
			cout << "Enter Product ID: " << endl;
			cin >> productId;
			int i = 0;
			Node* c = head;
			while (c != NULL)
			{
				if (productId == c->productID)
				{
					i++;
					break;
				}
				c = c->next;
			}

			if (i == 1)
			{
				cout << "Already Product Id create..........." << endl;

			}
			else
			{
				break;
			}
		}

		cout << "Enter Medicine Quanity: " << endl;
		int medicineQuantity;
		cin >> medicineQuantity;
		cout << "Check Expire Medicine: " << endl;

		string expiredDate;
		cin >> expiredDate;
		string issueDate;
		cout << "Enter Issue Date: " << endl;
		cin >> issueDate;

		Node* newNode = new Node;
		newNode->medicineName = medicineName;
		newNode->medicineQuantity = medicineQuantity;
		newNode->productID = productId;
		newNode->issueDate = issueDate;
		newNode->expiredDate = expiredDate;
		//newNode->orderNo = orderNo;
		newNode->next = NULL;
		Node* current;
		if (head == NULL)
		{
			newNode->prev = NULL;
			head = newNode;
		}
		else
		{
			current = head;
			while (current->next != NULL)
			{
				current = current->next;
			}
			current->next = newNode;
			newNode->prev = current;


		}

	}


	//This function Is Update Stock
	void UpdateStock(string medicineName,int projuctID)
	{
		Node* curr = head;
		while (curr != NULL)
		{
			if (curr->medicineName == medicineName || curr->productID == projuctID)
			{
				cout << "Update Quantity: " << endl;
				int q;
				cin >> q;
				curr->medicineQuantity = curr->medicineQuantity + q;
				cout << "Update Expiry Date: " << endl;
				string ue;
				cin>>ue;
				curr->expiredDate = ue;
				int p;
				cout << "Price update: " << endl;
				cout << "\t1. Yes" << endl;
				cout << "\t2. No" << endl;
				cin >> p;
				if (p == 1)
				{
					int price;					
					cout << "New Price: " << endl;
					cin >> price;
					curr->price = price;
				}

			}
			curr = curr->next;
		}
	}

	//Check Order
	void CheckOrder()
	{
		Node* curr = head;
		cout << "===============================================================================" << endl;
		cout << "|  Medicine ID |     Medicine Name    |  	Quantity     |    Price     |" << endl;
		cout << "=======++==================++================++===============++===============" << endl;
		while (curr != NULL)
		{
			cout << "\t"<<curr->productID << "\t\t";
			cout << curr->medicineName << "\t\t\t";
			cout << curr->medicineQuantity << "\t\t";
			cout << curr->price << endl;
			curr=curr->next;
		}

	}

	//This function is Cancel Order
	void CancelOrder()
	{

	}

};


int main()
{

	//create objeact 

	Stock* s = new Stock;
	while (true)
	{
		cout << "1. Stock Management " << endl;
		cout << "2. Exit" << endl;
		int select;
		cin >> select;
		switch (select)
		{
		case 1:
			cout << "1. Add Stock" << endl;
			cout << "2. Update Stock" << endl;
			cout << "3. Check Order" << endl;
			cout << "4. Cancel Order" << endl;
			cout << "5. Medicine Count" << endl;
			cout << "6. Check Expired Item" << endl;
			cout << "7. Go back" << endl;
			int select1;
			cin >> select1;
			if (select1 == 1)
			{
				//Write a Code Option 1 Add Stock
				s->AddStock();				
			}
			else if (select1 == 2)
			{
				string medicineName;
				int productID;
				cout << "Search Medicine: " << endl;
				cout << "\t1. Medicine Name: " << endl;
				cout << "\t2. Product ID: " << endl;
				int a;
				cin >> a;
				if (a == 1)
				{
					cout << "Enter Medicine Name: " << endl;
					cin >> medicineName;
					productID = 0;
				}
				else if (a == 2)
				{
					cout << "Enter Product ID: " << endl;
					cin >> productID;
					medicineName = " ";
				}
				s->UpdateStock(medicineName,productID);
			}
			else if (select1 == 3)
			{
				s->CheckOrder();
			}
			else if (select1 == 4)
			{

			}
			else if(select1==5)
			{

			}
			break;

			/////////
		default:

			break;
		}

	

}

}