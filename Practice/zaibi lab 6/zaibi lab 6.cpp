

#include <iostream>

using namespace std;
//Create Node With Class
class node
{
public:
    int data;
    node* next;
};

//Student List
class StudentList {
private: 
    node* head, * tail;
    string name;
    int rollno;
    float cgpa;


public:
    StudentList()
    {
        head = NULL;
        tail = NULL;
        name = "zaibi";
        rollno = 3;
        cgpa = 3.33;

    }

    //Create Parameter Ctor
    StudentList(string n, int r, float c)
    {
        name = n;
        rollno = r;
        cgpa = c;
        
        node* temp = new node();
        
        temp->data = rollno;
        temp->data = cgpa;
        temp->next = NULL;
        temp->next = head;
        head = temp;
       
       

    }
    //function show

    void show()
    {
        node* curr = head;
        while (curr != NULL)
        {
            cout << curr->data << endl;
            curr = curr->next;
        }
        
    }
    //getter
    string getname()
    {
        return name;
    }
    int getrollno()
    {
        return rollno;
    }
    float getCgpa()
    {
        return cgpa;
    }
    //setter
    void setName(string name)
    {
        name = this->name;
    }
    void setRollno(int rollno)
    {
        rollno = this->rollno;
    }
    float setCgpa(float cgpa)
    {
        cgpa = this->cgpa;
    }







};

int main()
{
    StudentList s("Jahanzaib",4,3.2);
    s.show();
}
