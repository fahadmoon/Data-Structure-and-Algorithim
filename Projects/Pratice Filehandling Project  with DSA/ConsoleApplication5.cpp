#include <iostream>
#include <fstream>
#include <string>
#include<stdio.h>
#include <iomanip> //using library setw()
using namespace std;

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
            file << temp->rNo << " " <<temp->nameStudent<< " " << temp->CAmarks << " " << temp->DSAmarks << " " << temp->CSmarks << " " << temp->MVCmarks << " " << temp->ISLmarks << " " << temp->LAmarks << endl;
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
        cout << right  << setw(12) << "Roll No. |" << setw(16) << "Student Name |" << setw(16) << "DSA MARKS |" << setw(20) << "CA MARKS |" << setw(15) << "LA MARKS |" << setw(15) << "MVC MARKS |" << setw(15) << "CS MARKS |" << setw(15) << "ISL MARKS |" << endl;
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
            file >>  r >> name >> DSAmarks >> CAmarks >> LAmarks >> MVCmarks >> CSmarks >> ISLmarks;

            while (!file.eof())
            {
                if (roll == r)
                {
                    file1  << r << ", " << name << ", " << DSAmarks << ", " << CAmarks << ", " << LAmarks << ", " << MVCmarks << ", " << CSmarks << ", " << ISLmarks << ", " << endl;
                }
                else
                {
                    file1 << r << ", " << name << ", " << DSAmarks << ", " << CAmarks << ", " << LAmarks << ", " << MVCmarks << ", " << CSmarks << ", " << ISLmarks << ", " << endl;

                }
                file >>r >> name >> DSAmarks >> CAmarks >> LAmarks >> MVCmarks >> CSmarks >> ISLmarks;
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



int main()
{
    teacher s;
    s.InsertRecord();
    s.Display();
    s.Update();
    s.Display();

    
}