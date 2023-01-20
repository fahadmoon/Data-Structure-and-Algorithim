#include <iostream>
#include <ctime>
#include <string>
#include <iomanip>
#include <stdlib.h>
//#include <windows.h>
#include<fstream>
using namespace std;
//Stock Data
class StockData
{
public:
	string medicineName;
	double price;
	int medicineQuantity;
	int productID;
	string expiredDate; 
	string issueDate;
	//double pharmacyinbalance;
	StockData()
	{
		medicineName = "";
	}
	StockData(string medicineName, double price, int medicineQuantity, int productID, string expiry, string issueDate)
	{
		this->medicineName = medicineName;
		this->price = price;
		this->medicineQuantity = medicineQuantity;
		this->productID = productID;
		this->issueDate = issueDate;
		this->expiredDate = expiry;
	}
	
	
};
class NodeBalance
{
public:
	double pharmacybalance;
	NodeBalance* next;
	NodeBalance() {}
	NodeBalance(double bal)
	{
		this->pharmacybalance = bal;
		next = NULL;
		fstream file;
		file.open("Balance.txt", ios::app | ios::out);
		file << pharmacybalance;
		file.close();
	}
	void updateBalance(double newBal)
	{
		this->pharmacybalance = newBal;
		fstream file,file1;
		file.open("Balance.txt", ios::in);
		file1.open("Balance1.txt", ios::app | ios::out);
		while (!file.eof())
		{
			file >> newBal;
			file1 << pharmacybalance;
			file >> newBal;
		}
		file1.close();
		file.close();
		remove("Balance.txt");
		rename("Balance1.txt", "Balance.txt");
	}
	
	void LoadFileBalance()
	{
		int bal;
		fstream file;
		file.open("Balance.txt", ios::in);
		file >> bal;
		this->pharmacybalance = bal;
		next = NULL;
		file.close();
	}
};

//Create Stock Node

class StockNode
{
public:
	StockData* stockData;
	StockNode* next;
	StockNode(StockData* data)
	{
		stockData = data;
		next = NULL;
	}

};
//Stock Class
class Stock
{
private:
	StockNode* head;
public:
	Stock()
	{
		head = NULL;
	}
	//Return Head
	StockNode* GetHead()
	{
		return head;
	}
	//AddStock
	void AddStock(StockData* data)
	{
		StockNode* storeNode = new StockNode(data);
		StockNode* curr = head;
		if (head == NULL)
		{
			head = storeNode;
			cout << " Medicine Product ID is " << head->stockData->productID << endl;
			//Store Node Data in File Handling
			AddStockFile(head->stockData->medicineName, head->stockData->price, head->stockData->medicineQuantity, head->stockData->productID, head->stockData->expiredDate, head->stockData->issueDate);
			cout << endl << endl;
			
		}
		else
		{
			while (curr->next != NULL)
			{
				curr = curr->next;
			}
			curr->next = storeNode;
			//Store Node Data in File Handling
			AddStockFile(curr->stockData->medicineName, curr->stockData->price, curr->stockData->medicineQuantity, curr->stockData->productID, curr->stockData->expiredDate, curr->stockData->issueDate);
			cout << " Medicine Product ID is " << curr->stockData->productID << endl;
		}
		cout << " Medicine Added Successfully... " << endl;
	}

	//File Hanndling Function for ADD Stock
	void AddStockFile(string medicineName, double price, int medicineQuantity, int productID, string expiry, string issueDate)
	{
		fstream filestock;
		filestock.open("StockData.txt", ios::app | ios::out);
		filestock << medicineName << " " << price << " " << medicineQuantity << " " << productID << " " << expiry << " " << issueDate << endl;
		filestock.close();
	}


	////check expiry date
	void CheckExpiry(StockNode* head_ref)
	{
		time_t now = time(0);
		tm* localTime = new tm;
		localtime_s(localTime, &now);
		int currentYear = localTime->tm_year + 1900;
		int currentMonth = localTime->tm_mon + 1;
		int currentDay = localTime->tm_mday;
		int i = 0;
		//cout << expiryYear << " " << expiryMonth << " " << expiryYear << endl;
		cout << left << setw(6) << "No" << setw(15) << "Medicine" << setw(14) << "Product ID" << setw(13) << "Quantity" << setw(10) << "Price" << setw(15) << "Expiry Date" << setw(15) << "Manufacturing Date" << endl;
		cout << "-----------------------------------------------------------------------------------------------------" << endl;
		while (head_ref != NULL)
		{

			int expiryYear = stoi(head_ref->stockData->expiredDate.substr(6, 4));
			int expiryMonth = stoi(head_ref->stockData->expiredDate.substr(3, 2));
			int expiryDay = stoi(head_ref->stockData->expiredDate.substr(0, 2));
			//cout << expiryYear << " " << expiryMonth << " " << expiryYear << endl;
			if (currentYear > expiryYear || (currentYear == expiryYear && currentMonth > expiryMonth) || (currentYear == expiryYear && currentMonth == expiryMonth && currentDay > expiryDay)) {

				cout << left << setw(6) << ++i << setw(15) << head_ref->stockData->medicineName << setw(14) << head_ref->stockData->productID << setw(13) << head_ref->stockData->medicineQuantity << setw(10) << head_ref->stockData->price << setw(15) << head_ref->stockData->expiredDate << setw(15) << head_ref->stockData->issueDate << endl;

			}
			head_ref = head_ref->next;
		}

	}
	//////Check Expiry With File Handling
	void CheckExpiryHandling()
	{

	}
	void UpdateStock(StockNode* head_ref, string medicine)
	{
		int productid = stoi(medicine);

		while (head_ref != NULL)
		{
			if (head_ref->stockData->medicineName == medicine || head_ref->stockData->productID == productid)
			{
				int q;
				// quantity from user
				cout << "Update Medicine Quantity: " << endl;
				while (true)
				{
					cin >> q;
					if (q > 0)
					{
						break;
					}
					else
					{
						cout << "Medicine Quantity greater than 0" << endl;
					}
				}
				

				//Expiry Date('DD/MM/YYYY') 
				cout << "Enter Expiry Date('DD/MM/YYYY')" << endl;
				while (true)
				{
					cin >> head_ref->stockData->expiredDate;
					if (head_ref->stockData->expiredDate.length() == 10)
					{
						break;
					}
					else
					{
						cout << "Please enter the expiry date of this methed ('DD/MM/YYYY')" << endl;
					}
				}
				//Issue Date(DD/MM/YYYY)
				cout << "Enter Issue Date(DD/MM/YYYY)" << endl;

				while (true)
				{
					cin >> head_ref->stockData->issueDate;
					if (head_ref->stockData->issueDate.length() == 10)
					{
						break;
					}
					else
					{
						cout << "Please enter the expiry date of this methed ('DD/MM/YYYY')" << endl;
					}
				}
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
					head->stockData->price = price;
				}
			}
			head_ref = head_ref->next;
		}
	}
	//Display
	void Display(StockNode* head_ref)
	{
		int i = 0;
		cout << left << setw(6) << "No" << setw(15) << "Medicine" << setw(14) << "Product ID" << setw(13) << "Quantity" << setw(10) << "Price" << setw(15) << "Expiry Date" << setw(15) << "Manufacturing Date" << endl;
		cout << "-----------------------------------------------------------------------------------------------------" << endl;
		while (head_ref != NULL)
		{
			cout << left << setw(6) << ++i << setw(15) << head_ref->stockData->medicineName << setw(14) << head_ref->stockData->productID << setw(13) << head_ref->stockData->medicineQuantity << setw(10) << head_ref->stockData->price << setw(15) << head_ref->stockData->expiredDate << setw(15) << head_ref->stockData->issueDate << endl;
			head_ref = head_ref->next;
		}
	}
	//delete 
	void DeleteMedicine(StockNode* head_ref, string medicine)
	{

		int productid = stoi(medicine);
		StockNode* previous = head_ref;
		if (previous->stockData->medicineName == medicine || previous->stockData->productID == productid) {
			head = previous->next;
			delete previous;
			return;
		}
		StockNode* current = previous->next;
		while (current != NULL)
		{
			if (current->stockData->medicineName == medicine || current->stockData->productID == productid)
			{
				previous->next = current->next;
				delete current;
				return;
			}
			previous = current;
			current = current->next;
		}
	}
	//This Function is search Stock
	void SearchStock(StockNode* head_ref, string medicine)
	{
		int a;
		int productid = stoi(medicine);
		////		string a=s.substr(0,2);
		////		productid= stoi(a);
		//if (productid > 0)
		//{
		//	a= productid;
		//}

		while (head_ref != NULL)
		{
			if (head_ref->stockData->medicineName == medicine || head_ref->stockData->productID == productid)
			{
				cout << "Medicine Name: " << head_ref->stockData->medicineName << endl;
				cout << "Product ID: " << head_ref->stockData->productID << endl;
				cout << "Quantity: " << head_ref->stockData->medicineQuantity << endl;
				cout << "Price per Item: " << head_ref->stockData->price << endl;
				cout << "Expiry Date: " << head_ref->stockData->expiredDate << endl;
			}
			head_ref = head_ref->next;
		}
	}
	//employee RAndom ID
	/*int ProductIDRandom()
	{

		int randomNumber;
		srand(time(0));
			randomNumber = rand() % 4000 + 5000;
		return randomNumber;
	}*/
};

//this function is Load file in StockNode
/// <LoadFileStockNode>
void LoadFileStockNode()
{
	StockData s;
	//read data from file handling
	string medicinename, expirydate, issuedate;
	double priceMedicine;
	int medicinequantity, productID;

	StockNode* head, * curr;
	head = NULL;
	fstream fStock;
	fStock.open("StockData.txt", ios::in);
	{
		fStock >> medicinename >> priceMedicine >> medicinequantity >> productID >> expirydate >> issuedate;
		while (!fStock.eof())
		{
			curr = head;
			s.medicineName = medicinename;
			s.price = priceMedicine;
			s.medicineQuantity = medicinequantity;
			s.productID = productID;
			s.expiredDate = expirydate;
			s.issueDate = issuedate;
			StockData* s1 = new StockData(s.medicineName, s.price, s.medicineQuantity, s.productID, s.expiredDate, s.issueDate);
			StockNode* storeNode = new StockNode(s1);
			if (head == NULL)
			{
				head = storeNode;
			}
			else
			{
				while (curr->next != NULL)
				{
					curr = curr->next;
				}
				curr->next = storeNode;
			}

		}
	}
	fStock.close();
}
/// </LoadFileStockNode>


//this function is Check data in this form
bool isNumber(string s)
{
	for (int i = 0; i < s.length(); i++)
	{
		if (!isdigit(s[i]))
			return false;
	}
	return true;
}
string CheckDateCorrect(string date)
{
	while (true)
	{
		cin >> date;
		if (date.length() != 10)
		{
			cout << "Invalid input, please enter the date in the format 'DD/MM/YYYY'." << endl;
			continue;
		}

		if (date.substr(2, 1) != "/" || date.substr(5, 1) != "/")
		{
			cout << "Invalid input, please enter the date in the format 'DD/MM/YYYY'." << endl;
			continue;
		}

		string day = date.substr(0, 2);
		string month = date.substr(3, 2);
		string year = date.substr(6, 4);

		if (!isNumber(day) || !isNumber(month) || !isNumber(year))
		{
			cout << "Invalid input, please enter a valid date" << endl;
			continue;
		}

		int iDay = stoi(day);
		int iMonth = stoi(month);
		int iYear = stoi(year);

		if (iDay < 1 || iDay > 31)
		{
			cout << "Invalid day, please enter a day between 1 and 31." << endl;
			continue;
		}
		if (iMonth < 1 || iMonth > 12)
		{
			cout << "Invalid month, please enter a month between 1 and 12." << endl;
			continue;
		}
		if (iYear < 1999 || iYear>2050)
		{
			if (iYear < 1999 || iYear>2050)
			{
				cout << "Please enter B/W 2000 or 2050 " << endl;
			}
			else
			{
				cout << "Invalid year, please enter a valid year." << endl;
			}
			cout << "Invalid year, please enter a valid year." << endl;
			continue;
		}
		break;
	}
	return date;
}
//Main Function
int main()
{
	NodeBalance* head = new NodeBalance();
	//NodeBalance* head1 = new NodeBalance(15000);
	head->LoadFileBalance();
	LoadFileStockNode();
	system("Color E4");
	Stock stock;
	while (true)
	{
		menu:
		system("cls");
		cout << "\n\n\t\t\t\t=======================================================================";
		cout << "\n\t\t\t\t=======================================================================" << endl << endl;

		cout << "\t\t\t\t\tWELCOME TO PHARMACY MANAGEMENT SYSTEM" << endl;

		cout << endl << "\t\t\t\t=======================================================================";
		cout << endl << "\t\t\t\t=======================================================================";


		cout << endl << "\n\n\t\t\t\t    ::MAIN MENU::" << endl;
		cout << endl;
		cout << "\n\t\t\t\t1. Add Stock";
		cout << "\n\t\t\t\t2. Search Medicine";
		cout << "\n\t\t\t\t3. Update Stock";
		cout << "\n\t\t\t\t4. Remove Medicine" << endl;
		cout << "\t\t\t\t5. Check Expiry" << endl;
		cout << "\t\t\t\t6. Display Stock" << endl;
		cout << "\t\t\t\t7. " << endl;
		cout << "\t\t\t\t8. EXIT";
		cout << endl;

		int option;
		cout << endl << "\t\t\t\tSelect Your Option (1-8): ";
		cin >> option;

		switch (option)
		{
		case 1:
		{
			StockData s;
			system("cls");
			//Check  duplicate Medicine if duplicate 
			int ch = 0;
			cout << "Enter Medicine Name:" << endl;
			while (true)
			{
			a:
				cin >> s.medicineName;
				StockNode* check = stock.GetHead();
				while (check != NULL)
				{
					if (s.medicineName == check->stockData->medicineName)
					{
						ch == 1;
						cout << "Already exist medicine" << endl;
						goto a;
					}
					check = check->next;
				}
				if (ch == 1)
				{
					cout << "Already exist medicine" << endl;
				}
				else
				{
					break;
				}
			}
			int c = 0;
			//product ID Check duplicate
			/// <product ID>
			cout << "Enter Medicine Product ID:" << endl;
			string productID;
			while (true)
			{
				int h = 0;
				try
				{
				p:
					cin >> productID;
					if (!(isdigit))
						throw ("Invalid input");

					int int_productID = stoi(productID);
					if (int_productID <= 0)
						throw ("Invalid input");
					while (true)
					{
						StockNode* check = stock.GetHead();
						while (check != NULL)
						{
							if (int_productID == check->stockData->productID)
							{
								ch++;
								cout << "Already exist medicine" << endl;
								goto p;
							}
							check = check->next;
						}
						s.productID = int_productID;
						break;
					}
					break;
				}
				catch (exception e)
				{
					cout << e.what() << endl;
				}
			}
			/// </product ID>
			/// <product ID></product ID>


			//Price
			string price;
			cout << "Enter Medicine Price: " << endl;
			while (true)
			{
				try
				{
					cin >> price;
					if (!(isdigit))
						throw ("Invalid input");

					double int_price = stoi(price);
					if (int_price <= 0)
						throw ("Invalid input");
					s.price = int_price;
					break;
				}
				catch (exception e)
				{
					cout << "Invalid input" << endl;
				}
			}
			//quantity from user
			cout << "Enter Medicine Quantity: " << endl;
			string Quantity;
			while (true)
			{
				try
				{
					cin >> Quantity;
					if (!(isdigit))
						throw ("Invalid input");

					int int_Quantity = stoi(Quantity);
					if (int_Quantity <= 0)
						throw ("Invalid input, please enter a positive integer value.");
					s.medicineQuantity = int_Quantity;
					break;
				}
				catch (exception e)
				{
					cout << e.what() << endl;
				}
			}

			/// <StockBill>
			double billStock;
			billStock = s.price * s.medicineQuantity;
			if (billStock < head->pharmacybalance)
			{
				double balance = head->pharmacybalance - billStock;
				head->updateBalance(balance);
			}
			else if (billStock > head->pharmacybalance)
			{
				cout << "Balance is Low" << endl;
				system("pause");
				goto menu;
				break;
			}
			/// </StockBill>
		
			//Issue Date('DD/MM/YYYY') 
			cout << "Enter Issue Date(DD/MM/YYYY)" << endl;
			s.issueDate = CheckDateCorrect(s.issueDate);
			//Expiry Date('DD/MM/YYYY')
			cout << "Enter Expiry Date('DD/MM/YYYY')" << endl;
			//option Goto data
			while (true)
			{
				s.expiredDate = CheckDateCorrect(s.expiredDate);
				//issue data
				int issueDay = stoi(s.issueDate.substr(0, 2));
				int issueMonth = stoi(s.issueDate.substr(3, 2));
				int issueYear = stoi(s.issueDate.substr(6, 4));
				//Expiry date
				cout << issueYear << " " << issueMonth << " " << issueDay << endl;
				int expiryDay = stoi(s.expiredDate.substr(0, 2));
				int expiryMonth = stoi(s.expiredDate.substr(3, 2));
				int expiryYear = stoi(s.expiredDate.substr(6, 4));
				cout << expiryYear << " " << expiryMonth << " " << expiryDay << endl;
				if ((expiryYear <= issueYear) && (expiryMonth <= issueMonth) && (expiryDay <= issueDay))
				{
					cout << "Expiry Date is greater than issue date " << endl;
				
				}
				else
				{
					break;
				}
			}
			
			//balance store
			

			/// <returns></returns>
			
			stock.AddStock(new StockData(s.medicineName, s.price, s.medicineQuantity, s.productID, s.expiredDate, s.issueDate));
			break;
		}
		case 2:
		{
			system("cls");
			string medicine;
			cout << "Enter Medicine Name OR Product ID: " << endl;;
			cin >> medicine;
			stock.SearchStock(stock.GetHead(), medicine);
			break;
		}
		case 3:
		{
			system("cls");
			string medicine;
			cout << "Enter Medicine Name OR Product ID: " << endl;;
			cin >> medicine;
			stock.UpdateStock(stock.GetHead(), medicine);
			break;
		}
		case 4:
		{
			system("cls");
			string medicine;
			cout << "Enter Medicine Name OR Product ID: " << endl;;
			cin >> medicine;
			stock.DeleteMedicine(stock.GetHead(), medicine);

			break;
		}

		case 5:
		{
			system("cls");
			stock.CheckExpiry(stock.GetHead());
			break;
		}
		case 6:
		{
			system("cls");
			stock.Display(stock.GetHead());
			break;
		}
		case 7:
		{
			system("cls");

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
