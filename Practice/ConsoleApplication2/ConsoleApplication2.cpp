#include <iostream>
#include <string>
using namespace std;

class carinfo
{
    string carName;
    string colour;
    int plateNo;
    carinfo* next;

public:
    carinfo()
    {
        carName = " ";
        colour = " ";
        plateNo = 0;
        next = NULL;
    }
    void setcarName(string name)
    {
        carName = name;
    }
    void setcolour(string p)
    {
        colour = p;
    }
    void setplateNo(int q)
    {
        plateNo = q;
    }
    void setnext(carinfo* ptr)
    {
        next = ptr;
    }
    string getcarName()
    {
        return carName;
    }
    string getcolour()
    {
        return colour;
    }
    int getplateNo()
    {
        return plateNo;
    }
    carinfo* NextAddress()
    {
        return next;
    }
};
class itemlist
{
   
public:
    carinfo* head;
    itemlist()
    {
        head = NULL;
    }
    
    //inserting at the start of list
    void insertAtStart(string name, string colour, int plateNo)
    {
        carinfo* newItem = new carinfo;
        newItem->setcarName(name);
        newItem->setcolour(colour);
        newItem->setplateNo(plateNo);
        newItem->setnext(head);
        head = newItem;
    }
    //insertion at the end of list
    void insertAtEnd(string name, string colour, int plateNo)
    {
        carinfo* newItem = new carinfo;
        newItem->setcarName(name);
        newItem->setcolour(colour);
        newItem->setplateNo(plateNo);
        newItem->setnext(NULL);
        //if list is empty
        if (head == NULL) {
            head = newItem;
            return;
        }
        //finding last node
        carinfo* last = head;
        while (last->NextAddress() != NULL) {
            last = last->NextAddress();
        }
        last->setnext(newItem);
    }

    //insert at a specific position
    void insertinfoAtPos(string name, string colour, int plateNo, carinfo* previousNode)
    {
        //checking if the previous node is null
        if (previousNode == NULL) {
            cout << "Cant add at this position" << endl;
            return;
        }
        carinfo* newItem = new carinfo;
        newItem->setcarName(name);
        newItem->setcolour(colour);
        newItem->setplateNo(plateNo);
        newItem->setnext(previousNode->NextAddress());
        *previousNode->NextAddress() = *newItem;
    }

    //remove at specific position
    void removeItem(carinfo* node, string n)
    {
        carinfo* current = head;
        carinfo* ptr;
        while (current->NextAddress()->getcarName() != n)
        {
            current = current->NextAddress();
        }
        ptr = current->NextAddress();
        *current->NextAddress() = *current->NextAddress()->NextAddress();
        delete ptr;

    }
    void printlist() {
        carinfo* newitem = head;
        while (newitem != NULL) {
            cout << newitem->getcolour() << endl;
            cout << newitem->getplateNo() << endl;
            cout << newitem->getcarName() << endl;
            newitem = newitem->NextAddress();
        }
    }
};
int main()
{
    while (true)
    {
        cout << "-----------Welcome-------------" << endl;
        cout << "press 1 to add at end of list" << endl;
        cout << "press 2 to add at start of list" << endl;
        cout << "press 3 to add at specific position in list" << endl;
        cout << "press 4 to remove from list" << endl;
        cout << "press 5 to print list" << endl;
        cout << "press 6 to exit the program" << endl;
        cout << "-------------------------" << endl;
        string name;
        string colour;
        int plateNo;
        itemlist Obj;
        int option;


        cout << "enter option" << endl;
        cin >> option;
        switch (option)
        {
        case 1:
            cout << "Enter name to add at end of list" << endl;
            cin >> name;
            cout << "Enter colour of item to add at end of list" << endl;
            cin >> colour;
            cout << "Enter plateNo of to add at end of list" << endl;
            cin >> plateNo;
            Obj.insertAtEnd(name, colour, plateNo);
            break;

        case 2:
            cout << "Enter name to add at start of list" << endl;
            cin >> name;
            cout << "Enter colour of item to add at start of list" << endl;
            cin >> colour;
            cout << "Enter plateNo of to add at start of list" << endl;
            cin >> plateNo;
            Obj.insertAtStart(name, colour, plateNo);
            break;

        case 3:
            cout << "Enter name to add in list" << endl;
            cin >> name;
            cout << "Enter colour of item to add in list" << endl;
            cin >> colour;
            cout << "Enter plateNo of item to add in list" << endl;
            cin >> plateNo;
            cout << "Enter plateNo of item to add in list" << endl;
            cin >> plateNo;
            Obj.insertinfoAtPos(name, colour, plateNo,Obj.*head);
                break;
        case 4:
            cout << "Enter name remove in list" << endl;
            cin >> name;
            Obj.removeItem(Obj.head, name);
                break;
        case 5:
            Obj.printlist();
        case 6:
            exit(1);
            break;
        default:
            cout << "no" << endl;
        }
    }
}