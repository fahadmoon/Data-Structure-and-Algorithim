#include<iostream>
#include<conio.h>
#include<windows.h>
#include<string>
#include <fstream>

using namespace std;

// Abstract Base Class
class DataMembers
{
protected:

	// Data Member Use in Bank And ATM Class 
	int anumber; //Account Number
	int pass;   //Account password
	string aholder; //Account Holder Name 
	string fname; //Father Name
	char taccount; //Account Type
	int date;
	int month;
	int year;
	string cno; //Contact Number
	double balance;   //balance

public:

	virtual void Withdraw_Amount() = 0;
	virtual void Balance_Inquiry() = 0;


};

// Bank Class


class Bank : public DataMembers
{

protected:

	// Data Member Use in File Handling 

	int an;   //Account Number
	int p;   //Account password
	string n; //Account Holder Name 
	string fn; //Father Name
	char t; //Account Type
	int d;
	int m;
	int y;
	string cn; //Contact Number
	double b;   //balance   
public:


	void entryform()
	{
	p:

		cout << "\n\t\t\t\t........Enter your Details...." << endl;
		cout << "\n\t\t\t\tEnter 4 Digit Account Number:";
		while (true)
		{
			cin >> anumber;

			if (anumber > 999 && anumber < 10000)
			{
				break;
			}

			else
			{
				cout << "\n\t\t\t\tPlease enter maximum 4 digit number:";
			}

		}


		cout << "\n\t\t\t\tEnter 4 Digit Password:";

		while (true)
		{
			cin >> pass;

			if (pass > 999 && pass < 10000)
			{
				break;
			}

			else
			{
				cout << "\n\t\t\t\tPlease enter maximum 4 digit number:";
			}

		}
		cout << "\n\t\t\t\tEnter Account Holder Name:";

		cin.ignore();
		getline(cin, aholder);
		cout << "\n\t\t\t\tEnter Father Name: ";


		getline(cin, fname);
		cout << "\n\t\t\t\tEnter Account Type (Saving/Current):";
		do
		{
			cin >> taccount;
			if (taccount == 'S' || taccount == 's' || taccount == 'C' || taccount == 'c')
			{
				break;
			}
			else {
				cout << "\n\t\t\t\tPlease enter correct account type:";
			}


		} while (true);
		////////Date of Birth
		cout << "\n\t\t\t\tEnter Date of birth DD/MM/YYYY:";
		cout << "\n\t\t\t\tDD: ";

		while (true)
		{

			cin >> date;
			if (date > 0 && date < 31)
			{

				break;
			}
			else {
				cout << "\n\t\t\t\tPlease enter correct date:";
			}
		}
		cout << "\n\t\t\t\tMM:";

		while (true)
		{

			cin >> month;
			if (month > 0 && month < 13)
			{
				break;
			}

			else
			{
				cout << "\n\t\t\t\tPlease enter correct month:";
			}

		}
		cout << "\n\t\t\t\tYYYY:";


		while (true)
		{
			cin >> year;
			if (year > 1900 && year < 2024)
			{
				break;

			}
			else
			{
				cout << "\n\t\t\t\tplease enter correct year:";
			}


		}

		cout << "\n\t\t\t\tEnter Contact Number: ";
		//Contact Number

		while (true)
		{
			cin >> cno;
			if (cno.length() == 11)
			{
				break;
			}

			else
			{
				cout << "\n\t\t\t\tPlease enter correct contact Number:";
			}

		}
		while (true) {
			cout << "\n\t\t\t\tDeposit Amount:";
			cin >> balance;
			if (balance > 100)
			{
				break;

			}

			else
				cout << "\n\t\t\t\tPlease Enter Greater than 100" << endl;
		}

		fstream file;
		file.open("Bank.txt", ios::in);
		if (!file) {

			file.open("Bank.txt", ios::out | ios::app);
			file << " " << anumber << " " << pass << " " << aholder << " " << fname << " " << taccount << " " << date << " " << month << " "
				<< year << " " << cno << " " << balance << " " << endl;
			file.close();
		}
		else {

			file >> an >> p >> n >> fn >> t >> d >> m >> y >> cn >> b;
			while (!file.eof()) {
				if (an == anumber) {
					cout << "\n\t\t\t\tAccount number already Exist.... " << endl;
				//	getch();
					system("cls");
					goto p;

				}
				file >> an >> p >> n >> fn >> t >> d >> m >> y >> cn >> b;
			}
			file.close();

			file.open("Bank.txt", ios::out | ios::app);
			//		file<< "Customer Details "<<" anumber"<<" Name "<<" f name "<<" date of birth "<<" contect no"<<" Bal;ance "<<endl;
			file << " " << anumber << " " << pass << " " << aholder << " " << fname << " " << taccount << " " << date << " " << month << " "
				<< year << " " << cno << " " << balance << " " << endl;
			file.close();
		}
		cout << "\n\t\t\t\tNew user Account created successfully.......... " << endl;

	}

	void deposit_Amount(int a)
	{

		int ac;
		double deposit;
		int found = 0;

		ac = a;
		fstream file, file1;

		file.open("Bank.txt", ios::in);

		if (!file) {

			cout << "\n\t\t\t\tFile opening Error......." << endl;
		}
		else {

			file1.open("Bank1.txt", ios::app | ios::out);

			file >> anumber >> pass >> aholder >> fname >> taccount >> date >> month >> year >> cno >> balance;
			while (!file.eof()) {

				if (ac == anumber) {
					cout << "\n\t\t\t\t--------------Account Details------------" << endl << endl;
					cout << "\n\t\t\t\tAccount Number: " << anumber;
					cout << "\n\t\t\t\tPassword: " << pass;
					cout << "\n\t\t\t\tAccount Holder Name: " << aholder;
					cout << "\n\t\t\t\tFather Name: " << fname;
					cout << " \n\t\t\t\tAccount Type (S/C): " << taccount;
					cout << "\n\t\t\t\t Date of Birth:" << date << "/" << month << "/" << year;
					cout << "\n\t\t\t\tContact Number: " << cno;
					cout << "\n\t\t\t\tYour Total Balance is: " << balance << endl;

					cout << endl << endl << "\n\t\t\t\t----------Deposit Amount---------" << endl;
					cout << "\n\t\t\t\tEnter Deposit Amount:";
					cin >> deposit;
					balance += deposit;
					file1 << " " << anumber << " " << pass << " " << aholder << " " << fname << " " << taccount << " " << date << " " << month << " "
						<< year << " " << cno << " " << balance << " " << endl;
					found++;
					cout << "\n\t\t\t\tYour Amount " << deposit << " Deposit Successfully........." << endl;
					cout << "\n\t\t\t\tYour New Balance is: " << balance << endl;
				}
				else {

					file1 << " " << anumber << " " << pass << " " << aholder << " " << fname << " " << taccount << " " << date << " " << month << " "
						<< year << " " << cno << " " << balance << " " << endl;
				}

				file >> anumber >> pass >> aholder >> fname >> taccount >> date >> month >> year >> cno >> balance;
			}
			file.close();
			file1.close();
			remove("Bank.txt");
			rename("Bank1.txt", "Bank.txt");

			if (found == 0) {
				cout << "\n\t\t\t\tAccount Number can't Found......" << endl;
			}

		}

	}


	//Case 3

	void Withdraw_Amount()
	{

		double withdraw;
		int acno;
		int found = 0;

		fstream file, file1;

		file.open("Bank.txt", ios::in);

		if (!file) {

			cout << "\n\t\t\t\tFile opening Error......." << endl;
		}
		else {

			cout << "\n\t\t\t\tEnter your Account Number: ";
			cin >> acno;

			file1.open("Bank1.txt", ios::app | ios::out);

			file >> anumber >> pass >> aholder >> fname >> taccount >> date >> month >> year >> cno >> balance;
			while (!file.eof())
			{

				if (acno == anumber)
				{
					cout << "\n\t\t\t\t--------------Account Details------------" << endl << endl;
					cout << "\n\t\t\t\tAccount Number: " << anumber;
					cout << "\n\t\t\t\tPassword: " << pass;
					cout << "\n\t\t\t\tAccount Holder Name: " << aholder;
					cout << "\n\t\t\t\tFather Name: " << fname;
					cout << " \n\t\t\t\tAccount Type (S/C): " << taccount;
					cout << "\n\t\t\t\t Date of Birth:" << date << "/" << month << "/" << year;
					cout << "\n\t\t\t\tContact Number: " << cno;
					cout << "\n\t\t\t\tYour Total Balance is: " << balance << endl;

					cout << endl << endl << "\n\t\t\t\t----------Withdraw Amount---------" << endl;
					cout << "\n\t\t\t\tEnter Withdraw Amount:";
					cin >> withdraw;
					if (withdraw <= balance) {

						balance -= withdraw;
						file1 << " " << anumber << " " << pass << " " << aholder << " " << fname << " " << taccount << " " << date << " " << month << " "
							<< year << " " << cno << " " << balance << " " << endl;

						cout << "\n\t\t\t\tYour Amount " << withdraw << " Withdraw Successfully........." << endl;
						cout << "\n\t\t\t\tYour New Balance is: " << balance << endl;
					}
					else {
						file1 << " " << anumber << " " << pass << " " << aholder << " " << fname << " " << taccount << " " << date << " " << month << " "
							<< year << " " << cno << " " << balance << " " << endl;

						cout << "\n\t\t\t\tYour Current Balance " << balance << " is Less...........! " << endl;
						cout << "\n\t\t\t\tPlease Enter Correct Amount..........!" << endl;
					}
					found++;
				}
				else {

					file1 << " " << anumber << " " << pass << " " << aholder << " " << fname << " " << taccount << " " << date << " " << month << " "
						<< year << " " << cno << " " << balance << " " << endl;
				}

				file >> anumber >> pass >> aholder >> fname >> taccount >> date >> month >> year >> cno >> balance;
			}
			file.close();
			file1.close();
			remove("Bank.txt");
			rename("Bank1.txt", "Bank.txt");

			if (found == 0) {
				cout << "\n\t\t\t\tAccount Number can't Found......" << endl;
			}

		}

	}

	//Case 4

	void Balance_Inquiry()
	{
		int acno;
		int found = 0;
		fstream file;
		file.open("Bank.txt", ios::in);
		if (!file) {

			cout << "\n\t\t\t\File Opening Error........." << endl;
		}
		else {

			cout << "\n\t\t\tEnter Account Number : ";
			cin >> acno;

			file >> anumber >> pass >> aholder >> fname >> taccount >> date >> month >> year >> cno >> balance;

			while (!file.eof()) {

				if (acno == anumber) {

					cout << "\n\t\t\t\tYour Total Balance is: " << balance << endl;
					found++;
				}
				file >> anumber >> pass >> aholder >> fname >> taccount >> date >> month >> year >> cno >> balance;

			}
			file.close();

			if (found == 0) {

				cout << "\n\t\t\t\tUser id Can't Found........";
			}

		}

	}


	// case 5
	void Search_Record()
	{
		int acno;
		int found = 0;
		fstream file, file1;
		file.open("Bank.txt", ios::in);
		if (!file) {

			cout << "\n\t\t\t\File Opening Error........." << endl;
		}
		else {

			cout << "\n\t\t\tEnter Account Number : ";
			cin >> acno;

			file >> anumber >> pass >> aholder >> fname >> taccount >> date >> month >> year >> cno >> balance;

			while (!file.eof()) {

				if (acno == anumber) {

					cout << "\n\t\t\t\t--------------Account Details------------" << endl << endl;
					cout << "\n\t\t\t\tAccount Number: " << anumber;
					cout << "\n\t\t\t\tPassword: " << pass;
					cout << "\n\t\t\t\tAccount Holder Name: " << aholder;
					cout << "\n\t\t\t\tFather Name: " << fname;
					cout << " \n\t\t\t\tAccount Type (S/C): " << taccount;
					cout << "\n\t\t\t\t Date of Birth:" << date << "/" << month << "/" << year;
					cout << "\n\t\t\t\tContact Number: " << cno;
					cout << "\n\t\t\t\tYour Total Balance is: " << balance << endl;
					found++;
				}
				file >> anumber >> pass >> aholder >> fname >> taccount >> date >> month >> year >> cno >> balance;

			}
			file.close();
		}
		if (found == 0) {

			cout << "\n\t\t\t\tUser id Can't Found........";
		}

	}




	// case 6

	void Transfer_amount()
	{

		fstream file, file1;
		int s_ano;
		int r_ano;
		int amount;
		int found = 0;

		file.open("Bank.txt", ios::in);
		if (!file) {

			cout << "\n\t\t\t\File Opening Error........." << endl;
		}
		else {
			cout << "\n\t\t\tEnter sender Account Number : ";
			cin >> s_ano;
			cout << "\n\t\t\tEnter Reciver Account Number : ";
			cin >> r_ano;
			cout << "\n\t\t\tEnter Transction Amount : ";
			cin >> amount;

			file >> anumber >> pass >> aholder >> fname >> taccount >> date >> month >> year >> cno >> balance;

			while (!file.eof()) {

				if (s_ano == anumber && amount <= balance) {

					found++;
				}
				else if (r_ano == anumber) {
					found++;
				}

				file >> anumber >> pass >> aholder >> fname >> taccount >> date >> month >> year >> cno >> balance;
			}

			file.close();

			if (found == 2) {

				file.open("Bank.txt", ios::in);
				file1.open("Bank1.txt", ios::app | ios::out);
				file >> anumber >> pass >> aholder >> fname >> taccount >> date >> month >> year >> cno >> balance;

				while (!file.eof()) {

					if (s_ano == anumber) {

						balance -= amount;
						file1 << " " << anumber << " " << pass << " " << aholder << " " << fname << " " << taccount << " " << date << " " << month << " "
							<< year << " " << cno << " " << balance << " " << endl;
					}

					else if (r_ano == anumber) {

						balance += amount;
						file1 << " " << anumber << " " << pass << " " << aholder << " " << fname << " " << taccount << " " << date << " " << month << " "
							<< year << " " << cno << " " << balance << " " << endl;

						cout << "\n\t\t\tYour Amount Transfer Successfully..........." << endl;
					}
					else {

						file1 << " " << anumber << " " << pass << " " << aholder << " " << fname << " " << taccount << " " << date << " " << month << " "
							<< year << " " << cno << " " << balance << " " << endl;
					}
					file >> anumber >> pass >> aholder >> fname >> taccount >> date >> month >> year >> cno >> balance;
				}
				file.close();
				file1.close();
				remove("Bank.txt");
				rename("Bank1.txt", "Bank.txt");

			}
			else {

				cout << "\n\t\t\tTransction IDs Not Found and Balance invalid........" << endl;


			}
		}
	}


	// Case 7
	void Modify_Account()
	{
		int acno;
		int found = 0;
		fstream file, file1;
		file.open("Bank.txt", ios::in);
		if (!file) {

			cout << "\n\t\t\t\File Opening Error........." << endl;
		}
		else {

			cout << "\n\t\t\tEnter Account Number : ";
			cin >> acno;
			file1.open("Bank1.txt", ios::app | ios::out);
			file >> anumber >> pass >> aholder >> fname >> taccount >> date >> month >> year >> cno >> balance;

			while (!file.eof()) {

				if (acno == anumber) {

					cout << "\n\t\t\t\t==============Previous Account Details==============" << endl << endl;
					cout << "\n\t\t\t\tAccount Number: " << anumber;
					cout << "\n\t\t\t\tAccount Holder Name: " << aholder;
					cout << "\n\t\t\t\tFather Name: " << fname;
					cout << " \n\t\t\t\tAccount Type (S/C): " << taccount;
					cout << "\n\t\t\t\tDate of Birth:" << date << "/" << month << "/" << year;

					cout << "\n\t\t\t\tContact Number: " << cno;
					cout << "\n\t\t\t\tYour Total Balance is:" << balance << endl << endl;

					cout << "\n\t\t\t\t==============Now Update Your Account==============" << endl << endl;


					cout << "\n\t\t\t\tEnter Account Holder Name:";

					cin.ignore();
					getline(cin, n);
					cout << "\n\t\t\t\tEnter Father Name: ";


					getline(cin, fn);
					cout << "\n\t\t\t\tEnter Account Type (Saving/Current):";
					do
					{
						cin >> t;
						if (t == 'S' || t == 's' || t == 'C' || t == 'c')
						{
							break;
						}
						else {

							cout << "\n\t\t\t\tPlease enter correct account type:";
						}


					} while (true);
					////////Date of Birth
					cout << "\n\t\t\t\tEnter Date of birth DD/MM/YYYY:";
					cout << "\n\t\t\t\tDD: ";

					while (true)
					{

						cin >> d;
						if (d > 0 && d < 31)
						{

							break;
						}
						else {

							cout << "\n\t\t\t\tPlease enter correct date:";
						}
					}
					cout << "\n\t\t\t\tMM:";

					while (true)
					{

						cin >> m;
						if (m > 0 && m < 13)
						{
							break;
						}

						else
						{
							cout << "\n\t\t\t\tPlease enter correct month:";
						}

					}
					cout << "\n\t\t\t\tYYYY:";


					while (true)
					{
						cin >> y;
						if (y > 1900 && y < 2023)
						{
							break;

						}
						else
						{
							cout << "\n\t\t\t\tplease enter correct year:";
						}


					}

					while (true)
					{
						cin >> cno;
						if (cno.length() == 11)
						{
							break;
						}

						else
						{
							cout << "\n\t\t\t\tPlease enter correct contact Number:";
						}

					}

					file1 << " " << anumber << " " << pass << " " << n << " " << fn << " " << t << " " << d << " " << m << " "
						<< y << " " << cn << " " << balance << " " << endl;

					cout << "\n\t\t\t\tRecord Edit Successfully.........." << endl;
					found++;
				}

				else {

					file1 << " " << anumber << " " << pass << " " << aholder << " " << fname << " " << taccount << " " << date << " " << month << " "
						<< year << " " << cno << " " << balance << " " << endl;
				}
				file >> anumber >> pass >> aholder >> fname >> taccount >> date >> month >> year >> cno >> balance;

			}
			file.close();
			file1.close();
			remove("Bank.txt");
			rename("Bank1.txt", "Bank.txt");
			if (found == 0) {

				cout << "\n\t\t\t\tUser id Can't Found........." << endl;
			}

		}

	}


	//case 8

	void Delete_Record()
	{
		int acno;
		int found = 0;
		fstream file, file1;
		file.open("Bank.txt", ios::in);
		if (!file) {

			cout << "\n\t\t\t\File Opening Error........." << endl;
		}
		else {

			cout << "\n\t\t\tEnter Account Number : ";
			cin >> acno;
			file1.open("Bank1.txt", ios::app | ios::out);
			file >> anumber >> pass >> aholder >> fname >> taccount >> date >> month >> year >> cno >> balance;

			while (!file.eof()) {

				if (acno == anumber) {



					cout << "\n\n\t\t\tRecord Deleted Successfully........." << endl;
					found++;
				}

				else {

					file1 << " " << anumber << " " << pass << " " << aholder << " " << fname << " " << taccount << " " << date << " " << month << " "
						<< year << " " << cno << " " << balance << " " << endl;
				}
				file >> anumber >> pass >> aholder >> fname >> taccount >> date >> month >> year >> cno >> balance;

			}
			file.close();
			file1.close();
			remove("Bank.txt");
			rename("Bank1.txt", "Bank.txt");
			if (found == 0) {

				cout << "\n\t\t\t\tUser id Can't Found........" << endl;
			}

		}

	}

	// Case 9

	void Show_All_Account()
	{
		int found = 0;
		int acc = 1;
		fstream file;
		file.open("Bank.txt", ios::in);
		if (!file) {

			cout << "\n\t\t\t\File Opening Error........." << endl;
		}
		else {

			file >> anumber >> pass >> aholder >> fname >> taccount >> date >> month >> year >> cno >> balance;

			while (!file.eof()) {

				cout << "\n\t\t\t\t==============Account No " << acc << " Details==============" << endl;
				cout << "\n\t\t\t\tAccount Number: " << anumber;
				cout << "\n\t\t\t\tPassword: " << pass;
				cout << "\n\t\t\t\tAccount Holder Name: " << aholder;
				cout << "\n\t\t\t\tFather Name: " << fname;
				cout << " \n\t\t\t\tAccount Type (S/C): " << taccount;
				cout << "\n\t\t\t\t Date of Birth:" << date << "/" << month << "/" << year;
				cout << "\n\t\t\t\tContact Number: " << cno;
				cout << "\n\t\t\t\tYour Total Balance is: " << balance << endl;
				acc++;
				found++;
				file >> anumber >> pass >> aholder >> fname >> taccount >> date >> month >> year >> cno >> balance;

			}
			file.close();

		}

		if (found == 0) {

			cout << "\n\t\t\t\tNo Record Available.. " << endl;
		}
	}

};

// ATM CLASS

class ATM : public DataMembers
{

public:

	int acno;
	int ps;

	ATM()
	{

		cout << "\n\n\t\t=======================================================================";
		cout << "\n\t\t\=======================================================================" << endl << endl;

		cout << "\t\t\t\tWELCOME TO HABIB BANK ATM SYSTEM" << endl;

		cout << endl << "\t\t=======================================================================";
		cout << endl << "\t\t=======================================================================";
		cout << "\n\n\n\n\n\t\t\tEnter Account Number : ";
		cin >> acno;
		cout << "\n\t\t\tEnter Password : ";
		cin >> ps;

	}
	void Balance_Inquiry()

	{
		fstream file;
		file.open("Bank.txt", ios::in);
		if (!file) {

			cout << "\n\t\t\t\File Opening Error........." << endl;
		}
		else {

			file >> anumber >> pass >> aholder >> fname >> taccount >> date >> month >> year >> cno >> balance;

			while (!file.eof()) {

				if (acno == anumber && ps == pass) {

					cout << "\n\n\n\t\t\tYour Total Balance is: " << balance << endl;

				}
				file >> anumber >> pass >> aholder >> fname >> taccount >> date >> month >> year >> cno >> balance;

			}
			file.close();

		}

	}

	void Withdraw_Amount()
	{

		double withdraw;
		int ch;
		fstream file, file1;
		file.open("Bank.txt", ios::in);

		if (!file) {

			cout << "\n\t\t\t\tFile opening Error......." << endl;
		}
		else {

			file1.open("Bank1.txt", ios::app | ios::out);

			file >> anumber >> pass >> aholder >> fname >> taccount >> date >> month >> year >> cno >> balance;
			while (!file.eof()) {

				if (acno == anumber && ps == pass)
				{

					cout << endl << endl << "\n\t\t\t\t----------Withdraw Amount---------" << endl << endl;
					cout << "\n\t\t\t\tEnter Withdraw Amount:";
					cin >> withdraw;
					if (withdraw > balance)
					{
						file1 << " " << anumber << " " << pass << " " << aholder << " " << fname << " " << taccount << " " << date << " " << month << " "
							<< year << " " << cno << " " << balance << " " << endl;

						cout << "\n\t\t\t\tYour Current Balance " << balance << " is Less...........! " << endl;
						cout << "\n\t\t\t\tPlease Enter Correct Amount..........!" << endl;
					}

					else
					{
						balance -= withdraw;
						file1 << " " << anumber << " " << pass << " " << aholder << " " << fname << " " << taccount << " " << date << " " << month << " "
							<< year << " " << cno << " " << balance << " " << endl;

						cout << "\n\t\t\t\tYour Amount " << withdraw << " Withdraw Successfully........." << endl;
						cout << "\n\t\t\t\tDo you Want Withdraw Slip: " << endl;
						cout << "\n\t\t\t\t1. Yes";
						cout << "\n\t\t\t\t2. No";
						cout << "\n\t\t\t\tEnter Your choice(1-2): ";
						cin >> ch;
						switch (ch) {

						case 1:
						{
							cout << "\n\t\t\=======================================================================" << endl << endl;

							cout << "\t\t\tWELCOME TO HABIB BANK ATM SYSTEM" << endl;

							cout << endl << "\t\t=======================================================================";


							cout << "\n\t\t\t\tAccount Holder Name is: " << aholder;
							cout << "\n\t\t\t\tFather Name is: " << fname << endl << endl;

							cout << "\n\t\t\t\tYou Withdraw " << withdraw << " Amount........." << endl;
							cout << "\n\t\t\t\tYour Current Balance is: " << balance << endl;

							break;
						}

						case 2:
						{
							break;
						}
						default:
						{
							cout << "\n\t\t\t\tPlease Enter Correct Choice: " << endl;
							break;
						}
						}

					}

				}
				else {

					file1 << " " << anumber << " " << pass << " " << aholder << " " << fname << " " << taccount << " " << date << " " << month << " "
						<< year << " " << cno << " " << balance << " " << endl;
				}

				file >> anumber >> pass >> aholder >> fname >> taccount >> date >> month >> year >> cno >> balance;
			}
			file.close();
			file1.close();
			remove("Bank.txt");
			rename("Bank1.txt", "Bank.txt");

		}

	}

};
//login class

class LOGIN
{
private:
	string userName;
	string password;
	char ch1;
	int loginAttempt = 1;
public:
	LOGIN()
	{


		for (int i = 3; i >= 1; i--)
		{
			system("cls");
			cout << endl << endl << endl;
			cout << "\n\t\t\t\tLoading..............";
			cout << endl << endl << "\n\t\t\t\t" << i;
			Sleep(700);
			system("cls");
		}

	}

};



//Main Function
int main() {

	Bank* B = new Bank();
	system("color 60");
	{
		LOGIN* login = new LOGIN();
	}


	while (true) {
	p:
		system("cls");
		cout << "\n\n\t\t=======================================================================";
		cout << "\n\t\t\=======================================================================" << endl << endl;

		cout << "\t\t\tWELCOME TO HABIB BANK LIMITED ACCOUNT MANAGEMENT SYSTEM" << endl;

		cout << endl << "\t\t=======================================================================";
		cout << endl << "\t\t=======================================================================";


		cout << endl << "\n\n\t\t\t\t    ::MAIN MENU::" << endl;

		cout << endl << "\n\t\t\t\t1. BANK MANAGEMENT SYSTEM";
		cout << "\n\t\t\t\t2. ATM MAMAGEMENT SYSTEM";
		cout << "\n\t\t\t\t3. EXIT";
		cout << endl << endl;


		int choice;
		cout << endl << "\t\t\t\tSelect Your Choice (1-3): ";
		cin >> choice;

		// Manu Switch

		switch (choice)
		{

			// Bank Management System

		case 1:
		{

			system("cls");
			while (true) {
				system("cls");
				cout << "\n\n\t\t=======================================================================";
				cout << "\n\t\t\=======================================================================" << endl << endl;

				cout << "\t\t\tWELCOME TO HABIB BANK LIMITED ACCOUNT MANAGEMENT SYSTEM" << endl;

				cout << endl << "\t\t=======================================================================";
				cout << endl << "\t\t=======================================================================";


				cout << endl << "\n\n\t\t\t\t    ::BANK MENU::" << endl;

				cout << endl << "\n\t\t\t\t1. NEW ACCOUNT";
				cout << "\n\t\t\t\t2. DEPOSIT AMOUNT";
				cout << "\n\t\t\t\t3. WITHDRAW AMOUNT";
				cout << "\n\t\t\t\t4. BALANCE INQUIRY";
				cout << "\n\t\t\t\t5. SEARCH ALREADY USER RECORD";
				cout << endl << "\t\t\t\t6. TRANSFER AMOUNT";
				cout << endl << "\t\t\t\t7. MODIFY ACCOUNT";
				cout << endl << "\t\t\t\t8. DELETE ACCOUNT";
				cout << endl << "\t\t\t\t9. SHOW ALL ACCOUNT HOLDER LIST";
				cout << endl << "\t\t\t\t10. Back to Main Manu";
				cout << endl << endl;


				int option;
				cout << endl << "\t\t\t\tSelect Your Option (1-10): ";
				cin >> option;

				// Bank Switch Start

				switch (option)
				{
				case 1:
				{
					system("cls");
					B->entryform();


					break;
				}
				case 2:
				{
					system("cls");
					int acno;
					cout << "\n\t\t\t\tEnter your Account Number: ";
					cin >> acno;

					B->deposit_Amount(acno);

					break;
				}
				case 3:
				{
					system("cls");
					B->Withdraw_Amount();
					break;
				}
				case 4:
				{
					system("cls");

					B->Balance_Inquiry();
					break;
				}

				case 5:
				{
					system("cls");
					B->Search_Record();

					break;
				}
				case 6:
				{
					system("cls");

					B->Transfer_amount();
					break;
				}
				case 7:
				{
					system("cls");
					B->Modify_Account();
					break;
				}
				case 8:
				{
					system("cls");
					B->Delete_Record();
					break;
				}

				case 9:
				{
					system("cls");
					B->Show_All_Account();
					break;
				}
				case 10:
				{
					goto p;

					break;
				}

				default:
				{

					cout << "\n\t\t\t\tPlease Enter the Correct option" << endl;
				}
				}
				system("pause");
			}

			break;

		}    // Bank Switch End

	// ATM Management System

		case 2:
		{
			system("cls");
			ATM* A = new ATM();
			system("cls");

			while (true) {
				system("cls");
				cout << "\n\n\t\t=======================================================================";
				cout << "\n\t\t\=======================================================================" << endl << endl;

				cout << "\t\t\tWELCOME TO HABIB BANK LIMITED ACCOUNT MANAGEMENT SYSTEM" << endl;

				cout << endl << "\t\t=======================================================================";
				cout << endl << "\t\t=======================================================================";


				cout << endl << "\n\n\t\t\t\t    ::ATM MENU::" << endl;


				cout << "\n\t\t\t\t1. BALANCE INQUIRY";
				cout << "\n\t\t\t\t2. WITHDRAW AMOUNT";
				cout << "\n\t\t\t\t3. Go to Main Manu";

				cout << endl << endl;

				int option;
				cout << endl << "\t\t\t\tSelect Your Option (1-3): ";
				cin >> option;
				// ATM Switch Cases
				switch (option)
				{
				case 1:
				{
					system("cls");

					A->Balance_Inquiry();

					break;
				}
				case 2:
				{
					system("cls");
					A->Withdraw_Amount();

					break;
				}
				case 3:
				{
					goto p;
					break;
				}

				default:
				{

					cout << "\n\t\t\t\tPlease Enter the Correct option" << endl;
				}
				}
				system("pause");
			}

			break;
		}

		// ATM Switch End

		case 3:
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