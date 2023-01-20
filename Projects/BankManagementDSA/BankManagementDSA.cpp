#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;
class node
{
public:
	int acc_No;
	string nameAcc_Holder;
	string fathername;
	char account_Type;
	double amount;
	node* next;
	node* prev;

};

class Bank
{
private:
	node* head;
public:
	Bank()
	{
		head = NULL;
	}

	//Create Account
	void CreateAccount(string name, string fname, char accType, double balance)
	{
		node* temp, * curr;
		temp = new node;

		temp->nameAcc_Holder = name;
		temp->fathername = fname;
		temp->account_Type = accType;
		temp->amount = balance;

		srand(time(0));
		int a = rand() % 1000;

		temp->acc_No = a;
		cout << "Account number created: " << endl;
		cout << "Your Account Number is " << temp->acc_No << endl;
		temp->next = NULL;
		if (head == NULL)
		{
			temp->prev = NULL;
			head = temp;
		}
		else
		{
			curr = head;
			while (curr->next != NULL)
			{
				curr = curr->next;
			}

			curr->next = temp;
			curr->prev = curr;

		}
	}

	//Deposit Function
	void deposit(int accNO)
	{
		node* curr;
		curr = head;
		while (curr != NULL)
		{
			if (accNO == curr->acc_No)
			{
				double depositbal;
				cout << "Enter Deposit Balance: " << endl;
				cin >> depositbal;
				if (depositbal > 499)
				{
					curr->amount = curr->amount + depositbal;
					cout << "Deposit Amount " << depositbal << endl;
					cout << "Total Balance: " << curr->amount << endl;
				}
				else
				{
					cout << "Your deposit is low!!!!" << endl;
				}

			}
			else
			{
				cout << "Your account was not found!!" << endl;
			}
			curr = curr->next;
		}

	}
	//Withdraw Function
	void withdraw(int accNO)
	{
		node* curr;
		curr = head;
		while (curr != NULL)
		{
			if (accNO == curr->acc_No)
			{
				double withdrawbal;
				cout << "Enter Withdraw Balance: " << endl;
				cin >> withdrawbal;
				if (curr->amount > withdrawbal)
				{
					curr->amount = curr->amount - withdrawbal;
					cout << "Withdraw Balance: " << withdrawbal << endl;
					cout << "Total Balance: " << curr->amount << endl;
				}
				else
				{
					cout << "Your Balance is low" << endl;
				}

			}
			else
			{
				cout << "Your account was not found!!" << endl;
			}
			curr = curr->next;
		}
	}
	//Balance Enquary
	void BalanceCheck(int accNo)
	{
		node* curr;
		curr = head;
		while (curr != NULL)
		{
			if (accNo == curr->acc_No)
			{
				cout << "Your Balance is " << curr->amount << endl;

			}
			else
			{
				cout << "Your account was not found" << endl;
			}
			curr = curr->next;
		}

	}
	//MOdify Account 
	void ModifyAccount(int accNo)
	{
		node* curr = head;
		while (curr != NULL)
		{
			if (curr->acc_No == accNo)
			{
				string name;
				cout << "Enter Your Name: " << endl;
				cin >> name;
				curr->nameAcc_Holder = name;

				string fathername;
				cout << "Enter Father Name: " << endl;
				cin >> fathername;
				curr->fathername = fathername;
				char acctype;
				cout << "Enter Account Type(Current/Saving): " << endl;
				cin >> acctype;
				curr->account_Type = acctype;

			}
			else
			{
				cout << "Your account was not found" << endl;
			}
			curr = curr->next;
		}
	}

	//Delete Account
	void DeleteAccount()
	{
		int roll;
		cout << "Enter Search Roll No: " << endl;
		cin >> roll;


		int found = 0;
		if (head->acc_No == roll)
		{
			node* temp = head;

			head = head->next;
			head->prev = NULL;
			found++;
			delete temp;
		}
		else
		{
			node* temp, * curr;
			curr = head;
			while (curr != NULL)
			{
				if (curr->acc_No == roll)
				{
					temp = curr;
					temp->prev->next = temp->next;
					temp->next->prev = temp->prev;
					curr = temp->prev;
					found++;
					delete temp;
					break;
				}
				curr = curr->next;
			}
		}

		if (found == 0)
		{
			cout << "Roll No not found!!" << endl;
		}

	}

	//Display Information
	void display()
	{
		node* curr=head;
		while (curr != NULL)
		{
			cout << "Account Number: " << curr->acc_No << endl;
			cout << "Name: " << curr->nameAcc_Holder << endl;
			cout << "Father Name: " << curr->fathername << endl;
			cout << "Account Type: " << curr->account_Type << endl;
			cout << "Balance: " << curr->amount << endl << endl;
			cout << "-------------------------------------------" << endl;
			curr = curr->next;
		}
	}


};

int main()
{
    Bank bank;
    



	while (true) {
		
		cout << "\n\n\t\t\t\t=======================================================================";
		cout << "\n\t\t\t\t=======================================================================" << endl << endl;

		cout << "\t\t\t\t\tWELCOME TO HABIB BANK LIMITED ACCOUNT MANAGEMENT SYSTEM" << endl;

		cout << endl << "\t\t\t\t=======================================================================";
		cout << endl << "\t\t\t\t=======================================================================";


		cout << endl << "\n\n\t\t\t\t    ::MAIN MENU::" << endl;
		cout << endl << "\n\t\t\t\t1. NEW ACCOUNT";
		cout << "\n\t\t\t\t2. DEPOSIT AMOUNT";
		cout << "\n\t\t\t\t3. WITHDRAW AMOUNT";
		cout << "\n\t\t\t\t4. BALANCE ENQUIRY";
		cout << endl << "\t\t\t\t5. ALL ACCOUNT HOLDER LIST";
		cout << endl << "\t\t\t\t6. MODIFY AN ACCOUNT";
		cout << endl << "\t\t\t\t7. CLOSE AN ACCOUNT";
		cout << endl << "\t\t\t\t8. EXIT";
		cout << endl << endl;

		int option;
		cout << endl << "\t\t\t\tSelect Your Option (1-8): ";
		cin >> option;

		switch (option)
		{
		case 1:
		{
			string name;
			cout << "Enter Your Name: " << endl;
			cin >> name;
			string fathername;
			cout << "Enter Father Name: " << endl;
			cin >> fathername;
			char acctype;
			cout << "Enter Account Type(Current/Saving): " << endl;
			cin >> acctype;
			double depositamount;
			cout << "Enter Deposit Amount: " << endl;
			cin >> depositamount;
			bank.CreateAccount(name,fathername, acctype, depositamount);
			break;
		}
		case 2:
		{
			int accNo;
			cout << "Enter Account Number: " << endl;
			cin >> accNo;
		
			bank.deposit(accNo);
			break;
		}
		case 3:
		{
			int accNo;
			cout << "Enter Account Number: " << endl;
			cin >> accNo;
			bank.withdraw(accNo);
			break;
		}
		case 4:
		{
			int accNo;
			cout << "Enter Account No: " << endl;
			cin >> accNo;
			bank.BalanceCheck(accNo);
			break;
		}

		case 5:
		{
			bank.display();
			break;
		}
		case 6:
		{
			int accNo;
			cout << "Enter Account No: " << endl;
			cin >> accNo;
			bank.ModifyAccount(accNo);
			break;
		}
		case 7:
		{
			/*int accNo;
			cout << "Enter Account No: " << endl;
			cin >> accNo;*/
			bank.DeleteAccount();
			break;
		}

		case 8:
		{
			exit(0);
			return 0;

			break;
		}

		default:
		{

			cout << "\n\t\t\t\tPlease Enter the Correct option" << endl;
		}
		}
		system("pause");
	}

}