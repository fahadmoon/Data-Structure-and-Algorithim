// FileLoad.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
using namespace   std;
class Student {
public:
    string name;
    int rollno;
    Student()
    {

    }
    Student(string name, int rollno)
    {
        this->name = name;
        this->rollno = rollno;
    }
};
class Node
{
public:
    Student* data;
    Node* next;
    Node(Student* data)
    {
        this->data = data;
        next = NULL;
    }

};
class studentData {
private:
    Node* head;
public:
    studentData()
    {
        head = NULL;
       
    }

    void Insert(Student* data)
    {
        Node* newNode = new Node(data);
        Node* curr;
        fstream file;
        if (head == NULL)
        {
            head = newNode;
            file.open("Student.txt", ios::out | ios::app);
            file << head->data->name << " " << head->data->rollno << endl;
            file.close();
        }
        else
        {
            curr = head;
            while (curr->next != NULL)
            {
                curr = curr->next;
            }
            curr->next = newNode;
            file.open("Student.txt", ios::out | ios::app);
            file << head->data->name << " " << head->data->rollno << endl;
            file.close();
        }
        cout << "Data Successful " << endl;
    }

    void display()
    {
        while (head != NULL)
        {
            cout <<"Name: " << head->data->name << endl;
            cout <<"Roll No: "<< head->data->name << endl << endl;
            head=head->next;
        }
    }
    void LoadFile()
    {
        Student s;
        Node* curr;
       
        fstream file;
        file.open("Student.txt", ios::in);
        file >> s.name >> s.rollno;
        while (!file.eof())
        {
            Node* newNode = new Node(new Student(s.name, s.rollno));
            if (head == NULL)
            {
                head = newNode;
            }
            else
            {
                 curr=head;
                 while (curr->next!=NULL)
                 {
                     curr = curr->next;
                 }
                 curr->next = newNode;
            }
            file >> s.name >> s.rollno;
        }
    }


};

int main()
{
    studentData s;
    int c;
   
    while (true)
    {
        cout << "1. INSERT" << endl;
        cout << "2. Display" << endl;
        cout << "3. LoadFile" << endl;
        cout << "4. Exit" << endl;
        cin >> c;
        switch (c)
        {
        case 1:
        {
            cout << "Enter NAme: " << endl;
            string name;
            cin >> name;
            cout << "Enter Roll No : " << endl;
            int roll;
            cin >> roll;
            system("cls");
            s.Insert(new Student(name, roll));
            system("pause");
            break;
        }
        case 2:
           
            s.display();
            
            break;
        case 3:
            s.LoadFile();
           
            break;
        case 4:
            exit(0);
        default:
            break;
        }
    }
    
}




class NodeBalance
{
public:
    double pharmacybalance;
    NodeBalance* next;
};
class balance :public NodeBalance
{
private:
    NodeBalance* head;
public:
    balance()
    {
        head = NULL;
    }
    void InsertBalance(double bal)
    {
        NodeBalance* b = new NodeBalance;
        b->pharmacybalance = bal;
        b->next = NULL;
        head = b;
        fstream file;
        file.open("Balance.txt", ios::app | ios::out);
        file << head->pharmacybalance;
        file.close();
    }
    void updateBalance(double newBal)
    {
        NodeBalance* n = head;
        fstream file, file1;
        file.open("Balance.txt", ios::in);
        file1.open("Balance1.txt", ios::app | ios::out);
        file >> newBal;
        while (!file.eof())
        {
            if (n->next == NULL)
            {
                head->pharmacybalance = newBal;
                file1 << head->pharmacybalance;

            }

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
        while (!file.eof())
        {
            NodeBalance* n = new NodeBalance();
            n->pharmacybalance = bal;
            n->next = NULL;
            file >> bal;
        }

        file.close();
    }


};


