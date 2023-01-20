#include <iostream>
#include <fstream>
#include <string>
#include<stdio.h>
#include <iomanip> //using library setw()
using namespace std;

class node
{
public:
    int adID;   //admission no
    int rollNo;
    string name;
    string fname; //fathername
    string dob;
    string address;
    int aID;   //admission no
    int rNo;
    string nameStudent;
    int DSAmarks, CAmarks, LAmarks, CSmarks, MVCmarks, ISLmarks; //subjects
    char garde;//Date of birth
    node* next;
    node* prev;
};

class Student
{
private:
    node* head;
    // using data type file handling
    int aID;   //admission no
    int rNo;
    string nameStudent;
    string fathername; //fathername
    string d;//Date of birth
    string addrss; //address
public:
    Student()
    {
        head = NULL;
    }
    //Insert Data
    void Insert()
    {


        node* curr;
        int roll, aNO;
        string name, fathername, dob, address;
        while (true)
        {
            cout << "Enter Admission No: ";
            cin >> aNO;
            node* check = head;
            int i = 0;
            while (check != NULL)
            {
                if (check->adID == aNO)
                {
                    i++;
                    break;
                }
                check = check->next;
            }
            if (i == 1)
            {
                cout << "Already exist Admission no" << endl;
            }
            else
            {
                break;
            }
        }

        while (true)
        {
            cout << "Enter Roll No: ";
            cin >> roll;
            node* check = head;
            int i = 0;
            while (check != NULL)
            {
                if (check->rollNo == roll)
                {
                    i++;
                    break;
                }
                check = check->next;
            }
            if (i == 1)
            {
                cout << "Already exist Admission no" << endl;
            }
            else
            {
                break;
            }
        }
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Father Name: ";
        cin >> fathername;
        cout << "Enter Address: ";
        cin >> address;
        cout << "Enter Date of Birth(DD/MM/YYYY): ";
        cin >> dob;
        //create New Node
        node* temp = new node;
        //Store date Node
        temp->rollNo = roll;
        temp->adID = aNO;
        temp->name = name;
        temp->fname = fathername;
        temp->dob = dob;
        temp->address = address;
        temp->next = NULL;
        if (head == NULL)
        {
            temp->prev = NULL;
            head = temp;
            SaveToFile();
        }
        else
        {
            curr = head;
            while (curr->next != NULL) {
                curr = curr->next;
            }
            curr->next = temp;
            temp->prev = curr;
            SaveToFile();
        }
    }
    //Save Data to File
    void SaveToFile()
    {
        fstream file;
        file.open("student.txt", ios::out | ios::app);
        node* curr = head;
        file << curr->adID << " " << curr->rollNo << " " << curr->name << " " << curr->fname << " " << curr->dob << " " << curr->address << endl;
        curr = curr->next;
        file.close();
        cout << endl << endl;
        cout << "\t\t\t\t Data Saved To File Successfully!" << endl;
        system("pause");
        system("cls");
    }

    //Search Student Record
    void StudentSearchRecord()
    {
        int found = 0;
        int searchRollNo;
        cout << "\t\t\t\t------------------------" << endl;
        cout << "\t\t\t\t Enter Search Roll No#: ";
        cin >> searchRollNo;
        node* curr = head;
        while (curr != NULL) {
            if (searchRollNo == curr->rollNo)
            {
                cout << "\t\t\t\t Student Admission No#: " << curr->adID << endl;
                cout << "\t\t\t\t Student Roll No#: " << curr->rollNo << endl;
                cout << "\t\t\t\t Student Name: " << curr->name << endl;
                cout << "\t\t\t\t Student Father Name: " << curr->fname << endl;
                cout << "\t\t\t\t Student Address: " << curr->address << endl;
                cout << "\t\t\t\t Student Date of Birth(DD/MM/YYYY): " << curr->dob << endl;;
                found++;
                cout << endl << endl;
                cout << "\t\t\t\t Student Record Searched Successfully...." << endl;
                system("pause");
                system("cls");
                break;
            }
            curr = curr->next;
        }
        if (found == 0)
        {
            cout << endl << endl;
            cout << "\t\t\t\t Roll No# Not Found....!" << endl;
            system("pause");
            system("cls");
        }
    }

    //Count Student 
    void CountStudent()
    {

        ifstream file;


        int count = 0;
        node* curr = head;
        while (curr != NULL)
        {
            count++;
            curr = curr->next;
        }
        cout << endl << endl;
        cout << "\t\t\t\t Total Students: " << count << endl;
        system("pause");
        system("cls");
    }

    //Update Function
    void Update()
    {
        int found = 0;
        node* curr = head;
        int adNO;
        cout << "\t\t\t\t------------------------" << endl;
        cout << "\t\t\t\t Enter Admission No#: ";
        cin >> adNO;
        while (curr != NULL)
        {
            if (adNO == curr->adID)
            {
                int a;
                string f, n, addrss, d;
                cout << "\t\t\t\t Enter Roll No#: ";
                cin >> curr->rollNo;
                cout << "\t\t\t\t Enter Name: ";
                cin >> curr->name;
                cout << "\t\t\t\t Enter Father Name: ";
                cin >> curr->fname;
                cout << "\t\t\t\t Enter Address: ";
                cin >> curr->address;
                cout << "\t\t\t\t Enter Date Of Birth(DD/MM/YYYY): ";
                cin >> curr->dob;
                UpdateRecordFileHandlng(curr->adID, curr->rollNo, curr->name, curr->fname, curr->dob, curr->address);
                found++;
                cout << endl;
                cout << "\t\t\t\t Student Record Updated Successfully...." << endl;
                system("pause");
                system("cls");
                break;
            }
            curr = curr->next;
        }
        if (found == 0)
        {
            cout << endl << endl;
            cout << "\t\t\t\t Addmission No# not found!" << endl;
            system("pause");
            system("cls");
        }
    }
    //Update FileHandlng 
    void UpdateRecordFileHandlng(int a, int roll, string name, string fname, string dob, string address)
    {
        fstream file, file1;
        file.open("student.txt", ios::in);
        {
            file1.open("student1.txt", ios::app | ios::in);
            file >> aID >> rNo >> nameStudent >> fathername >> d >> addrss;

            while (!file.eof())
            {
                if (aID == a)
                {
                    file1 << a << ", " << roll << ", " << name << ", " << fname << ", " << dob << ", " << address << endl;
                }
                else
                {
                    file1 << aID << ", " << rNo << ", " << nameStudent << ", " << fathername << ", " << d << ", " << addrss << endl;;

                }
                file >> aID >> rNo >> nameStudent >> fathername >> d >> addrss;
            }
        }
        file.close();
        file1.close();
        remove("student.txt");
        rename("student1.txt", "student.txt");
    }


    //Delete Student Data
    void DeleteStudent()
    {
        int found = 0;
        int AddmissionNo;
        cout << endl << endl;
        cout << "\t\t\t\t------------------------" << endl;
        cout << "\t\t\t\t Enter Addmission No#: ";
        cin >> AddmissionNo;
        node* current = head;
        node* temp = NULL;
        while (current != NULL)
        {
            if (current->adID == AddmissionNo)
            {
                if (current == head)
                    head = current->next;
                else if (current == temp)
                    temp = current->prev;
                else
                {
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                }
                RemoveFileHandlingStudent(current->adID);
                delete current;
                found++;
                system("pause");
                system("cls");
                break;
            }
            current = current->next;
        }
        if (found == 0)
        {
            cout << endl << endl;
            cout << "\t\t\t\t Student Data not Found" << endl;
            system("pause");
            system("cls");
        }
    }



    //Remove FileHandling Student
    void RemoveFileHandlingStudent(int a)
    {

        fstream f, f1;
        f.open("student.txt", ios::in);
        {
            f1.open("student1.txt", ios::out | ios::app);
            f >> aID >> rNo >> nameStudent >> fathername >> d >> addrss;
            while (!f.eof())
            {
                if (aID == a)
                {
                    cout << endl << endl;
                    cout << "\t\t\t\t  Student Removed Successfully...." << endl;
                    break;
                }
                else
                {
                    f1 << aID << ", " << rNo << "," << nameStudent << ", " << fathername << ", " << d << ", " << addrss << endl;;
                }
                f >> aID >> rNo >> nameStudent >> fathername >> d >> addrss;
            }
            f1.close();
            f.close();
            remove("student.txt");
            rename("student1.txt", "student.txt");
        }
    }
    //Display
    void Display()
    {
        int a = 1;//a++ count student no
        int found = 0;
        node* curr = head;
        cout << endl << endl;
        cout << "\t-------------------------------------------------------------------------------------------------------" << endl;
        cout << right << setw(5) << "\t| No. |" << setw(17) << "Admission No. |" << setw(12) << "Roll No. |" << setw(16) << "Student Name |" << setw(16) << "Father Name |" << setw(20) << "Date of Birth |" << setw(15) << "Address |" << endl;
        cout << "\t-------------------------------------------------------------------------------------------------------" << endl;
        while (curr != NULL)
        {

            cout << "\t" << right << setw(5) << a++ << setw(17) << curr->adID << setw(12) << curr->rollNo << setw(16) << curr->name << setw(16) << curr->fname << setw(20) << curr->dob << setw(15) << curr->address << endl;

            //			
            //			cout << "Roll No: " << curr->rollNo << endl;
            //			cout << "Your Name: " << curr->name << endl;
            //			cout << "CGPA: " << curr->cgpa << endl;
            curr = curr->next;
            found++;


        }
        cout << endl;
        system("pause");
        system("cls");

    }




    //Load Data from File
    void LoadFromFile()
    {
        //using data type file handling
        int aID;   //admission no
        int rNo;


        string nameStudent;
        string fathername; //fathername
        string d;//Date of birth
        string addrss; //address
        Student s;
        fstream file;
        file.open("student.txt", ios::in);
        if (!file)
        {
            cout << "\t\t\t\t Error Opening File....." << endl;
        }
        else
        {
            while (file >> aID >> rNo >> nameStudent >> fathername >> d >> addrss)
            {
                // s.Insert(aID, rNo, nameStudent, fathername, d, addrss);
                 //file >> aID >> rNo >> nameStudent >> fathername >> d >> addrss;
                node* curr;
                //create New Node
                node* temp = new node;
                //Store date Node
                temp->rollNo = aID;
                temp->adID = rNo;
                temp->name = nameStudent;
                temp->fname = fathername;
                temp->dob = d;
                temp->address = addrss;
                temp->next = NULL;
                if (head == NULL)
                {
                    temp->prev = NULL;
                    head = temp;
                }
                else
                {
                    curr = head;
                    while (curr->next != NULL) {
                        curr = curr->next;
                    }
                    curr->next = temp;
                    temp->prev = curr;
                }


            }
            cout << endl << endl;
            cout << "\t\t\t\t Data Loaded From File Successfully....." << endl;
            system("pause");
            system("cls");
        }

        file.close();

    }
};

class Teachernode
{
public:
    int rNo;
    string nameStudent;
    int DSAmarks, CAmarks, LAmarks, CSmarks, MVCmarks, ISLmarks; //subjects
    char garde;//Date of birth
    Teachernode* next;
    Teachernode* prev;

};
class teacher
{
private:
    Teachernode* head;
public:
    teacher()
    {
        head = NULL;
    }
    //Insert Data
    void InsertRecord()
    {
        Teachernode* curr1;
        int roll, aNO;
        int DSAmarks, CAmarks, LAmarks, CSmarks, MVCmarks, ISLmarks; //subjects
        char garde;//grade
        string name, fathername, dob, address;
        cout << "Enter Roll No: ";
        cin >> roll;

        cout << "\t\t\t\t Enter Name: ";
        cin >> name;
        cout << "\t\t\t\t Enter DSA Marks: ";
        cin >> DSAmarks;
        cout << "\t\t\t\t Enter CA Marks: ";
        cin >> CAmarks;
        cout << "\t\t\t\t Enter LA Marks: ";
        cin >> LAmarks;
        cout << "\t\t\t\t Enter MVC Marks: ";
        cin >> MVCmarks;
        cout << "\t\t\t\t Enter CS Marks: ";
        cin >> CSmarks;
        cout << "\t\t\t\t Enter ISL Marks: ";
        cin >> ISLmarks;
        //create New Node
        Teachernode* temp = new Teachernode;
        //Store date Node
        temp->rNo = roll;
        temp->nameStudent = name;
        temp->DSAmarks = DSAmarks;
        temp->CAmarks = CAmarks;
        temp->LAmarks = LAmarks;
        temp->MVCmarks = MVCmarks;
        temp->CSmarks = CSmarks;
        temp->ISLmarks = ISLmarks;
        temp->next = NULL;
        if (head == NULL)
        {
            temp->prev = NULL;
            head = temp;
            fstream file;
            file.open("teacher.txt", ios::out | ios::app);
            file << temp->rNo << " " << temp->nameStudent << " " << temp->CAmarks << " " << temp->DSAmarks << " " << temp->CSmarks << " " << temp->MVCmarks << " " << temp->ISLmarks << " " << temp->LAmarks << endl;
            file.close();
        }
        else
        {

            curr1 = head;
            while (curr1->next != NULL)
            {
                curr1 = curr1->next;
            }
            curr1->next = temp;
            temp->prev = curr1;
            fstream file;
            file.open("teacher.txt", ios::out | ios::app);
            file << temp->rNo << " " << temp->CAmarks << " " << temp->DSAmarks << " " << temp->CSmarks << " " << temp->MVCmarks << " " << temp->ISLmarks << " " << temp->LAmarks << endl;
            file.close();
        }
    }

    void Display()
    {
        int a = 1;//a++ count student no
        int found = 0;
        Teachernode* curr = head;
        cout << endl << endl;
        cout << "\t-------------------------------------------------------------------------------------------------------" << endl;
        cout << right << setw(12) << "Roll No. |" << setw(16) << "Student Name |" << setw(16) << "DSA MARKS |" << setw(20) << "CA MARKS |" << setw(15) << "LA MARKS |" << setw(15) << "MVC MARKS |" << setw(15) << "CS MARKS |" << setw(15) << "ISL MARKS |" << endl;
        cout << "\t-------------------------------------------------------------------------------------------------------" << endl;
        while (curr != NULL)
        {
            cout << right << setw(12) << curr->rNo << setw(16) << curr->nameStudent << setw(16) << curr->DSAmarks << setw(20) << curr->CAmarks << setw(15) << curr->LAmarks << setw(15) << curr->MVCmarks << setw(15) << curr->CSmarks << setw(15) << curr->ISLmarks << endl;
            curr = curr->next;

        }
        cout << endl;
        system("pause");
        system("cls");

    }


    void Update()
    {

        int found = 0;
        Teachernode* curr = head;
        int adNO;
        cout << "\t\t\t\t------------------------" << endl;
        cout << "\t\t\t\t Enter Roll No#: ";
        cin >> adNO;
        while (curr != NULL)
        {
            if (adNO == curr->rNo)
            {
                int a;
                string f;

                cout << "\t\t\t\t Enter Name: ";
                cin >> curr->nameStudent;
                cout << "\t\t\t\t Enter DSA Marks: ";
                cin >> curr->DSAmarks;
                cout << "\t\t\t\t Enter CA Marks: ";
                cin >> curr->CAmarks;
                cout << "\t\t\t\t Enter LA Marks: ";
                cin >> curr->LAmarks;
                cout << "\t\t\t\t Enter MVC Marks: ";
                cin >> curr->MVCmarks;
                cout << "\t\t\t\t Enter CS Marks: ";
                cin >> curr->CSmarks;
                cout << "\t\t\t\t Enter ISL Marks: ";
                cin >> curr->ISLmarks;
                UpdateRecordFileHandlng(curr->rNo, curr->nameStudent, curr->DSAmarks, curr->CAmarks, curr->LAmarks, curr->MVCmarks, curr->CSmarks, curr->ISLmarks);
                found++;
                cout << endl;
                cout << "\t\t\t\t Student Record Updated Successfully...." << endl;
                system("pause");
                system("cls");
                break;
            }
            curr = curr->next;
        }
        if (found == 0)
        {
            cout << endl << endl;
            cout << "\t\t\t\t Addmission No# not found!" << endl;
            system("pause");
            system("cls");
        }
    }

    void UpdateRecordFileHandlng(int roll, string name, int DSAmarks, int CAmarks, int LAmarks, int MVCmarks, int CSmarks, int ISLmarks)
    {
        int r;
        fstream file, file1;
        file.open("teacher.txt", ios::in);
        {
            file1.open("teacher1.txt", ios::app | ios::in);
            file >> r >> name >> DSAmarks >> CAmarks >> LAmarks >> MVCmarks >> CSmarks >> ISLmarks;

            while (!file.eof())
            {
                if (roll == r)
                {
                    file1 << r << ", " << name << ", " << DSAmarks << ", " << CAmarks << ", " << LAmarks << ", " << MVCmarks << ", " << CSmarks << ", " << ISLmarks << ", " << endl;
                }
                else
                {
                    file1 << r << ", " << name << ", " << DSAmarks << ", " << CAmarks << ", " << LAmarks << ", " << MVCmarks << ", " << CSmarks << ", " << ISLmarks << ", " << endl;

                }
                file >> r >> name >> DSAmarks >> CAmarks >> LAmarks >> MVCmarks >> CSmarks >> ISLmarks;
            }
        }
        file.close();
        file1.close();
        remove("teacher.txt");
        rename("teacher1.txt", "teacher.txt");
    }

    void DeleteStudent()
    {
        int found = 0;
        int AddmissionNo;
        cout << endl << endl;
        cout << "\t\t\t\t------------------------" << endl;
        cout << "\t\t\t\t Enter Roll No#: ";
        cin >> AddmissionNo;
        Teachernode* current = head;
        Teachernode* temp = NULL;
        while (current != NULL)
        {
            if (current->rNo == AddmissionNo)
            {
                if (current == head)
                    head = current->next;
                else if (current == temp)
                    temp = current->prev;
                else
                {
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                }
                RemoveFileHandlingStudent(current->rNo);
                delete current;
                found++;
                system("pause");
                system("cls");
                break;
            }
            current = current->next;
        }
        if (found == 0)
        {
            cout << endl << endl;
            cout << "\t\t\t\t Student Data not Found" << endl;
            system("pause");
            system("cls");
        }
    }



    //Remove FileHandling Student
    void RemoveFileHandlingStudent(int a)
    {
        int aID;   //admission no
        int rNo;
        string nameStudent;
        int DSAmarks, CAmarks, LAmarks, CSmarks, MVCmarks, ISLmarks; //subjects
        char garde;//grade
        fstream f, f1;
        f.open("student.txt", ios::in);
        {
            f1.open("student1.txt", ios::out | ios::app);
            f >> rNo >> nameStudent >> DSAmarks >> CAmarks >> LAmarks >> MVCmarks >> CSmarks >> ISLmarks;
            while (!f.eof())
            {
                if (rNo == a)
                {
                    cout << endl << endl;
                    cout << "\t\t\t\t  Student Removed Successfully...." << endl;
                    break;
                }
                else
                {
                    f1 << rNo << "," << nameStudent << ", " << DSAmarks << ", " << CAmarks << ", " << LAmarks << ", " << MVCmarks << ", " << CSmarks << ", " << ISLmarks << ", " << endl;
                }
                f >> rNo >> nameStudent >> DSAmarks >> CAmarks >> LAmarks >> MVCmarks >> CSmarks >> ISLmarks;
            }
            f1.close();
            f.close();
            remove("teacher.txt");
            rename("teacher1.txt", "teacher.txt");
        }
    }

    void LoadFromFile()
    {
        //using data type file handling
        int aID;   //admission no
        int rNo;
        string nameStudent;
        int DSAmarks, CAmarks, LAmarks, CSmarks, MVCmarks, ISLmarks; //subjects
        char garde;//grade
        //Student s;
        fstream file;
        file.open("teacher.txt", ios::in);
        if (!file)
        {
            cout << "\t\t\t\t Error Opening File....." << endl;
        }
        else
        {
            while (file >> aID >> rNo >> nameStudent >> DSAmarks >> CAmarks >> LAmarks >> MVCmarks >> CSmarks >> ISLmarks)
            {
                // s.Insert(aID, rNo, nameStudent, fathername, d, addrss);
                 //file >> aID >> rNo >> nameStudent >> fathername >> d >> addrss;
                Teachernode* curr;
                //create New Node
                Teachernode* temp = new Teachernode;
                //Store date Node
                temp->rNo = rNo;

                temp->nameStudent = nameStudent;
                temp->DSAmarks = DSAmarks;
                temp->CAmarks = CAmarks;
                temp->LAmarks = LAmarks;
                temp->MVCmarks = MVCmarks;
                temp->CSmarks = CSmarks;
                temp->ISLmarks = ISLmarks;
                temp->next = NULL;
                if (head == NULL)
                {
                    temp->prev = NULL;
                    head = temp;
                }
                else
                {
                    curr = head;
                    while (curr->next != NULL) {
                        curr = curr->next;
                    }
                    curr->next = temp;
                    temp->prev = curr;
                }


            }
            cout << endl << endl;
            cout << "\t\t\t\t Data Loaded From File Successfully....." << endl;
            system("pause");
            system("cls");
        }

        file.close();

    }


};

void teachermenu()
{
    teacher t;
    int choice;
    while (true)
    {
        cout << endl << endl;
        cout << "\t\t\t\t======================================================\n";
        cout << "\t\t\t\t|...............STUDENT MANAGEMENT SYSTEM............|\n";
        cout << "\t\t\t\t======================================================\n";

        cout << "\t\t\t\t| (1). Insert Student Data: " << endl;
        cout << "\t\t\t\t| (2). Search Student Data: " << endl;
        cout << "\t\t\t\t| (3). Total Student: " << endl;
        cout << "\t\t\t\t| (4). Update Student Data: " << endl;
        cout << "\t\t\t\t| (5). Delete Student Data: " << endl;
        cout << "\t\t\t\t| (6). Display Student Data: " << endl;
        cout << "\t\t\t\t| (7). Load Student Data From File: " << endl;
        cout << "\t\t\t\t| (8). Exit" << endl;
        cout << "\t\t\t\t| Enter Your Choice: ";
        cin >> choice;
        system("cls");
        switch (choice)
        {
        case 1:
        {
            system("cls");
            t.InsertRecord();
            system("pause");
            break;
        }

        case 4:
            system("cls");
            t.Update();
            system("pause");
            break;
        case 5:
            system("cls");
            t.DeleteStudent();
            system("pause");
            break;
        case 6:
            system("cls");
            t.Display();
            system("pause");
            break;
        case 7:
            system("cls");
            t.LoadFromFile();
            system("pause");
            break;
        case 8:
            return;
        default:
            cout << endl << endl;
            cout << "\t\t\t\t Invalid Choice....." << endl;
            system("pause");
            system("cls");

        }

    }
   
}

int main()
{
    node* head = NULL;

    Student s;

    int m, entry, choice;
    int ttry = 0;
    char username[10], password[10];
    char pass[10];
    while (true)
    {

        cout << endl << endl;
        cout << "\t\t\t\t======================================================\n";
        cout << "\t\t\t\t|...............STUDENT MANAGEMENT SYSTEM............|\n";
        cout << "\t\t\t\t======================================================\n";

        cout << "\t\t\t\t 1  Admin \n\t\t\t\t 2  Staff \n\t\t\t\t 3  User \n";
        cin >> entry;

        switch (entry) {
        case 1:
        {
            cout << "\n\t\t\t\t Enter the password letter by letter: ";
            cin >> pass;
            if (strcmp(pass, "admin") == 0)
            {
                cout << "\n\n\nCongrats!!Access Granted!!\n\n";


            }
            system("CLS");
            while (true)
            {

                cout << endl << endl;
                cout << "\t\t\t\t======================================================\n";
                cout << "\t\t\t\t|...............STUDENT MANAGEMENT SYSTEM............|\n";
                cout << "\t\t\t\t======================================================\n";

                cout << "\t\t\t\t| (1). Insert Student Data: " << endl;
                cout << "\t\t\t\t| (2). Search Student Data: " << endl;
                cout << "\t\t\t\t| (3). Total Student: " << endl;
                cout << "\t\t\t\t| (4). Update Student Data: " << endl;
                cout << "\t\t\t\t| (5). Delete Student Data: " << endl;
                cout << "\t\t\t\t| (6). Display Student Data: " << endl;
                cout << "\t\t\t\t| (7). Load Student Data From File: " << endl;
                cout << "\t\t\t\t| (8). Exit" << endl;
                cout << "\t\t\t\t| Enter Your Choice: ";
                cin >> choice;
                system("cls");
                switch (choice)
                {
                case 1:
                {
                    s.Insert();
                    break;
                }
                case 2:
                    s.StudentSearchRecord();
                    break;
                case 3:
                    s.CountStudent();
                    break;
                case 4:
                    s.Update();
                    break;
                case 5:
                    s.DeleteStudent();
                    break;
                case 6:
                    s.Display();
                    break;
                case 7:
                    s.LoadFromFile();
                    break;
                case 8:
                    return 0;
                default:
                    cout << endl << endl;
                    cout << "\t\t\t\t Invalid Choice....." << endl;
                    system("pause");
                    system("cls");
                    main();
                }

            }

            break;
        }
        case 2:
        {
            system("cls");
            teachermenu();
            system("pause");
            break;
        }
    defalt:
        {
            cout << "invalid input";
        }
        }

    }
}