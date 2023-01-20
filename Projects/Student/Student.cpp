#include <iostream>
#include <fstream>
#include <string>
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

    node* next;
    node* prev;
};

class Student
{
private:
    node* head;
public:
    Student()
    {
        head = NULL;
    }
    //Insert Data
    void Insert()
    {
        int roll, aNO;
        string name, fathername, dob, address;
        ///user data enter

        //cheack node if duplicate Admission No 
        cout << "Enter Admission No: ";
        while (true)
        {
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
        cout << "Enter Roll No: ";
        cin >> roll;
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Father Name: ";
        cin >> fathername;
        cout << "Enter Address: ";
        cin >> address;
        cout << "Enter Date of Birth(DD/MM/YYYY): ";
        cin >> dob;

        //
        node* curr;
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

    //Search Student Record
    void StudentSearchRecord()
    {
        int found = 0;
        int searchRollNo;
        cout << "Enter Search Roll No: ";
        cin >> searchRollNo;
        node* curr = head;
        while (curr != NULL) {
            if (searchRollNo == curr->rollNo)
            {
                cout << "Enter Admission No: " << curr->adID << endl;
                cout << "Enter Roll No: " << curr->rollNo << endl;
                cout << "Enter Name: " << curr->name << endl;
                cout << "Enter Father Name: " << curr->fname << endl;
                cout << "Enter Address: " << curr->address << endl;
                cout << "Enter Date of Birth(DD/MM/YYYY): " << curr->dob << endl;;
                found++;
                break;
            }
            curr = curr->next;
        }
        if (found == 0)
        {
            cout << "Roll No not found!" << endl;
        }
    }

    //Count Student 
    void CountStudent() {
        int count = 0;
        node* curr = head;
        while (curr != NULL) {
            count++;
            curr = curr->next;
        }
        cout << "Total Students: " << count << endl;
    }

    //Update Function
    void Update()
    {
        int found = 0;
        node* curr = head;
        int adNO;
        cout << "Enter Admission no: ";
        cin >> adNO;
        while (curr != NULL) {
            if (adNO == curr->adID) {
                cout << "Enter Roll No: ";
                cin >> curr->rollNo;
                cout << "Enter Name: ";
                cin >> curr->name;
                cout << "Enter Father Name: ";
                cin >> curr->fname;//father Name update
                cout << "Enter Address: ";
                cin >> curr->address;
                cout << "Enter Date of Birth(DD/MM/YYYY): ";
                cin >> curr->dob;
                found++;
                break;
            }
            curr = curr->next;
        }
        if (found == 0) {
            cout << "Addmission No not found!" << endl;
        }
    }

    //Delete Student Data
       //Delete Student Data
    void DeleteStudent()
    {
        int found = 0;
        int roll;
        cout << "Enter Roll No: ";
        cin >> roll;
        node* curr = head;
        node* temp = NULL;
        if (head->rollNo == roll) {
            temp = head;
            head = head->next;
            head->prev = NULL;
            delete temp;
            found++;
        }
        else
        {
            while (curr != NULL)
            {
                if (curr->rollNo == roll)
                {
                    temp = curr;
                    curr->prev->next = curr->next;
                    curr->next->prev = curr->prev;
                    delete temp;
                    found++;
                    break;
                }
                curr = curr->next;
            }
        }
        if (found == 0) {
            cout << "Roll No not found!" << endl;
        }
    }
    //Display
    void Display()
    {
        int a = 1;//a++ count student no
        int found = 0;
        node* curr = head;
        cout << left << setw(5) << "NO" << setw(17) << "Admission No" << setw(12) << "Roll No" << setw(16) << "Student Name" << setw(16) << "Father Name" << setw(20) << "Date of Birth" << setw(15) << "Address" << endl;
        cout << "--------------------------------------------------------------------------------------------" << endl;
        while (curr != NULL)
        {

            cout << left << setw(5) << a++ << setw(17) << curr->adID << setw(12) << curr->rollNo << setw(16) << curr->name << setw(16) << curr->fname << setw(20) << curr->dob << setw(15) << curr->address << endl;

            //			
            //			cout << "Roll No: " << curr->rollNo << endl;
            //			cout << "Your Name: " << curr->name << endl;
            //			cout << "CGPA: " << curr->cgpa << endl;
            curr = curr->next;
            found++;
        }

    }

    //Save Data to File
    void SaveToFile()
    {
        int a = 1;//a++ count student no
        ofstream file;
        file.open("students.txt", ios::out | ios::trunc);
        node* curr = head;
        while (curr != NULL) {
            file << a++ << "," << curr->adID << "," << curr->rollNo << "," << curr->name << "," << curr->fname << "," << curr->dob << "," << curr->address << endl;

            curr = curr->next;
        }
        file.close();
        cout << "Data saved to file successfully!" << endl;
    }


    //Load Data from File
    void LoadFromFile()
    {
        ifstream file;
        file.open("students.txt", ios::in);
        if (!file)
        {
            cout << "Error opening file!" << endl;
            return;
        }
        int roll, aNO;
        string name, fathername, dob, address;
        while (file >> aNO >> roll >> name >> fathername >> dob >> address)
        {
            node* temp = new node;

            temp->adID = aNO;
            temp->rollNo = roll;
            temp->name = name;
            temp->fname = fathername;
            temp->dob = dob;
            temp->address = address;
            temp->next = NULL;
            temp->prev = NULL;
            node* curr = head;
            if (head == NULL) {
                head = temp;
            }
            else {
                while (curr->next != NULL) {
                    curr = curr->next;
                }
                curr->next = temp;
                temp->prev = curr;
            }
        }
        file.close();
        cout << "Data loaded from file successfully!" << endl;
    }
};

int main() {
    Student s;
    int choice;
    while (true)
    {

        cout << "1. Insert" << endl;
        cout << "2. Search" << endl;
        cout << "3. Count" << endl;
        cout << "4. Update" << endl;
        cout << "5. Delete" << endl;
        cout << "6. Display" << endl;
        cout << "7. Save to File" << endl;
        cout << "8. Load from File" << endl;
        cout << "9. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            s.Insert();
            break;
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
            s.SaveToFile();
            break;
        case 8:
            s.LoadFromFile();
            break;
        case 9:
            return 0;
        default:
            cout << "Invalid choice!" << endl;
        }
    }
    return 0;
}
