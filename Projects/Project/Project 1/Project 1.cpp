#include <iostream>
#include <ctime>
#include <string>
#include <iomanip>
#include <stdlib.h>
#include <sstream>//only used for purchasedDate(stringstream);
#include<fstream>

using namespace std;

//Stock Data
string CheckDateCorrect(string date);
int main();
class StockData
{
public:
	string medicineName;
	double price;
	int medicineQuantity;
	int productID;
	string expiredDate;
	string issueDate;
	int billNumber;
	//double pharmacyinbalance;
	StockData()
	{
		medicineName = "";
	}
	//filestock << medicineName << " " << price << " " << medicineQuantity << " " << productID << " " << expiry << " " << issueDate << endl;

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


class EmployeeData {
public:
	string name;
	string phone;
	int employeeID;
	int age;

	EmployeeData() {

	}

	EmployeeData(string name, int employeeID, int age)
	{
		this->name = name;
		this->phone = phone;
		this->age = age;
		this->employeeID = employeeID;
	}
	~EmployeeData() {

	}
};


class NodeBalance
{
public:
	double pharmacybalance;
	NodeBalance* next;
	NodeBalance* head = NULL;
	NodeBalance() {

	}
	
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
		head->pharmacybalance = newBal;
		fstream file, file1;
		file.open("Balance.txt", ios::in);
		file1.open("Balance1.txt", ios::app | ios::out);
		file >> newBal;
		
		while (!file.eof())
		{

			file1 << head->pharmacybalance;
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


//Node Employee
class employeeNode {
public:
	EmployeeData* employeeData;
	employeeNode* next;
	employeeNode* head = NULL;
};



//Create Stock Node
class StockNode
{
public:
	StockNode* head;
	StockData* stockData;
	StockNode* next;
	
	StockNode() {
	
	}
	
	StockNode(StockData* data)
	{
		stockData = data;
		next = NULL;
	}

};


//Empolyee Class
class employee :public employeeNode, public EmployeeData {
public:
	employee() {

	}
	void employeeManagement() {
		do {
			int choice;

			system("cls");
			cout << "\n\n\t\t\t=======================================================================";
			cout << "\n\t\t\t=======================================================================" << endl << endl;

			cout << "\t\t\t\t\tWELCOME TO PHARMACY MANAGEMENT SYSTEM" << endl;

			cout << endl << "\t\t\t=======================================================================";
			cout << endl << "\t\t\t=======================================================================" << endl << endl;

			cout << "==========Select an Option==========" << endl << endl;
			cout << "1- Add Employee." << endl;
			cout << "2- Remove an Employee." << endl;
			cout << "3- Update an Employee." << endl;
			cout << "4- Display Employees." << endl;
			cout << "5- Exit." << endl;
			cin >> choice;

			switch (choice) {
			case 1: {
				system("cls");

				string na;
				cout << "Name: " << endl;
				cin >> na;

				int age;
				cout << "Age: " << endl;
				cin >> age;
				while (1)
				{
					if (cin.fail())
					{
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "Please Enter a valid input again: " << endl;
						cin >> age;
					}
					if (!cin.fail())
						break;
				}

				while (age < 18 || age > 55) {
					cout << "Given employee is not eligible for this job!" << endl;
					cin >> age;
					while (1)
					{
						if (cin.fail())
						{
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
							cout << "Please Enter a valid input again: " << endl;
							cin >> age;
						}
						if (!cin.fail())
							break;
					}
				}

				int id;
				id = random();
				cout << "Your Employee ID is: " << id << endl;

				EmployeeData* e = new EmployeeData(na, id, age);
				addEmployee(e);
				system("PAUSE");
				break;
			}

			case 2: {
				system("cls");
				int n;
				cout << "Enter ID of Employee to remove:" << endl;
				cin >> n;
				while (1)
				{
					if (cin.fail())
					{
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "Please Enter a valid input again: " << endl;
						cin >> n;
					}
					if (!cin.fail())
						break;
				}
				removeEmployee(&head, n);
				cout << "Employee removed Successfully..." << endl;
				system("PAUSE");
				break;
			}

			case 3: {
				system("cls");
				int num;
				cout << "Enter ID of the Employee you need to Update: " << endl;
				cin >> num;
				while (1)
				{
					if (cin.fail())
					{
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "Please Enter a valid input again: " << endl;
						cin >> num;
					}
					if (!cin.fail())
						break;
				}

				updateEmployee(num, head);
				break;
			}

			case 4: {
				system("cls");
				cout << "----------Employee List----------" << endl << endl;
				displayEmployee(head);
				system("PAUSE");
				break;
			}

			case 5: {
				exit(1);
				break;
			}

			default: {
				while (1)
				{
					if (cin.fail())
					{
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "Please Enter a valid input again: " << endl;
						cin >> choice;
					}
					if (!cin.fail())
						break;
				}
			}
			}
		} while (true);
	}


	int random() {
		srand(time(0));
		int r = 1 + rand() % 1000;
		return r;
	}


	void login() {

		string userName;
		string userPassword;
		int loginAttempt = 5;

		while (loginAttempt > 0)
		{
			cout << "Please enter your username: ";
			cin >> userName;
			cout << "Please enter your password: ";
			cin >> userPassword;

			if (userName == "momin" && userPassword == "momin123")
			{
				cout << "Welcome Momin!\n";
				break;
			}
			else if (userName == "fahad" && userPassword == "fahad123")
			{
				cout << "Welcome Fahad!\n";
				break;
			}
			else
			{
				cout << "Invalid login attempt. Please try again.\n" << '\n';
				loginAttempt--;
				cout << "You have " << loginAttempt << " attempts remaining." << endl;
			}
		}
		if (loginAttempt == 0)
		{
			cout << "Too many login attempts! The program will now terminate.";
			exit(1);
		}
	}


	void addEmployee(EmployeeData* data) {
		ofstream add;

		employee* newEmp = new employee();
		newEmp->employeeData = data;

		newEmp->next = head;
		head = newEmp;

		cout << "Employee Added Successfully... " << endl;
		add.open("employee.txt", ios::app);
		add << "Name: " << data->name << endl;
		add << "Age: " << data->age << endl;
		add << "ID: " << data->employeeID << endl;
		add << "-----------------" << endl << endl;
		add.close();
	}

	void updateEmployee(int i, employeeNode* head_ref) {
		int a;

		if (head == NULL) {
			cout << "No Employees present." << endl;
			return;
		}

		cout << "Enter updated age of employee: " << endl;
		cin >> a;

		while (1)
		{
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Please Enter a valid age again: " << endl;
				cin >> a;
			}
			if (!cin.fail())
				break;
		}

		while (head_ref->next != NULL) {
			if (head_ref->employeeData->employeeID == i) {
				head_ref->employeeData->age = a;
				cout << "Age of employee updated..." << endl;
			}

			head_ref = head_ref->next;
		}

		cout << "Record does not exist in the list!" << endl;
	}

	void removeEmployee(employeeNode** head_ref, int key) {
		employeeNode* temp = *head_ref;
		employeeNode* prev = NULL;

		if (temp != NULL && temp->employeeData->employeeID == key) {
			*head_ref = temp->next;
			free(temp);
			return;
		}

		while (temp != NULL && temp->employeeData->employeeID != key) {
			prev = temp;
			temp = temp->next;
		}


		if (temp == NULL)
			cout << "No such ID is present!";

		// Remove the node
		prev->next = temp->next;

		free(temp);
	}


	void displayEmployee(employeeNode* head_ref) {

		ifstream r;
		string r1;

		cout << "Existing Employees: " << endl;
		cout << "----------------------" << endl;

		if (head_ref == NULL) {
			r.open("employee.txt");
			if (r.is_open()) {

				while (!r.eof()) {
					getline(r, r1);
					cout << r1 << endl;
				}
			}
			r.close();
		}

		else {
			while (head_ref != NULL) {
				cout << "Name: " << head_ref->employeeData->name << endl;
				cout << "Age: " << head_ref->employeeData->age << endl;
				cout << "ID: " << head_ref->employeeData->employeeID << endl;
				cout << "----------------------" << endl << endl;
				head_ref = head_ref->next;
			}
		}
	}
};


//Stock Class
class Stock:public StockNode, public StockData
{
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
		fstream file;
		StockNode* storeNode = new StockNode(data);
		StockNode* curr;
		curr = head;
		if (head == NULL)
		{
			head = storeNode;
			file.open("StockData.txt", ios::app | ios::out);
			file << head->stockData->medicineName << " " << head->stockData->price << " " << head->stockData->medicineQuantity << " " << head->stockData->productID << " " << head->stockData->expiredDate << " " << head->stockData->issueDate << endl;
			file.close();

		}
		else
		{
			curr = head;
			while (curr->next != NULL)
			{
				curr = curr->next;
			}
			curr->next = storeNode;
			file.open("StockData.txt", ios::app | ios::out);
			file << curr->next->stockData->medicineName << " " << curr->next->stockData->price << " " << curr->next->stockData->medicineQuantity << " " << curr->next->stockData->productID << " " << curr->next->stockData->expiredDate << " " << curr->next->stockData->issueDate << endl;
			file.close();

		}
		cout << " Medicine Added Successfully... " << endl;
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


	//Update Stock
	void UpdateStock(StockNode* head_ref, int medicine)
	{
		
		int found = 0;
		StockData s;
		while (head_ref != NULL)
		{
			if (medicine==head_ref->stockData->productID )
			{
				found++;
				int q;
				// quantity from user
				cout << "Update Medicine Quantity: " << endl;
				while (true)
				{
					try
					{
						string s;
						cin >> s;
						if (!(isdigit))
							throw ("Invalid input");

						int qn = stoi(s);
						if (qn <= 0)
							throw ("Invalid input");
						q = qn;
						break;
					}
					catch (exception e)
					{
						cout << "Only Digits input" << endl;
					}
				}
				//adding quantity in node 
				head_ref->stockData->medicineQuantity = head_ref->stockData->medicineQuantity + q;
				//Issue Date(DD/MM/YYYY)
				cout << "Enter Issue Date(DD/MM/YYYY)" << endl;
				head_ref->stockData->issueDate = CheckDateCorrect(s.issueDate);
				//Expiry Date('DD/MM/YYYY') 
				cout << "Enter Expiry Date('DD/MM/YYYY')" << endl;
				while (true)
				{
					head_ref->stockData->expiredDate = CheckDateCorrect(s.expiredDate);
					//issue data
					int issueDay = stoi(head_ref->stockData->issueDate.substr(0, 2));
					int issueMonth = stoi(head_ref->stockData->issueDate.substr(3, 2));
					int issueYear = stoi(head_ref->stockData->issueDate.substr(6, 4));
					//Expiry date
					//cout << issueYear << " " << issueMonth << " " << issueDay << endl;
					int expiryDay = stoi(head_ref->stockData->expiredDate.substr(0, 2));
					int expiryMonth = stoi(head_ref->stockData->expiredDate.substr(3, 2));
					int expiryYear = stoi(head_ref->stockData->expiredDate.substr(6, 4));
					//cout << expiryYear << " " << expiryMonth << " " << expiryDay << endl;
					if ((expiryYear <= issueYear) && (expiryMonth <= issueMonth) && (expiryDay <= issueDay))
					{
						cout << "Expiry Date is greater than issue date " << endl;
					}
					else
					{
						break;
					}
				}


				int p;
				cout << "Price update: " << endl;
				cout << "\t1. Yes" << endl;
				cout << "\t2. No" << endl;

				while (true)
				{
					try
					{
						string ch;
						cin >> ch;
						if (!(isdigit))
							throw ("Invalid input");

						double a = stoi(ch);
						if (a <= 0)
							throw ("Invalid input");
						p = a;
						break;
					}
					catch (exception e)
					{
						cout << "Invalid input" << endl;
					}
				}
				if (p == 1)
				{
					int price_;
					cout << "New Price: " << endl;
					//cin >> price;
					cout << "Enter Medicine Price: " << endl;
					while (true)
					{
						try
						{
							string price;
							cin >> price;
							if (!(isdigit))
								throw ("Invalid input");

							double int_price = stoi(price);
							if (int_price <= 0)
								throw ("Invalid input");
							price_ = int_price;
							break;
						}
						catch (exception e)
						{
							cout << "Invalid input" << endl;
						}
					}
					head_ref->stockData->price = price_;
				}
				else if (p == 2)
				{
					system("pause");
				}
				else
				{
					cout << "Press 1 or 2" << endl;
				}
				//Update Stock in File Handling 
				UpdateStockFile(head_ref->stockData->medicineName, head_ref->stockData->price, head_ref->stockData->medicineQuantity, head_ref->stockData->productID, head_ref->stockData->expiredDate, head_ref->stockData->issueDate);
			}
			head_ref = head_ref->next;
		}
		if (found == 0)
		{
			cout << "Not found" << endl;
		}
	}
	
	
	void UpdateStockFile(string med, double p, int q, int pID, string expiry, string issue)
	{
		StockData s;
		fstream update, update1;
		update.open("StockData.txt", ios::in);
		{
			update1.open("update.txt", ios::out | ios::app);
			update >> s.medicineName >> s.price >> s.medicineQuantity >> s.productID >> s.expiredDate >> s.issueDate;
			while (!update.eof())
			{
				if (med == s.medicineName || pID == s.productID)
				{
					update1 << med << " " << p << " " << q << " " << pID << " " << expiry << " " << issue << endl;
				}
				else
				{
					update1 << s.medicineName << s.price << s.medicineQuantity << s.productID << s.expiredDate << s.issueDate;
				}
				update >> s.medicineName >> s.price >> s.medicineQuantity >> s.productID >> s.expiredDate >> s.issueDate;
			}
		}
		update.close();
		update1.close();
		remove("StockData.txt");
		rename("update.txt", "StockData.txt");
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
	
	
	void DeleteMedicine()
	{
		int found = 0;
		int medicine;
		cout << "Enter Medicine Product ID: " << endl;;

		while (true)
		{
			try
			{
				string s;
				cin >> s;
				if (!(isdigit))
					throw ("Invalid input");

				int qn = stoi(s);
				if (qn <= 0)
					throw ("Invalid input");
				medicine = qn;
				break;
			}
			catch (exception e)
			{
				cout << "Please enter medicine product ID:" << endl;
			}
		}
		StockNode* current = head;
		StockNode* temp = NULL;
		
		while (current != NULL)
		{
			if (current->stockData->productID == medicine)
			{
				if (current == head)
					head = current->next;
				else
					temp->next = current->next;
				DeleteMedicineFile(current->stockData->medicineName);
				delete current;
				found++;
				break;
			}
			temp = current;
			current = current->next;
		}
		
		if (found == 0)
		{
			cout << "Data Not Found" << endl;
		}
	}

	//delete 
	//void DeleteMedicine(StockNode* head_ref, string medicine)
	//{
	//	NodeBalance* balance;
	//	int productid = stoi(medicine);
	//	StockNode* previous = head_ref;

	//	if (previous->stockData->medicineName == medicine || previous->stockData->productID == productid)
	//	{
	//		//update balance
	//		//delete file
	//		DeleteMedicineFile(previous->stockData->medicineName);
	//		//delete Node
	//		head = previous->next;
	//		delete previous;
	//		
	//	}
	//	StockNode* current = previous->next;
	//	while (current != NULL)
	//	{
	//		if (current->stockData->medicineName == medicine || current->stockData->productID == productid)
	//		{
	//			previous->next = current->next;
	//			//update balance
	//			DeleteMedicineFile(current->stockData->medicineName);
	//			delete current;
	//			
	//		}
	//		previous = current;
	//		current = current->next;
	//	}


	//}
	
	//delete medicine from file
	void DeleteMedicineFile(string medicine)
	{
		int found = 0;
		StockData s;
		fstream f, f1;
		f.open("StockData.txt", ios::in);
		{
			f1.open("s.txt", ios::out | ios::app);
			f >> s.medicineName >> s.price >> s.medicineQuantity >> s.productID >> s.expiredDate >> s.issueDate;
			while (!f.eof())
			{
				if (s.medicineName == medicine)
				{
					cout << "Remove Medicine: " << medicine << endl;
					found++;
				}
				else
				{
					f1 << s.medicineName << " " << s.price << " " << s.medicineQuantity << " " << s.productID << " " << s.expiredDate << " " << s.issueDate << endl;
				}
				f >> s.medicineName >> s.price >> s.medicineQuantity >> s.productID >> s.expiredDate >> s.issueDate;
			}
			if (found == 0)
			{
				cout << "Medicine not found!" << endl;
			}
			f1.close();
			f.close();
			remove("StockData.txt");
			rename("s.txt", "StockData.txt");
		}
	}


	//This Function is search Stock
	void SearchStock(StockNode* head_ref)
	{
		int medicine;
		cout << "Enter Medicine Product ID: " << endl;;

		while (true)
		{
			try
			{
				string s;
				cin >> s;
				if (!(isdigit))
					throw ("Invalid input");

				int qn = stoi(s);
				if (qn <= 0)
					throw ("Invalid input");
				medicine = qn;
				break;
			}
			catch (exception e)
			{
				cout << "Please enter medicine product ID:" << endl;
			}
		}

		while (head_ref != NULL)
		{
			if (head_ref->stockData->productID == medicine)
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
	
	
	//this function is Load file in StockNode
	void LoadFile()
	{
		StockData s;
		StockNode* curr;
		//filestock << medicineName << " " << price << " " << medicineQuantity << " " << productID << " " << expiry << " " << issueDate << endl;
		fstream file;
		file.open("StockData.txt", ios::in);
		if (!file)
		{
			cout << "File Is Empty" << endl;
		}
		else
		{
			file >> s.medicineName >> s.price >> s.medicineQuantity >> s.productID >> s.expiredDate >> s.issueDate;
			while (!file.eof())
			{
				StockNode* newNode = new StockNode(new StockData(s.medicineName, s.price, s.medicineQuantity, s.productID, s.expiredDate, s.issueDate));
				if (head == NULL)
				{
					head = newNode;
				}
				else
				{
					curr = head;
					while (curr->next != NULL)
					{
						curr = curr->next;
					}
					curr->next = newNode;
				}
				file >> s.medicineName >> s.price >> s.medicineQuantity >> s.productID >> s.expiredDate >> s.issueDate;
			}
		}
		file.close();
	}

};


//Sale class
class Sale
{
private:
	StockData s;
	double totalBill;
	int itemsPurchased;
	string customerName;
	stringstream purchasedDate;//using library for <sstream>
	int billNumber;

public:
	
	Sale()
	{
		billNumber = 0;
		time_t now = time(nullptr);
		struct tm timeInfo;
		localtime_s(&timeInfo, &now);
		purchasedDate << timeInfo.tm_hour << ":" << timeInfo.tm_min << ":" << timeInfo.tm_sec << "-" << timeInfo.tm_mday << "/" << timeInfo.tm_mon + 1 << "/" << timeInfo.tm_year + 1900;
	}
	
	void SaleMedicine(StockNode* head_ref)
	{
		StockNode* curr = head_ref;//check stock availble
		int found = 0;
		string medicine;
	p://itemsPurchased
		cout << "Enter Medicine Product ID: " << endl;;
		while (true)
		{
			cin >> medicine;
			try
			{
				// Check if the input contains only alphabets and digits
				for (int i = 0; i < medicine.length(); i++)
				{
					if (!isalnum(medicine[i]))
					{
						throw invalid_argument("Invalid input: Name OR Product ID ");
					}
				}
				break;
			}
			catch (exception e)
			{
				cout << e.what() << endl;
			}
		}
		
		int product_ID = stoi(medicine);
		while (head_ref != NULL)
		{
			if (head_ref->stockData->medicineName == medicine || head_ref->stockData->productID == product_ID)
			{
				//customerName
				cout << "Enter Customer Name: " << endl;
				while (true)
				{
					cin >> customerName;
					try
					{
						// Check if the input contains only alphabets and digits
						for (int i = 0; i < medicine.length(); i++)
						{
							if (!isalnum(medicine[i]))
							{
								throw invalid_argument("Invalid input:Enter Customer Name:  ");
							}
						}
						break;
					}
					catch (exception e)
					{
						cout << e.what() << endl;
					}
				}
				//purchased medicine item
				cout << "How many items to purchased" << endl;
				while (true)
				{
					try
					{
						//int itemsPurchased;
						cin >> itemsPurchased;
						if (!(isdigit))
							throw ("Invalid input");

						//double int_price = stoi(price);
						if (itemsPurchased <= 0)
							throw ("Invalid input");
						break;
					}
					catch (exception e)
					{
						cout << "Invalid input" << endl;
					}
				}
				//check stock availble
				if (itemsPurchased < head_ref->stockData->medicineQuantity)
				{

				}
				else if (itemsPurchased > head_ref->stockData->medicineQuantity)
				{
					cout << "Total Items Avalible: " << head_ref->stockData->medicineQuantity << endl;
					if (head_ref->stockData->medicineQuantity == 0)
					{
						system("pause");
					}
					else
					{
						goto p;
					}
				}

				int discount=0;
				//cout << "Discount: " << endl;
				//while (true)
				//{
				//	try
				//	{
				//	d:
				//		string a;
				//		cin >> a;
				//		if (!(isdigit))
				//			throw ("Invalid input");
				//		int a_ = stoi(a);
				//		//double int_price = stoi(price);
				//		if (a_ <= -1)
				//			throw ("Invalid input");
				//		discount = a_;
				//		while (true)
				//		{
				//			if (discount >= 0 && discount <= 10)
				//			{
				//				break;
				//			}
				//			else
				//			{
				//				cout << "Only Discount 1 to 10%: " << endl;
				//				goto d;
				//			}
				//		}
				//		break;
				//	}
				//	catch (exception e)
				//	{
				//		cout << "Invalid input" << endl;
				//	}
				//}

				//time purchased 
				//total bill
				double price = (head_ref->stockData->price / 10) + head_ref->stockData->price;
				//double dis = head_ref->stockData->price - discount;

				double totalBill = price * itemsPurchased;
				billNumber += 1;
				//	int itemAvaliblenow;
				head_ref->stockData->medicineQuantity = head_ref->stockData->medicineQuantity - itemsPurchased;
				HistoryPurcheasedFile(customerName, itemsPurchased, purchasedDate.str(), totalBill, discount, head_ref->stockData->medicineName);
				updateStock(head_ref->stockData->medicineName, head_ref->stockData->medicineQuantity);
				//Recie(pt
				Reciept(customerName, itemsPurchased, purchasedDate.str(), discount, totalBill);
				//store total bil

				balance(totalBill);
				found++;
			}
			head_ref = head_ref->next;
		}

		if (found == 0)
		{
			cout << "Medicine are not avalible" << endl;
		}
	}
	
	
	//Purchased History
	void HistoryPurcheasedFile(string cName, int items, string time, int tBill, int discont,string m)
	{
		fstream file;
		file.open("HistoryPurchased.txt", ios::app | ios::out);
		file << cName << " " << items << " " << time.c_str() << " " << tBill << " " << discont<<" "<<m << endl;
		file.close();
	}
	
	
	void HistoryPurcheasedShow()
	{
		int a = 0;
		string cName; int items; string time; int discont; double tBill;string m;
		fstream f;
		f.open("HistoryPurchased.txt", ios::in);
		if (!f)
		{
			cout << "No sales were made" << endl;
		}
		else
		{
			cout << left << setw(6) << "No" << setw(15) << "Medicine Name" << setw(15) << "Customer Name" << setw(27) << "Purchased Time" << setw(13) << "Quantity"   << setw(15) << "Total Bill" << endl;
			cout << "-----------------------------------------------------------------------------------------------------" << endl;
			f >> cName >> items >> time >> tBill >> discont>>m;
			while (!f.eof())
			{
				cout << left << setw(6) << ++a << setw(15) << m << setw(15) << cName << setw(27) << time.c_str() << setw(13) << items  << setw(15) << tBill << endl;
				f >> cName >> items >> time >> tBill >> discont>>m;
			}
		}
		f.close();
	}
	
	
	//Update Stock
	void updateStock(string medName, int item)
	{
		fstream file, file1;
		file.open("StockData.txt", ios::in);
		{
			file1.open("data1.txt", ios::out | ios::app);
			file >> s.medicineName >> s.price >> s.medicineQuantity >> s.productID >> s.expiredDate >> s.issueDate;
			while (!file.eof())
			{
				if (medName == s.medicineName)
				{
					file1 << medName << " " << s.price << " " << item << " " << s.productID << " " << s.expiredDate << " " << s.issueDate << endl;
				}
				else
				{
					file1 << s.medicineName << " " << s.price << " " << s.medicineQuantity << " " << s.productID << " " << s.expiredDate << " " << s.issueDate << endl;
				}
				file >> s.medicineName >> s.price >> s.medicineQuantity >> s.productID >> s.expiredDate >> s.issueDate;
			}
		}

		file.close();
		file1.close();
		remove("StockData.txt");
		rename("data1.txt", "StockData.txt");
	}

	
	//store balance
	void balance(double bal)
	{
		fstream f;

		double b;
		fstream file, file1;
		file.open("balance.txt", ios::in);
		if (!file)
		{
			f.open("balance.txt", ios::out | ios::app);
			f << bal;
			f.close();
		}
		else
		{
			file1.open("balance1.txt", ios::out | ios::app);
			file >> b;
			while (!file.eof())
			{
				double balance = b + bal;
				file1 << balance;
				file >> b;
			}

		}
		file.close();
		file1.close();
		remove("balance.txt");
		rename("balance1.txt", "balance.txt");
	}
	
	
	//Reciept
	void Reciept(string cName, int item, string date, int discount, double totalBill)
	{
		system("cls");
		string a, b, c;
		a = to_string(discount);
		b = to_string(item);
		c = to_string(totalBill);
		cout << endl << endl;
		cout << "\t\t-----------------------------------------\n\t\t-\t\t\t\t\t-" << endl;
		cout << "\t\t-\t   Welcome to Pharmacy\t\t-" << endl;
		cout << "\t\t-\t   \t\t\t\t-" << endl;

		cout << "\t\t-----------------------------------------\n\t\t-\t\t\t\t\t-" << endl;
		cout << "\t\t-" << setw(15) << "   Purchased Time: " << date << "  -\n\t\t- \t\t\t\t\t- " << endl;
		cout << "\t\t-" << left << setw(39) << "   Customer Name: " + cName << "-\n\t\t- \t\t\t\t\t- " << endl;
		cout << "\t\t-" << left << setw(39) << "   Purchased Quantity: " + b << "-\n\t\t- \t\t\t\t\t- " << endl;
		cout << "\t\t-----------------------------------------\n\t\t-\t\t\t\t\t-" << endl;
		cout << "\t\t-" << left << setw(16) << "\t\tTotal Bill: " + c << "    -\n\t\t- \t\t\t\t\t- " << endl;
		cout << "\t\t-" << left << setw(33) << "\tThanks for coming..." << "-\n\t\t- \t\t\t\t\t- " << endl;
		cout << "\t\t-----------------------------------------\n\t" << endl;
	}
};



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



class ManagementStock
{
public:
	void Managementstock()
	{
		StockNode* head_ref = NULL;
		double pharmacybalance;
		Stock stock;
		stock.LoadFile();
		NodeBalance* head = NULL;
		while (head != NULL)
		{
			pharmacybalance = head->pharmacybalance;
			head = head->next;
		}
		NodeBalance* head1 = new NodeBalance();
		head = head1;
		head->LoadFileBalance();
		

		while (true)
		{

			system("cls");
			cout << "\n\n\t\t\t=======================================================================";
			cout << "\n\t\t\t=======================================================================" << endl << endl;

			cout << "\t\t\t\t\tWELCOME TO PHARMACY MANAGEMENT SYSTEM" << endl;

			cout << endl << "\t\t\t=======================================================================";
			cout << endl << "\t\t\t=======================================================================";


			cout << endl << "==========MAIN MENU==========" << endl;
			cout << endl;
			cout << "1. Add Stock" << endl;
			cout << "2. Search Medicine" << endl;
			cout << "3. Update Stock" << endl;
			cout << "4. Remove Medicine" << endl;
			cout << "5. Check Expiry" << endl;
			cout << "6. Display Stock" << endl;
			cout << "7. Sell Medicine" << endl;
			cout << "8. Check Selling" << endl;
			cout << "9. Go Back";
			cout << endl;

			int option;
			cout << endl << "\t\t\t\tSelect Your Option (1-8): ";
			cin >> option;

			while (1)
			{
				if (cin.fail())
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Please Enter a valid input again: " << endl;
					cin >> option;
				}
				if (!cin.fail())
					break;
			}

			while (option < 1 && option > 9) {

				cout << "Please choose a valid option!" << endl;
				cin >> option;

				while (1)
				{
					if (cin.fail())
					{
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "Please Enter a valid input again: " << endl;
						cin >> option;
					}
					if (!cin.fail())
						break;
				}
			}
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
				a://Already exist medicine use goto
					cin >> s.medicineName;
					try
					{
						// Check if the input contains only alphabets and digits
						for (int i = 0; i < s.medicineName.length(); i++)
						{
							if (!isalnum(s.medicineName[i]))
							{
								throw invalid_argument("Invalid input:only alphabets and digits ");
							}
						}
						while (true)
						{
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
						break;

					}
					catch (exception e)
					{
						cout << e.what() << endl;
					}
				}

				int c = 0;
				//product ID Check duplicate
				// <product ID>
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
						cout << "Invalid input" << endl;
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
				//Issue Date('DD/MM/YYYY') 
				cout << "Enter Issue Date(DD/MM/YYYY)" << endl;
				s.issueDate = CheckDateCorrect(s.issueDate);
				//Expiry Date('DD/MM/YYYY')
				cout << "Enter Expiry Date('DD/MM/YYYY')" << endl;
				//s.expiredDate = CheckDateCorrect(s.expiredDate);
				while (true)
				{
					s.expiredDate = CheckDateCorrect(s.expiredDate);
					//issue data
					int issueDay = stoi(s.issueDate.substr(0, 2));
					int issueMonth = stoi(s.issueDate.substr(3, 2));
					int issueYear = stoi(s.issueDate.substr(6, 4));
					//Expiry date
					//cout << issueYear << " " << issueMonth << " " << issueDay << endl;
					int expiryDay = stoi(s.expiredDate.substr(0, 2));
					int expiryMonth = stoi(s.expiredDate.substr(3, 2));
					int expiryYear = stoi(s.expiredDate.substr(6, 4));
					//cout << expiryYear << " " << expiryMonth << " " << expiryDay << endl;
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
				
				stock.SearchStock(stock.GetHead());
				break;
			}
			
			case 3:
			{
				system("cls");
				int medicine;
				cout << "Enter Medicine Product ID: " << endl;;
				
				while (true)
				{
					try
					{
						string s;
						cin >> s;
						if (!(isdigit))
							throw ("Invalid input");

						int qn = stoi(s);
						if (qn <= 0)
							throw ("Invalid input");
					    medicine = qn;
						break;
					}
					catch (exception e)
					{
						cout << "Please enter medicine product ID:" << endl;
					}
				}
				stock.UpdateStock(stock.GetHead(), medicine);
				break;
			}
			
			case 4:
			{
				system("cls");
				stock.DeleteMedicine();
				break;
			}

			case 5:
			{
				system("cls");
				stock.CheckExpiry(stock.GetHead());
				cout << endl << endl;
				cout << "Delete Expiry Item" << endl;
				int c;
				cout << "\t1. Yes" << endl;
				cout << "\t2. No" << endl;

				while (true)
				{
					try
					{
						string a;
						cin >> a;
						if (!(isdigit))
							throw ("Invalid input");
						int b = stoi(a);
						if (b <= 0)
							throw ("Invalid input, please enter a positive integer value.");
						c = b;
						break;
					}
					catch (exception e)
					{
						cout << e.what() << endl;
					}
				}
				while (true)
				{
					if (c == 1)
					{
						stock.DeleteMedicine();

						//system("cls");
						stock.CheckExpiry(stock.GetHead());
						break;
					}
					else if (c == 2)
					{
						break;
					}
					else
					{
						cout << "press Only 1 aur 2" << endl;
					}
				}
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
				Sale s;
				s.SaleMedicine(stock.GetHead());
				break;
			}
			case 8:
			{
				system("cls");
				Sale s;
				s.HistoryPurcheasedShow();
				//system("pause");
				break;
			}

			case 9:
			{
				system("cls");
				main();
				system("pause");
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
};


//Main Function
int main()
{
	employee a;
	ManagementStock m;
	int choice, c2;
	do {
		cout << "\n\n\t\t\t=======================================================================";
		cout << "\n\t\t\t=======================================================================" << endl << endl;

		cout << "\t\t\t\t\tWELCOME TO PHARMACY MANAGEMENT SYSTEM" << endl;

		cout << endl << "\t\t\t=======================================================================";
		cout << endl << "\t\t\t=======================================================================" << endl << endl;
		cout << "1- User Menu" << endl;
		cout << "2- Admin Menu" << endl;
		cout << "3- Exit" << endl;
		cin >> c2;

		while (1)
		{
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Please Enter a valid input again: " << endl;
				cin >> c2;
			}
			if (!cin.fail())
				break;
		}

		while (c2 < 1 && c2 > 2) {

			cout << "Please choose a valid option!" << endl;
			cin >> c2;

			while (1)
			{
				if (cin.fail())
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Please Enter a valid input again: " << endl;
					cin >> c2;
				}
				if (!cin.fail())
					break;
			}
		}

		switch (c2) {
		case 1: {
			do {
				system("cls");
				cout << "\n\n\t\t\t=======================================================================";
				cout << "\n\t\t\t=======================================================================" << endl << endl;

				cout << "\t\t\t\t\tWELCOME TO PHARMACY MANAGEMENT SYSTEM" << endl;

				cout << endl << "\t\t\t=======================================================================";
				cout << endl << "\t\t\t=======================================================================" << endl << endl;

				int a;
				cout << "1- Stock Management." << endl;
				cout << "2- Go back" << endl;
				cin >> a;
				while (1)
				{
					if (cin.fail())
					{
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "Please Enter a valid input again: " << endl;
						cin >> a;
					}
					if (!cin.fail())
						break;
				}

				while (a < 1 && a > 2) {

					cout << "Please choose a valid option!" << endl;
					cin >> a;

					while (1)
					{
						if (cin.fail())
						{
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
							cout << "Please Enter a valid input again: " << endl;
							cin >> a;
						}
						if (!cin.fail())
							break;
					}
				}

				switch (a) {
				case 1:
					system("cls");
					m.Managementstock();
					break;

				case 2:
					system("cls");
					main();
					system("pause");
					break;

				default:
					while (a < 1 && a > 3) {

						cout << "Please choose a valid option!" << endl;
						cin >> a;
					}
				}
			} while (true);
			break;
		}

		case 2:
			a.login();
			system("PAUSE");
			system("cls");
			do {
				cout << "\n\n\t\t\t=======================================================================";
				cout << "\n\t\t\t=======================================================================" << endl << endl;

				cout << "\t\t\t\t\tWELCOME TO PHARMACY MANAGEMENT SYSTEM" << endl;

				cout << endl << "\t\t\t=======================================================================";
				cout << endl << "\t\t\t=======================================================================" << endl << endl;

				cout << "1- Employee Management. " << endl;
				cout << "2- Stock Management. " << endl;
				cout << "3- Exit." << endl;

				cin >> choice;

				while (1)
				{
					if (cin.fail())
					{
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "Please Enter a valid input again: " << endl;
						cin >> choice;
					}
					if (!cin.fail())
						break;
				}

				while (choice < 1 && choice > 3) {

					cout << "Please choose a valid option!" << endl;
					cin >> choice;

					while (1)
					{
						if (cin.fail())
						{
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
							cout << "Please Enter a valid input again: " << endl;
							cin >> choice;
						}
						if (!cin.fail())
							break;
					}
				}
				system("cls");


				switch (choice) {

				case 1:
					a.employeeManagement();
					break;

				case 2:
					m.Managementstock();
					break;

				case 3:
					system("cls");
					main();
					system("pause");
					break;

				default:
					while (choice < 1 && choice > 3) {

						cout << "Please choose a valid option!" << endl;
						cin >> choice;
					}
				}
			} while (true);

		case 3:
		{
			exit(0);
			return 0;
			break;
		}
		default: {
			while (c2 < 1 && c2 > 2) {
				cout << "Invalid Input! Please Enter Again: " << endl;
				cin >> c2;
			}
		}
		}
	} while (true);
}